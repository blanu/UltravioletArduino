//
//  AudioPlaySdRawUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlaySdRawUniverse.h"

void AudioPlaySdRawUniverse::begin()
{
    AudioPlaySdRawRequest *request = new AudioPlaySdRawRequest(AudioPlaySdRawRequest_BEGIN, NULL);
    AudioPlaySdRawResponse *response = this->module->handle(request);
    if (response->type == AudioPlaySdRawResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlaySdRaw.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

void AudioPlaySdRawUniverse::stop()
{
    AudioPlaySdRawRequest *request = new AudioPlaySdRawRequest(AudioPlaySdRawRequest_STOP, NULL);
    AudioPlaySdRawResponse *response = this->module->handle(request);
    if (response->type == AudioPlaySdRawResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlaySdRaw.stop(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

uint32_t AudioPlaySdRawUniverse::positionMillis()
{
    AudioPlaySdRawRequest *request = new AudioPlaySdRawRequest(AudioPlaySdRawRequest_POSITIONMILLIS, NULL);
    AudioPlaySdRawResponse *response = this->module->handle(request);
    if (response->type == AudioPlaySdRawResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlaySdRaw.positionMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlaySdRawPositionmillisResponse *result = (AudioPlaySdRawPositionmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

uint32_t AudioPlaySdRawUniverse::lengthMillis()
{
    AudioPlaySdRawRequest *request = new AudioPlaySdRawRequest(AudioPlaySdRawRequest_LENGTHMILLIS, NULL);
    AudioPlaySdRawResponse *response = this->module->handle(request);
    if (response->type == AudioPlaySdRawResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlaySdRaw.lengthMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlaySdRawLengthmillisResponse *result = (AudioPlaySdRawLengthmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}