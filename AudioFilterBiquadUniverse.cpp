//
//  AudioFilterBiquadUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterBiquadUniverse.h"

void AudioFilterBiquadUniverse::setLowpass(uint32_t stage, float frequency, float q = 0.7071)
{
    AudioFilterBiquadSetlowpassRequest *requestBody = new AudioFilterBiquadSetlowpassRequest(stage, frequency, 0.7071);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETLOWPASS, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setLowpass(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterBiquadUniverse::setHighpass(uint32_t stage, float frequency, float q = 0.7071)
{
    AudioFilterBiquadSethighpassRequest *requestBody = new AudioFilterBiquadSethighpassRequest(stage, frequency, 0.7071);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETHIGHPASS, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setHighpass(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterBiquadUniverse::setBandpass(uint32_t stage, float frequency, float q = 1.0)
{
    AudioFilterBiquadSetbandpassRequest *requestBody = new AudioFilterBiquadSetbandpassRequest(stage, frequency, 1.0);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETBANDPASS, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setBandpass(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterBiquadUniverse::setNotch(uint32_t stage, float frequency, float q = 1.0)
{
    AudioFilterBiquadSetnotchRequest *requestBody = new AudioFilterBiquadSetnotchRequest(stage, frequency, 1.0);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETNOTCH, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setNotch(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterBiquadUniverse::setLowShelf(uint32_t stage, float frequency, float gain, float slope = 1.0f)
{
    AudioFilterBiquadSetlowshelfRequest *requestBody = new AudioFilterBiquadSetlowshelfRequest(stage, frequency, gain, 1.0f);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETLOWSHELF, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setLowShelf(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterBiquadUniverse::setHighShelf(uint32_t stage, float frequency, float gain, float slope = 1.0f)
{
    AudioFilterBiquadSethighshelfRequest *requestBody = new AudioFilterBiquadSethighshelfRequest(stage, frequency, gain, 1.0f);
    AudioFilterBiquadRequest *request = new AudioFilterBiquadRequest(AudioFilterBiquadRequest_SETHIGHSHELF, (void *)requestBody);
    AudioFilterBiquadResponse *response = this->module->handle(request);
    if (response->type == AudioFilterBiquadResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterBiquad.setHighShelf(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}