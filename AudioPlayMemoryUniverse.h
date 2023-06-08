//
// AudioPlayMemoryUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayMemoryUniverse_h_
#define AudioPlayMemoryUniverse_h_

#include "AudioPlayMemoryMessages.h"
#include "AudioPlayMemoryModule.h"

class AudioPlayMemoryUniverse
{
    public:
        AudioPlayMemoryUniverse(AudioPlayMemoryModule *handler) : module(handler) {}

        AudioPlayMemoryModule *module;

        void stop();
        uint32_t positionMillis();
        uint32_t lengthMillis();
};

#endif