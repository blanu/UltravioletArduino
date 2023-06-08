//
// AudioPlayMemoryModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayMemoryModule_h_
#define AudioPlayMemoryModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioPlayMemoryMessages.h"

class AudioPlayMemoryModule
{
    public:
        AudioPlayMemoryModule(AudioPlayMemory *component) : logic(component) {}

        AudioPlayMemory *logic;
        AudioPlayMemoryResponse *handle(AudioPlayMemoryRequest *request);
};

#endif