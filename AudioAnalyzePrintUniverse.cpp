//
//  AudioAnalyzePrintUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzePrintUniverse.h"

void AudioAnalyzePrintUniverse::trigger()
{
    AudioAnalyzePrintRequest *request = new AudioAnalyzePrintRequest(AudioAnalyzePrintRequest_TRIGGER, NULL);
    AudioAnalyzePrintResponse *response = this->module->handle(request);
    if (response->type == AudioAnalyzePrintResponse_ERROR)
    {
        Serial.println("ERROR in AudioAnalyzePrint.trigger(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete response;
}