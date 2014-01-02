#ifndef __CURSOR_ENTITY_H__
#define __CURSOR_ENTITY_H__

#include "../../../tools/CursorPositionBuffer.h"
#include "Entity.h"

#include <allegro5/allegro.h>

class CursorEntity : public Entity, private NoCopy {
    private:
        /** @brief Singleton of the CursorEntity. */
        static CursorEntity* Singleton ;

        /** @brief  Color used to display a tail after the cursor. */
        ALLEGRO_COLOR m_tailColors[CursorPositionBuffer::BUFFER_MAXSIZE] ;
        /** @brief  Speed of the cursor. */
        unsigned short m_speed ;

                                            /** CONSTRUCTION AND DESTRUCTION **/
        /**
         * @brief Construction of a CursorEntity.
         */
        CursorEntity() ;

        /** @brief Destruction of the CursorEntity. */
        virtual ~CursorEntity() throw() ;

    public:
        /**
         * @brief Get the unique instance of CursorEntity.
         * @return  The unique instance of CursorEntity.
         */
        static CursorEntity* getInstance() ;


        /** @brief  Test if the cursor has cutted the given entity. */
        bool cuts(Entity* entity) ;

        /** @brief Display the cursor. */
        virtual void display() ;

        /** @brief  Update the Entity. */
        virtual void update() ;

        /** @brief  Get the cursor speed. */
        short getSpeed() ;
} ;

#endif
