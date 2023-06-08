//
// AudioPlayFSWavModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayFSWavModule_h_
#define AudioPlayFSWavModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioPlayFSWavMessages.h"

class AudioPlayFSWavModule
{
    public:
        AudioPlayFSWavModule(AudioPlayFSWav *component) : logic(component) {}

        AudioPlayFSWav *logic;
        AudioPlayFSWavResponse *handle(AudioPlayFSWavRequest *request);
};

#endif