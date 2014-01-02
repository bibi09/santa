#include "AlButtonBitmap.h"
#include "../../../tools/managers/SpriteManager.h"

using namespace std ;


AlButtonBitmap::AlButtonBitmap(const Position& pos,
                               string& sprite,
                               AlAbstractAction* action) : AlButton(pos,
                                                                    action) {
    string spritePath = "gui/buttons/" + sprite ;
    m_sprite = SpriteManager::getInstance() -> addSprite(spritePath) ;

    updateBounds(Position(m_bounds.getX(), m_bounds.getY()),
                 Dimension(al_get_bitmap_width(m_sprite),
                           al_get_bitmap_height(m_sprite))) ;
}

AlButtonBitmap::~AlButtonBitmap() {}


void AlButtonBitmap::display() {
    al_draw_bitmap(m_sprite, m_bounds.getX(), m_bounds.getY(), 0) ;
}

void AlButtonBitmap::update() {}
