#include "RedGift.h"

RedGift::RedGift(float xPos,
                 float yPos,
                 float xSpeed,
                 float ySpeed) : BonusEntity("red_gift", 40, 10) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

RedGift::RedGift(Position pos,
                 Speed speed) : BonusEntity("red_gift", 40, 10) {
    setPosition(pos.x, pos.y) ;
    setInitialSpeed(speed.x, speed.y) ;
}

RedGift::~RedGift() {}
