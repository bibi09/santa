#include "SnowGlobe.h"
#include "../confetti/SnowFreeze.h"
#include "../../hud/Score.h"
#include "../../../../tools/managers/AudioManager.h"
#include "../../../../tools/managers/ConfettiManager.h"

/** @brief  Create a new BombGift with position and speed. */
SnowGlobe::SnowGlobe(float xPos,
                     float yPos,
                     float xSpeed,
                     float ySpeed) : MalusEntity("items/snow_globe", 20, -10) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
    m_angleStep = 0.f ;
}

/** @brief  Create a new SnowGlobe with position and speed. */
SnowGlobe::SnowGlobe(Position pos,
                     Speed speed) : SnowGlobe(pos.x, pos.y, speed.x, speed.y) {}

/** @brief  Destruction of a SnowGlobe. */
SnowGlobe::~SnowGlobe() {}



void SnowGlobe::additionnalStuffOnBreak() {
    // Play glass sound
    AudioManager::getInstance() -> playSound("snow_freeze") ;

    // Add a snow impact
    SnowFreeze* splash = new SnowFreeze() ;
    ConfettiManager::addConfetti(splash) ;
    Score::getInstance() -> reset() ;
}
