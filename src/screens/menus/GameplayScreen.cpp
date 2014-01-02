#include "GameplayScreen.h"
#include "../gui/buttons/AlButtonBitmap.h"
#include "../gui/labels/AlLabel.h"
#include "../levels/rules_screens/RuleScreenLevel1.h"
#include "../../tools/Logger.h"
#include "../../tools/managers/ScreenManager.h"
#include "../../tools/managers/SpriteManager.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std ;


GameplayScreen::GameplayScreen() : MenuScreen("bg_intro",
                                              "",
                                              false,
                                              "How to play...") {
    #ifdef DEBUG
    Logger::print("GameplayScreen initialization") ;
    #endif

    /** Set fonts and colors for texts **/
    setTitleFont("media/fonts/musicals.ttf", 32) ;
    setTitleColor(255, 255, 255, 255) ;
    setTextFont("media/fonts/amperzand.ttf", 26) ;
    setTextColor(255, 255, 255, 255) ;

    /** Set the text of the story */
    string rules ;
    rules = "Hit gifts and candies with your snowball to increase your score. " ;
    rules += "Some are harder than others. You will need to go faster to break " ;
    rules += "them!" ;
    addText(rules, Position(230.f, 70.f)) ;

    rules = "But avoid purple gifts, snow globes, imps and other elements! " ;
    rules += "They can have side effects, decrease your score and even worse..." ;
    addText(rules, Position(230.f, 270.f)) ;


    /** Set the buttons. */
    string sprite ;
    AlButtonBitmap* button ;

    sprite = "play_button" ;
    button = new AlButtonBitmap(Position(20.f, 380.f), sprite, new GoToLevel1Action()) ;
    addComponent(button) ;
}

GameplayScreen::~GameplayScreen() {}



void GameplayScreen::additionnalDisplay() {
    static SpriteManager* sm = SpriteManager::getInstance() ;
    static ALLEGRO_BITMAP* spriteRedGift = sm -> addSprite("items/red_gift") ;
    static ALLEGRO_BITMAP* spriteZuurstok = sm -> addSprite("items/zuurstok") ;
    static ALLEGRO_BITMAP* spriteBombGift = sm -> addSprite("items/bomb_gift") ;
    static ALLEGRO_BITMAP* spriteGnome = sm -> addSprite("items/gnome") ;

    al_draw_bitmap(spriteRedGift, 40.f, 100.f, 0) ;
    al_draw_bitmap(spriteZuurstok, 90.f, 150.f, 0) ;
    al_draw_bitmap(spriteGnome, 120.f, 300.f, 0) ;
    al_draw_bitmap(spriteBombGift, 30.f, 310.f, 0) ;

    MenuScreen::additionnalDisplay() ;
}


void GameplayScreen::GoToLevel1Action::run() {
    ScreenManager::getInstance() -> replaceScreen(new RuleScreenLevel1()) ;
}
