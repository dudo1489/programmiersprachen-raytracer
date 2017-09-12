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
 
  
    
      Ray temp_ray = scene_.camera_.find(scene_.renderinfo_.camera_chosen)->second.generate_ray(x, y, height_, width_);
    
      
      p.color = raytrace(temp_ray, 2);
      //p.color = antialiase(temp_ray, 4, 0);

      //p.color = ToneMapping(p.color);

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

  Color Renderer::raytrace(Ray const& ray, unsigned int depth)
  {

    Hit hit = scene_.composite_ -> intersect(ray);  //alle shapes intersecten und am nahe gelegenste shape zurückgeben


    if(hit.hit_ == true)  //falls es hit gibt mache:
    { 

      Color color;

      ambientlight(color, hit.shape_ -> get_material().ka_);  //errechne hintergrundlicht der szene 

     

      for(auto light : scene_.light_) //gehe über jede lichtquelle
        {
          
            pointlight(color, light, hit, ray); //errechne licht an objekt
          
        }

      if(depth>0)
      {
        
        spiegelung(color, hit, ray, depth);
      }

    
      return color;
    }
    
      else
      {
        return scene_.backgroundclr_;
      }
    }


  void Renderer::ambientlight(Color & color, Color const& ka )  //berechnet ambientlight 
  {
    color+=(scene_.backgroundclr_)*(ka);
  }


  void Renderer::pointlight(Color & color, std::shared_ptr<Light> const& light,Hit const& hit, Ray const& ray) //berechnet licht an shape
  {
    
    glm::vec3 direction = glm::normalize(light->point_- hit.intersect_); //vector an intersect punkt normalisieren
    Ray ray_to_light {hit.intersect_+(direction*0.001f), direction}; //ray von intersect punkt zu light erstellen


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

  void Renderer::spiegelung(Color & clr, Hit const& Hitze, Ray const& ray, unsigned int depth)
  {
    glm::vec3 direction = glm::normalize(glm::reflect(ray.direction, Hitze.normal_));
    Ray ray_to_Object{Hitze.intersect_+ (direction*0.01f), direction};

    Color next_Object_clr = raytrace(ray_to_Object, depth-1);

    clr += next_Object_clr;
    //clr = clr * next_Object_clr * (1.0f-Hitze.shape_->get_material().ks_);

  }

  /* Color Renderer::reflection(Hit const& hit, Ray const& ray, unsigned depth) const
  {
    Color reflection_color;
  
    glm::vec3 reflection = glm::normalize(glm::reflect(ray.direction, hit.normal_));
  
    Ray reflection_ray
    {
      hit.intersection_ + (0.01f * reflection),
  
      reflection
    };
  
    reflection_color = raytrace(reflection_ray, depth - 1);
  
    return reflection_color;
  } */ 

  Color Renderer::antialiase(Ray const& rayman, float fact, unsigned int depth)
  {
    Color tempClr;
    int samples = sqrt(fact);
    for(int x = 1; x < samples +1; ++x)
    {
      for(int y = 1; y < samples +1; ++y)
      {
        Ray ray;
        ray.direction.x = rayman.direction.x + (float) (x)/(float)samples-0.5f;
        ray.direction.y = rayman.direction.y + (float) (y)/(float)samples-0.5f;
        ray.direction.z = rayman.direction.z;
        tempClr += raytrace(ray, depth);
      }
      tempClr.r = tempClr.r/fact;
      tempClr.g = tempClr.g/fact;
      tempClr.b = tempClr.b/fact;

      return tempClr;
    }
  }

  Color Renderer::ToneMapping(Color & clr)
  {
    Color color;
    color.r = clr.r/(clr.r+1);
    color.g = clr.g/(clr.g+1);
    color.b = clr.b/(clr.b+1);
    return color;
  }