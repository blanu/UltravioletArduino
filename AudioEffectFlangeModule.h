//
// AudioEffectFlangeModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFlangeModule_h_
#define AudioEffectFlangeModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectFlangeMessages.h"

class AudioEffectFlangeModule
{
    public:
        AudioEffectFlangeModule(AudioEffectFlange *component) : logic(component) {}

        AudioEffectFlange *logic;
        AudioEffectFlangeResponse *handle(AudioEffectFlangeRequest *request);
};

#endif