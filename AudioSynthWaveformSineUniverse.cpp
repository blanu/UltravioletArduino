//
//  AudioSynthWaveformSineUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformSineUniverse.h"

void AudioSynthWaveformSineUniverse::frequency(float freq)
{
    AudioSynthWaveformSineFrequencyRequest *requestBody = new AudioSynthWaveformSineFrequencyRequest(freq);
    AudioSynthWaveformSineRequest *request = new AudioSynthWaveformSineRequest(AudioSynthWaveformSineRequest_FREQUENCY, (void *)requestBody);
    AudioSynthWaveformSineResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformSineResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformSine.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformSineUniverse::phase(float angle)
{
    AudioSynthWaveformSinePhaseRequest *requestBody = new AudioSynthWaveformSinePhaseRequest(angle);
    AudioSynthWaveformSineRequest *request = new AudioSynthWaveformSineRequest(AudioSynthWaveformSineRequest_PHASE, (void *)requestBody);
    AudioSynthWaveformSineResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformSineResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformSine.phase(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformSineUniverse::amplitude(float n)
{
    AudioSynthWaveformSineAmplitudeRequest *requestBody = new AudioSynthWaveformSineAmplitudeRequest(n);
    AudioSynthWaveformSineRequest *request = new AudioSynthWaveformSineRequest(AudioSynthWaveformSineRequest_AMPLITUDE, (void *)requestBody);
    AudioSynthWaveformSineResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformSineResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformSine.amplitude(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}