//
//  AudioFilterStateVariableUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterStateVariableUniverse.h"

void AudioFilterStateVariableUniverse::frequency(float freq)
{
    AudioFilterStateVariableFrequencyRequest *requestBody = new AudioFilterStateVariableFrequencyRequest(freq);
    AudioFilterStateVariableRequest *request = new AudioFilterStateVariableRequest(AudioFilterStateVariableRequest_FREQUENCY, (void *)requestBody);
    AudioFilterStateVariableResponse *response = this->module->handle(request);
    if (response->type == AudioFilterStateVariableResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterStateVariable.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterStateVariableUniverse::resonance(float q)
{
    AudioFilterStateVariableResonanceRequest *requestBody = new AudioFilterStateVariableResonanceRequest(q);
    AudioFilterStateVariableRequest *request = new AudioFilterStateVariableRequest(AudioFilterStateVariableRequest_RESONANCE, (void *)requestBody);
    AudioFilterStateVariableResponse *response = this->module->handle(request);
    if (response->type == AudioFilterStateVariableResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterStateVariable.resonance(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioFilterStateVariableUniverse::octaveControl(float n)
{
    AudioFilterStateVariableOctavecontrolRequest *requestBody = new AudioFilterStateVariableOctavecontrolRequest(n);
    AudioFilterStateVariableRequest *request = new AudioFilterStateVariableRequest(AudioFilterStateVariableRequest_OCTAVECONTROL, (void *)requestBody);
    AudioFilterStateVariableResponse *response = this->module->handle(request);
    if (response->type == AudioFilterStateVariableResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterStateVariable.octaveControl(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}