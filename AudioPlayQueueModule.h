//
// AudioPlayQueueModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayQueueModule_h_
#define AudioPlayQueueModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioPlayQueueMessages.h"

class AudioPlayQueueModule
{
    public:
        AudioPlayQueueModule(AudioPlayQueue *component) : logic(component) {}

        AudioPlayQueue *logic;
        AudioPlayQueueResponse *handle(AudioPlayQueueRequest *request);
};

#endif