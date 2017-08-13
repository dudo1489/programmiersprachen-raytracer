#include <renderer.hpp>
#include <window.hpp>

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>
#include "sdfloader.hpp"
#include <memory>


int main(int argc, char* argv[])
{
  unsigned const width = 800;
  unsigned const height = 600;
  std::string const filename = "./checkerboard.ppm";
  std::shared_ptr<SDFloader> sdfloader;
  Scene loadedScene;
  
  loadedScene = sdfloader -> load(filename);

  Renderer app{width, height, filename};

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
