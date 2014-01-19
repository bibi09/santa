#include "Window.h"
#include "Logger.h"
#include <allegro5/allegro_image.h>
#include <string>

using namespace std ;

Window::Window(int sizeX, int sizeY) : m_display(0) {
	assert(al_init()) ;

    #ifdef DEBUG
    Logger::print("Set up display") ;
    #endif

    m_fullscreen = false ;
	m_display = al_create_display(sizeX, sizeY) ;
	assert(m_display != 0) ;
	assert(al_init_image_addon()) ;
	al_clear_to_color(al_map_rgb(0,0,0)) ;
	refresh() ;
}


Window::~Window() {
    al_destroy_display(m_display) ;
}

void Window::refresh() {
	al_flip_display() ;
}

void Window::switchFullscreen() {
    m_fullscreen = !m_fullscreen ;
    al_toggle_display_flag(m_display, ALLEGRO_FULLSCREEN_WINDOW, m_fullscreen) ;
}

ALLEGRO_DISPLAY* Window::getDisplay() {
	return m_display ;
}

/** @brief  Get the width of the displaying window. */
int Window::getWidth() {
    return al_get_display_width(m_display) ;
}

/** @brief  Get the height of the displaying window. */
int Window::getHeight() {
    return al_get_display_height(m_display) ;
}
