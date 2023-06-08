//
// AudioEffectTremoloModule.h
//
//
//  Created by Clockwork on Jun 5, 2023.
//

#ifndef AudioEffectTremoloModule_h_
#define AudioEffectTremoloModule_h_

#include <Arduino.h>
#include "effect_tremolo.h"
#include "AudioEffectTremoloMessages.h"

class AudioEffectTremoloModule
{
    public:
        AudioEffectTremoloModule(AudioEffectTremolo *component) : logic(component) {}

        AudioEffectTremolo *logic;
        AudioEffectTremoloResponse *handle(AudioEffectTremoloRequest *request);
};

#endif
