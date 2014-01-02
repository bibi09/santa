#include "Level1.h"
#include "hud/Score.h"
#include "rules_screens/RuleScreenLevel2.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"

using namespace std ;


Level1::Level1() : Level("bg_level1", "level1") {
    #ifdef DEBUG
    Logger::print("Level 1 initialization") ;
    #endif

    m_maxItems = 12 ;
}

Level1::~Level1() {}

void Level1::levelEnd() {
    static Score* score = Score::getInstance() ;
    if (score -> getScore() >= 500) {
        ScreenManager::getInstance() -> replaceScreen(new RuleScreenLevel2()) ;
    }
}

ScoringEntity* Level1::pickRandomItem(Position pos, Speed speed) {
    unsigned char id = rand() % 128 ;

    // Special and rare items
    switch (id) {
        case 7:
            return new Zuurstok(pos, speed) ;
        case 42:
            return new OrangeGift(pos, speed) ;
    }

    // Common items
    if (id < 76)
        return new RedGift(pos, speed) ;
    else if (id < 82)
        return new BlueGift(pos, speed) ;
    else if (id < 115)
        return new BombGift(pos, speed) ;
    else if (id < 120)
        return new Pan(pos, speed) ;
    else if (id < 123)
        return new SnowGlobe(pos, speed) ;
    else
        return new Gnome(pos, speed) ;
}
