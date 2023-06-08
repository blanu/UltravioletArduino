//
//  AudioOutputI2SModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioOutputI2SModule.h"

AudioOutputI2SResponse *AudioOutputI2SModule::handle(AudioOutputI2SRequest *request)
{
    switch (request->type)
    {
        case AudioOutputI2SRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioOutputI2S.begin -> void");
                return new AudioOutputI2SResponse(AudioOutputI2SRequest_BEGIN, NULL);
            }
    }

    return new AudioOutputI2SResponse(AudioOutputI2SResponse_ERROR, NULL);
};