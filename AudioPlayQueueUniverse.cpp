//
//  AudioPlayQueueUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayQueueUniverse.h"

void AudioPlayQueueUniverse::play(int16_t data)
{
    AudioPlayQueuePlayRequest *requestBody = new AudioPlayQueuePlayRequest(data);
    AudioPlayQueueRequest *request = new AudioPlayQueueRequest(AudioPlayQueueRequest_PLAY, (void *)requestBody);
    AudioPlayQueueResponse *response = this->module->handle(request);
    if (response->type == AudioPlayQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayQueue.play(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

bool AudioPlayQueueUniverse::available()
{
    AudioPlayQueueRequest *request = new AudioPlayQueueRequest(AudioPlayQueueRequest_AVAILABLE, NULL);
    AudioPlayQueueResponse *response = this->module->handle(request);
    if (response->type == AudioPlayQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayQueue.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioPlayQueueAvailableResponse *result = (AudioPlayQueueAvailableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

void AudioPlayQueueUniverse::playBuffer()
{
    AudioPlayQueueRequest *request = new AudioPlayQueueRequest(AudioPlayQueueRequest_PLAYBUFFER, NULL);
    AudioPlayQueueResponse *response = this->module->handle(request);
    if (response->type == AudioPlayQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayQueue.playBuffer(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

void AudioPlayQueueUniverse::stop()
{
    AudioPlayQueueRequest *request = new AudioPlayQueueRequest(AudioPlayQueueRequest_STOP, NULL);
    AudioPlayQueueResponse *response = this->module->handle(request);
    if (response->type == AudioPlayQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioPlayQueue.stop(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}