#include "BonusEntity.h"
#include "../../../../tools/managers/AudioManager.h"
#include "../../../../tools/managers/ConfettiManager.h"
#include "../../../../tools/managers/SpriteManager.h"

using namespace std ;

const string BonusEntity::DefaultSound = "hit_bonus" ;


/** @brief  Create a new BonusEntity. */
BonusEntity::BonusEntity(const string& sprite,
                         unsigned char minimalSpeed,
                         short points) : ScoringEntity("items/" + sprite,
                                                       minimalSpeed,
                                                       points) {
    m_soundPlayed = DefaultSound ;
    string base = "items/cutted/" + sprite ;

    string spritePath = base + "_cutted_part1" ;
    m_sprites["cutted_part1"] = SpriteManager::getInstance() -> addSprite(spritePath) ;

    spritePath = base + "_cutted_part2" ;
    m_sprites["cutted_part2"] = SpriteManager::getInstance() -> addSprite(spritePath) ;
}

/** @brief  Destroy a BonusEntity. */
BonusEntity::~BonusEntity() {}

void BonusEntity::additionnalStuffOnBreak() {
    // Play glass sound
    AudioManager::getInstance() -> playSound(m_soundPlayed) ;

    /* ADD THE CUTTED CONFETTI WITH SPEED AND CENTERED POSITION. */
    static bool centered = true ;

    // Place the confetti at the current entity position
    Position confPos = {m_bounds.getCenterX(), m_bounds.getCenterY()} ;

    // Determine the confetti speed
    float speedX = (rand() % 4) + 1 ;
    float speedY = (rand() % 5) - 2 ;
    if (rand() % 2) speedX = -speedX ;
    Speed confSpeed = {speedX, speedY} ;

    // Part 1
    ConfettiEntity* newConfetti = new ConfettiEntity(m_sprites["cutted_part1"], 6, 0) ;
    newConfetti -> setPosition(confPos, centered) ;
    newConfetti -> setInitialSpeed(confSpeed) ;
    ConfettiManager::addConfetti(newConfetti) ;


    // Part 2
    confSpeed = {-speedX, speedY} ;
    newConfetti = new ConfettiEntity(m_sprites["cutted_part2"], 6, 0) ;
    newConfetti -> setPosition(confPos, centered) ;
    newConfetti -> setInitialSpeed(confSpeed) ;
    ConfettiManager::addConfetti(newConfetti) ;
}
