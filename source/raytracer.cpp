#include <renderer.hpp>
#include <window.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>
#include "sdfloader.hpp"
#include <memory>
#include "scene.hpp"


int main(int argc, char* argv[])
{
  std::string input_path;
  unsigned const width = 800;
  unsigned const height = 600;
  std::cout << "Please enter the path to your file:" << std::endl;
  std::cin >> input_path;

  std::string const filename = "./raytrace.ppm";

  Scene sceneToRender = load(input_path); //lade scene 



  Renderer app{width, height, filename};
 // Renderer app{width, height, filename, sceneToRender};

  std::thread thr([&app]() { app.render(); });

  Window win{glm::ivec2{width,height}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    win.show(app.colorbuffer());
  }

  thr.join();

  return 0;
}
