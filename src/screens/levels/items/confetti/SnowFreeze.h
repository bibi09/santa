#ifndef __SNOWFREEZE_ENTITY_H__
#define __SNOWFREEZE_ENTITY_H__

#include "ConfettiEntity.h"

class SnowFreeze : public ConfettiEntity {
    public:
        /** @brief  Create a SnowFreeze. */
        SnowFreeze() ;

        /** @brief  Destroy a SnowFreeze. */
        virtual ~SnowFreeze() ;


        /** @brief  Update the ConfettiEntity. */
        virtual void update() ;


        /** @brief  Test if the entity is alive to be updated. */
        virtual bool isAlive() ;
} ;

#endif
