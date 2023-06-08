//
// AudioSynthWaveformSineUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformSineUniverse_h_
#define AudioSynthWaveformSineUniverse_h_

#include "AudioSynthWaveformSineMessages.h"
#include "AudioSynthWaveformSineModule.h"

class AudioSynthWaveformSineUniverse
{
    public:
        AudioSynthWaveformSineUniverse(AudioSynthWaveformSineModule *handler) : module(handler) {}

        AudioSynthWaveformSineModule *module;

        void frequency(float freq);
        void phase(float angle);
        void amplitude(float n);
};

#endif