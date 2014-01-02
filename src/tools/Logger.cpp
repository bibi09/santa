#include "Logger.h"

using namespace std ;

    
Logger* Logger::Singleton = 0 ;
sem_t Logger::Access ;


Logger::Logger() {
    assert(sem_init(&Access, 0, 1) == 0) ;
}

Logger::~Logger() throw () {
    sem_destroy(&Access) ;
}

Logger* Logger::getInstance() {
    if (Singleton == 0)
        Singleton = new Logger() ;

    return Singleton ;
}


void Logger::print(const string& log) {
    getInstance() ;

    sem_wait(&Access) ;                             // -- Critical section
    time_t now = time(0) ;
    struct tm tstruct = *localtime(&now) ;
    char buffer[80] ;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d.%X", &tstruct) ;

    string printed = "[" + string(buffer) + "] " + log ;
    cout << printed << endl ;
    sem_post(&Access) ;                             // Critical section --
}
