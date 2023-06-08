//
// AudioEffectReverbModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectReverbModule_h_
#define AudioEffectReverbModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectReverbMessages.h"

class AudioEffectReverbModule
{
    public:
        AudioEffectReverbModule(AudioEffectReverb *component) : logic(component) {}

        AudioEffectReverb *logic;
        AudioEffectReverbResponse *handle(AudioEffectReverbRequest *request);
};

#endif