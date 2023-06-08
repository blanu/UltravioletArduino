//
//  AudioOutputI2SUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioOutputI2SUniverse.h"

void AudioOutputI2SUniverse::begin()
{
    AudioOutputI2SRequest *request = new AudioOutputI2SRequest(AudioOutputI2SRequest_BEGIN, NULL);
    AudioOutputI2SResponse *response = this->module->handle(request);
    if (response->type == AudioOutputI2SResponse_ERROR)
    {
        Serial.println("ERROR in AudioOutputI2S.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}