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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
