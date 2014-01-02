#include "BlueGift.h"

BlueGift::BlueGift(float xPos,
                   float yPos,
                   float xSpeed,
                   float ySpeed) : BonusEntity("blue_gift", 50, 35) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

BlueGift::BlueGift(Position pos,
                   Speed speed) : BlueGift(pos.x, pos.y, speed.x, speed.y) {}

BlueGift::~BlueGift() {}
