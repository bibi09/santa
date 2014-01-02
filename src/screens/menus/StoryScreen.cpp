#include "StoryScreen.h"
#include "GameplayScreen.h"
#include "../gui/buttons/AlButtonBitmap.h"
#include "../gui/labels/AlLabel.h"
#include "../levels/rules_screens/RuleScreenLevel1.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"
#include <iostream>

using namespace std ;


StoryScreen::StoryScreen() : MenuScreen("bg_intro",
                                        "intro",
                                        false,
                                        "It is Christmas, yet...") {
    #ifdef DEBUG
    Logger::print("StoryScreen initialization") ;
    #endif

    /** Set fonts and colors for texts **/
    setTitleFont("media/fonts/musicals.ttf", 32) ;
    setTitleColor(255, 255, 255, 255) ;
    setTextFont("media/fonts/amperzand.ttf", 26) ;
    setTextColor(255, 255, 255, 255) ;

    /** Set the text of the story */
    string story ;
    story = "Santa Claus is so foodie he hasn't seen his imps making some " ;
    story += "jokes. They have mixed up all the gifts !" ;
    addText(story, Position(20.f, 100.f)) ;

    story = "The imps have put bangers into the gifts and some others are " ;
    story += "very dangerous too. Children cannot receive them!..." ;
    addText(story, Position(20.f, 200.f)) ;

    story = "Help Santa Claus to find the good ones. Be careful..." ;
    addText(story, Position(20.f, 300.f)) ;


    /** Set the buttons. */
    string sprite ;
    AlButtonBitmap* button ;

    sprite = "play_button" ;
    button = new AlButtonBitmap(Position(20.f, 380.f), sprite, new GoToLevel1Action()) ;
    addComponent(button) ;

    sprite = "howto_button" ;
    button = new AlButtonBitmap(Position(290.f, 380.f), sprite, new GoToGameplayAction()) ;
    addComponent(button) ;
}

StoryScreen::~StoryScreen() {}



void StoryScreen::GoToGameplayAction::run() {
    ScreenManager::getInstance() -> pushScreen(new GameplayScreen()) ;
}

void StoryScreen::GoToLevel1Action::run() {
    ScreenManager::getInstance() -> pushScreen(new RuleScreenLevel1()) ;
}
