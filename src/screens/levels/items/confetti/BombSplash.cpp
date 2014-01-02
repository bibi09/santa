#include "BombSplash.h"

using namespace std ;


BombSplash::BombSplash() : ConfettiEntity("malus_effects/bomb_splash", 5, 2) {}

BombSplash::~BombSplash() {}


void BombSplash::update() {
    // No physics on this confetti!
    updateDisplay() ;
}


bool BombSplash::isAlive() {
    return m_alpha > 64 ;
}
