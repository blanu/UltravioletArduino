//
//  AudioAnalyzeToneDetectUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeToneDetectUniverse.h"

void AudioAnalyzeToneDetectUniverse::frequency(float freq, uint16_t cycles=10)
{
    AudioAnalyzeToneDetectFrequencyRequest *requestBody = new AudioAnalyzeToneDetectFrequencyRequest(freq, cycles=10);
    AudioAnalyzeToneDetectRequest *request = new AudioAnalyzeToneDetectRequest(AudioAnalyzeToneDetectRequest_FREQUENCY, (void *)requestBody);
    AudioAnalyzeToneDetectResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeToneDetectResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeToneDetect.frequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioAnalyzeToneDetectUniverse::set_params(int32_t coef, uint16_t cycles, uint16_t len)
{
    AudioAnalyzeToneDetectSet_ParamsRequest *requestBody = new AudioAnalyzeToneDetectSet_ParamsRequest(coef, cycles, len);
    AudioAnalyzeToneDetectRequest *request = new AudioAnalyzeToneDetectRequest(AudioAnalyzeToneDetectRequest_SET_PARAMS, (void *)requestBody);
    AudioAnalyzeToneDetectResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeToneDetectResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeToneDetect.set_params(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

bool AudioAnalyzeToneDetectUniverse::available()
{
    AudioAnalyzeToneDetectRequest *request = new AudioAnalyzeToneDetectRequest(AudioAnalyzeToneDetectRequest_AVAILABLE, NULL);
    AudioAnalyzeToneDetectResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeToneDetectResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeToneDetect.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeToneDetectAvailableResponse *result = (AudioAnalyzeToneDetectAvailableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeToneDetectUniverse::read()
{
    AudioAnalyzeToneDetectRequest *request = new AudioAnalyzeToneDetectRequest(AudioAnalyzeToneDetectRequest_READ, NULL);
    AudioAnalyzeToneDetectResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeToneDetectResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeToneDetect.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeToneDetectReadResponse *result = (AudioAnalyzeToneDetectReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

void AudioAnalyzeToneDetectUniverse::threshold(float level)
{
    AudioAnalyzeToneDetectThresholdRequest *requestBody = new AudioAnalyzeToneDetectThresholdRequest(level);
    AudioAnalyzeToneDetectRequest *request = new AudioAnalyzeToneDetectRequest(AudioAnalyzeToneDetectRequest_THRESHOLD, (void *)requestBody);
    AudioAnalyzeToneDetectResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeToneDetectResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeToneDetect.threshold(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}