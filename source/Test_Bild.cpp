#include "fensterchen.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <window.hpp>

int main(int argc, char* argv[])
{
  unsigned width = 800;
  unsigned height = 600;
  std::string const filename = "./test_bild.ppm";

  Renderer test{width, height, filename};

  std::thread thr([&test]() { test.render(); });


  Window win{glm::ivec2{800,800}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();
    auto m = win.mouse_position();

    win.update();
  }

  return 0;
}
