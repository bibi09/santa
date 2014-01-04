#include "Level.h"
#include "hud/Score.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std ;


Level::Level(const std::string& background,
             const std::string& bgm) : GameScreen(background, bgm) {
    m_waitSpawn = 0 ;
    Score::getInstance() -> reset() ;
}


Level::~Level() {}

void Level::update() {
    CursorEntity::getInstance() -> update() ;

    updatePhysicsEntities() ;
    ConfettiManager::update() ;

    // Add new items if not enough are alive
    m_waitSpawn-- ;
    if ((m_items.size() < m_maxItems) && m_waitSpawn < 0)
        addScoringItem() ;

    levelEnd() ;
}

void Level::explodeAll(ScoringEntity* source) {
    /* To know if the level is already making explode all the entities.
     * It avoids cyclic explosions...*/
    static bool isExplodingAll = false ;

    if (!isExplodingAll) {
        isExplodingAll = true ;

        for (auto it = m_items.begin() ; it != m_items.end() ; it++) {
            ScoringEntity* ent = *it ;

            if (ent != source) {
                ent -> forceBreak() ;
                it = m_items.erase(it) ;
                delete ent ;
            }
        }

        isExplodingAll = false ;
    }
}


void Level::additionnalDisplay() {
    // Draw the different entities
    for (auto& entity : m_items)
        entity -> display() ;

    CursorEntity::getInstance() -> display() ;
    ConfettiManager::display() ;
    Score::getInstance() -> display() ;
}


void Level::addScoringItem() {
    unsigned char fromLeft = rand() % 2 ;

    // Position of the new item.
    Position pos ;
    pos.x = -((rand() % 50) + 80) ;
    pos.y = (rand() % WINDOW_HEIGHT) ;

    // Initial speed of the new item.
    Speed speed ;
    speed.x = (rand() % 3) + 4 ;
    speed.y = -((rand() % 3) + 3) ;

    // Invert the position and speed if the item spawns on the right
    if (!fromLeft) {
        pos.x += -pos.x + WINDOW_WIDTH ;
        speed.x = -speed.x ;
    }

    m_items.push_back(pickRandomItem(pos, speed)) ;
    m_waitSpawn = rand() % 64 ;
}


void Level::updatePhysicsEntities() {
    for (auto it = m_items.begin() ; it != m_items.end() ; it++) {
        ScoringEntity* ent = *it ;

        if (!ent -> isAlive()) {
            it = m_items.erase(it) ;
            delete ent ;
        }
        else {
            if ((CursorEntity::getInstance() -> cuts(ent))
                    && (ent -> isBroken(CursorEntity::getInstance()))
                    && (ent -> disappearOnBreak())) {
                it = m_items.erase(it) ;
                delete ent ;
            }
            else {
                ent -> update() ;
            }
        }
    }
}
