#include "SnowFreeze.h"

SnowFreeze::SnowFreeze() : ConfettiEntity("malus_effects/snow_freeze", 4, 1) {}

SnowFreeze::~SnowFreeze() {}


void SnowFreeze::update() {
    // No physics on this confetti!
    updateDisplay() ;
}


bool SnowFreeze::isAlive() {
    return m_alpha > 64 ;
}
