#include "OrangeGift.h"

OrangeGift::OrangeGift(float xPos,
                       float yPos,
                       float xSpeed,
                       float ySpeed) : BonusEntity("orange_gift", 100, 65) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

OrangeGift::OrangeGift(Position pos,
                       Speed speed) : BonusEntity("orange_gift", 100, 65) {
    setPosition(pos.x, pos.y) ;
    setInitialSpeed(speed.x, speed.y) ;
}

OrangeGift::~OrangeGift() {}
