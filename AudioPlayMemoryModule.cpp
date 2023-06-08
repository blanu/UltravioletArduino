//
//  AudioPlayMemoryModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayMemoryModule.h"

AudioPlayMemoryResponse *AudioPlayMemoryModule::handle(AudioPlayMemoryRequest *request)
{
    switch (request->type)
    {
        case AudioPlayMemoryRequest_STOP:
            {
                
                this->logic->stop();
                
                Serial.println("AudioPlayMemory.stop -> void");
                return new AudioPlayMemoryResponse(AudioPlayMemoryRequest_STOP, NULL);
            }

        case AudioPlayMemoryRequest_POSITIONMILLIS:
            {
                
                uint32_t result = this->logic->positionMillis();
                AudioPlayMemoryPositionmillisResponse response = AudioPlayMemoryPositionmillisResponse(result);
                Serial.println("AudioPlayMemory.positionMillis -> uint32_t");
                return new AudioPlayMemoryResponse(AudioPlayMemoryRequest_POSITIONMILLIS, (void *)&response);
            }

        case AudioPlayMemoryRequest_LENGTHMILLIS:
            {
                
                uint32_t result = this->logic->lengthMillis();
                AudioPlayMemoryLengthmillisResponse response = AudioPlayMemoryLengthmillisResponse(result);
                Serial.println("AudioPlayMemory.lengthMillis -> uint32_t");
                return new AudioPlayMemoryResponse(AudioPlayMemoryRequest_LENGTHMILLIS, (void *)&response);
            }
    }

    return new AudioPlayMemoryResponse(AudioPlayMemoryResponse_ERROR, NULL);
};