#include "CursorEntity.h"
#include <allegro5/allegro_primitives.h>

using namespace std ;

CursorEntity* CursorEntity::Singleton = 0 ;


CursorEntity::CursorEntity() : Entity("cursor/snowball") {
    setPosition(-1.f, -1.f) ;

    char step = 128 / CURSOR_BUFFER_MAX_SIZE ;
    for (int i = 0 ; i < CURSOR_BUFFER_MAX_SIZE ; i++) {
        m_tailColors[i] = al_map_rgba(200, 240, 255, 96 + (i * step)) ;
    }
}

/** @brief Destruction of the CursorEntity. */
CursorEntity::~CursorEntity() throw() {}


CursorEntity* CursorEntity::getInstance() {
    if (Singleton == 0)
        Singleton = new CursorEntity() ;
    return Singleton ;
}


/** @brief  Test if the cursor has cutted the given entity. */
bool CursorEntity::cuts(Entity* entity) {
    assert(entity != this) ;

#ifndef USE_MOUSE
    CursorPositionBuffer* cursorPos = CursorPositionBuffer::getInstance() ;
    std::vector<Position> previousPos = cursorPos -> getPositions() ;

    if (previousPos.size() > 1) {
        Position first = previousPos[previousPos.size() - 2] ;
        Position last = previousPos.back() ;
        return entity -> isCutted(last, first) ;
    }

    return false ;
#else
    CursorPositionBuffer* cursorPos = CursorPositionBuffer::getInstance() ;
    return entity -> isTouched(cursorPos -> getLastPosition()) ;
#endif
}


/** @brief Display the cursor. */
void CursorEntity::display() {
#ifndef USE_MOUSE
    // Draw the cursor tail
    CursorPositionBuffer* cursorPos = CursorPositionBuffer::getInstance() ;
    std::vector<Position> previousPos = cursorPos -> getPositions() ;

    for (unsigned char i = 1 ; i < previousPos.size() ; i++) {
        unsigned char iprev = i - 1 ;
        al_draw_line(previousPos[iprev].x,
                     previousPos[iprev].y,
                     previousPos[i].x,
                     previousPos[i].y,
                     m_tailColors[i],
                     i) ;
    }
#endif

    // Draw the cursor itself
    al_draw_bitmap(m_sprite, m_bounds.getX(), m_bounds.getY(), 0) ;

    #ifdef DEBUG
    al_draw_rectangle(m_bounds.getX(), m_bounds.getY(),
                      m_bounds.getMaxX(), m_bounds.getMaxY(),
                      al_map_rgb(0,0,255), 1) ;
    #endif
}


/** @brief  Update the Entity. */
void CursorEntity::update() {
    // Update cursor position
    CursorPositionBuffer* cursorPos = CursorPositionBuffer::getInstance() ;
    setPosition(cursorPos -> getLastPosition(), true) ;
}


/** @brief  Get the cursor speed. */
short CursorEntity::getSpeed() {
    return CursorPositionBuffer::getInstance() -> getSpeed() ;
}
