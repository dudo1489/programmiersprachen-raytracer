#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "box.cpp"
#include "sphere.cpp"
#include "shape.cpp"




TEST_CASE("Box default test", "[get]")
{
  Box box;
  REQUIRE(box.get_min().x == 0);
  REQUIRE(box.get_min().y == 0);
  REQUIRE(box.get_min().z == 0);
  REQUIRE(box.get_max().x == 1);
  REQUIRE(box.get_max().y == 1);
  REQUIRE(box.get_max().z == 1);
  REQUIRE(box.get_color().r == 0);
  REQUIRE(box.get_color().g == 0);
  REQUIRE(box.get_color().b == 0);
  REQUIRE(box.get_name() == "Box");
}

TEST_CASE("Box test", "[get]")
{
  Box box(glm::vec3{1.0,2.0,3.0},glm::vec3{4.0,5.0,6.0},Color{1.0,2.0,3.0},"Box_test");
  REQUIRE(box.get_min().x == 1.0);
  REQUIRE(box.get_min().y == 2.0);
  REQUIRE(box.get_min().z == 3.0);
  REQUIRE(box.get_max().x == 4.0);
  REQUIRE(box.get_max().y == 5.0);
  REQUIRE(box.get_max().z == 6.0);
  REQUIRE(box.get_color().r == 1.0);
  REQUIRE(box.get_color().g == 2.0);
  REQUIRE(box.get_color().b == 3.0);
  REQUIRE(box.get_name() == "Box_test");
}

TEST_CASE("Sphere default test", "[get]")
{
  Sphere sphere;
  REQUIRE(sphere.get_center().x == 0);
  REQUIRE(sphere.get_center().y == 0);
  REQUIRE(sphere.get_center().z == 0);
  REQUIRE(sphere.get_radius() == 1);
  REQUIRE(sphere.get_color().r == 0);
  REQUIRE(sphere.get_color().g == 0);
  REQUIRE(sphere.get_color().b == 0);
  REQUIRE(sphere.get_name() == "Sphere");
}

TEST_CASE("Sphere test", "[get]")
{
  Sphere sphere{glm::vec3{1.0,2.0,3.0},3.0,Color{1.0,3.0,1.0},"Sphere_test"};
  REQUIRE(sphere.get_center().x == 1.0);
  REQUIRE(sphere.get_center().y == 2.0);
  REQUIRE(sphere.get_center().z == 3.0);
  REQUIRE(sphere.get_radius() == 3.0);
  REQUIRE(sphere.get_color().r == 1.0);
  REQUIRE(sphere.get_color().g == 3.0);
  REQUIRE(sphere.get_color().b == 1.0);
  REQUIRE(sphere.get_name() == "Sphere_test");
}

TEST_CASE("box area", "[area]")
{
  Box box{glm::vec3{2.0,2.0,2.0}, glm::vec3{5.0,5.0,5.0}};
  REQUIRE(box.area() == 54.0);

}

TEST_CASE("box volume", "[volume]")
{
  Box box{glm::vec3{2.0,2.0,2.0}, glm::vec3{5.0,5.0,5.0}};
  REQUIRE(box.volume() == 27.0);
}

TEST_CASE("sphere area", "[area]")
{
  Sphere sphere{glm::vec3{1.0,2.0,3.0},5.0};
  REQUIRE(sphere.area() == Approx(314.159));
}

TEST_CASE("sphere volume", "[volume]")
{
  Sphere sphere{glm::vec3{1.0,2.0,3.0},5.0};
  REQUIRE(sphere.volume() == Approx(392.699));
}

TEST_CASE("box print", "[print]")
{
  Box box;
  box.print(std::cout);
  std::cout<<"\n";
}

TEST_CASE("sphere print", "[print]")
{
  Sphere sphere;
  sphere.print(std::cout);
  std::cout<<"\n";
}

TEST_CASE("intersectRAySphere", "[intersect]")
{
  Ray ray{glm::vec3{0.0},glm::vec3{1.0}};
  Sphere sphere{glm::vec3{5.0},1.0};

  REQUIRE(sphere.intersect(ray,0.0) == true);

  Ray ray2{glm::vec3{0.0}, glm::vec3{0.0}};

  
}

TEST_CASE("intersectRaySphere", "[intersect]")
{
  
	//Ray
	glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
	//ray direction has to be normalized !
	//you can use:
		//v = glm::normalize(some_vector);
	glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

	//Sphere
	glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
	float sphere_radius{1.0f};

	float distance{0.0f};
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius,
		distance);

	REQUIRE(distance == Approx(4.0f));

	Sphere s {sphere_center, sphere_radius, Color{0.0f,0.0f,0.0f}, "sphere"};

	Ray r {ray_origin,ray_direction};

	s.intersect(r,distance);

	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("destructor test", "[destructor]")
{

  Color red(250, 0, 0);
  glm::vec3 position(0,0,0);

  Sphere* s1 = new Sphere(position, 1.2, red, "sphere0");
  Shape* s2 = new Sphere(position, 1.2, red, "sphere1");

  s1->print(std::cout);
  s2->print(std::cout);

  delete s1;
  delete s2;
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
 