//
// AudioEffectDelayExternalUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayExternalUniverse_h_
#define AudioEffectDelayExternalUniverse_h_

#include "AudioEffectDelayExternalMessages.h"
#include "AudioEffectDelayExternalModule.h"

class AudioEffectDelayExternalUniverse
{
    public:
        AudioEffectDelayExternalUniverse(AudioEffectDelayExternalModule *handler) : module(handler) {}

        AudioEffectDelayExternalModule *module;

        void delay(uint8_t channel, float milliseconds);
        void disable(uint8_t channel);
};

#endif