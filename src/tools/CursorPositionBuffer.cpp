#include "CursorPositionBuffer.h"
#include <iostream>

using namespace std ;


#ifdef USE_MOUSE
    float CursorPositionBuffer::POSITION_WEIGHTS[CURSOR_BUFFER_MAX_SIZE] = {1.0} ;
#else
    float CursorPositionBuffer::POSITION_WEIGHTS[CURSOR_BUFFER_MAX_SIZE] = {0.01, 0.05, 0.09, 0.15, 0.70} ;
#endif
CursorPositionBuffer* CursorPositionBuffer::Singleton = 0 ;
sem_t CursorPositionBuffer::Access ;


CursorPositionBuffer::CursorPositionBuffer() {
    assert(sem_init(&Access, 0, 1) == 0) ;
    m_positions.reserve(CURSOR_BUFFER_MAX_SIZE + 1) ;

    Position initCursorPosition = {-1.f, -1.f} ;
    m_positions.push_back(initCursorPosition) ;
}

CursorPositionBuffer::~CursorPositionBuffer() throw () {
    sem_destroy(&Access) ;
}

CursorPositionBuffer* CursorPositionBuffer::getInstance() {
    if (Singleton == 0)
        Singleton = new CursorPositionBuffer() ;

    return Singleton ;
}


void CursorPositionBuffer::addPosition(float x, float y) {
    Position pos = {x, y} ;

    sem_wait(&Access) ;                             // -- Critical section

    m_positions.push_back(pos) ;
    if (m_positions.size() > CURSOR_BUFFER_MAX_SIZE)
        m_positions.erase(m_positions.begin()) ;

    sem_post(&Access) ;                             // Critical section --
}

void CursorPositionBuffer::addPosition(const Position& pos) {
    addPosition(pos.x, pos.y) ;
}


void CursorPositionBuffer::lostCursor() {
    sem_wait(&Access) ;                             // -- Critical section
    if (m_positions.size() > 1)
        m_positions.erase(m_positions.begin()) ;
    sem_post(&Access) ;                             // Critical section --
}


Position CursorPositionBuffer::getLastPosition() {
    Position pos ;

    sem_wait(&Access) ;                             // -- Critical section
    #ifdef USE_MOUSE
        pos = m_positions.back() ;
    #else
        extrapolate() ;
        pos = m_extrapolated ;
    #endif
    sem_post(&Access) ;                             // Critical section --

    return pos ;
}

/** @brief  Get previous and current positions of the cursor. */
vector<Position> CursorPositionBuffer::getPositions() {
    sem_wait(&Access) ;                             // -- Critical section
    std::vector<Position> copy(m_positions) ;
    #ifndef USE_MOUSE
        copy.back() = m_extrapolated ;
    #endif
    sem_post(&Access) ;                             // Critical section --

    return copy ;
}

short CursorPositionBuffer::getSpeed() {
    if (m_positions.size() < 2)
        return 0 ;

    sem_wait(&Access) ;                             // -- Critical section
    Position beforeLast = m_positions[m_positions.size() - 2] ;
    Position last = m_positions.back() ;
    sem_post(&Access) ;                             // Critical section --

    short diffX = last.x - beforeLast.x ;
    short diffY = last.y - beforeLast.y ;
    return sqrt((diffX*diffX) + (diffY*diffY)) ;
}


void CursorPositionBuffer::extrapolate() {
    #ifndef USE_MOUSE
        m_extrapolated = meanPosition() ;

        Distance diff = {0.f, 0.f} ;
        Position current ;
        Position previous = m_positions[0] ;
        for (unsigned char i = 1 ; i < m_positions.size() ; i++) {
            current = m_positions[i] ;
            Distance tmpDiff = current - previous ;
            diff = diff + tmpDiff ;
            previous = current ;
        }

        diff.x = diff.x / m_positions.size() ;
        diff.y = diff.y / m_positions.size() ;

        m_extrapolated = m_extrapolated + diff ;
    #endif
}

Position CursorPositionBuffer::meanPosition() {
    #ifndef USE_MOUSE
        Position mean = {0.f, 0.f} ;

        for (int i = 0 ; i < CURSOR_BUFFER_MAX_SIZE ; i++) {
            mean.x += POSITION_WEIGHTS[i] * m_positions[i].x ;
            mean.y += POSITION_WEIGHTS[i] * m_positions[i].y ;
        }

        return mean ;
    #else
        return m_positions.back() ;
    #endif
}
