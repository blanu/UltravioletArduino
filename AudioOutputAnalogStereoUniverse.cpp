//
//  AudioOutputAnalogStereoUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioOutputAnalogStereoUniverse.h"

void AudioOutputAnalogStereoUniverse::begin()
{
    AudioOutputAnalogStereoRequest *request = new AudioOutputAnalogStereoRequest(AudioOutputAnalogStereoRequest_BEGIN, NULL);
    AudioOutputAnalogStereoResponse *response = this->module->handle(request);
    if (response->type == AudioOutputAnalogStereoResponse_ERROR)
    {
        Serial.println("ERROR in AudioOutputAnalogStereo.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}

void AudioOutputAnalogStereoUniverse::analogReference(int ref)
{
    AudioOutputAnalogStereoAnalogreferenceRequest *requestBody = new AudioOutputAnalogStereoAnalogreferenceRequest(ref);
    AudioOutputAnalogStereoRequest *request = new AudioOutputAnalogStereoRequest(AudioOutputAnalogStereoRequest_ANALOGREFERENCE, (void *)requestBody);
    AudioOutputAnalogStereoResponse *response = this->module->handle(request);
    if (response->type == AudioOutputAnalogStereoResponse_ERROR)
    {
        Serial.println("ERROR in AudioOutputAnalogStereo.analogReference(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}