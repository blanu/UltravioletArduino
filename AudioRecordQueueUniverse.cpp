//
//  AudioRecordQueueUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioRecordQueueUniverse.h"

void AudioRecordQueueUniverse::begin()
{
    AudioRecordQueueRequest *request = new AudioRecordQueueRequest(AudioRecordQueueRequest_BEGIN, NULL);
    AudioRecordQueueResponse *response = this->module->handle(request);
    if (response->type == AudioRecordQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioRecordQueue.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

int AudioRecordQueueUniverse::available()
{
    AudioRecordQueueRequest *request = new AudioRecordQueueRequest(AudioRecordQueueRequest_AVAILABLE, NULL);
    AudioRecordQueueResponse *response = this->module->handle(request);
    if (response->type == AudioRecordQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioRecordQueue.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioRecordQueueAvailableResponse *result = (AudioRecordQueueAvailableResponse *)response->body;
    int returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

void AudioRecordQueueUniverse::clear()
{
    AudioRecordQueueRequest *request = new AudioRecordQueueRequest(AudioRecordQueueRequest_CLEAR, NULL);
    AudioRecordQueueResponse *response = this->module->handle(request);
    if (response->type == AudioRecordQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioRecordQueue.clear(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

void AudioRecordQueueUniverse::freeBuffer()
{
    AudioRecordQueueRequest *request = new AudioRecordQueueRequest(AudioRecordQueueRequest_FREEBUFFER, NULL);
    AudioRecordQueueResponse *response = this->module->handle(request);
    if (response->type == AudioRecordQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioRecordQueue.freeBuffer(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

void AudioRecordQueueUniverse::end()
{
    AudioRecordQueueRequest *request = new AudioRecordQueueRequest(AudioRecordQueueRequest_END, NULL);
    AudioRecordQueueResponse *response = this->module->handle(request);
    if (response->type == AudioRecordQueueResponse_ERROR)
    {
        Serial.println("ERROR in AudioRecordQueue.end(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}