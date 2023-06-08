//
//  AudioAnalyzeFFT1024Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeFFT1024Universe.h"

 AudioAnalyzeFFT1024Universe::window()
{
    AudioAnalyzeFFT1024Request *request = new AudioAnalyzeFFT1024Request(AudioAnalyzeFFT1024Request_WINDOW, NULL);
    AudioAnalyzeFFT1024Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT1024Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT1024.window(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeFFT1024WindowResponse *result = (AudioAnalyzeFFT1024WindowResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeFFT1024Universe::read(unsigned int binNumber)
{
    AudioAnalyzeFFT1024ReadRequest *requestBody = new AudioAnalyzeFFT1024ReadRequest(binNumber);
    AudioAnalyzeFFT1024Request *request = new AudioAnalyzeFFT1024Request(AudioAnalyzeFFT1024Request_READ, (void *)requestBody);
    AudioAnalyzeFFT1024Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT1024Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT1024.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeFFT1024ReadResponse *result = (AudioAnalyzeFFT1024ReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

void AudioAnalyzeFFT1024Universe::averageTogether(uint8_t n)
{
    AudioAnalyzeFFT1024AveragetogetherRequest *requestBody = new AudioAnalyzeFFT1024AveragetogetherRequest(n);
    AudioAnalyzeFFT1024Request *request = new AudioAnalyzeFFT1024Request(AudioAnalyzeFFT1024Request_AVERAGETOGETHER, (void *)requestBody);
    AudioAnalyzeFFT1024Response *response = this->module->handle(request);
    if (response->type == AudioAnalyzeFFT1024Response_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeFFT1024.averageTogether(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}