#ifndef __RULE_SCREEN_LEVEL_TWO_H__
#define __RULE_SCREEN_LEVEL_TWO_H__

#include "RuleScreen.h"
#include <string>

class RuleScreenLevel2 : public RuleScreen {
    private:
        /** @brief  Title of the screen. */
        static const std::string Title ;
        /** @brief  Text of the rule. */
        static const std::string Text ;

    public:
        /** @brief  Create a RuleScreenLevel2. */
        RuleScreenLevel2() ;

        /** @brief  Destroy a RuleScreenLevel2. */
        virtual ~RuleScreenLevel2() ;


    private:
        /**
         * @brief   Action to play the level.
         * @author  Denis CARLUS
         */
        class PlayAction : public AlAbstractAction {
            /** @brief  Run the action. */
            virtual void run() ;
        } ;
} ;

#endif
