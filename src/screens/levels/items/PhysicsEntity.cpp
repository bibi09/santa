#include "PhysicsEntity.h"
#include <allegro5/allegro_primitives.h>

using namespace std ;

const unsigned char PhysicsEntity::MAX_FALL_SPEED = 10 ;


PhysicsEntity::PhysicsEntity(const string& sprite) : Entity(sprite) {
    m_speed.x = 0.f ;
    m_speed.y = 0.f ;

    m_angleStep = Math::toRadian((rand() % 5) + 1) ;
    m_angle = Math::toRadian(rand() % 360) ;
}

PhysicsEntity::PhysicsEntity(const ALLEGRO_BITMAP* sprite) : Entity(sprite) {
    m_speed.x = 0.f ;
    m_speed.y = 0.f ;

    m_angleStep = Math::toRadian((rand() % 5) + 1) ;
    m_angle = Math::toRadian(rand() % 360) ;
}

PhysicsEntity::~PhysicsEntity() {}


void PhysicsEntity::display() {
    al_draw_rotated_bitmap(m_sprite,
                           m_bounds.getHalfWidth(), m_bounds.getHalfHeight(),
                           m_bounds.getCenterX(), m_bounds.getCenterY(),
                           m_angle,
                           0) ;

    #ifdef DEBUG
    al_draw_rectangle(m_bounds.getX(), m_bounds.getY(),
                      m_bounds.getMaxX(), m_bounds.getMaxY(),
                      al_map_rgb(255,0,0), 1) ;
    al_draw_filled_rectangle(m_bounds.getCenterX() - 5,
                             m_bounds.getCenterY() - 5,
                             m_bounds.getCenterX() + 5,
                             m_bounds.getCenterY() + 5,
                             al_map_rgb(0,0,255)) ;
    #endif
}


void PhysicsEntity::update() {
    m_bounds.moveOffset(m_speed.x, m_speed.y) ;

    if (m_speed.x > 0.f)
        m_speed.x -= 0.01f ;
    if (m_speed.y < MAX_FALL_SPEED)
        m_speed.y -= - 0.1f ;

    m_angle += m_angleStep ;
}


void PhysicsEntity::setInitialSpeed(float xSpeed, float ySpeed) {
    m_speed.x = xSpeed ;
    m_speed.y = ySpeed ;
}

void PhysicsEntity::setInitialSpeed(const Speed& speed) {
    m_speed = speed ;
}


bool PhysicsEntity::isAlive() {
    static const unsigned short LIMIT_ALIVE = WINDOW_HEIGHT + 100 ;
    return (m_bounds.getY() < LIMIT_ALIVE) ;
}
