//
//  AudioSynthSimpleDrumUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthSimpleDrumUniverse.h"

 AudioSynthSimpleDrumUniverse::length()
{
    AudioSynthSimpleDrumRequest *request = new AudioSynthSimpleDrumRequest(AudioSynthSimpleDrumRequest_LENGTH, NULL);
    AudioSynthSimpleDrumResponse *response = this->module->handle(request);
    if (response->type == AudioSynthSimpleDrumResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthSimpleDrum.length(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthSimpleDrumLengthResponse *result = (AudioSynthSimpleDrumLengthResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

 AudioSynthSimpleDrumUniverse::frequency()
{
    AudioSynthSimpleDrumRequest *request = new AudioSynthSimpleDrumRequest(AudioSynthSimpleDrumRequest_FREQUENCY, NULL);
    AudioSynthSimpleDrumResponse *response = this->module->handle(request);
    if (response->type == AudioSynthSimpleDrumResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthSimpleDrum.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthSimpleDrumFrequencyResponse *result = (AudioSynthSimpleDrumFrequencyResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

 AudioSynthSimpleDrumUniverse::pitchMod()
{
    AudioSynthSimpleDrumRequest *request = new AudioSynthSimpleDrumRequest(AudioSynthSimpleDrumRequest_PITCHMOD, NULL);
    AudioSynthSimpleDrumResponse *response = this->module->handle(request);
    if (response->type == AudioSynthSimpleDrumResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthSimpleDrum.pitchMod(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthSimpleDrumPitchmodResponse *result = (AudioSynthSimpleDrumPitchmodResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

void AudioSynthSimpleDrumUniverse::secondMix(float level)
{
    AudioSynthSimpleDrumSecondmixRequest *requestBody = new AudioSynthSimpleDrumSecondmixRequest(level);
    AudioSynthSimpleDrumRequest *request = new AudioSynthSimpleDrumRequest(AudioSynthSimpleDrumRequest_SECONDMIX, (void *)requestBody);
    AudioSynthSimpleDrumResponse *response = this->module->handle(request);
    if (response->type == AudioSynthSimpleDrumResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthSimpleDrum.secondMix(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}