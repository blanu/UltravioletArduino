//
// AudioSynthNoisePinkModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoisePinkModule_h_
#define AudioSynthNoisePinkModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthNoisePinkMessages.h"

class AudioSynthNoisePinkModule
{
    public:
        AudioSynthNoisePinkModule(AudioSynthNoisePink *component) : logic(component) {}

        AudioSynthNoisePink *logic;
        AudioSynthNoisePinkResponse *handle(AudioSynthNoisePinkRequest *request);
};

#endif