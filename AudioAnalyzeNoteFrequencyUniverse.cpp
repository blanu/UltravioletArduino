//
//  AudioAnalyzeNoteFrequencyUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeNoteFrequencyUniverse.h"

 AudioAnalyzeNoteFrequencyUniverse::AudioAnalyzeNoteFrequency()
{
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_AUDIOANALYZENOTEFREQUENCY, NULL);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.AudioAnalyzeNoteFrequency(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse *result = (AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

void AudioAnalyzeNoteFrequencyUniverse::begin(float threshold)
{
    AudioAnalyzeNoteFrequencyBeginRequest *requestBody = new AudioAnalyzeNoteFrequencyBeginRequest(threshold);
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_BEGIN, (void *)requestBody);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioAnalyzeNoteFrequencyUniverse::threshold(float p)
{
    AudioAnalyzeNoteFrequencyThresholdRequest *requestBody = new AudioAnalyzeNoteFrequencyThresholdRequest(p);
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_THRESHOLD, (void *)requestBody);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.threshold(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

bool AudioAnalyzeNoteFrequencyUniverse::available()
{
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_AVAILABLE, NULL);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeNoteFrequencyAvailableResponse *result = (AudioAnalyzeNoteFrequencyAvailableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeNoteFrequencyUniverse::read()
{
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_READ, NULL);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeNoteFrequencyReadResponse *result = (AudioAnalyzeNoteFrequencyReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeNoteFrequencyUniverse::probability()
{
    AudioAnalyzeNoteFrequencyRequest *request = new AudioAnalyzeNoteFrequencyRequest(AudioAnalyzeNoteFrequencyRequest_PROBABILITY, NULL);
    AudioAnalyzeNoteFrequencyResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeNoteFrequencyResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeNoteFrequency.probability(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeNoteFrequencyProbabilityResponse *result = (AudioAnalyzeNoteFrequencyProbabilityResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}