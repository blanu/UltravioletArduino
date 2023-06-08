//
//  AudioPlayMemoryUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayMemoryUniverse.h"

void AudioPlayMemoryUniverse::stop()
{
    AudioPlayMemoryRequest *request = new AudioPlayMemoryRequest(AudioPlayMemoryRequest_STOP, NULL);
    AudioPlayMemoryResponse *response = this->module->handle(request);
    if (response->type == AudioPlayMemoryResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayMemory.stop(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

uint32_t AudioPlayMemoryUniverse::positionMillis()
{
    AudioPlayMemoryRequest *request = new AudioPlayMemoryRequest(AudioPlayMemoryRequest_POSITIONMILLIS, NULL);
    AudioPlayMemoryResponse *response = this->module->handle(request);
    if (response->type == AudioPlayMemoryResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayMemory.positionMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayMemoryPositionmillisResponse *result = (AudioPlayMemoryPositionmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

uint32_t AudioPlayMemoryUniverse::lengthMillis()
{
    AudioPlayMemoryRequest *request = new AudioPlayMemoryRequest(AudioPlayMemoryRequest_LENGTHMILLIS, NULL);
    AudioPlayMemoryResponse *response = this->module->handle(request);
    if (response->type == AudioPlayMemoryResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayMemory.lengthMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayMemoryLengthmillisResponse *result = (AudioPlayMemoryLengthmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}