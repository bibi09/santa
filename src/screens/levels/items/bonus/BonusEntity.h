#ifndef __BONUS_ENTITY_H__
#define __BONUS_ENTITY_H__

#include "../ScoringEntity.h"
#include <string>

class BonusEntity : public ScoringEntity {
    protected:
        /** @brief  Default played sound on break. */
        const static std::string DefaultSound ;
        /** @brief  Sound played when the bonus is broken. */
        std::string m_soundPlayed ;

    public:
        /** @brief  Create a new BonusEntity. */
        BonusEntity(const std::string& sprite,
                    unsigned char minimalSpeed,
                    short points) ;

        /** @brief  Destroy a BonusEntity. */
        virtual ~BonusEntity() ;

    protected:
        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() ;
} ;

#endif
