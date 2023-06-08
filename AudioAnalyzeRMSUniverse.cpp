//
//  AudioAnalyzeRMSUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeRMSUniverse.h"

bool AudioAnalyzeRMSUniverse::available()
{
    AudioAnalyzeRMSRequest *request = new AudioAnalyzeRMSRequest(AudioAnalyzeRMSRequest_AVAILABLE, NULL);
    AudioAnalyzeRMSResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeRMSResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeRMS.available(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeRMSAvailableResponse *result = (AudioAnalyzeRMSAvailableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

float AudioAnalyzeRMSUniverse::read()
{
    AudioAnalyzeRMSRequest *request = new AudioAnalyzeRMSRequest(AudioAnalyzeRMSRequest_READ, NULL);
    AudioAnalyzeRMSResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzeRMSResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzeRMS.read(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioAnalyzeRMSReadResponse *result = (AudioAnalyzeRMSReadResponse *)response->body;
    float returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}