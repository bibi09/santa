#ifndef __THREAD_API_H__
#define __THREAD_API_H__

#include <assert.h>
#include <semaphore.h>
#include <thread>

class Thread {
    private:
        /** @brief  Thread object that is abstracted. */
        std::thread m_thread ;
        /** @brief  To know if the thread is already running. */
        bool m_running ;
        /** @brief Regulate the access to the object to avoid concurrency problems. */
        sem_t m_access ;


    public:
        /** @brief  Create a new Thread. */
        Thread() ;

        /** @brief  Destruction of a Thread. */
        virtual ~Thread() ;


        /** @brief  Run the thread and wait for it is finished. */
        void run() ;

        /** @brief  To know if the thread is already running. */
        bool isRunning() ;

        /** @brief  Wait the thread ends. */
        void waitForEnding() ;

        /** @brief  Stop the thread execution. */
        void stop() ;


    protected:
        /** @brief  The task of the thread. */
        virtual void task() = 0 ;

        /** @brief  Effective stop task. */
        virtual void effectiveStop() = 0 ;
} ;

#endif
