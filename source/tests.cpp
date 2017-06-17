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

TEST_CASE("Sphere default test", "[get]")
{
  Sphere sphere;
  REQUIRE(sphere.get_center().x == 0);
  REQUIRE(sphere.get_center().y == 0);
  REQUIRE(sphere.get_center().z == 0);
  REQUIRE(sphere.get_radius() == 1);
  REQUIRE(sphere.get_color().r == 0);
  REQUIRE(sphere.get_color().b == 0);
  REQUIRE(sphere.get_color().b == 0);
  REQUIRE(sphere.get_name() == "Sphere");
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
