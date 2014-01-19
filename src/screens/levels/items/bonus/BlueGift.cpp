#include "BlueGift.h"

BlueGift::BlueGift(float xPos,
                   float yPos,
                   float xSpeed,
                   float ySpeed) : BonusEntity("blue_gift", 50, 35) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

BlueGift::BlueGift(Position pos,
                   Speed speed) : BonusEntity("blue_gift", 50, 35) {
    setPosition(pos.x, pos.y) ;
    setInitialSpeed(speed.x, speed.y) ;
}

BlueGift::~BlueGift() {}
