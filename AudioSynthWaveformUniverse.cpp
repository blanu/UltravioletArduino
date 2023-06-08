//
//  AudioSynthWaveformUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformUniverse.h"

void AudioSynthWaveformUniverse::frequency(float t_freq)
{
    AudioSynthWaveformFrequencyRequest *requestBody = new AudioSynthWaveformFrequencyRequest(t_freq);
    AudioSynthWaveformRequest *request = new AudioSynthWaveformRequest(AudioSynthWaveformRequest_FREQUENCY, (void *)requestBody);
    AudioSynthWaveformResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveform.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformUniverse::phase(float angle)
{
    AudioSynthWaveformPhaseRequest *requestBody = new AudioSynthWaveformPhaseRequest(angle);
    AudioSynthWaveformRequest *request = new AudioSynthWaveformRequest(AudioSynthWaveformRequest_PHASE, (void *)requestBody);
    AudioSynthWaveformResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveform.phase(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformUniverse::offset(float n)
{
    AudioSynthWaveformOffsetRequest *requestBody = new AudioSynthWaveformOffsetRequest(n);
    AudioSynthWaveformRequest *request = new AudioSynthWaveformRequest(AudioSynthWaveformRequest_OFFSET, (void *)requestBody);
    AudioSynthWaveformResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveform.offset(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformUniverse::begin(short t_type)
{
    AudioSynthWaveformBeginRequest *requestBody = new AudioSynthWaveformBeginRequest(t_type);
    AudioSynthWaveformRequest *request = new AudioSynthWaveformRequest(AudioSynthWaveformRequest_BEGIN, (void *)requestBody);
    AudioSynthWaveformResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveform.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}