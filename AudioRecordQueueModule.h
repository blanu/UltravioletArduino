//
// AudioRecordQueueModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioRecordQueueModule_h_
#define AudioRecordQueueModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioRecordQueueMessages.h"

class AudioRecordQueueModule
{
    public:
        AudioRecordQueueModule(AudioRecordQueue *component) : logic(component) {}

        AudioRecordQueue *logic;
        AudioRecordQueueResponse *handle(AudioRecordQueueRequest *request);
};

#endif