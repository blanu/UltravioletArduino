//
//  AudioRecordQueueModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioRecordQueueModule.h"

AudioRecordQueueResponse *AudioRecordQueueModule::handle(AudioRecordQueueRequest *request)
{
    switch (request->type)
    {
        case AudioRecordQueueRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioRecordQueue.begin -> void");
                return new AudioRecordQueueResponse(AudioRecordQueueRequest_BEGIN, NULL);
            }

        case AudioRecordQueueRequest_AVAILABLE:
            {
                
                int result = this->logic->available();
                AudioRecordQueueAvailableResponse response = AudioRecordQueueAvailableResponse(result);
                Serial.println("AudioRecordQueue.available -> int");
                return new AudioRecordQueueResponse(AudioRecordQueueRequest_AVAILABLE, (void *)&response);
            }

        case AudioRecordQueueRequest_CLEAR:
            {
                
                this->logic->clear();
                
                Serial.println("AudioRecordQueue.clear -> void");
                return new AudioRecordQueueResponse(AudioRecordQueueRequest_CLEAR, NULL);
            }

        case AudioRecordQueueRequest_FREEBUFFER:
            {
                
                this->logic->freeBuffer();
                
                Serial.println("AudioRecordQueue.freeBuffer -> void");
                return new AudioRecordQueueResponse(AudioRecordQueueRequest_FREEBUFFER, NULL);
            }

        case AudioRecordQueueRequest_END:
            {
                
                this->logic->end();
                
                Serial.println("AudioRecordQueue.end -> void");
                return new AudioRecordQueueResponse(AudioRecordQueueRequest_END, NULL);
            }
    }

    return new AudioRecordQueueResponse(AudioRecordQueueResponse_ERROR, NULL);
};