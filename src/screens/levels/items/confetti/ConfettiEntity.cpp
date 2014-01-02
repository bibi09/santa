#include "ConfettiEntity.h"

using namespace std ;


ConfettiEntity::ConfettiEntity(const string& sprite,
                               unsigned char displayTime,
                               unsigned char fadeOutTime) : PhysicsEntity(sprite) {
    m_alpha = 255 ;
    m_frameDisplay = displayTime * 60 ;     // The game runs at 60FPS

    if (fadeOutTime != 0) {
        m_stepFadeOut = 255 / (fadeOutTime * 60) ;
        if (m_stepFadeOut == 0)
            m_stepFadeOut = 1 ;
    }
    else {
        m_stepFadeOut = 255 ;
    }
}

ConfettiEntity::ConfettiEntity(ALLEGRO_BITMAP* sprite,
                               unsigned char displayTime,
                               unsigned char fadeOutTime) : PhysicsEntity(sprite) {
    m_alpha = 255 ;
    m_frameDisplay = displayTime * 60 ;     // The game runs at 60FPS

    if (fadeOutTime != 0) {
        m_stepFadeOut = 255 / (fadeOutTime * 60) ;
        if (m_stepFadeOut == 0)
            m_stepFadeOut = 1 ;
    }
    else {
        m_stepFadeOut = 255 ;
    }
}


ConfettiEntity::~ConfettiEntity() {}


void ConfettiEntity::display() {
    ALLEGRO_COLOR color = al_map_rgba(255, 255, 255, m_alpha) ;

    al_draw_tinted_rotated_bitmap(m_sprite, color,
                                  m_bounds.getHalfWidth(), m_bounds.getHalfHeight(),
                                  m_bounds.getCenterX(), m_bounds.getCenterY(),
                                  m_angle,
                                  0) ;
}

void ConfettiEntity::update() {
    PhysicsEntity::update() ;
    updateDisplay() ;
}

void ConfettiEntity::updateDisplay() {
    if (m_frameDisplay > 1) m_frameDisplay-- ;
    else if (m_alpha > 1)   m_alpha -= m_stepFadeOut ;
}
