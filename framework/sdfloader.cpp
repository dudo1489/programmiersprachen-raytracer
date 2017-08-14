#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "sdfloader.hpp"




Scene load(std::string const& file_to_read)
{
    std::ifstream file;
    std::string line;
    Scene loadedScene;
    std::map<std::string, std::shared_ptr<Shape>> shape_ptr;
    
    file.open(file_to_read);    //open file

    if(!file.is_open())
    {
        std::cout<<"could not open file";
    }
    else
    {
        while (std::getline(file, line))    //jede Zeile der datei durchgehen
        {
            std::stringstream ss;
            std::string keyword;

            ss << line; //string stream ss wird zur zeile
            ss >> keyword;  //ss springt zum ersten wort


            if(keyword == "define")
            {
                ss >> keyword;

                if(keyword == "material")
                {
                    Material material;  //material zwischenspeichern

                    ss >> material.name_;    //name, rgb farbwerte werden zu material member
                    ss >> material.ka_.r;
                    ss >> material.ka_.g;
                    ss >> material.ka_.b;
                    ss >> material.kd_.r;
                    ss >> material.kd_.g;
                    ss >> material.kd_.b;
                    ss >> material.ks_.r;
                    ss >> material.ks_.g;
                    ss >> material.ks_.b;
                    ss >> material.m_;

                    loadedScene.materials_[material.name_]=material;    //material in scene ueberschreiben
                                                                        //wird nach keyword in die map materials_ eingeordnet
                    std::cout << "added material: " << material.name_ << "\n";
                }


                if(keyword == "shape")
                {
                    ss >> keyword;

                    if(keyword == "box")
                    {
                        //Box box;    //neue einzuordnende box erstellen
                        std::string boxName;    //boxname und Clr nich in box vorhanden daher separat speichern
                        std::string boxClrName;
                        glm::vec3 boxMin;
                        glm::vec3 boxMax;

                        ss >> boxName;
                        ss >> boxMin.x;
                        ss >> boxMin.y;
                        ss >> boxMin.z;
                        ss >> boxMax.x;
                        ss >> boxMax.y;
                        ss >> boxMax.z;
                        ss >> boxClrName;

                        Material boxMaterial = loadedScene.materials_.find(boxClrName) -> second; //boxmaterial mit einbeziehen um boxconstructor zu verwenden 
                                                                                                // -> second damit boxMaterial value der map annimmt ->first wuerde auf key zeigen
                        auto box = std::make_shared<Box>(boxMin, boxMax, boxMaterial, boxName);    //make_shared uebergibt argumente an constructor,
                                                                                                    //gibt objekt vom typ shared_ptr zurueck welches auf erstelltes objekt zeigt

                        shape_ptr[boxName]=box;    //box in map fuer shape zeiger speichern nach keyword boxname

                        std::cout << "added shape box: " << boxName << "\n";
                    }

                    if(keyword == "sphere")
                    {
                        
                        std::string sphereName;
                        std::string sphereColor;
                        glm::vec3 center;
                        float radius;

                        ss >> sphereName;
                        ss >> center.x;
                        ss >> center.y;
                        ss >> center.z;
                        ss >> radius;
                        ss >> sphereColor;


                        Material sphereMaterial = loadedScene.materials_.find(sphereColor) -> second; //wie bei box
                        auto sphere = std::make_shared<Sphere>(center, radius, sphereMaterial, sphereName);
                        
                        shape_ptr[sphereName]=sphere;

                        std::cout << "added shape sphere: " << sphereName << "\n";
                    }


                    if(keyword == "composite")
                    {
                        std::string compositeName;
                        std::string shapeName;

                        ss >> compositeName;   
                        loadedScene.composite_ = std::make_shared<Composite>(compositeName);    //erstelle zeiger auf composite
                       
                        while(!ss.eof())    //while ss not at end of file 
                        {
                        ss >> shapeName;
                        auto shape_to_insert = shape_ptr.find(shapeName);

                            if(shape_to_insert != shape_ptr.end())
                            {
                            loadedScene.composite_ -> add_shape(shape_to_insert -> second);
                            std::cout << "added composite: " << compositeName << "\n"; 
                            
                            }
                        } 

                    }
                }

                if(keyword == "light")
                    {
                        std::string lightName;
                        glm::vec3 point;
                        Color color;
                        float brightness;

                        ss >> lightName;
                        ss >> point.x;
                        ss >> point.y;
                        ss >> point.z;
                        ss >> color.r;
                        ss >> color.g;
                        ss >> color.b;
                        ss >> brightness;

                        auto light = std::make_shared<Light>(lightName, point, color, brightness);

                        loadedScene.light_[lightName]=light;
                    }
    
                 if(keyword == "camera")
                    {
                        std::string cameraName;
                        glm::vec3 position;
                        float fov_x;

                        ss >> cameraName;

                        ss >> position.x;
                        ss >> position.y;
                        ss >> position.z;

                        ss >> fov_x;

                        auto camera = std::make_shared<Camera>(cameraName, position, fov_x);    

                        loadedScene.camera_[cameraName]=camera;
                    } 

            }
        }
    }

    return loadedScene;

}
