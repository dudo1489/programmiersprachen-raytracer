#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include "sdfloader.hpp"



Scene SDFloader::load(std::string const& file_to_read)
{
    std::ifstream file;
    std::string line;
    Scene loadedScene;


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
                }


                if(keyword == "shape")
                {
                    ss >> keyword;

                    if(keyword == "box")
                    {
                        //Box box;    //neue einzuordnende box erstellen
                        std::string boxname;    //boxname und Clr nich in box vorhanden daher separat speichern
                        std::string boxClrName;
                        glm::vec3 boxMin;
                        glm::vec3 boxMax;

                        ss >> boxname;
                        ss >> boxMin.x;
                        ss >> boxMin.y;
                        ss >> boxMin.z;
                        ss >> boxMax.x;
                        ss >> boxMax.y;
                        ss >> boxMax.z;
                        ss >> boxClrName;

                        Material boxMaterial = loadedScene.materials_.find(boxClrName) -> second; //boxmaterial mit einbeziehen um boxconstructor zu verwenden 
                                                                                                // -> second damit boxMaterial value der map annimmt ->first wuerde auf key zeigen
                        auto box = std::make_shared<Box>(boxMin, boxMax, boxMaterial, boxname);    //make_shared uebergibt argumente an constructor,
                                                                                                    //gibt objekt vom typ shared_ptr zurueck welches auf erstelltes objekt zeigt

                        loadedScene.shape_[boxname]=box;    //box in loadedScene speichern nach keyword boxname
                    }

                    if(keyword == "sphere")
                    {

                    }
                }
            }
        }
    }
}


/* int main()
{
	
	std::ifstream Colorsource;
	Colorsource.open("farben_zum_einlesen.txt", std::ios_base::in);

	if(!Colorsource)
	std::cerr << "didn´t found <farben_zum_einlesen.txt>\n";
	else{
		std::ofstream Materialliste("materiallist.cpp");
		if (!Materialliste)
			std::cerr  << "can not open <materiallist.cpp>\n";
		else{
			std::string line_to_read;

			while (std::getline (Colorsource, line_to_read))
			{ 
				
				Material new_material;
				std::map<std::string, Material> materials;

				std::stringstream ss;
				std::string not_used;


				ss << line_to_read;

				ss >> not_used;
				if (not_used == "define")
				{ 
					ss >> not_used;
					if(not_used == "material")
					{
					    	ss >> new_material.name_;
						ss >> new_material.ka_.r;
						  ss >> new_material.ka_.g;
						ss >> new_material.ka_.b;
						ss >> new_material.kd_.r;
						ss >> new_material.kd_.g;
						ss >> new_material.kd_.b;
						ss >> new_material.ks_.r;
						ss >> new_material.ks_.g;  
						ss >> new_material.ks_.b;    
						ss >> new_material.m_;
						materials[new_material.name_] = new_material;
						std::cout << new_material << std::endl;
					}
				}
			}
			
		}

	}
 	
	return 0;
}
  */


//  Material testmat(std::string {"testmaterial"}, Color{0.5f,1.0f,0.5f}, Color{0.8f,0.8f,0.4f}, Color{0.8f,0.9f,0.6f}, 0.6f);