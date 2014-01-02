#include "EndScreen.h"
#include "GameplayScreen.h"
#include "../gui/buttons/AlButtonBitmap.h"
#include "../gui/labels/AlLabel.h"
#include "../levels/rules_screens/RuleScreenLevel1.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"
#include <iostream>

using namespace std ;


EndScreen::EndScreen() : MenuScreen("bg_intro",
                                    "intro",
                                    false,
                                    "Oh oh oh !") {
    #ifdef DEBUG
    Logger::print("EndScreen initialization") ;
    #endif

    /** Set fonts and colors for texts **/
    setTitleFont("media/fonts/musicals.ttf", 32) ;
    setTitleColor(255, 255, 255, 255) ;
    setTextFont("media/fonts/amperzand.ttf", 26) ;
    setTextColor(255, 255, 255, 255) ;

    /** Set the text of the story */
    string story ;
    story = "Well done! Everything is now OK. Santa is ready to give all the " ;
    story += "gifts to well-behaved children." ;
    addText(story, Position(20.f, 100.f)) ;


    /** Set the buttons. */
    string sprite ;
    AlButtonBitmap* button ;

    sprite = "back_mainmenu_button" ;
    button = new AlButtonBitmap(Position(20.f, 380.f), sprite, new GoToMainMenuAction()) ;
    addComponent(button) ;
}

EndScreen::~EndScreen() {}



void EndScreen::GoToMainMenuAction::run() {
    ScreenManager::getInstance() -> previousScreen() ;
}
