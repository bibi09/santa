#include "Level2.h"
#include "hud/Score.h"
#include "rules_screens/RuleScreenLevel3.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"

#include "items/bonus/BlueGift.h"
#include "items/bonus/RedGift.h"
#include "items/bonus/SpecialGift.h"
#include "items/bonus/Zuurstok.h"
#include "items/malus/BombGift.h"
#include "items/malus/Gnome.h"
#include "items/malus/Pan.h"
#include "items/malus/SnowGlobe.h"

using namespace std ;


Level2::Level2() : Level("bg_level2", "level2") {
    #ifdef DEBUG
    Logger::print("Level 2 initialization") ;
    #endif

    m_maxItems = 12 ;
}

Level2::~Level2() {}

void Level2::preload() {
    Position pos ;
    Speed speed ;

    new BlueGift(pos, speed) ;
    new RedGift(pos, speed) ;
    new SpecialGift(pos, speed) ;
    new Zuurstok(pos, speed) ;
    new BombGift(pos, speed) ;
    new Pan(pos, speed) ;
    new SnowGlobe(pos, speed) ;
    new Gnome(pos, speed) ;
}


void Level2::levelEnd() {
    static Score* score = Score::getInstance() ;
    if (score -> getScore() >= 5) {
        ScreenManager::getInstance() -> replaceScreen(new RuleScreenLevel3()) ;
    }
}

ScoringEntity* Level2::pickRandomItem(Position pos, Speed speed) {
    unsigned char id = rand() % 128 ;

    ScoringEntity* entity ;

    // Special and rare items
    switch (id) {
        case 0:
        case 5:
        case 9:
        case 19:
        case 87:
            return new SpecialGift(pos, speed) ;
    }

    // Common items
    if (id < 32)
        entity = new Zuurstok(pos, speed) ;
    if (id < 76)
        entity = new RedGift(pos, speed) ;
    else if (id < 82)
        entity =  new Pan(pos, speed) ;
    else if (id < 115)
        entity =  new SnowGlobe(pos, speed) ;
    else if (id < 120)
        entity =  new BlueGift(pos, speed) ;
    else if (id < 123)
        entity =  new BombGift(pos, speed) ;
    else
        entity =  new Gnome(pos, speed) ;

    entity -> dontCountPoints() ;
    return entity ;
}
