#include "Zuurstok.h"

using namespace std ;


Zuurstok::Zuurstok(float xPos,
                   float yPos,
                   float xSpeed,
                   float ySpeed) : BonusEntity("zuurstok", 30, 100) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

Zuurstok::Zuurstok(Position pos,
                   Speed speed) : Zuurstok(pos.x, pos.y, speed.x, speed.y) {}

Zuurstok::~Zuurstok() {}
