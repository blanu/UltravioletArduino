//
// AudioEffectEnvelopeModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectEnvelopeModule_h_
#define AudioEffectEnvelopeModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectEnvelopeMessages.h"

class AudioEffectEnvelopeModule
{
    public:
        AudioEffectEnvelopeModule(AudioEffectEnvelope *component) : logic(component) {}

        AudioEffectEnvelope *logic;
        AudioEffectEnvelopeResponse *handle(AudioEffectEnvelopeRequest *request);
};

#endif