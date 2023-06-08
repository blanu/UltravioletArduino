//
//  AudioSynthNoisePinkUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthNoisePinkUniverse.h"

void AudioSynthNoisePinkUniverse::amplitude(float n)
{
    AudioSynthNoisePinkAmplitudeRequest *requestBody = new AudioSynthNoisePinkAmplitudeRequest(n);
    AudioSynthNoisePinkRequest *request = new AudioSynthNoisePinkRequest(AudioSynthNoisePinkRequest_AMPLITUDE, (void *)requestBody);
    AudioSynthNoisePinkResponse *response = this->module->handle(request);
    if (response->type == AudioSynthNoisePinkResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthNoisePink.amplitude(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}