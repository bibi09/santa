#include "SpecialGift.h"

SpecialGift::SpecialGift(float xPos,
                         float yPos,
                         float xSpeed,
                         float ySpeed) : BonusEntity("special_gift",
                                                     100,
                                                      1) {
    m_soundPlayed = "golden_bonus" ;
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

SpecialGift::SpecialGift(Position pos,
                         Speed speed) : SpecialGift(pos.x,
                                                    pos.y,
                                                    speed.x,
                                                    speed.y) {}

SpecialGift::~SpecialGift() {}
