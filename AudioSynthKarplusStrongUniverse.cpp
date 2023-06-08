//
//  AudioSynthKarplusStrongUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthKarplusStrongUniverse.h"

void AudioSynthKarplusStrongUniverse::noteOn(float frequency, float velocity)
{
    AudioSynthKarplusStrongNoteonRequest *requestBody = new AudioSynthKarplusStrongNoteonRequest(frequency, velocity);
    AudioSynthKarplusStrongRequest *request = new AudioSynthKarplusStrongRequest(AudioSynthKarplusStrongRequest_NOTEON, (void *)requestBody);
    AudioSynthKarplusStrongResponse *response = this->module->handle(request);
    if (response->type == AudioSynthKarplusStrongResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthKarplusStrong.noteOn(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthKarplusStrongUniverse::noteOff(float velocity)
{
    AudioSynthKarplusStrongNoteoffRequest *requestBody = new AudioSynthKarplusStrongNoteoffRequest(velocity);
    AudioSynthKarplusStrongRequest *request = new AudioSynthKarplusStrongRequest(AudioSynthKarplusStrongRequest_NOTEOFF, (void *)requestBody);
    AudioSynthKarplusStrongResponse *response = this->module->handle(request);
    if (response->type == AudioSynthKarplusStrongResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthKarplusStrong.noteOff(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}