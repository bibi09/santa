#ifndef __CONFETTI_MANAGER_H__
#define __CONFETTI_MANAGER_H__

#include "../patterns/NoCopy.h"
#include "../../screens/levels/items/confetti/ConfettiEntity.h"
#include <assert.h>
#include <semaphore.h>
#include <list>


/**
 * @brief   Manage confetti, elements that appear when an entity is broken by
 *          the player.
 * @author  Denis CARLUS
 */
class ConfettiManager : private NoCopy {
	typedef std::list<ConfettiEntity*>::iterator ConfettiIterator ;

    private:
        /** @brief Singleton of the ConfettiManager handler. */
        static ConfettiManager* Singleton ;

        /**
         * @brief Regulate the access to the singleton to avoid concurrency
         *        problems.
         */
        static sem_t Access ;

        /** List of the loaded sprites. */
        static std::list<ConfettiEntity*> Confetti ;

                                            /** CONSTRUCTION AND DESTRUCTION **/
        /** @brief Construction of a SpriteManager handler. */
        ConfettiManager() ;

        /** @brief Destruction of the SpriteManager handler. */
        ~ConfettiManager() throw() ;


    public:
        /**
         * @brief Get the unique instance of ConfettiManager.
         * @return  The unique instance of ConfettiManager.
         */
        static ConfettiManager* getInstance() ;


        /** @brief  Add a confetti. */
        static void addConfetti(ConfettiEntity* confetti) ;

        /** @brief  Display the alive confetti. */
        static void display() ;

        /** @brief  Update the alive confetti. */
        static void update() ;
} ;

#endif
