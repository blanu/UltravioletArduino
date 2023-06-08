//
// AudioEffectDelayExternalModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayExternalModule_h_
#define AudioEffectDelayExternalModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectDelayExternalMessages.h"

class AudioEffectDelayExternalModule
{
    public:
        AudioEffectDelayExternalModule(AudioEffectDelayExternal *component) : logic(component) {}

        AudioEffectDelayExternal *logic;
        AudioEffectDelayExternalResponse *handle(AudioEffectDelayExternalRequest *request);
};

#endif