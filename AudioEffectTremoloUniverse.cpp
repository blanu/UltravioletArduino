//
//  AudioEffectTremoloUniverse.cpp
//
//
//  Created by Clockwork on Jun 5, 2023.
//

#include "AudioEffectTremoloUniverse.h"

void AudioEffectTremoloUniverse::begin(uint32_t milliseconds)
{
    AudioEffectTremoloBeginRequest *requestBody = new AudioEffectTremoloBeginRequest(milliseconds);
    AudioEffectTremoloRequest *request = new AudioEffectTremoloRequest(AudioEffectTremoloRequest_BEGIN, (void *)requestBody);
    AudioEffectTremoloResponse *response = this->module->handle(request);
    if (response->type == AudioEffectTremoloResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectTremolo.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}