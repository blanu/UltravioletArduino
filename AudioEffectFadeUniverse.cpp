//
//  AudioEffectFadeUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectFadeUniverse.h"

void AudioEffectFadeUniverse::fadeIn(uint32_t milliseconds)
{
    AudioEffectFadeFadeinRequest *requestBody = new AudioEffectFadeFadeinRequest(milliseconds);
    AudioEffectFadeRequest *request = new AudioEffectFadeRequest(AudioEffectFadeRequest_FADEIN, (void *)requestBody);
    AudioEffectFadeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectFadeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectFade.fadeIn(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectFadeUniverse::fadeOut(uint32_t milliseconds)
{
    AudioEffectFadeFadeoutRequest *requestBody = new AudioEffectFadeFadeoutRequest(milliseconds);
    AudioEffectFadeRequest *request = new AudioEffectFadeRequest(AudioEffectFadeRequest_FADEOUT, (void *)requestBody);
    AudioEffectFadeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectFadeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectFade.fadeOut(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}