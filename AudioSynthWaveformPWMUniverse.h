//
// AudioSynthWaveformPWMUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformPWMUniverse_h_
#define AudioSynthWaveformPWMUniverse_h_

#include "AudioSynthWaveformPWMMessages.h"
#include "AudioSynthWaveformPWMModule.h"

class AudioSynthWaveformPWMUniverse
{
    public:
        AudioSynthWaveformPWMUniverse(AudioSynthWaveformPWMModule *handler) : module(handler) {}

        AudioSynthWaveformPWMModule *module;

        void frequency(float freq);
        void amplitude(float n);
};

#endif