//
//  AudioEffectBitcrusherUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectBitcrusherUniverse.h"

void AudioEffectBitcrusherUniverse::bits(uint8_t b)
{
    AudioEffectBitcrusherBitsRequest *requestBody = new AudioEffectBitcrusherBitsRequest(b);
    AudioEffectBitcrusherRequest *request = new AudioEffectBitcrusherRequest(AudioEffectBitcrusherRequest_BITS, (void *)requestBody);
    AudioEffectBitcrusherResponse *response = this->module->handle(request);
    if (response->type == AudioEffectBitcrusherResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectBitcrusher.bits(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectBitcrusherUniverse::sampleRate(float hz)
{
    AudioEffectBitcrusherSamplerateRequest *requestBody = new AudioEffectBitcrusherSamplerateRequest(hz);
    AudioEffectBitcrusherRequest *request = new AudioEffectBitcrusherRequest(AudioEffectBitcrusherRequest_SAMPLERATE, (void *)requestBody);
    AudioEffectBitcrusherResponse *response = this->module->handle(request);
    if (response->type == AudioEffectBitcrusherResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectBitcrusher.sampleRate(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}