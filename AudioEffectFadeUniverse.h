//
// AudioEffectFadeUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFadeUniverse_h_
#define AudioEffectFadeUniverse_h_

#include "AudioEffectFadeMessages.h"
#include "AudioEffectFadeModule.h"

class AudioEffectFadeUniverse
{
    public:
        AudioEffectFadeUniverse(AudioEffectFadeModule *handler) : module(handler) {}

        AudioEffectFadeModule *module;

        void fadeIn(uint32_t milliseconds);
        void fadeOut(uint32_t milliseconds);
};

#endif