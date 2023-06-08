//
//  AudioInputI2SModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioInputI2SModule.h"

AudioInputI2SResponse *AudioInputI2SModule::handle(AudioInputI2SRequest *request)
{
    switch (request->type)
    {
        case AudioInputI2SRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioInputI2S.begin -> void");
                return new AudioInputI2SResponse(AudioInputI2SRequest_BEGIN, NULL);
            }
    }

    return new AudioInputI2SResponse(AudioInputI2SResponse_ERROR, NULL);
};