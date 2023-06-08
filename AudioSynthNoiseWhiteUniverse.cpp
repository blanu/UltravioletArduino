//
//  AudioSynthNoiseWhiteUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthNoiseWhiteUniverse.h"

void AudioSynthNoiseWhiteUniverse::amplitude(float n)
{
    AudioSynthNoiseWhiteAmplitudeRequest *requestBody = new AudioSynthNoiseWhiteAmplitudeRequest(n);
    AudioSynthNoiseWhiteRequest *request = new AudioSynthNoiseWhiteRequest(AudioSynthNoiseWhiteRequest_AMPLITUDE, (void *)requestBody);
    AudioSynthNoiseWhiteResponse *response = this->module->handle(request);
    if (response->type == AudioSynthNoiseWhiteResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthNoiseWhite.amplitude(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}