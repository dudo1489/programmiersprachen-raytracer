// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>
#include "scene.hpp"

class Renderer
{
public:
  Renderer(unsigned w, unsigned h, std::string const& file);
  Renderer(unsigned w, unsigned h, std::string const& file, Scene const& scene);

  void render();
  void write(Pixel const& p);
  Color raytrace(Ray const& ray);
  Color ambientlight(Color & color, Color const& ka);
<<<<<<< HEAD
  void specularlight(Color & clr, Hit const& Hitze, std::shared_ptr<Light> const& light,  Ray const& raylight, Ray const& ray);
  void diffuselight(Color & clr, Hit const& Hitze, std::shared_ptr<Light> const& light,  Ray const& raylight);
=======

  //Ray getRay()
>>>>>>> 2c9fad5a9c3c599e4a93a106ade3b4557be155a9
  
  void pointlight(Color & color, std::shared_ptr<Light> const& light,Hit const& hit, Ray const& ray);
  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }



private:
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
  Scene scene_;
};

#endif // #ifndef BUW_RENDERER_HPP
