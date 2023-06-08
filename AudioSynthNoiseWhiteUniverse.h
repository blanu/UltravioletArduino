//
// AudioSynthNoiseWhiteUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoiseWhiteUniverse_h_
#define AudioSynthNoiseWhiteUniverse_h_

#include "AudioSynthNoiseWhiteMessages.h"
#include "AudioSynthNoiseWhiteModule.h"

class AudioSynthNoiseWhiteUniverse
{
    public:
        AudioSynthNoiseWhiteUniverse(AudioSynthNoiseWhiteModule *handler) : module(handler) {}

        AudioSynthNoiseWhiteModule *module;

        void amplitude(float n);
};

#endif