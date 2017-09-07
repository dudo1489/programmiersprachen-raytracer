#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


void print_sdf(int file_number, string name, int szene_number)
{
	fstream f;
	f.open(name, ios::out);
	f << "# "<<file_number<<" , "<<name<<" , "<<szene_number<<endl;
	f << "# Materials"<<endl;
	f << "define material red .7 0 0 .5 .5 .5 .5 .5 .5 30 0"<<endl;
	f << "define material blue 0 0 .7 .5 .5 .5 .5 .5 .5 30 0"<<endl;
	f << "define material green 0 .7 0 .5 .5 .5 .5 .5 .5 30 0"<<endl;
	f << "define material yellow .7 .7 0 .9 .9 .1 .8 .8 .8 50 0"<<endl;
	f << "define material grey .05 .05 .05 .7 .7 .7 .4 .4 .4 15 0"<<endl;
	f << "define material darkgrey 0.05 0.05 0.05 .2 .2 .2 .2 .2 .2 100 0"<<endl;
	f << "define material glass 0 0 0 0 0 0 .5 .5 .5 400 1"<<endl;
	f << "define material pinkglass .15 0 0 0.1 0 0 .5 .5 .5 400 1"<<endl;
	f << "define material turkis 0 .4 .4 .1 .4 .4 .2 .6 .6 8 0"<<endl;
	

	f << "# Shape Objects"<<endl;
	int counter = 0;
	int height_ = 10;
	int width_ = 10;

	int min_X = -100;
	int min_Y = -100;
	int min_Z = -100;

	int max_X = -90;
	int max_Y = -90; 
	int max_Z = -90;

	int boxsize = 1;

  for (unsigned y = 0; y < height_; ++y) 
  {
  	int min_Y_temp = min_Y;
  	int max_Y_temp = max_Y; 

    for (unsigned x = 0; x < width_; ++x) 
    {

    	++counter;


	    if ( ((x/boxsize)%2) != ((y/boxsize)%2)) 
	    {
	          f << "define shape box checker"<< counter <<"    "<<min_X<<" "<<min_Y_temp<<" "<<min_Z<<"      "<<max_X<<" "<<max_Y_temp<<" "<<max_Z<<"      blue" << endl;
	    } 

	    else 
	    {
	          f << "define shape box checker"<< counter <<"    "<<min_X<<" "<<min_Y_temp<<" "<<min_Z<<"      "<<max_X<<" "<<max_Y_temp<<" "<<max_Z<<"      red" << endl;
		}
		min_Y_temp= min_Y_temp+20;
		max_Y_temp = max_Y_temp+20;
  
    }
    min_X = min_X+20;
    max_X = max_X+20;
  }
f << "# Composite" << endl;
f << "define shape composite checkerfield ";
for (int i = 1; i<(height_*width_+1); ++i){f << "checker"<<i<<" ";}
f <<endl;
f << "# Lights" << endl;
f << "define light sun 50 100 0 .9 .9 .9 100"<<endl;
f << "# Camera" << endl;
f << "define camera eye 90 0 100 0 0 0 -1 0 1 0 "<<endl;
f << "# - and go" << endl;
f << "render eye ./image"<<szene_number<<".ppm 480 320" << endl;


  f.close();

  return;
}

string concat(const string &s, int number)
{
    ostringstream result;
    result << number<< s<<".sdf";
    return result.str();
}


int main()
{
	int i=20;										//Anzahl der zu erstellenden SDF-Dateien

	string file_name = "ray";		
	
	for (int y=0;y<i;++y)
	{
	string temp_name = concat(file_name, y);
	print_sdf(i, temp_name, y);
	
	}

}
	