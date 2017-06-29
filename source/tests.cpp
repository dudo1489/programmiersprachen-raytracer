#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "box.cpp"
#include "sphere.cpp"
#include "shape.cpp"
#include "material.cpp"





TEST_CASE("Box default test", "[get]")
{

  Box box;
  REQUIRE(box.get_min().x == 0);
  REQUIRE(box.get_min().y == 0);
  REQUIRE(box.get_min().z == 0);
  REQUIRE(box.get_max().x == 1);
  REQUIRE(box.get_max().y == 1);
  REQUIRE(box.get_max().z == 1);
  REQUIRE(box.get_material().name_ == "new_Material");
  Color testcolor1(0.0f,0.0f,0.0f);
  Color ka_test(0.0f,0.1f,0.2f);  
  Color kd_test(0.6f,0.7f,0.8f);
  Color ks_test(0.3f,0.4f,0.5f);
  testcolor1 = box.get_material().ka_;
  REQUIRE(ka_test.r == testcolor1.r);
  REQUIRE(ka_test.g == testcolor1.g);
  REQUIRE(ka_test.b == testcolor1.b);  
  testcolor1 = box.get_material().kd_;
  REQUIRE(kd_test.r == testcolor1.r);
  REQUIRE(kd_test.g == testcolor1.g);
  REQUIRE(kd_test.b == testcolor1.b);
  testcolor1 = box.get_material().ks_;
  REQUIRE(ks_test.r == testcolor1.r);
  REQUIRE(ks_test.g == testcolor1.g);
  REQUIRE(ks_test.b == testcolor1.b);
  REQUIRE(box.get_name() == "Box");
}

TEST_CASE("Box test", "[get]")
{

  Box box(glm::vec3{1.0,2.0,3.0},glm::vec3{4.0,5.0,6.0},Material{},"Box_test");
  REQUIRE(box.get_min().x == 1.0);
  REQUIRE(box.get_min().y == 2.0);
  REQUIRE(box.get_min().z == 3.0);
  REQUIRE(box.get_max().x == 4.0);
  REQUIRE(box.get_max().y == 5.0);
  REQUIRE(box.get_max().z == 6.0);

  REQUIRE(box.get_material().name_ == "new_Material");
  Color testcolor(0.0,0.0,0.0);
  Color ka_test(0.0,0.1,0.2);  
  Color ks_test(0.3,0.4,0.5);
  Color kd_test(0.6,0.7,0.8);
  testcolor = box.get_material().ka_;
  REQUIRE(ka_test.r == testcolor.r);
  REQUIRE(ka_test.g == testcolor.g);
  REQUIRE(ka_test.b == testcolor.b);  
  testcolor = box.get_material().ks_;
  REQUIRE(ks_test.r == testcolor.r);
  REQUIRE(ks_test.g == testcolor.g);
  REQUIRE(ks_test.b == testcolor.b);
  testcolor = box.get_material().kd_;
  REQUIRE(kd_test.r == testcolor.r);
  REQUIRE(kd_test.g == testcolor.g);
  REQUIRE(kd_test.b == testcolor.b);
  float m_test = box.get_material().m_;
  REQUIRE(m_test == 0.9f);

  REQUIRE(box.get_name() == "Box_test");
}
TEST_CASE("Box test2", "[get_usermat]")
{
  Material testmat(std::string {"testmaterial"}, Color{0.5f,1.0f,0.5f}, Color{0.8f,0.8f,0.4f}, Color{0.8f,0.9f,0.6f}, 0.6f);

  Box box(glm::vec3{1.0,2.0,3.0},glm::vec3{4.0,5.0,6.0},Material{testmat},"Box_test2");
  REQUIRE(box.get_min().x == 1.0);
  REQUIRE(box.get_min().y == 2.0);
  REQUIRE(box.get_min().z == 3.0);
  REQUIRE(box.get_max().x == 4.0);
  REQUIRE(box.get_max().y == 5.0);
  REQUIRE(box.get_max().z == 6.0);

  REQUIRE(box.get_material().name_ == "testmaterial");
  Color testcolor1(0.0f,0.0f,0.0f);
  Color ka_test(0.5f,1.0f,0.5f);  
  Color kd_test(0.8f,0.8f,0.4f);
  Color ks_test(0.8f,0.9f,0.6f);
  testcolor1 = box.get_material().ka_;
  REQUIRE(ka_test.r == testcolor1.r);
  REQUIRE(ka_test.g == testcolor1.g);
  REQUIRE(ka_test.b == testcolor1.b);  
  testcolor1 = box.get_material().kd_;
  REQUIRE(kd_test.r == testcolor1.r);
  REQUIRE(kd_test.g == testcolor1.g);
  REQUIRE(kd_test.b == testcolor1.b);
  testcolor1 = box.get_material().ks_;
  REQUIRE(ks_test.r == testcolor1.r);
  REQUIRE(ks_test.g == testcolor1.g);
  REQUIRE(ks_test.b == testcolor1.b);


  REQUIRE(box.get_name() == "Box_test2");
}

