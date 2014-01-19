#include "Gnome.h"
#include "../../../../tools/managers/AudioManager.h"


Gnome::Gnome(float xPos,
             float yPos,
             float xSpeed,
             float ySpeed) : MalusEntity("items/gnome", 5, -100) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
    setCuttedSprite("items/cutted/gnome_cutted") ;
    makeDisappearOnBreak(false) ;
}

Gnome::Gnome(Position pos,
             Speed speed) : MalusEntity("items/gnome", 5, -100) {
    setPosition(pos.x, pos.y) ;
    setInitialSpeed(speed.x, speed.y) ;
    setCuttedSprite("items/cutted/gnome_cutted") ;
    makeDisappearOnBreak(false) ;
}

Gnome::~Gnome() {}


void Gnome::additionnalStuffOnBreak() {
    // Play pain sound
    AudioManager::getInstance() -> playSound("gnome_hurt") ;
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
