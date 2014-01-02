#ifndef __MALUS_ENTITY_H__
#define __MALUS_ENTITY_H__

#include "../ScoringEntity.h"

class MalusEntity : public ScoringEntity {
    public:
        /** @brief  Create a new MalusEntity. */
        MalusEntity(const std::string& sprite,
                    unsigned char minimalSpeed,
                    short points) ;

        /** @brief  Destroy a MalusEntity. */
        virtual ~MalusEntity() ;

    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
