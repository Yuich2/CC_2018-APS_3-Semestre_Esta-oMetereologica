
#ifndef RAINDROP_H
#define RAINDROP_H

#include <pigpio.h>

#define RAINDROP 24

class RainDrop {
public:
    RainDrop();
    RainDrop(const RainDrop& orig);
    virtual ~RainDrop();
    int readRain();
private:

};

#endif /* RAINDROP_H */

