===================================================================================================================

	to compile on your Raspberry Pi:

	g++ -v ./main.cpp ./DHT11.cpp ./RainDrop.cpp ./XML.cpp -o ./Program -lwiringPi -lpigpio -lpthread


	The program reads the dht11 sensor and a raindrop sensor and writes it in a .xml file. 
	This version stores the last 11 reads of both sensors. 

===================================================================================================================

	Made by Shimoda, Oliveira and Queiroz.

===================================================================================================================