TEST_CASE("Sphere default test", "[get]")
{
  Sphere sphere;
  REQUIRE(sphere.get_center().x == 0);
  REQUIRE(sphere.get_center().y == 0);
  REQUIRE(sphere.get_center().z == 0);
  REQUIRE(sphere.get_radius() == 1);

  REQUIRE(sphere.get_material().name_ == "new_Material");
  Color testcolor(0.0,0.0,0.0);
  Color ka_test(0.0,0.1,0.2);  
  Color ks_test(0.3,0.4,0.5);
  Color kd_test(0.6,0.7,0.8);
  testcolor = sphere.get_material().ka_;
  REQUIRE(ka_test.r == testcolor.r);
  REQUIRE(ka_test.g == testcolor.g);
  REQUIRE(ka_test.b == testcolor.b);  
  testcolor = sphere.get_material().ks_;
  REQUIRE(ks_test.r == testcolor.r);
  REQUIRE(ks_test.g == testcolor.g);
  REQUIRE(ks_test.b == testcolor.b);
  testcolor = sphere.get_material().kd_;
  REQUIRE(kd_test.r == testcolor.r);
  REQUIRE(kd_test.g == testcolor.g);
  REQUIRE(kd_test.b == testcolor.b);
  float m_test = sphere.get_material().m_;

  REQUIRE(m_test == 0.9f);
  REQUIRE(sphere.get_name() == "Sphere");
}

TEST_CASE("Sphere test", "[get]")
{
  Sphere sphere{glm::vec3{1.0,2.0,3.0},3.0,Material{},"Sphere_test"};
  REQUIRE(sphere.get_center().x == 1.0);
  REQUIRE(sphere.get_center().y == 2.0);
  REQUIRE(sphere.get_center().z == 3.0);
  REQUIRE(sphere.get_radius() == 3.0);
  REQUIRE(sphere.get_material().name_ == "new_Material");
  Color testcolor(0.0,0.0,0.0);
  Color ka_test(0.0,0.1,0.2);  
  Color ks_test(0.3,0.4,0.5);
  Color kd_test(0.6,0.7,0.8);
  testcolor = sphere.get_material().ka_;
  REQUIRE(ka_test.r == testcolor.r);
  REQUIRE(ka_test.g == testcolor.g);
  REQUIRE(ka_test.b == testcolor.b);  
  testcolor = sphere.get_material().ks_;
  REQUIRE(ks_test.r == testcolor.r);
  REQUIRE(ks_test.g == testcolor.g);
  REQUIRE(ks_test.b == testcolor.b);
  testcolor = sphere.get_material().kd_;
  REQUIRE(kd_test.r == testcolor.r);
  REQUIRE(kd_test.g == testcolor.g);
  REQUIRE(kd_test.b == testcolor.b);
  float m_test = sphere.get_material().m_;
  REQUIRE(m_test == 0.9f);
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
  Material testmat(std::string {"testmaterial"}, Color{0.5f,1.0f,0.5f}, Color{0.6f,0.9f,0.6f}, Color{0.7f,0.8f,0.4f}, 0.6f);

	Sphere s {sphere_center, sphere_radius, Material{testmat}, "sphere"};

	Ray r {ray_origin,ray_direction};

	s.intersect(r,distance);

	REQUIRE(distance == Approx(4.0f));
}


TEST_CASE("destructor test", "[destructor]")
{
  Material testmat(std::string {"testmaterial"}, Color{0.5f,1.0f,0.5f}, Color{0.6f,0.9f,0.6f}, Color{0.7f,0.8f,0.4f}, 0.6f);

  std::cout<<"Aufgabe 5.8"<<"\n";
  Color red(250, 0, 0);
  glm::vec3 position(0,0,0);

  Sphere* s1 = new Sphere(position, 1.2, testmat, "sphere0");
  Shape* s2 = new Sphere(position, 1.2, testmat, "sphere1");

  s1->print(std::cout);
  s2->print(std::cout);

  delete s1;
  delete s2;
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
 