#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "patterns/NoCopy.h"

#include <cassert>
#include <semaphore.h>
#include <ctime>
#include <iostream>
#include <string>

/**
 * @brief A simple logger to display logs while the execution.
 * @version 1.0     08/07/2013
 * @author  Denis CARLUS
 */
class Logger : private NoCopy {
    private:
        /** @brief Singleton of the Logger. */
        static Logger* Singleton ;

        /**
         * @brief Regulate the access to the singleton to avoid concurrency
         *        problems.
         */
        static sem_t Access ;


                                            /** CONSTRUCTION AND DESTRUCTION **/
        /**
         * @brief Construction of a Logger handler.
         */
        Logger() ;

        /** @brief Destruction of the Logger handler. */
        ~Logger() throw() ;


    public:
        /**
         * @brief Get the unique instance of Logger.
         * @return  The unique instance of Logger.
         */
        static Logger* getInstance() ;


        /**
         * @brief Print a log on screen.
         * @param log   The log to print.
         */
        static void print(const std::string& log) ;
} ;

#endif
