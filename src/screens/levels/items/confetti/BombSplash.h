#ifndef __BOMBSPLASH_ENTITY_H__
#define __BOMBSPLASH_ENTITY_H__

#include "ConfettiEntity.h"

class BombSplash : public ConfettiEntity {
    public:
        /** @brief  Create a BombSplash. */
        BombSplash() ;

        /** @brief  Destroy a BombSplash. */
        virtual ~BombSplash() ;

        /** @brief  Update the ConfettiEntity. */
        virtual void update() ;

        /** @brief  Test if the entity is alive to be updated. */
        virtual bool isAlive() ;
} ;

#endif
