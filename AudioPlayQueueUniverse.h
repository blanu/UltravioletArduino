//
// AudioPlayQueueUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayQueueUniverse_h_
#define AudioPlayQueueUniverse_h_

#include "AudioPlayQueueMessages.h"
#include "AudioPlayQueueModule.h"

class AudioPlayQueueUniverse
{
    public:
        AudioPlayQueueUniverse(AudioPlayQueueModule *handler) : module(handler) {}

        AudioPlayQueueModule *module;

        void play(int16_t data);
        bool available();
        void playBuffer();
        void stop();
};

#endif