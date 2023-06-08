//
//  AudioControlCS42448Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlCS42448Universe.h"

void AudioControlCS42448Universe::setAddress(uint8_t addr)
{
    AudioControlCS42448SetaddressRequest *requestBody = new AudioControlCS42448SetaddressRequest(addr);
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_SETADDRESS, (void *)requestBody);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.setAddress(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

bool AudioControlCS42448Universe::enable()
{
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_ENABLE, NULL);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.enable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448EnableResponse *result = (AudioControlCS42448EnableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS42448Universe::disable()
{
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_DISABLE, NULL);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.disable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448DisableResponse *result = (AudioControlCS42448DisableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS42448Universe::volume(float level)
{
    AudioControlCS42448VolumeRequest *requestBody = new AudioControlCS42448VolumeRequest(level);
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_VOLUME, (void *)requestBody);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.volume(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448VolumeResponse *result = (AudioControlCS42448VolumeResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

return AudioControlCS42448Universe::volumeInteger()
{
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_VOLUMEINTEGER, NULL);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.volumeInteger(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448VolumeintegerResponse *result = (AudioControlCS42448VolumeintegerResponse *)response->body;
    return returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS42448Universe::inputLevel(float level)
{
    AudioControlCS42448InputlevelRequest *requestBody = new AudioControlCS42448InputlevelRequest(level);
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_INPUTLEVEL, (void *)requestBody);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.inputLevel(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448InputlevelResponse *result = (AudioControlCS42448InputlevelResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

return AudioControlCS42448Universe::inputLevelInteger()
{
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_INPUTLEVELINTEGER, NULL);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.inputLevelInteger(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448InputlevelintegerResponse *result = (AudioControlCS42448InputlevelintegerResponse *)response->body;
    return returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlCS42448Universe::inputSelect(int n)
{
    AudioControlCS42448InputselectRequest *requestBody = new AudioControlCS42448InputselectRequest(n);
    AudioControlCS42448Request *request = new AudioControlCS42448Request(AudioControlCS42448Request_INPUTSELECT, (void *)requestBody);
    AudioControlCS42448Response *response = this->module->handle(request);
    if (response->type == AudioControlCS42448Response_ERROR)
    {
        Serial.println("ERROR in AudioControlCS42448.inputSelect(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlCS42448InputselectResponse *result = (AudioControlCS42448InputselectResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}