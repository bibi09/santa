#include "Level3.h"
#include "hud/Score.h"
#include "../menus/EndScreen.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"
#include "../../tools/managers/AudioManager.h"

#include "items/bonus/BlueGift.h"
#include "items/bonus/RedGift.h"
#include "items/bonus/GingerbreadMan.h"
#include "items/bonus/Zuurstok.h"
#include "items/malus/BombGift.h"
#include "items/malus/AngryGnome.h"
#include "items/malus/Pan.h"
#include "items/malus/SnowGlobe.h"

using namespace std ;


Level3::Level3() : Level("bg_level3", "level3") {
    #ifdef DEBUG
    Logger::print("Level 3 initialization") ;
    #endif

    m_maxItems = 12 ;
}

Level3::~Level3() {}


void Level3::preload() {
    Position pos ;
    Speed speed ;

    new BlueGift(pos, speed) ;
    new RedGift(pos, speed) ;
    new GingerbreadMan(pos, speed) ;
    new Zuurstok(pos, speed) ;
    new BombGift(pos, speed) ;
    new Pan(pos, speed) ;
    new SnowGlobe(pos, speed) ;
    new AngryGnome(pos, speed) ;
}


void Level3::levelEnd() {
    static Score* score = Score::getInstance() ;
    if (score -> getScore() >= 10) {
        AudioManager::getInstance() -> playSound("ohohoh") ;
        ScreenManager::getInstance() -> replaceScreen(new EndScreen()) ;
    }
}

ScoringEntity* Level3::pickRandomItem(Position pos, Speed speed) {
    unsigned char id = rand() % 128 ;

    ScoringEntity* entity ;

    // Common items
    if (id < 16)
        return new GingerbreadMan(pos, speed) ;
    if (id < 32)
        entity = new RedGift(pos, speed) ;
    if (id < 76)
        return new AngryGnome(pos, speed) ;
    else if (id < 82)
        entity =  new Pan(pos, speed) ;
    else if (id < 115)
        entity =  new SnowGlobe(pos, speed) ;
    else if (id < 120)
        entity = new Zuurstok(pos, speed) ;
    else if (id < 123)
        entity =  new BombGift(pos, speed) ;
    else
        entity =  new BlueGift(pos, speed) ;
        

    entity -> dontCountPoints() ;
    return entity ;
}
