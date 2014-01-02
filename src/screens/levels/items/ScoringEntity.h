#ifndef __SCORING_ENTITY_H__
#define __SCORING_ENTITY_H__

#include "PhysicsEntity.h"
#include "CursorEntity.h"

class ScoringEntity : public PhysicsEntity {
    private:
        /** @brief  Minimal speed to break the entity. */
        unsigned char m_minimalSpeed ;
        /** @brief  To know if the entity is already broken. */
        bool m_isBroken ;
        /** @brief  Score points given by the entity. */
        short m_points ;
        /** @brief  Make the entity disappear when broken. */
        bool m_makeDisappear ;
        /** @brief  Used to automatically count the points given by the entity. */
        bool m_countPoints ;

    public:
        /** @brief  Create a new BonusEntity. */
        ScoringEntity(const std::string& sprite,
                      unsigned char minimalSpeed,
                      short points) ;

        /** @brief  Destroy a ScoringEntity. */
        virtual ~ScoringEntity() ;

        /** @brief  Test if the entity is broken. */
        virtual bool isBroken(short speed) ;

        /** @brief  Test if the entity is broken by a cursor. */
        virtual bool isBroken(CursorEntity* cursor) ;

        /** @brief  Force the entity to break. */
        void forceBreak() ;

        /** @brief  Get the score points given by the entity when broken. */
        short getScorePoints() ;


        /** @brief  Make the entity disappear when broken, or not. */
        void makeDisappearOnBreak(bool disappear) ;


        /** @brief  To know if the entity should be deleted when broken. */
        bool disappearOnBreak() ;

        /** @brief  To not count the score points on break. */
        void dontCountPoints() ;

    protected:
        /** @brief  Event triggered when entity is broken. */
        virtual void onBreak() ;


        /** @brief  Run additionnal operations on break. */
        virtual void additionnalStuffOnBreak() = 0 ;


        /** @brief  Generate some confetti when entity is broken. */
        void generateConfetti() ;
} ;

#endif
