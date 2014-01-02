#include "BombGift.h"
#include "../confetti/BombSplash.h"
#include "../../Level.h"
#include "../../../../tools/managers/AudioManager.h"
#include "../../../../tools/managers/ConfettiManager.h"
#include "../../../../tools/managers/ScreenManager.h"
#include "../../../../tools/geometry/Position.h"

using namespace std ;


/** @brief  Create a new BombGift with position and speed. */
BombGift::BombGift(float xPos,
                   float yPos,
                   float xSpeed,
                   float ySpeed) : MalusEntity("items/bomb_gift", 40, -50) {
    setPosition(xPos, yPos) ;
    setInitialSpeed(xSpeed, ySpeed) ;
    m_angleStep = 0.f ;
}

/** @brief  Create a new BombGift with position and speed. */
BombGift::BombGift(Position pos,
                   Speed speed) : BombGift(pos.x, pos.y, speed.x, speed.y) {}

/** @brief  Destruction of a BombGift. */
BombGift::~BombGift() {}


void BombGift::additionnalStuffOnBreak() {
    static bool centered = true ;

    // Play bomb sound
    AudioManager::getInstance() -> playSound("bomb_explosion") ;

    // Add a bomb impact
    BombSplash* splash = new BombSplash() ;
    Position splashPos = {m_bounds.getCenterX(), m_bounds.getCenterY()} ;
    splash -> setPosition(splashPos, centered) ;
    ConfettiManager::addConfetti(splash) ;

    ScreenManager* sm = ScreenManager::getInstance() ;
    Level* level = (Level*) sm -> getCurrentScreen() ;
    level -> explodeAll(this) ;
}
