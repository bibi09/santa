#include "RuleScreenLevel1.h"
#include "../Level1.h"
#include "../../../tools/managers/ScreenManager.h"

using namespace std ;

const string RuleScreenLevel1::Title = "Level One" ;
const string RuleScreenLevel1::Text = "Your first mission is to help Santa to find the good gifts. Get 500 points !" ;


RuleScreenLevel1::RuleScreenLevel1() : RuleScreen(Title, Text) {
    setButtonAction(new PlayAction()) ;
}

RuleScreenLevel1::~RuleScreenLevel1() {}


void RuleScreenLevel1::PlayAction::run() {
    ScreenManager::getInstance() -> replaceScreen(new Level1()) ;
}
