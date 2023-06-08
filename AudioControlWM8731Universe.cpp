//
//  AudioControlWM8731Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlWM8731Universe.h"

bool AudioControlWM8731Universe::enable()
{
    AudioControlWM8731Request *request = new AudioControlWM8731Request(AudioControlWM8731Request_ENABLE, NULL);
    AudioControlWM8731Response *response = this->module->handle(request);
    if (response->type == AudioControlWM8731Response_ERROR)
    {
        Serial.println("ERROR in AudioControlWM8731.enable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlWM8731EnableResponse *result = (AudioControlWM8731EnableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}