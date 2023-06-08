//
//  AudioControlCS4272Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlCS4272Universe.h"

bool AudioControlCS4272Universe::enable()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_ENABLE, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.enable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272EnableResponse *result = (AudioControlCS4272EnableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::volume(float left, float right)
{
    AudioControlCS4272VolumeRequest *requestBody = new AudioControlCS4272VolumeRequest(left, right);
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_VOLUME, (void *)requestBody);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.volume(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272VolumeResponse *result = (AudioControlCS4272VolumeResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::dacVolume(float left, float right)
{
    AudioControlCS4272DacvolumeRequest *requestBody = new AudioControlCS4272DacvolumeRequest(left, right);
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_DACVOLUME, (void *)requestBody);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.dacVolume(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272DacvolumeResponse *result = (AudioControlCS4272DacvolumeResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::muteOutput()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_MUTEOUTPUT, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.muteOutput(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272MuteoutputResponse *result = (AudioControlCS4272MuteoutputResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::unmuteOutput()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_UNMUTEOUTPUT, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.unmuteOutput(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272UnmuteoutputResponse *result = (AudioControlCS4272UnmuteoutputResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::muteInput()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_MUTEINPUT, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.muteInput(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272MuteinputResponse *result = (AudioControlCS4272MuteinputResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::unmuteInput()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_UNMUTEINPUT, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.unmuteInput(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272UnmuteinputResponse *result = (AudioControlCS4272UnmuteinputResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::enableDither()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_ENABLEDITHER, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.enableDither(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272EnableditherResponse *result = (AudioControlCS4272EnableditherResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS4272Universe::disableDither()
{
    AudioControlCS4272Request *request = new AudioControlCS4272Request(AudioControlCS4272Request_DISABLEDITHER, NULL);
    AudioControlCS4272Response *response = this->module->handle(request);
    if (response->type == AudioControlCS4272Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS4272.disableDither(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS4272DisableditherResponse *result = (AudioControlCS4272DisableditherResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}