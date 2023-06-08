//
// AudioRecordQueueUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioRecordQueueUniverse_h_
#define AudioRecordQueueUniverse_h_

#include "AudioRecordQueueMessages.h"
#include "AudioRecordQueueModule.h"

class AudioRecordQueueUniverse
{
    public:
        AudioRecordQueueUniverse(AudioRecordQueueModule *handler) : module(handler) {}

        AudioRecordQueueModule *module;

        void begin();
        int available();
        void clear();
        void freeBuffer();
        void end();
};

#endif