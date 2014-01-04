#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

const unsigned short WINDOW_WIDTH = 640 ;
const unsigned short WINDOW_HEIGHT = 480 ;

    #ifdef USE_MOUSE
       const unsigned char CURSOR_BUFFER_MAX_SIZE = 1 ;
    #else
        const unsigned char CURSOR_BUFFER_MAX_SIZE = 5 ;
    #endif

#endif
