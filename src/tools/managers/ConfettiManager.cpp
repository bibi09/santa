#include "ConfettiManager.h"

using namespace std ;

ConfettiManager* ConfettiManager::Singleton = 0 ;
sem_t ConfettiManager::Access ;
list<ConfettiEntity*> ConfettiManager::Confetti ;

ConfettiManager::ConfettiManager() {
    assert(sem_init(&Access, 0, 1) == 0) ;
}

ConfettiManager::~ConfettiManager() throw() {
    sem_destroy(&Access) ;
}


void ConfettiManager::update() {
    sem_wait(&Access) ;

    for (ConfettiIterator it = Confetti.begin() ; it != Confetti.end() ; it++) {
        ConfettiEntity* c = *it ;

        if (!c -> isAlive()) {
            it = Confetti.erase(it) ;
            delete c ;
        }
        else {
            c -> update() ;
        }
    }

    sem_post(&Access) ;
}


ConfettiManager* ConfettiManager::getInstance() {
    if (Singleton == 0)
        Singleton = new ConfettiManager() ;

    return Singleton ;
}


/** @brief  Add a confetti. */
void ConfettiManager::addConfetti(ConfettiEntity* confetti) {
    assert(confetti != 0) ;

    sem_wait(&Access) ;
    Confetti.push_back(confetti) ;
    sem_post(&Access) ;
}

/** @brief  Display the alive confetti. */
void ConfettiManager::display() {
    for (ConfettiIterator it = Confetti.begin() ; it != Confetti.end() ; it++) {
        (*it) -> display() ;
	}
}
