
#include "libraries/RainDrop.hpp"

RainDrop::RainDrop() {
}

RainDrop::RainDrop(const RainDrop& orig) {
}

RainDrop::~RainDrop() {
}

int RainDrop::readRain()
{
    
    gpioSetMode(RAINDROP, PI_INPUT);
    gpioSetPullUpDown(RAINDROP, PI_PUD_DOWN);
    return gpioRead(RAINDROP);

}

