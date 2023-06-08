//
// AudioPlayFSWavUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayFSWavUniverse_h_
#define AudioPlayFSWavUniverse_h_

#include "AudioPlayFSWavMessages.h"
#include "AudioPlayFSWavModule.h"

class AudioPlayFSWavUniverse
{
    public:
        AudioPlayFSWavUniverse(AudioPlayFSWavModule *handler) : module(handler) {}

        AudioPlayFSWavModule *module;

        void begin();
        bool isPlaying();
        uint32_t positionMillis();
        uint32_t lengthMillis();
};

#endif