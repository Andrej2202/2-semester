#include "additionalInfo.hpp"

class ShotResult { 
    Undershoot, 
    Hit, 
    Overshoot 
};

template<std::integral T>
int accuratFire(T velocity, T angle, T neededDistance, T gravity){
    return std::abs(((velocity * velocity * sin(2.0 * angle)) / gravity) - neededDistance) < 1;
}