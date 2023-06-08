//
//  AudioPlayFSWavUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayFSWavUniverse.h"

void AudioPlayFSWavUniverse::begin()
{
    AudioPlayFSWavRequest *request = new AudioPlayFSWavRequest(AudioPlayFSWavRequest_BEGIN, NULL);
    AudioPlayFSWavResponse *response = this->module->handle(request);
    if (response->type == AudioPlayFSWavResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayFSWav.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

bool AudioPlayFSWavUniverse::isPlaying()
{
    AudioPlayFSWavRequest *request = new AudioPlayFSWavRequest(AudioPlayFSWavRequest_ISPLAYING, NULL);
    AudioPlayFSWavResponse *response = this->module->handle(request);
    if (response->type == AudioPlayFSWavResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayFSWav.isPlaying(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayFSWavIsplayingResponse *result = (AudioPlayFSWavIsplayingResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

uint32_t AudioPlayFSWavUniverse::positionMillis()
{
    AudioPlayFSWavRequest *request = new AudioPlayFSWavRequest(AudioPlayFSWavRequest_POSITIONMILLIS, NULL);
    AudioPlayFSWavResponse *response = this->module->handle(request);
    if (response->type == AudioPlayFSWavResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayFSWav.positionMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayFSWavPositionmillisResponse *result = (AudioPlayFSWavPositionmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

uint32_t AudioPlayFSWavUniverse::lengthMillis()
{
    AudioPlayFSWavRequest *request = new AudioPlayFSWavRequest(AudioPlayFSWavRequest_LENGTHMILLIS, NULL);
    AudioPlayFSWavResponse *response = this->module->handle(request);
    if (response->type == AudioPlayFSWavResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayFSWav.lengthMillis(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayFSWavLengthmillisResponse *result = (AudioPlayFSWavLengthmillisResponse *)response->body;
    uint32_t returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}