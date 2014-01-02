#include "Thread.h"

using namespace std ;


Thread::Thread() {
    assert(sem_init(&m_access, 0, 1) == 0) ;
    m_running = false ;
}

Thread::~Thread() {
    sem_destroy(&m_access) ;
}


void Thread::run() {
    sem_wait(&m_access) ;                       // -- Critical section

    if (!m_running) {
        m_running = true ;
        m_thread = thread(&Thread::task, this) ;
    }

    sem_post(&m_access) ;                       // -- Critical section
}

bool Thread::isRunning() {
    sem_wait(&m_access) ;                       // -- Critical section
    bool result = m_running ;
    sem_post(&m_access) ;                       // -- Critical section

    return result ;
}

void Thread::waitForEnding() {
    sem_wait(&m_access) ;                       // -- Critical section
    m_thread.join() ;
    sem_post(&m_access) ;                       // -- Critical section
}

void Thread::stop() {
    sem_wait(&m_access) ;                       // -- Critical section
    effectiveStop() ;
    sem_post(&m_access) ;                       // -- Critical section
}
