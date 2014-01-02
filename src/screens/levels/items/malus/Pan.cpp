#include "Pan.h"
#include "../../../../tools/managers/AudioManager.h"

Pan::Pan(float xPos,
         float yPos,
         float xSpeed,
         float ySpeed) : MalusEntity("items/pan", 10, -5) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
    setCuttedSprite("items/cutted/pan_cutted") ;
    makeDisappearOnBreak(false) ;
}

Pan::Pan(Position pos,
         Speed speed) : Pan(pos.x, pos.y, speed.x, speed.y) {}

Pan::~Pan() {}


void Pan::additionnalStuffOnBreak() {
    // Play pain sound
    AudioManager::getInstance() -> playSound("pan_cut") ;
    m_angleStep = Math::toRadian((rand() % 6) + 2) ;

    if (rand() % 2 == 0)
        m_angleStep = -m_angleStep ;

    Speed newSpeed ;
    newSpeed.x = rand() % 6 ;
    newSpeed.y = rand() % 5 ;
    if (rand() % 2 == 0)    newSpeed.x = -newSpeed.x ;
    if (rand() % 2 == 0)    newSpeed.y = -newSpeed.y ;
    setInitialSpeed(newSpeed.x, newSpeed.y) ;
}
