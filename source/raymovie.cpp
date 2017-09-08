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

//int argc, char* argv[]
string concat(const string &s, int number)
{
    ostringstream result;
    result << number<< s;
    return result.str();
}
void raytrace(int number, std::string path)
{
  unsigned int width = 401;
  unsigned int height = 401;
  path = concat(path, number);

  Scene sceneToRender = load(path); //lade scene 

  //std::string const filename = "./raytrace.ppm";
  std::string const filename = sceneToRender.renderinfo_.image_name;

  std::cout<<"scene erstellt"<<"\n";

  width = sceneToRender.renderinfo_.image_width;
  height = sceneToRender.renderinfo_.image_height;


  //Renderer app{width, height, filename};
  Renderer app= Renderer{width, height, filename, sceneToRender};
 

 std::thread thr([&app]() { app.render(); });
  unsigned int  a = 100;
/*  Window win{glm::ivec2{a,a}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    win.show(app.colorbuffer());
  }
*/
  thr.join();

  return;
}



int main()
{
    std::string input_path;
    std::cout << "Please enter the path to your file:" << std::endl;
    std::cin >> input_path;
  for (int y=0;y<80;++y)
  {
  std::cout << "begin raytrace for image "<<y<<std::endl;
  raytrace(y, input_path);
  }

  return 0; 
}