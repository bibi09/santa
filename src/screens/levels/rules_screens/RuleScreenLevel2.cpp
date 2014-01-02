#include "RuleScreenLevel2.h"
#include "../Level2.h"
#include "../../../tools/managers/ScreenManager.h"

using namespace std ;

const string RuleScreenLevel2::Title = "Level Two" ;
const string RuleScreenLevel2::Text = "Congratulations ! You did it ! Yet, it's not the end... Five important gifts are missing. They are orange. Catch them before the imps ! Before you start, the orange gifts are very hard to cut, so move quickly your hand when you see one of them !" ;


RuleScreenLevel2::RuleScreenLevel2() : RuleScreen(Title, Text) {
    setButtonAction(new PlayAction()) ;
}

RuleScreenLevel2::~RuleScreenLevel2() {}


void RuleScreenLevel2::PlayAction::run() {
    ScreenManager::getInstance() -> replaceScreen(new Level2()) ;
}
