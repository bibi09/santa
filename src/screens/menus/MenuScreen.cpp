#include "MenuScreen.h"
#include "../gui/AlComponent.h"
#include "../gui/labels/AlLabel.h"
#include <iostream>

using namespace std ;


MenuScreen::MenuScreen(const string& background,
                       const string& bgm,
                       bool stopBGMOnEnd,
                       const string& title) : GameScreen(background,
                                                         bgm,
                                                         stopBGMOnEnd) {
    al_init_font_addon() ;
    assert(al_init_ttf_addon()) ;

    m_title = title ;
    setTitleColor(0, 0, 0, 255)  ;
    setTextColor(0, 0, 0, 255)  ;
}

MenuScreen::~MenuScreen() {
	for (FontIterator it = m_fonts.begin() ; it != m_fonts.end() ; it++) {
        al_destroy_font(it -> second) ;
    }

	unsigned int max = m_guiComponents.size() ;
    for (unsigned int i = 0 ; i < max ; i++) {
        delete m_guiComponents[i] ;
    }
}


void MenuScreen::update() {
    m_cursor -> update() ;

    float cursorX = m_cursor -> getX() ;
    float cursorY = m_cursor -> getY() ;
    unsigned int max = m_guiComponents.size() ;
    for (unsigned int i = 0 ; i < max ; i++) {
        if (m_guiComponents[i] -> testCursor(cursorX, cursorY)) {
            m_guiComponents[i] -> trigger() ;
        }
    }
}

void MenuScreen::preload() {}


void MenuScreen::additionnalDisplay() {
    al_draw_text(m_fonts["title"],
                 m_colors["title"],
                 20,
                 20,
                 ALLEGRO_ALIGN_LEFT,
                 m_title.c_str()) ;

    unsigned int max = m_guiComponents.size() ;
    for (unsigned int i = 0 ; i < max ; i++) {
        m_guiComponents[i] -> display() ;
	}

    m_cursor -> display() ;
}


void MenuScreen::addText(const string& text, const Position& pos) {
    AlLabel* label = new AlLabel(pos, text, m_fonts["text"]) ;
    label -> setColor(AlComponent::LAYER_FOREGROUND, m_colors["text"]) ;
    addComponent(label) ;
}


void MenuScreen::addComponent(AlComponent* component) {
    assert(component != 0) ;
    m_guiComponents.push_back(component) ;
}


void MenuScreen::setButtonsFont(const string& path, unsigned char size) {
    m_fonts["buttons"] = al_load_ttf_font(path.c_str(), size, 0) ;
}

void MenuScreen::setTitleFont(const string& path, unsigned char size) {
    m_fonts["title"] = al_load_ttf_font(path.c_str(), size, 0) ;
}

void MenuScreen::setTitleColor(unsigned char red,
                   unsigned char green,
                   unsigned char blue,
                   unsigned char alpha) {
    m_colors["title"] = al_map_rgba(red, green, blue, alpha) ;
}

void MenuScreen::setTextFont(const string& path, unsigned char size) {
    m_fonts["text"] = al_load_ttf_font(path.c_str(), size, 0) ;
}

void MenuScreen::setTextColor(unsigned char red,
                  unsigned char green,
                  unsigned char blue,
                  unsigned char alpha) {
    m_colors["text"] = al_map_rgba(red, green, blue, alpha) ;
}
