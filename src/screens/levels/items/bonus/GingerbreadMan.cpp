#include "GingerbreadMan.h"

GingerbreadMan::GingerbreadMan(float xPos,
                               float yPos,
                               float xSpeed,
                               float ySpeed) : BonusEntity("gingerbread_man",
                                                           100,
                                                           1) {
    m_soundPlayed = "golden_bonus" ;
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
}

GingerbreadMan::GingerbreadMan(Position pos,
                               Speed speed) : BonusEntity("gingerbread_man",
                                                           100,
                                                           1) {
    m_soundPlayed = "golden_bonus" ;
    setPosition(pos.x, pos.y) ;
    setInitialSpeed(speed.x, speed.y) ;
}

GingerbreadMan::~GingerbreadMan() {}
