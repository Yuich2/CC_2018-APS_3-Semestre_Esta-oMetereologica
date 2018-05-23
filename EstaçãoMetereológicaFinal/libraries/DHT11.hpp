
#ifndef DHT11_H
#define DHT11_H

#include <wiringPi.h>
#include <cstdint>
#include <iostream>

#define MAXTIMINGS	85
#define DHTPIN		7

class DHT11{
public:
    DHT11();
    DHT11(const DHT11& orig);
    virtual ~DHT11();
    void readDHT11(float *fahrenheit, int *celsius, float *humidity);
    int readRain();
private:

};

#endif /* DHT11_H */

