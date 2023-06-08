//
// AudioPlaySdRawUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlaySdRawUniverse_h_
#define AudioPlaySdRawUniverse_h_

#include "AudioPlaySdRawMessages.h"
#include "AudioPlaySdRawModule.h"

class AudioPlaySdRawUniverse
{
    public:
        AudioPlaySdRawUniverse(AudioPlaySdRawModule *handler) : module(handler) {}

        AudioPlaySdRawModule *module;

        void begin();
        void stop();
        uint32_t positionMillis();
        uint32_t lengthMillis();
};

#endif