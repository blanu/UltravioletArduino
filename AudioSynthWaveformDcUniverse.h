//
// AudioSynthWaveformDcUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformDcUniverse_h_
#define AudioSynthWaveformDcUniverse_h_

#include "AudioSynthWaveformDcMessages.h"
#include "AudioSynthWaveformDcModule.h"

class AudioSynthWaveformDcUniverse
{
    public:
        AudioSynthWaveformDcUniverse(AudioSynthWaveformDcModule *handler) : module(handler) {}

        AudioSynthWaveformDcModule *module;

        void amplitude(float n);
        float read();
};

#endif