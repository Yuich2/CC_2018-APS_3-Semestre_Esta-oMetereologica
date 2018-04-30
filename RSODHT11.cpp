#include <iostream>

extern "C"
{
/*
The extern "C" is the code to recognise the DHT11 sensor. The "C" flag tell to the
g++ compiler that everything who there  between the brackets is writing in classic C 
programming language. Whith this c code had c headers to satisfy dependencies and libraries
very important to the sensor.
*/
	#include "unistd.h"
	#include "sys/types.h"
	#include "sys/stat.h"
	#include "fcntl.h"
	#include "poll.h"
	#include "time.h"
	#include "stdlib.h"
	#include "string.h"
	#include "stdio.h"
	#include "errno.h"
	#include "wiringPi.h"

	#define HELP \
		"\n \033[1mDHT11 by blog.everpi.net\n\n" \
		"\tUsage: [wiringpi_pin]\033[0m\n\n"

	unsigned int dht11_read(int pin)
	{
		int bits = 42;
		unsigned char data = 0;
		unsigned int dht11_data = 0;
		unsigned int parity = 0;
		int waithigh = 0;
		struct timespec ntime = {.tv_sec = 0, 
					 .tv_nsec = 1000L};

		unsigned int waitvalues[42] = {0};

			pinMode(pin, OUTPUT);
			digitalWrite(pin, LOW);
			delay(11);
			digitalWrite(pin, HIGH);
			pinMode(pin, INPUT);
		while(bits)
		{
			while(1)
			{
				data = digitalRead(pin);
				if(data == 1)
				{
					break;
				}
			}
			waithigh = 0;
			while(digitalRead(pin) == 1)
			{
				delayMicroseconds(1);
				waithigh++;
				if(waithigh > 5000)
				{
					break;
				}
			}
			waitvalues[bits] = waithigh;
			if(waithigh > 20)
			{
				data = 1;
			}
			else
			{
				data = 0;
			}
			if(bits <= 8)
			{
				parity = (parity<<1) | data;
			}
			else
			{
				dht11_data = ((dht11_data<<1) | data);
			}
			bits--;
		}
		if(parity == (((dht11_data&0xff00)>>8) + (dht11_data>>24)))
		{
			return dht11_data;
		}
		else
		{
			return 0;
		}
	}

	int main(int argc, char *argv[])
 	{
          unsigned int data = 0;
          if(argc < 2)
          {
                  printf("%s",HELP);
                  return 0;
          }
          if(wiringPiSetup()==-1)
          {
                  exit(1);
          }
	  while(!data)
          {
                data = dht11_read(strtol(argv[1],NULL,10));
          }
        	fprintf(stderr,"H:%u%\nTemp:uC°\n",data>>24, (data&0xff00)>>8);
        	return 0;
	}

}

