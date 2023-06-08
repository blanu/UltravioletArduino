//
// AudioEffectFadeModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFadeModule_h_
#define AudioEffectFadeModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectFadeMessages.h"

class AudioEffectFadeModule
{
    public:
        AudioEffectFadeModule(AudioEffectFade *component) : logic(component) {}

        AudioEffectFade *logic;
        AudioEffectFadeResponse *handle(AudioEffectFadeRequest *request);
};

#endif