//
// AudioSynthNoisePinkUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoisePinkUniverse_h_
#define AudioSynthNoisePinkUniverse_h_

#include "AudioSynthNoisePinkMessages.h"
#include "AudioSynthNoisePinkModule.h"

class AudioSynthNoisePinkUniverse
{
    public:
        AudioSynthNoisePinkUniverse(AudioSynthNoisePinkModule *handler) : module(handler) {}

        AudioSynthNoisePinkModule *module;

        void amplitude(float n);
};

#endif