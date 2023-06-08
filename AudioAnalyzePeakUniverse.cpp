//
//  AudioAnalyzePeakUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzePeakUniverse.h"

bool AudioAnalyzePeakUniverse::available()
{
    AudioAnalyzePeakRequest *request = new AudioAnalyzePeakRequest(AudioAnalyzePeakRequest_AVAILABLE, NULL);
    AudioAnalyzePeakResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzePeakResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzePeak.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzePeakAvailableResponse *result = (AudioAnalyzePeakAvailableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzePeakUniverse::read()
{
    AudioAnalyzePeakRequest *request = new AudioAnalyzePeakRequest(AudioAnalyzePeakRequest_READ, NULL);
    AudioAnalyzePeakResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzePeakResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzePeak.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzePeakReadResponse *result = (AudioAnalyzePeakReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzePeakUniverse::readPeakToPeak()
{
    AudioAnalyzePeakRequest *request = new AudioAnalyzePeakRequest(AudioAnalyzePeakRequest_READPEAKTOPEAK, NULL);
    AudioAnalyzePeakResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzePeakResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzePeak.readPeakToPeak(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzePeakReadpeaktopeakResponse *result = (AudioAnalyzePeakReadpeaktopeakResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}