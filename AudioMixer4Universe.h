//
// AudioMixer4Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioMixer4Universe_h_
#define AudioMixer4Universe_h_

#include "AudioMixer4Messages.h"
#include "AudioMixer4Module.h"

class AudioMixer4Universe
{
    public:
        AudioMixer4Universe(AudioMixer4Module *handler) : module(handler) {}

        AudioMixer4Module *module;

        void gain(unsigned int channel, float gain);
};

#endif