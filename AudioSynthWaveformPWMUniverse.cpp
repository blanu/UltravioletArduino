//
//  AudioSynthWaveformPWMUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformPWMUniverse.h"

void AudioSynthWaveformPWMUniverse::frequency(float freq)
{
    AudioSynthWaveformPWMFrequencyRequest *requestBody = new AudioSynthWaveformPWMFrequencyRequest(freq);
    AudioSynthWaveformPWMRequest *request = new AudioSynthWaveformPWMRequest(AudioSynthWaveformPWMRequest_FREQUENCY, (void *)requestBody);
    AudioSynthWaveformPWMResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformPWMResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformPWM.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioSynthWaveformPWMUniverse::amplitude(float n)
{
    AudioSynthWaveformPWMAmplitudeRequest *requestBody = new AudioSynthWaveformPWMAmplitudeRequest(n);
    AudioSynthWaveformPWMRequest *request = new AudioSynthWaveformPWMRequest(AudioSynthWaveformPWMRequest_AMPLITUDE, (void *)requestBody);
    AudioSynthWaveformPWMResponse *response = this->module->handle(request);
    if (response->type == AudioSynthWaveformPWMResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthWaveformPWM.amplitude(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}