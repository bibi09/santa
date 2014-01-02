#include "ScoringEntity.h"
#include "confetti/SnowConfetti4.h"
#include "confetti/SnowConfetti8.h"
#include "confetti/SnowConfetti12.h"
#include "../hud/Score.h"
#include "../../../tools/managers/ConfettiManager.h"

using namespace std ;


ScoringEntity::ScoringEntity(const string& sprite,
                             unsigned char minimalSpeed,
                             short points) : PhysicsEntity(sprite) {
    #ifdef USE_MOUSE
        minimalSpeed = minimalSpeed / 10 ;
    #endif

    m_points = points ;
    m_minimalSpeed = minimalSpeed ;
    m_makeDisappear = true ;
    m_isBroken = false ;
    m_countPoints = true ;
}

ScoringEntity::~ScoringEntity() {}

bool ScoringEntity::isBroken(short speed) {
    if (!m_isBroken) {
        m_isBroken = (speed >= m_minimalSpeed) ;
        if (m_isBroken) {
            onBreak() ;
        }
    }

    return m_isBroken ;
}

bool ScoringEntity::isBroken(CursorEntity* cursor) {
    return isBroken(cursor -> getSpeed()) ;
}

void ScoringEntity::forceBreak() {
    onBreak() ;
}


short ScoringEntity::getScorePoints() {
    return m_points ;
}


void ScoringEntity::makeDisappearOnBreak(bool disappear) {
    m_makeDisappear = disappear ;
}


bool ScoringEntity::disappearOnBreak() {
    return m_makeDisappear ;
}

void ScoringEntity::dontCountPoints() {
    m_countPoints = false ;
}

void ScoringEntity::onBreak() {
    generateConfetti() ;
    additionnalStuffOnBreak() ;

    if (m_countPoints)
        Score::getInstance() -> addScore(m_points) ;
}


void ScoringEntity::generateConfetti() {
    static bool centered = true ;

    unsigned char amount = (rand() % 6) + 2 ;
    for (unsigned char i = 0 ; i < amount ; i++) {
        ConfettiEntity* newConfetti ;
        unsigned char id = rand() % 10 ;

        // Determine the confetti type
        if (id < 3)
            newConfetti = new SnowConfetti4() ;
        else if (id < 8)
            newConfetti = new SnowConfetti8() ;
        else
            newConfetti = new SnowConfetti12() ;

        // Determine the confetti speed
        float speedX = rand() % 4 ;
        float speedY = (rand() % 5) - 2 ;
        if (rand() % 2) speedX = -speedX ;
        Speed confSpeed = {speedX, speedY} ;

        // Place the confetti at the current entity position
        Position confPos = {m_bounds.getCenterX(), m_bounds.getCenterY()} ;
        newConfetti -> setPosition(confPos, centered) ;
        newConfetti -> setInitialSpeed(confSpeed) ;

        ConfettiManager::addConfetti(newConfetti) ;
    }
}
