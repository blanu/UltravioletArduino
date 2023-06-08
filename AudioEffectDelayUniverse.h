//
// AudioEffectDelayUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayUniverse_h_
#define AudioEffectDelayUniverse_h_

#include "AudioEffectDelayMessages.h"
#include "AudioEffectDelayModule.h"

class AudioEffectDelayUniverse
{
    public:
        AudioEffectDelayUniverse(AudioEffectDelayModule *handler) : module(handler) {}

        AudioEffectDelayModule *module;

        void delay(uint8_t channel, float milliseconds);
        void disable(uint8_t channel);
};

#endif