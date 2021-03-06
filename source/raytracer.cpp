#include "renderer.hpp"
#include <window.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>
#include <sdfloader.hpp>
#include <memory>
#include "scene.hpp"
#include "shape.hpp"
#include "ray.hpp"
#include "composite.hpp"



int main(int argc, char* argv[])
{
  std::string input_path;
  unsigned int width = 401;
  unsigned int height = 401;
  std::cout << "Please enter the path to your file:" << std::endl;
  std::cin >> input_path;

  Scene sceneToRender = load(input_path); //lade scene 

  //std::string const filename = "./raytrace.ppm";
  std::string const filename = sceneToRender.renderinfo_.image_name;

  std::cout<<"scene erstellt"<<"\n";

  width = sceneToRender.renderinfo_.image_width;
  height = sceneToRender.renderinfo_.image_height;


  //Renderer app{width, height, filename};
  Renderer app= Renderer{width, height, filename, sceneToRender};
 

 //std::thread thr([&app]() { app.render(); });
app.render();
  Window win{glm::ivec2{width,height}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    win.show(app.colorbuffer());
  }

  //thr.join();

  return 0;
}
