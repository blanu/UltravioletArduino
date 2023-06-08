//
//  AudioFilterFIRUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterFIRUniverse.h"

void AudioFilterFIRUniverse::end()
{
    AudioFilterFIRRequest *request = new AudioFilterFIRRequest(AudioFilterFIRRequest_END, NULL);
    AudioFilterFIRResponse *response = this->module->handle(request);
    if (response->type == AudioFilterFIRResponse_ERROR)
    {
        Serial.println("ERROR in AudioFilterFIR.end(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}