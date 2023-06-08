//
//  AudioEffectDelayExternalModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectDelayExternalModule.h"

AudioEffectDelayExternalResponse *AudioEffectDelayExternalModule::handle(AudioEffectDelayExternalRequest *request)
{
    switch (request->type)
    {
        case AudioEffectDelayExternalRequest_DELAY:
            {
                AudioEffectDelayExternalDelayRequest *parameters = (AudioEffectDelayExternalDelayRequest *)request->body;
                this->logic->delay(parameters->channel, parameters->milliseconds);
                
                Serial.println("AudioEffectDelayExternal.delay -> void");
                return new AudioEffectDelayExternalResponse(AudioEffectDelayExternalRequest_DELAY, NULL);
            }

        case AudioEffectDelayExternalRequest_DISABLE:
            {
                AudioEffectDelayExternalDisableRequest *parameters = (AudioEffectDelayExternalDisableRequest *)request->body;
                this->logic->disable(parameters->channel);
                
                Serial.println("AudioEffectDelayExternal.disable -> void");
                return new AudioEffectDelayExternalResponse(AudioEffectDelayExternalRequest_DISABLE, NULL);
            }
    }

    return new AudioEffectDelayExternalResponse(AudioEffectDelayExternalResponse_ERROR, NULL);
};