//
//  AudioInputI2SUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioInputI2SUniverse.h"

void AudioInputI2SUniverse::begin()
{
    AudioInputI2SRequest *request = new AudioInputI2SRequest(AudioInputI2SRequest_BEGIN, NULL);
    AudioInputI2SResponse *response = this->module->handle(request);
    if (response->type == AudioInputI2SResponse_ERROR)
    {
        Serial.println("ERROR in AudioInputI2S.begin(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}