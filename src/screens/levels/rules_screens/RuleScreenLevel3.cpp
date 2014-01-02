#include "RuleScreenLevel3.h"
#include "../Level3.h"
#include "../../../tools/managers/ScreenManager.h"

using namespace std ;

const string RuleScreenLevel3::Title = "Level Three" ;
const string RuleScreenLevel3::Text = "Wonderful !... Argh, imps get hungry and angry ! Do not touch them or they won't want to assist Santa Claus. Christmas couldn't exist anymore if a such thing happened... Try to collect ten cookies to let cooler heads prevail." ;


RuleScreenLevel3::RuleScreenLevel3() : RuleScreen(Title, Text) {
    setButtonAction(new PlayAction()) ;
}

RuleScreenLevel3::~RuleScreenLevel3() {}


void RuleScreenLevel3::PlayAction::run() {
    ScreenManager::getInstance() -> replaceScreen(new Level3()) ;
}
