// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{std::cout<<"renderkonstruktor ohne scene \n";}

Renderer::Renderer(unsigned w, unsigned h, std::string const& file, Scene const& scene)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
  , scene_(scene)
{std::cout<<"rendererkonstruktor works"<<"\n";}

void Renderer::render()
{
  //const std::size_t checkersize = 20;
 // float distance = -(float(width_)/2)/tan(M_PI*scene_.camera_.fov_x_/(2*180));
 // std::cout << "Size of composite: " << scene_.composite_->shape_.size() <<"\n \n";

  float distance = 400;

  float pos_y = (((float)height_) / -2);

  for (unsigned y = 0; y < height_; ++y) 
  {
    ++pos_y;

    float pos_x = (((float)width_) / -2);

    for (unsigned x = 0; x < width_; ++x) 
    {
      ++pos_x;
      Pixel p(x,y);
      std::cout<<"\n"<<"Pixel "<<x<<", "<<y<<"\n";

  //   Ray temp_ray {{0,0,0}, glm::normalize(glm::vec3(pos_x, pos_y, distance))};
  //   Ray temp_ray = scene_.camera_.generate_ray(pos_x, pos_y, distance);
      Ray temp_ray = scene_.camera_.generate_ray(x, y, height_, width_);
      Color tempcolor;
      //Ray testray {{0,0,0}, glm::normalize(glm::vec3(x, y, distance))};
      tempcolor = raytrace(temp_ray);

      p.color = ToneMapping(tempcolor);

  /*    if ( ((x/checkersize)%3) != ((y/checkersize)%2)) {
          p.color = Color(0.0, 1.0, float(x)/height_);
          } else {
          p.color = Color(1, 0.0, .0float(y)/width_);
        }
  */

  //    p.color = Color(1.0, 0.0, 1.0);//berechnet aus 
      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

  Color Renderer::raytrace(Ray const& ray)
  {

    Hit hit = scene_.composite_ -> intersect(ray);  //alle shapes intersecten und am nahe gelegenste shape zurückgeben


    if(hit.hit_ == true)  //falls es hit gibt mache:
    { 

      Color color = hit.shape_->get_material().ka_;

      ambientlight(color, hit.shape_ -> get_material().ka_);  //errechne hintergrundlicht der szene 

      std::cout << "hit1 color:" <<color.r << ","<< color.g <<"," <<color.b <<"\n";

     

    for(auto light : scene_.light_) //gehe über jede lichtquelle
        {
          
            pointlight(color, light, hit, ray); //errechne licht an objekt
          
        }
     
      std::cout << "hit2 color:" <<color.r << ","<< color.g <<"," <<color.b <<"\n";
      
    
      return color;
    }
    
    else
    {
        std::cout << "no hit color:" <<scene_.backgroundclr_.r << ","<<scene_.backgroundclr_.g <<"," << scene_.backgroundclr_.b <<"\n";
        
        return scene_.backgroundclr_;}
    }


  void Renderer::ambientlight(Color & color, Color const& ka )  //berechnet ambientlight 
  {
    color+=(scene_.backgroundclr_)*(ka);
    std::cout << "obj color:" <<color.r << ","<< color.g <<"," <<color.b <<"\n";
   /* std::cout << "ambient color:" <<scene_.light_[0]->color_.r << ","<< scene_.light_[0]->color_.g <<"," <<scene_.light_[0]->color_.b << ","
                                  <<scene_.light_[0]->brightness_<< 
                                  ","<<scene_.light_[0]->point_.x<< ","<<scene_.light_[0]->point_.y<< ","<<scene_.light_[0]->point_.z<<"\n";
 */
  }


  void Renderer::pointlight(Color & color, std::shared_ptr<Light> const& light,Hit const& hit, Ray const& ray) //berechnet licht an shape
  {
    
    glm::vec3 direction = glm::normalize(light->point_- hit.intersect_); //vector an intersect punkt normalisieren
    Ray ray_to_light {hit.intersect_+(direction*0.001f), direction}; //ray von intersect punkt zu light erstellen

    //int distance = glm::length(hit.intersect_ - light->point_);  //distance zwischen light und intersect punkt

    Hit lightHit = scene_.composite_ -> intersect(ray_to_light);

     if(lightHit.hit_ == false)  //gibt es hit zwischen light und intersect 
    {
      diffuselight(color, hit, light, ray_to_light);
      specularlight(color, hit, light, ray_to_light, ray);
      //falls kein hit: berechne diffus und specular light
    } 
      std::cout << "point color:" <<color.r << ","<< color.g <<"," <<color.b <<"\n";
      //falls objekt dazwischen ist wirft es hier schatten
  }

//
  void Renderer::diffuselight(Color & clr, Hit const& Hitze, std::shared_ptr<Light> const& light,  Ray const& raylight)
      {
        float faktor=(glm::dot((Hitze.normal_) , raylight.direction));
        clr+= (light->color_) * (Hitze.shape_->get_material().kd_) * (std::max(faktor,0.0f));       
      }


  void Renderer::specularlight(Color & clr, Hit const& Hitze, std::shared_ptr<Light> const& light,  Ray const& raylight, Ray const& ray)
      {
        auto r = glm::normalize(glm::reflect(raylight.direction, Hitze.normal_));
        float cosb = std::max(0.0f, glm::dot(r, glm::normalize(ray.direction)));          //evtl hier nochmal mit transf. ray probieren!
        clr+= light->color_ * Hitze.shape_->get_material().ks_ * pow(cosb, Hitze.shape_->get_material().m_);
      }


  Color Renderer::ToneMapping(Color & clr)
  {
    Color color;
    color.r = clr.r/(clr.r+1);
    color.g = clr.g/(clr.g+1);
    color.b = clr.b/(clr.b+1);
    return color;
  }