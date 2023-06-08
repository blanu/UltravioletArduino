//
// AudioSynthWaveformUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformUniverse_h_
#define AudioSynthWaveformUniverse_h_

#include "AudioSynthWaveformMessages.h"
#include "AudioSynthWaveformModule.h"

class AudioSynthWaveformUniverse
{
    public:
        AudioSynthWaveformUniverse(AudioSynthWaveformModule *handler) : module(handler) {}

        AudioSynthWaveformModule *module;

        void frequency(float t_freq);
        void phase(float angle);
        void offset(float n);
        void begin(short t_type);
};

#endif