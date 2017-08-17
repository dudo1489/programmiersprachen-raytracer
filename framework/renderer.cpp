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

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      Ray testray{{0.0, 0.0, 0.0}, {10.0, 20.0, 30.0}}; //= scene_.camera_.calc_eye_ray(x, y, height_, width_);
      p.color = raytrace(testray);

    /* if ( ((x/checkersize)%3) != ((y/checkersize)%2)) {
        p.color = Color(0.0, 1.0, float(x)/height_);
      } else {
        p.color = Color(1, 0.0, .0float(y)/width_);
      }
    */

      // std::cout<<"Pixel"<<x<<","<<y<<"\n";
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
    
    std::cout << "test \n";
    Hit hit = scene_.composite_ -> intersect(ray);  //alle shapes intersecten und am nahe gelegenste shape zurückgeben
    std::cout << "kommt was? \n";
    if(hit.hit_ == true)  //falls es hit gibt mache:
    {
      Color color;
      color = ambientlight(color, hit.shape_ -> get_material().ka_);  //errechne hintergrundlicht der szene 
    

      for(auto light : scene_.light_) //gehe über jede lichtquelle
      {
          /* color += */  pointlight(color, light, hit, ray); //errechne licht an objekt
      }
    return color;
    }
    //

    return scene_.backgroundclr_;
  }


  Color Renderer::ambientlight(Color & color, Color const& ka )  //berechnet ambientlight 
  {
    color+=(scene_.backgroundclr_)*(ka);
  }


  void Renderer::pointlight(Color & color, std::shared_ptr<Light> const& light,Hit const& hit, Ray const& ray) //berechnet licht an shape
  {
    glm::vec3 direction = glm::normalize(light->point_-hit.intersect_); //vector an intersect punkt normalisieren
    Ray ray_to_light {hit.intersect_+(direction*0.001f), direction}; //ray von intersect punkt zu light erstellen

    //int distance = glm::length(hit.intersect_ - light.point_);  //distance zwischen light und intersect punkt

    Hit lightHit = scene_.composite_ -> intersect(ray_to_light);

     if(lightHit.hit_ == false)  //gibt es hit zwischen light und intersect 
    {
      diffuselight(color, hit, light, ray_to_light);
      specularlight(color, hit, light, ray_to_light, ray);
      //falls kein hit: berechne diffus und specular light
    } 
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