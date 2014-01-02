#include "AngryGnome.h"
#include "../../../../tools/managers/AudioManager.h"


AngryGnome::AngryGnome(float xPos,
                       float yPos,
                       float xSpeed,
                       float ySpeed) : MalusEntity("items/angry_gnome", 5, -1) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
    setCuttedSprite("items/cutted/angry_gnome_cutted") ;
    makeDisappearOnBreak(false) ;
}

AngryGnome::AngryGnome(Position pos,
                       Speed speed) : AngryGnome(pos.x, pos.y,
                                                 speed.x, speed.y) {}

AngryGnome::~AngryGnome() {}


void AngryGnome::additionnalStuffOnBreak() {
    // Play pain sound
    AudioManager::getInstance() -> playSound("gnome_laugh") ;
    m_angleStep = Math::toRadian((rand() % 6) + 2) ;

    if (rand() % 2 == 0)
        m_angleStep = -m_angleStep ;

    Speed newSpeed ;
    newSpeed.x = rand() % 4 ;
    newSpeed.y = rand() % 3 ;
    if (rand() % 2 == 0)    newSpeed.x = -newSpeed.x ;
    if (rand() % 2 == 0)    newSpeed.y = -newSpeed.y ;
    setInitialSpeed(newSpeed.x, newSpeed.y) ;
}
