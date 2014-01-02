#ifndef __CURSOR_POSITION_BUFFER_H__
#define __CURSOR_POSITION_BUFFER_H__

#include "patterns/NoCopy.h"
#include "geometry/Position.h"

#include <cassert>
#include <cmath>
#include <semaphore.h>
#include <vector>

/**
 * @brief   Buffer used to allow the threads to communicate and move the cursor
 *          while the player moves the detected object.
 * @author  Denis CARLUS
 */
class CursorPositionBuffer : private NoCopy {
    public:
        #ifdef USE_MOUSE
        /** @brief  Maximal size of the buffer. */
        static const int BUFFER_MAXSIZE = 3 ;
        #else
        /** @brief  Maximal size of the buffer. */
        static const int BUFFER_MAXSIZE = 5 ;
        #endif

    private:
        /** Position weights */
        static float POSITION_WEIGHTS[BUFFER_MAXSIZE] ;
        /** @brief  Singleton of the CursorPositionBuffer. */
        static CursorPositionBuffer* Singleton ;

        /**
         * @brief Regulate the access to the singleton to avoid concurrency
         *        problems.
         */
        static sem_t Access ;

        /** @brief  Contains some of the last positions of the cursor. */
        std::vector<Position> m_positions ;
        /** @brief  Extrapolated position. */
        Position m_extrapolated ;


                                            /** CONSTRUCTION AND DESTRUCTION **/
        /**
         * @brief Construction of a CursorPositionBuffer.
         */
        CursorPositionBuffer() ;

        /** @brief Destruction of the CursorPositionBuffer. */
        ~CursorPositionBuffer() throw() ;


    public:
        /**
         * @brief Get the unique instance of Allegro.
         * @return  The unique instance of Allegro.
         */
        static CursorPositionBuffer* getInstance() ;


        /** @brief  Add a position to the buffer. */
        void addPosition(float x, float y) ;


        /** @brief  Add a position to the buffer. */
        void addPosition(const Position& pos) ;

        /** @brief  Cursor is no more detected. Positions are cleared. */
        void lostCursor() ;

        /** @brief  Get the last position of the cursor. */
        Position getLastPosition() ;


        /** @brief  Get previous and current positions of the cursor. */
        std::vector<Position> getPositions() ;


        /** @brief  Compute the speed of the cursor from the two last positions. */
        short getSpeed() ;


    protected:
        /**
         * @brief  Extrapolate cursor position from the previous ones.
         *         Useful to have a smooth cursor move when camera exposure is
         *         too long...
         */
        void extrapolate() ;


        /** @brief  Compute the mean position from the previous ones. */
        Position meanPosition() ;
} ;

#endif
