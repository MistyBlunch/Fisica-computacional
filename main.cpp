#include<iostream>
#include<cmath>

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

int main() {
	//SFML settings
	const sf::Color Black(0, 0, 0, 255);
	const sf::Color GreyD4(33, 33, 33, 255);
    const sf::Color GreyL4(245, 245, 245, 255);
    const sf::Color Amber(255, 193, 7, 255);
    const sf::Color PinkA2(255, 64, 129, 255);
    const sf::Color Red(244,67,54);
    
    const float windowWidth = 800.f;
    const float windowHeight = 600.f;
    
    // Ajustes de antialising (para que no se vea pixeleado)
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;

    // Inicio de la ventana de la aplicación
    std::string programName = "Orbital Motion";

    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight, 32),
        programName,
        sf::Style::Titlebar | sf::Style::Close, settings
    );
    

    // Para "mejorar" la fecuencia de actualización de la pantalla
    window.setVerticalSyncEnabled(true);
    
	//parametros globales
	const double PI = 3.14159265358979;
 	const double G = 4 * std::pow(PI,2);
 	const double time_step = 0.0027397260273972603;  //1 dia
 	const int steps = 10 * 365;  // años
 
	//output file
	const char fileName[] = "orbit.csv";
	
	// Planet indexes
	int mercury = 0;
	int venus = 1;
	int earth = 2;
	int mars = 3;
	int jupyter = 4;
	int saturn = 5;
	int uranus = 6;
	int neptune = 7;
	int pluto = 8;
	
	// Orbital Parameters:
	double R[9];
	double Rx[9]; 
	double Ry[9];
	double Vx[9];
	double Vy[9];
	double Ax[9];
	double Ay[9];
	double X[9];
	double Y[9];
	int planeta[9];
	
	// Mercury
	Rx[mercury] = -0.387; 
	Ry[mercury] = 0;
	
	R[mercury] = std::sqrt(std::pow(Rx[mercury], 2) + std::pow(Ry[mercury], 2));  //como pitágoras ;
	
	Vx[mercury] = 0;
	Vy[mercury] = 10.09194640063934;
	
	Ax[mercury] = -1 * G * Rx[mercury] / std::pow(R[mercury],3);
	Ay[mercury] = -1 * G * Ry[mercury] / std::pow(R[mercury],3);
	
	// Venus
	Rx[venus] = -0.723; 
	Ry[venus] = 0;
	
	R[venus] = std::sqrt(std::pow(Rx[mercury], 2) + std::pow(Ry[mercury], 2));  //como pitágoras ;
	
	Vx[venus] = 0;
	Vy[venus] = 7.385896747252145;
	
	Ax[venus] = -1 * G * Rx[venus] / std::pow(R[venus],3);
	Ay[venus] = -1 * G * Ry[venus] / std::pow(R[venus],3);
	
	//Earth
	Rx[earth] = -1; 
	Ry[earth] = 0;
	
	R[earth] = std::sqrt(std::pow(Rx[mercury], 2) + std::pow(Ry[mercury], 2));  //como pitágoras ;
	
	Vx[earth] = 0;
	Vy[earth] = 6.2783201069518713;
	
	Ax[earth] = -1 * G * Rx[earth] / std::pow(R[earth],3);
	Ay[earth] = -1 * G * Ry[earth] / std::pow(R[earth],3);
	
	//Mars
	Rx[mars] = -1; 
	Ry[mars] = 0;
	
	R[mars] = std::sqrt(std::pow(Rx[mars], 2) + std::pow(Ry[mars], 2));  //como pitágoras ;
	
	Vx[mars] = 0;
	Vy[mars] = 5.088228800197652;
	
	Ax[mars] = -1 * G * Rx[mars] / std::pow(R[mars],3);
	Ay[mars] = -1 * G * Ry[mars] / std::pow(R[mars],3);
	
	//Jupyter
	Rx[jupyter] = -1; 
	Ry[jupyter] = 0;
	
	R[jupyter] = std::sqrt(std::pow(Rx[jupyter], 2) + std::pow(Ry[jupyter], 2));  //como pitágoras ;
	
	Vx[jupyter] = 0;
	Vy[jupyter] = 2.757434844921779;
	
	Ax[jupyter] = -1 * G * Rx[jupyter] / std::pow(R[jupyter],3);
	Ay[jupyter] = -1 * G * Ry[jupyter] / std::pow(R[jupyter],3);
	
	//Saturn
	Rx[saturn] = -1; 
	Ry[saturn] = 0;
	
	R[saturn] = std::sqrt(std::pow(Rx[saturn], 2) + std::pow(Ry[saturn], 2));  //como pitágoras ;
	
	Vx[saturn] = 0;
	Vy[saturn] = 2045.92397725461;
	
	Ax[saturn] = -1 * G * Rx[saturn] / std::pow(R[saturn],3);
	Ay[saturn] = -1 * G * Ry[saturn] / std::pow(R[saturn],3);
	
	//Uranus
	Rx[uranus] = -1; 
	Ry[uranus] = 0;
	
	R[uranus] = std::sqrt(std::pow(Rx[uranus], 2) + std::pow(Ry[uranus], 2));  //como pitágoras ;
	
	Vx[uranus] = 0;
	Vy[uranus] = 1440.369118632118;
	
	Ax[uranus] = -1 * G * Rx[uranus] / std::pow(R[uranus],3);
	Ay[uranus] = -1 * G * Ry[uranus] / std::pow(R[uranus],3);
	
	//Neptune
	Rx[neptune] = -1; 
	Ry[neptune] = 0;
	
	R[neptune] = std::sqrt(std::pow(Rx[neptune], 2) + std::pow(Ry[neptune], 2));  //como pitágoras ;
	
	Vx[neptune] = 0;
	Vy[neptune] = 1152.967903190608;
	
	Ax[neptune] = -1 * G * Rx[neptune] / std::pow(R[neptune],3);
	Ay[neptune] = -1 * G * Ry[neptune] / std::pow(R[neptune],3);
	
	//Pluto
	Rx[pluto] = -1; 
	Ry[pluto] = 0;
	
	R[pluto] = std::sqrt(std::pow(Rx[pluto], 2) + std::pow(Ry[pluto], 2));  //como pitágoras ;
	
	Vx[pluto] = 0;
	Vy[pluto] = 1000.381116504175;
	
	Ax[pluto] = -1 * G * Rx[pluto] / std::pow(R[pluto],3);
	Ay[pluto] = -1 * G * Ry[pluto] / std::pow(R[pluto],3);
	
	
	// SFML OBJECTS:
	// Sol
    sf::Texture sunTexture;
    if (!sunTexture.loadFromFile("sun.png")) {
        return EXIT_FAILURE;
    }
    sunTexture.setSmooth(true);
    sunTexture.setRepeated(false);
    
	float sunRadius = 30;
	sf::CircleShape sun(sunRadius);
    sun.setFillColor(Amber);
    sun.setOrigin(sunRadius, sunRadius);
    sun.setPosition(0.5 * windowWidth, 0.5 * windowHeight);
    sun.setTexture(&sunTexture);
    sun.setTextureRect(sf::IntRect(0, 0, sunRadius, sunRadius)); 
    
    // PLANETS
    
    float Radius[9];
    sf::Texture Textures[9];
	sf::CircleShape Shape[9]; //shape-->formas de los planetas
    
    
    for(int planet = 0; planet<9; planet++){
//    	std::cin >> planeta;
    	
    	switch(planet) {
    		
    		case 0:
				Radius[planet] = 10;
		    	if (!Textures[planet].loadFromFile("mercury.png")){
					return EXIT_FAILURE;
				}
				break;
			
			case 1:
				Radius[planet] = 15;
		    	if (!Textures[planet].loadFromFile("venus.png")){
					return EXIT_FAILURE;
				}
				break;
			
			case 2:
				Radius[planet] = 20;
		    	if (!Textures[planet].loadFromFile("tierra.png")){
					return EXIT_FAILURE;
				}
				break;
			
			case 3:
				Radius[planet] = 20;
		    	if (!Textures[planet].loadFromFile("marte.png")){
					return EXIT_FAILURE;
				}
				break;
				
			case 4:
				Radius[planet] = 25;
		    	if (!Textures[planet].loadFromFile("jupiter.png")){
					return EXIT_FAILURE;
				}
				break;
			
			case 5:
				Radius[planet] = 25;
		    	if (!Textures[planet].loadFromFile("saturno.png")){
					return EXIT_FAILURE;
				}
				break;		
			
			case 6:
				Radius[planet] = 30;
		    	if (!Textures[planet].loadFromFile("urano.png")){
					return EXIT_FAILURE;
				}
				break;
				
			case 7:
				Radius[planet] = 35;
		    	if (!Textures[planet].loadFromFile("neptuno.png")){
					return EXIT_FAILURE;
				}
				break;	
				
			case 8:
				Radius[planet] = 25;
		    	if (!Textures[planet].loadFromFile("pluton.png")){
					return EXIT_FAILURE;
				}
				break;		
			//complete
		}
    
	    Textures[planet].setSmooth(true);
	    Textures[planet].setRepeated(false);
	    
	    Shape[planet].setRadius(Radius[planet]);
	    Shape[planet].setFillColor(Amber);
	    Shape[planet].setOrigin(Radius[planet], Radius[planet]);
	    Shape[planet].setTexture(&Textures[planet]);
	    Shape[planet].setTextureRect(sf::IntRect(0, 0, Radius[planet], Radius[planet]));
	}
    
 	// Bucle principal de animación 
    while (window.isOpen()) {
        // Recivimos todos los eventos en el bucle de la animacion
        sf::Event event;

        while (window.pollEvent(event)) {
            // "Window closed" o "ESC": exit (salir)
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;
            }
		}
		
		window.clear(Black);
		window.draw(sun);
		
		for(int planet = 0; planet < 9; planet++){
			
			X[planet] = 200 * Rx[planet] + 0.5 * windowWidth;
			Y[planet] = -200 * Ry[planet] + 0.5 * windowHeight;
			
			Shape[planet].setPosition(X[planet], Y[planet]);  
			
			window.draw(Shape[planet]);
			
			// Calculations for the next step
			Rx[planet] = Rx[planet] + (Vx[planet] * time_step) + (0.5 * Ax[planet] * std::pow(time_step,2));
			Ry[planet] = Ry[planet] + (Vy[planet] * time_step) + (0.5 * Ay[planet] * std::pow(time_step,2));
						
			R[planet] = std::sqrt(std::pow(Rx[planet], 2) + std::pow(Ry[planet], 2) );
						
			Vx[planet] = Vx[planet] + (0.5 * Ax[planet] * time_step);   //la velocidad en (T+deltaT)/2
			Vy[planet] = Vy[planet] + (0.5 * Ay[planet] * time_step); 
						
			Ax[planet] = -1 * G * Rx[planet] / std::pow(R[planet], 3);
			Ay[planet] = -1 * G * Ry[planet] / std::pow(R[planet], 3);
			
			Vx[planet] = Vx[planet] + (0.5 * Ax[planet] * time_step); //correccion en T + deltasT
			Vy[planet] = Vy[planet] + (0.5 * Ay[planet] * time_step); 
		}
		
		window.display();  	 
   }
   
   return 0;
 }
 

