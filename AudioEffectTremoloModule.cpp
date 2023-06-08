//
//  AudioEffectTremoloModule.cpp
//
//
//  Created by Clockwork on Jun 5, 2023.
//

#include "AudioEffectTremoloModule.h"

AudioEffectTremoloResponse *AudioEffectTremoloModule::handle(AudioEffectTremoloRequest *request)
{
    switch (request->type)
    {
        case AudioEffectTremoloRequest_BEGIN:
            {
                AudioEffectTremoloBeginRequest *parameters = (AudioEffectTremoloBeginRequest *)request->body;
                this->logic->begin(parameters->milliseconds);
                
                Serial.println("AudioEffectTremolo.begin -> void");
                return new AudioEffectTremoloResponse(AudioEffectTremoloRequest_BEGIN, NULL);
            }
    }

    return new AudioEffectTremoloResponse(AudioEffectTremoloResponse_ERROR, NULL);
};