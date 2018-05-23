#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <wiringPi.h>
#include <pigpio.h>

#include "libraries/DHT11.hpp"
#include "libraries/XML.hpp"
#include "libraries/RainDrop.hpp"

using namespace std;

int main(int argc, char** argv) 
{

    //Setup
    string xmlTemp;
    char tmp;
    int celsius[11]= {0,0,0,0,0,0,0,0,0,0,0};
    float fahrenheit[11]= {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    float humidity[11]= {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    int rain[11] = {0,0,0,0,0,0,0,0,0,0,0};

    if (gpioInitialise() < 0)//checks if the library has initiated correctly
    {
            cout<< "Error" ;
            cin >> tmp; //just to read the error
            exit(1);
    }

    if(wiringPiSetup() == -1)
    {
            cout<< "Error" ;
            cin >> tmp; //just to read the error
            exit(1);
    }

    //Loop here
    while(1)
    {
            //array sorting by newest to oldest
            for(int cont=10; cont >= 1; cont--)
            {

                celsius[cont] = celsius[cont-1];
                fahrenheit[cont] = fahrenheit[cont-1];
                humidity[cont] = humidity[cont-1];
                rain[cont] = rain[cont-1];

            }
		
	
		//readings
            DHT11 dht;
	    new DHT11();	
            dht.readDHT11(&fahrenheit[0], &celsius[0], &humidity[0]);
            
            RainDrop raindrop;
	    new RainDrop();
            rain[0] = raindrop.readRain();

            //'data.xml'

            XML xml;
	    new XML();

	    xml.iniciarXML();//first line on xml file


            for(int i=0; i <=10; i++)
	    {

                  xml.gerarDadosXML( i, fahrenheit[i], celsius[i], humidity[i], rain[i]);//adds 1 group of info from the sensors	          
                       
            }	
	
            xmlTemp = xml.getXML(); //last line on xml file + return string

            //Saída de xmlTemp
            ofstream dataOut("data.xml");
            dataOut << xmlTemp;
            dataOut.close();

            //just to display on console, for control purpouses 
            if(rain[0])
                    cout << fahrenheit[0] << " Fº; " << celsius[0] << " Cº; " << humidity[0] << "% de Humidade, " << "Sem Chuva" << "\n";

            else
                    cout << fahrenheit[0] << " Fº; " << celsius[0] << " Cº; " << humidity[0] << "% de Humidade, " << "Com Chuva" << "\n";


            delay(60000);
    }
    gpioTerminate();
    return 0;
    
}

#endif /* MAIN_H */