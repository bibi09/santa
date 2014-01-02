#include "OrangeGift.h"

OrangeGift::OrangeGift(float xPos,
                       float yPos,
                       float xSpeed,
                       float ySpeed) : BonusEntity("orange_gift", 100, 65) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

OrangeGift::OrangeGift(Position pos,
                   Speed speed) : OrangeGift(pos.x, pos.y, speed.x, speed.y) {}

OrangeGift::~OrangeGift() {}
