#include "Score.h"
#include <cassert>

using namespace std ;

Score* Score::Singleton = 0 ;



Score::Score() {
    al_init_font_addon() ;
    assert(al_init_ttf_addon()) ;

    m_font = 0 ;
    m_font = al_load_ttf_font("media/fonts/musicals.ttf", 32, 0) ;
    assert(m_font != 0) ;

    m_score = 0 ;
}

Score::~Score() throw() {
    al_destroy_font(m_font) ;
}


Score* Score::getInstance() {
    if (Singleton == 0)
        Singleton = new Score() ;
    return Singleton ;
}


void Score::addScore(int value) {
    m_score += value ;
}


void Score::display() {
    std::string text = "Score: " + std::to_string(m_score) ;

    static ALLEGRO_COLOR color = al_map_rgba(255, 255, 255, 192) ;
    al_draw_text(m_font,
                 color,
                 20,
                 20,
                 ALLEGRO_ALIGN_LEFT,
                 text.c_str()) ;
}

void Score::reset() {
    m_score = 0 ;
}

int Score::getScore() {
    return m_score ;
}
