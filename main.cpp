#include<iostream>
#include<cmath>
#include<fstream>

int main() {
	//parametros globales
 const double PI = 3.14159265358979;
 const double G = 4 * std::pow(PI,2);
 const double time_step = 0.0027397260273972603;  //1 dia
 const int steps = 10 * 365;  //2 años
 
 //output file
 const char fileName[] = "orbit.csv";
 std::ofstream outputFile;
 
 //earth variables
 double earthR;
 double earthRx; 
 double earthRy;
 double earthVx;
 double earthVy;
 double earthAx;
 double earthAy;
 
 
 //Open file stream
 outputFile.open(fileName);
 
 //Earth initial conditions
 earthRx = -1;
 earthRy = 0;
 
 earthR = std::sqrt(std::pow(earthRx, 2) + std::pow(earthRy, 2));
 
 earthVx = 0;
 earthVy = 6.2783201069518713;
 
 earthAx = -1 * G * earthRx / std::pow(earthR,3);
 earthAy = -1 * G * earthRy / std::pow(earthR,3);
 
 //Earth motion
 for (int i = 0; i < steps; i++ ){
 	outputFile << earthRx <<", "
 	           << earthRy <<", " 
 	           << earthVx <<", " 
 	           << earthVy <<", " 
 	           << earthAx <<", " 
 	           << earthAy <<std::endl;
 	           
 	
 	earthRx = earthRx + (earthVx * time_step) + (0.5 * earthAx * std::pow(time_step,2));
 	earthRy = earthRy + (earthVy * time_step) + (0.5 * earthAy * std::pow(time_step,2));
 	
 	earthR = std::sqrt(std::pow(earthRx, 2) + std::pow(earthRy, 2) );
 	
 	earthVx = earthVx + (0.5 * earthAx * time_step);   //la velocidad en (T+daltaT)/2
 	earthVy = earthVy + (0.5 * earthAy * time_step); 
 	
 	earthAx = -1 * G * earthRx / std::pow(earthR,3);
    earthAy = -1 * G * earthRy / std::pow(earthR,3);
    
    earthVx = earthVx + (0.5 * earthAx * time_step); //correccion en T + deltasT
 	earthVy = earthVy + (0.5 * earthAy * time_step); 
   }
   
   outputFile.close();
   
   return 0;
 }
 

