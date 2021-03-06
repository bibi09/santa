#include "threads/CameraProcessing.h"
#include "tools/managers/AudioManager.h"
#include "tools/managers/SpriteManager.h"
#include "tools/managers/ConfettiManager.h"
#include "tools/Allegro.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std ;


/** @brief  Main function. */
int main(int, char**) {
    srand(time(NULL)) ;

    ConfettiManager::getInstance() ;
#ifndef USE_MOUSE
    CameraProcessing::getInstance() -> run() ;
#endif
    Allegro::getInstance() -> run() ;

    return 0 ;
}
