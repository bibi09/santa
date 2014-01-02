#include "Entity.h"
#include "../../../tools/managers/SpriteManager.h"
#include <allegro5/allegro_primitives.h>

using namespace std ;


Entity::Entity(const string& sprite) {
    m_sprites["base"] = SpriteManager::getInstance() -> addSprite(sprite) ;
    m_sprite = m_sprites["base"] ;

    float width = al_get_bitmap_width(m_sprite) ;
    float height = al_get_bitmap_height(m_sprite) ;
    m_bounds = Rectangle2D(width, height) ;
}

Entity::Entity(const ALLEGRO_BITMAP* sprite) {
    assert(sprite != 0) ;
    m_sprites["base"] = (ALLEGRO_BITMAP*) sprite ;
    m_sprite = m_sprites["base"] ;

    float width = al_get_bitmap_width(m_sprite) ;
    float height = al_get_bitmap_height(m_sprite) ;
    m_bounds = Rectangle2D(width, height) ;
}

Entity::~Entity() {}


void Entity::display() {
    al_draw_bitmap(m_sprite, m_bounds.getX(), m_bounds.getY(), 0) ;

    #ifdef DEBUG
    al_draw_rectangle(m_bounds.getX(), m_bounds.getY(),
                      m_bounds.getMaxX(), m_bounds.getMaxY(),
                      al_map_rgb(255,0,0), 1) ;
    #endif
}


bool Entity::isAlive() {
    static Position min = {0.f, 0.f} ;
    static Position max = {WINDOW_WIDTH, WINDOW_HEIGHT} ;
    Position current = {m_bounds.getX(), m_bounds.getY()} ;
    return (current >= min && current < max) ;
}


bool Entity::isTouched(Position& p) {
    bool touched = m_bounds.contains(p) ;

    if (touched && m_sprites.count("touched") > 0)
        m_sprite = m_sprites["touched"] ;

    return touched ;
}

bool Entity::isTouched(Entity* other) {
    bool touched = m_bounds.contains(other -> m_bounds) ;

    if (touched && m_sprites.count("touched") > 0)
        m_sprite = m_sprites["touched"] ;

    return touched ;
}

bool Entity::isCutted(Position& p1, Position& p2) {
    bool cutted = m_bounds.intersectsLine(p1, p2) ;

    if (cutted && m_sprites.count("cutted") > 0)
        m_sprite = m_sprites["cutted"] ;
    return cutted ;
}


void Entity::setCuttedSprite(const string& sprite) {
    m_sprites["cutted"] = SpriteManager::getInstance() -> addSprite(sprite) ;
}

void Entity::setTouchedSprite(const string& sprite) {
    m_sprites["touched"] = SpriteManager::getInstance() -> addSprite(sprite) ;
}

void Entity::setPosition(float x, float y, bool center) {
    if (center) {
        x -= al_get_bitmap_width(m_sprite) / 2.f ;
        y -= al_get_bitmap_height(m_sprite) / 2.f ;
    }
    m_bounds.moveTo(x, y) ;
}

void Entity::setPosition(const Position& pos, bool center) {
    setPosition(pos.x, pos.y, center) ;
}


float Entity::getX() {
    return m_bounds.getX() ;
}

float Entity::getY() {
    return m_bounds.getY() ;
}
