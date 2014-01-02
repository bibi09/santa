#include "GameScreen.h"
#include "../tools/managers/AudioManager.h"

using namespace std ;


GameScreen::GameScreen(const string& background,
                       const string& bgm,
                       bool stopBGMOnEnd) {
    if (!bgm.empty())
        AudioManager::getInstance() -> playBGM(bgm) ;

    string path = "media/img/" + background + ".png" ;
    m_background = al_load_bitmap(path.c_str()) ;
    m_cursor = CursorEntity::getInstance() ;
    m_stopBGMOnEnd = stopBGMOnEnd ;
}


GameScreen::~GameScreen() {
    al_destroy_bitmap(m_background) ;

    if (m_stopBGMOnEnd)
        AudioManager::getInstance() -> stopBGM() ;
}


void GameScreen::display() {
    al_draw_bitmap(m_background, 0, 0, 0) ;
    additionnalDisplay() ;
}
