#include "RuleScreen.h"
#include "../../gui/AlComponent.h"
#include "../../gui/buttons/AlButtonBitmap.h"


using namespace std ;

ALLEGRO_FONT* RuleScreen::TitleFont = 0 ;
ALLEGRO_FONT* RuleScreen::TextFont = 0 ;


RuleScreen::RuleScreen(const string& title,
                       const string& rule) : GameScreen("bg_intro",
                                                        "",
                                                        false) {
    if (TitleFont == 0) {
        TitleFont = al_load_ttf_font("media/fonts/musicals.ttf", 32, 0) ;
        TextFont = al_load_ttf_font("media/fonts/amperzand.ttf", 26, 0) ;
    }

    m_title = new AlLabel(Position(20.f, 20.f), title, TitleFont) ;
    m_title -> setColor(AlComponent::LAYER_FOREGROUND, al_map_rgba(255, 255, 255, 255)) ;
    m_rule = new AlLabel(Position(20.f, 80.f), rule, TextFont) ;
    m_rule -> setColor(AlComponent::LAYER_FOREGROUND, al_map_rgba(255, 255, 255, 255)) ;
    m_button = 0 ;
    m_countdown = 120 ;
}

RuleScreen::~RuleScreen() {
    if (m_button != 0)
        delete m_button ;

    delete m_rule ;
    delete m_title ;
}

void RuleScreen::update() {
    m_cursor -> update() ;

    m_countdown-- ;
    if (m_countdown < 0) {
        float cursorX = m_cursor -> getX() ;
        float cursorY = m_cursor -> getY() ;
        if (m_button != 0) {
            if (m_button -> testCursor(cursorX, cursorY)) {
                m_button -> trigger() ;
            }
        }
    }
}


void RuleScreen::additionnalDisplay() {
    m_title -> display() ;
    m_rule -> display() ;

    if (m_button != 0)
        m_button -> display() ;

    m_cursor -> display() ;
}

void RuleScreen::setButtonAction(AlAbstractAction* action) {
    static Position buttonPos(WINDOW_WIDTH - 180.f, WINDOW_HEIGHT - 100.f) ;
    static string spriteName = "play_button" ;
    m_button = new AlButtonBitmap(buttonPos, spriteName, action) ;
}
