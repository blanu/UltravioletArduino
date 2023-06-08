//
//  AudioEffectDelayExternalUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectDelayExternalUniverse.h"

void AudioEffectDelayExternalUniverse::delay(uint8_t channel, float milliseconds)
{
    AudioEffectDelayExternalDelayRequest *requestBody = new AudioEffectDelayExternalDelayRequest(channel, milliseconds);
    AudioEffectDelayExternalRequest *request = new AudioEffectDelayExternalRequest(AudioEffectDelayExternalRequest_DELAY, (void *)requestBody);
    AudioEffectDelayExternalResponse *response = this->module->handle(request);
    if (response->type == AudioEffectDelayExternalResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectDelayExternal.delay(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectDelayExternalUniverse::disable(uint8_t channel)
{
    AudioEffectDelayExternalDisableRequest *requestBody = new AudioEffectDelayExternalDisableRequest(channel);
    AudioEffectDelayExternalRequest *request = new AudioEffectDelayExternalRequest(AudioEffectDelayExternalRequest_DISABLE, (void *)requestBody);
    AudioEffectDelayExternalResponse *response = this->module->handle(request);
    if (response->type == AudioEffectDelayExternalResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectDelayExternal.disable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}