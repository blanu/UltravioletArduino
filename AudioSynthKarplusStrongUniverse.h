//
// AudioSynthKarplusStrongUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthKarplusStrongUniverse_h_
#define AudioSynthKarplusStrongUniverse_h_

#include "AudioSynthKarplusStrongMessages.h"
#include "AudioSynthKarplusStrongModule.h"

class AudioSynthKarplusStrongUniverse
{
    public:
        AudioSynthKarplusStrongUniverse(AudioSynthKarplusStrongModule *handler) : module(handler) {}

        AudioSynthKarplusStrongModule *module;

        void noteOn(float frequency, float velocity);
        void noteOff(float velocity);
};

#endif