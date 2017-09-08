#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


void print_sdf(int file_number, string name, float szene_number)
{
	szene_number= (szene_number*0.5);

	fstream f;
	f.open(name, ios::out);
	f << "# "<<file_number<<" , "<<name<<" , "<<szene_number<<endl;
	f << "# Materials"<<endl;
	f << "define material red .7 0 0 .4 .4 .4 0 0 0 1 "<<endl;
	f << "define material blue 0 0 .7 .4 .4 .4 0 0 0 1"<<endl;
	f << "define material green 0 .7 0 .5 .5 .5 .5 .5 .5 30 0"<<endl;
	f << "define material yellow .7 .7 0 .9 .9 .1 .8 .8 .8 50 0"<<endl;
	f << "define material grey .05 .05 .05 .7 .7 .7 .4 .4 .4 15 0"<<endl;
	f << "define material darkgrey 0.05 0.05 0.05 .2 .2 .2 .2 .2 .2 100 0"<<endl;
	f << "define material glass 0 0 0 0 0 0 .5 .5 .5 400 1"<<endl;
	f << "define material pinkglass .15 0 0 0.1 0 0 .5 .5 .5 400 1"<<endl;
	f << "define material turkis 0 .4 .4 .1 .4 .4 .2 .6 .6 8 0"<<endl;
	f << "define material phil .5 .5 .5 .7 .7 .7 0 0 0 0"<<endl;

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
f << "define shape sphere asphere 0 -22 -150 "<<(0.2*szene_number)<<" phil" << endl;
f << "define shape sphere bsphere -20 20 -200 30 phil" << endl;
f << "define shape sphere csphere 0 "<<-26+szene_number*0.5<<" "<<-200+szene_number<<" 10 phil" << endl;
f << "define shape sphere dsphere -20 "<<(-15-(0.5*szene_number))<<" -250 "<<szene_number<<" phil" << endl;
f << "# Composite" << endl;
f << "define shape composite checkerfield ";
for (int i = 1; i<(height_*width_+1); ++i){f << "checker"<<i<<" ";}
f << "asphere bsphere csphere dsphere"<<endl;
f << "# Lights" << endl;
f << "define light sun 50 100 0 .9 .9 .9 100"<<endl;
f << "define light ssun 50 100 -75 .1 .4 .7 800"<<endl;
f << "define light ssun2 20 20 -105 .1 .8 .1 500" << endl;
f << "define light ssun4 20 20 -150 .1 .8 .1 500" << endl;
f << "define light ssun3 -79 30 -105 .8 .8 0 100" << endl;
f << "# Abient" <<endl;
f << "ambient 0.2 0.2 0.2"<<endl;
f << "# Camera" << endl;
f << "define camera eye 45 -5 -5 "<<(50+(szene_number*-3))<<" 0 0 -1 0 1 0 "<<endl;
f << "# - and go" << endl;
f << "render eye ./image"<<(szene_number*2)<<".ppm 480 480" << endl;


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
	float i=130;										//Anzahl der zu erstellenden SDF-Dateien

	string file_name = "ray";		
	
	for (float y=0;y<i;++y)
	{
	string temp_name = concat(file_name, y);
	print_sdf(i, temp_name, y);
	
	}

}
	