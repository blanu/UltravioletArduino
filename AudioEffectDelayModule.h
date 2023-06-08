//
// AudioEffectDelayModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayModule_h_
#define AudioEffectDelayModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectDelayMessages.h"

class AudioEffectDelayModule
{
    public:
        AudioEffectDelayModule(AudioEffectDelay *component) : logic(component) {}

        AudioEffectDelay *logic;
        AudioEffectDelayResponse *handle(AudioEffectDelayRequest *request);
};

#endif