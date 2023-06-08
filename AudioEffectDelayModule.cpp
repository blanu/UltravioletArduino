//
//  AudioEffectDelayModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectDelayModule.h"

AudioEffectDelayResponse *AudioEffectDelayModule::handle(AudioEffectDelayRequest *request)
{
    switch (request->type)
    {
        case AudioEffectDelayRequest_DELAY:
            {
                AudioEffectDelayDelayRequest *parameters = (AudioEffectDelayDelayRequest *)request->body;
                this->logic->delay(parameters->channel, parameters->milliseconds);
                
                Serial.println("AudioEffectDelay.delay -> void");
                return new AudioEffectDelayResponse(AudioEffectDelayRequest_DELAY, NULL);
            }

        case AudioEffectDelayRequest_DISABLE:
            {
                AudioEffectDelayDisableRequest *parameters = (AudioEffectDelayDisableRequest *)request->body;
                this->logic->disable(parameters->channel);
                
                Serial.println("AudioEffectDelay.disable -> void");
                return new AudioEffectDelayResponse(AudioEffectDelayRequest_DISABLE, NULL);
            }
    }

    return new AudioEffectDelayResponse(AudioEffectDelayResponse_ERROR, NULL);
};