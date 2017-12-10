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
 	const int steps = 10 * 365;  //2 años
 
	//output file
	const char fileName[] = "orbit.csv";
	
	//earth variables
	double earthR;
	double earthRx; 
	double earthRy;
	double earthVx;
	double earthVy;
	double earthAx;
	double earthAy;
	double posX;
	double posY;
	
	//Earth initial conditions
	earthRx = -1;
	earthRy = 0;
	
	
	earthR = std::sqrt(std::pow(earthRx, 2) + std::pow(earthRy, 2));
	
	earthVx = 0;
	earthVy = 6.2783201069518713;
	
	earthAx = -1 * G * earthRx / std::pow(earthR,3);
	earthAy = -1 * G * earthRy / std::pow(earthR,3);
	
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
    
    
    // Tierra:
    sf::Texture earthTexture;
    if (!earthTexture.loadFromFile("planet.png")) {
        return EXIT_FAILURE;
    }
    earthTexture.setSmooth(true);
    earthTexture.setRepeated(false);
    
    float earthRadius = 15;
    sf::CircleShape earth(earthRadius);
    earth.setFillColor(Red);
    earth.setOrigin(earthRadius, earthRadius);
    earth.setTexture(&earthTexture);
    earth.setTextureRect(sf::IntRect(0, 0, earthRadius, earthRadius)); 
 
 
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
		
		posX = 200 * earthRx + 0.5 * windowWidth;
		posY = -200 * earthRy + 0.5 * windowHeight;
		earth.setPosition(posX, posY);
		
		window.clear(Black);
		window.draw(sun);
		window.draw(earth);
		window.display();
		


	 	std::cout  << posX << ", "
	 	   		   << posY << ", "
		 		   << earthRx << ", "
	 	           << earthRy << ", " 
	 	           << earthVx << ", " 
	 	           << earthVy << ", " 
	 	           << earthAx << ", " 
	 	           << earthAy << std::endl;

	 	earthRx = earthRx + (earthVx * time_step) + (0.5 * earthAx * std::pow(time_step,2));
	 	earthRy = earthRy + (earthVy * time_step) + (0.5 * earthAy * std::pow(time_step,2));
	 	
	 	posX = 200 * earthRx + 400;
	 	posY = -200 * earthRy + 300;
	 	
	 	earthR = std::sqrt(std::pow(earthRx, 2) + std::pow(earthRy, 2) );
	 	
	 	earthVx = earthVx + (0.5 * earthAx * time_step);   //la velocidad en (T+daltaT)/2
	 	earthVy = earthVy + (0.5 * earthAy * time_step); 
	 	
	 	earthAx = -1 * G * earthRx / std::pow(earthR,3);
	    earthAy = -1 * G * earthRy / std::pow(earthR,3);
	    
	    earthVx = earthVx + (0.5 * earthAx * time_step); //correccion en T + deltasT
	 	earthVy = earthVy + (0.5 * earthAy * time_step);  	 
   }
   
   return 0;
 }
 

