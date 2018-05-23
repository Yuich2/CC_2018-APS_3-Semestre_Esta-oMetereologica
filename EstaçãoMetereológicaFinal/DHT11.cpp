
#include "libraries/DHT11.hpp"

DHT11::DHT11() {
}

DHT11::DHT11(const DHT11& orig) {
}

DHT11::~DHT11() {
}

void DHT11::readDHT11(float *fahrenheit, int *celsius, float *humidity)
{

    int dht11_dat[5] = { 0, 0, 0, 0, 0 };

    uint8_t  laststate = HIGH;
    uint8_t counter	= 0;
    uint8_t  j = 0, i;
    float f; 

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    pinMode( DHTPIN, OUTPUT );
    digitalWrite( DHTPIN, LOW );
    delay( 18 );
    digitalWrite( DHTPIN, HIGH );
    delayMicroseconds( 40 );
    pinMode( DHTPIN, INPUT );

    for ( i = 0; i < MAXTIMINGS; i++ )
    {
            counter = 0;
            while ( digitalRead( DHTPIN ) == laststate )
            {
                    counter++;
                    delayMicroseconds( 2 );
                    if ( counter == 255 )
                    {
                            break;
                    }
            }
            laststate = digitalRead( DHTPIN );

            if ( counter == 255 )
                    break;

            if ( (i >= 4) && (i % 2 == 0) )
            {
                    dht11_dat[j / 8] <<= 1;
                    if ( counter > 16 )
                            dht11_dat[j / 8] |= 1;
                    j++;
            }
    }

    if ( (j >= 40) &&
         (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
    {
            f = dht11_dat[2] * 9. / 5. + 32;

            *fahrenheit = f;
            *celsius = dht11_dat[2];
            *humidity = dht11_dat[0];			
    }else  {
            std::cout<<"Data not good, skip\n";
    }
}



