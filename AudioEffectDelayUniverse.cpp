//
//  AudioEffectDelayUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectDelayUniverse.h"

void AudioEffectDelayUniverse::delay(uint8_t channel, float milliseconds)
{
    AudioEffectDelayDelayRequest *requestBody = new AudioEffectDelayDelayRequest(channel, milliseconds);
    AudioEffectDelayRequest *request = new AudioEffectDelayRequest(AudioEffectDelayRequest_DELAY, (void *)requestBody);
    AudioEffectDelayResponse *response = this->module->handle(request);
    if (response->type == AudioEffectDelayResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectDelay.delay(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectDelayUniverse::disable(uint8_t channel)
{
    AudioEffectDelayDisableRequest *requestBody = new AudioEffectDelayDisableRequest(channel);
    AudioEffectDelayRequest *request = new AudioEffectDelayRequest(AudioEffectDelayRequest_DISABLE, (void *)requestBody);
    AudioEffectDelayResponse *response = this->module->handle(request);
    if (response->type == AudioEffectDelayResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectDelay.disable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}