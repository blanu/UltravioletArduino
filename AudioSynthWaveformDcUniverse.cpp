//
//  AudioSynthWaveformDcUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformDcUniverse.h"

void AudioSynthWaveformDcUniverse::amplitude(float n)
{
    AudioSynthWaveformDcAmplitudeRequest *requestBody = new AudioSynthWaveformDcAmplitudeRequest(n);
    AudioSynthWaveformDcRequest *request = new AudioSynthWaveformDcRequest(AudioSynthWaveformDcRequest_AMPLITUDE, (void *)requestBody);
    AudioSynthWaveformDcResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformDcResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformDc.amplitude(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

float AudioSynthWaveformDcUniverse::read()
{
    AudioSynthWaveformDcRequest *request = new AudioSynthWaveformDcRequest(AudioSynthWaveformDcRequest_READ, NULL);
    AudioSynthWaveformDcResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformDcResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformDc.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthWaveformDcReadResponse *result = (AudioSynthWaveformDcReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}