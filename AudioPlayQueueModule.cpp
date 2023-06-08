//
//  AudioPlayQueueModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayQueueModule.h"

AudioPlayQueueResponse *AudioPlayQueueModule::handle(AudioPlayQueueRequest *request)
{
    switch (request->type)
    {
        case AudioPlayQueueRequest_PLAY:
            {
                AudioPlayQueuePlayRequest *parameters = (AudioPlayQueuePlayRequest *)request->body;
                this->logic->play(parameters->data);
                
                Serial.println("AudioPlayQueue.play -> void");
                return new AudioPlayQueueResponse(AudioPlayQueueRequest_PLAY, NULL);
            }

        case AudioPlayQueueRequest_AVAILABLE:
            {
                
                bool result = this->logic->available();
                AudioPlayQueueAvailableResponse response = AudioPlayQueueAvailableResponse(result);
                Serial.println("AudioPlayQueue.available -> bool");
                return new AudioPlayQueueResponse(AudioPlayQueueRequest_AVAILABLE, (void *)&response);
            }

        case AudioPlayQueueRequest_PLAYBUFFER:
            {
                
                this->logic->playBuffer();
                
                Serial.println("AudioPlayQueue.playBuffer -> void");
                return new AudioPlayQueueResponse(AudioPlayQueueRequest_PLAYBUFFER, NULL);
            }

        case AudioPlayQueueRequest_STOP:
            {
                
                this->logic->stop();
                
                Serial.println("AudioPlayQueue.stop -> void");
                return new AudioPlayQueueResponse(AudioPlayQueueRequest_STOP, NULL);
            }
    }

    return new AudioPlayQueueResponse(AudioPlayQueueResponse_ERROR, NULL);
};