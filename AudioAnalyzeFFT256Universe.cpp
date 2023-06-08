//
//  AudioAnalyzeFFT256Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeFFT256Universe.h"

 AudioAnalyzeFFT256Universe::window()
{
    AudioAnalyzeFFT256Request *request = new AudioAnalyzeFFT256Request(AudioAnalyzeFFT256Request_WINDOW, NULL);
    AudioAnalyzeFFT256Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT256Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT256.window(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeFFT256WindowResponse *result = (AudioAnalyzeFFT256WindowResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeFFT256Universe::read(unsigned int binNumber)
{
    AudioAnalyzeFFT256ReadRequest *requestBody = new AudioAnalyzeFFT256ReadRequest(binNumber);
    AudioAnalyzeFFT256Request *request = new AudioAnalyzeFFT256Request(AudioAnalyzeFFT256Request_READ, (void *)requestBody);
    AudioAnalyzeFFT256Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT256Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT256.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeFFT256ReadResponse *result = (AudioAnalyzeFFT256ReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

void AudioAnalyzeFFT256Universe::averageTogether(uint8_t n)
{
    AudioAnalyzeFFT256AveragetogetherRequest *requestBody = new AudioAnalyzeFFT256AveragetogetherRequest(n);
    AudioAnalyzeFFT256Request *request = new AudioAnalyzeFFT256Request(AudioAnalyzeFFT256Request_AVERAGETOGETHER, (void *)requestBody);
    AudioAnalyzeFFT256Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT256Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT256.averageTogether(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}