//
//  AudioEffectFlangeUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectFlangeUniverse.h"

boolean AudioEffectFlangeUniverse::voices(int delay_offset, int d_depth, float delay_rate)
{
    AudioEffectFlangeVoicesRequest *requestBody = new AudioEffectFlangeVoicesRequest(delay_offset, d_depth, delay_rate);
    AudioEffectFlangeRequest *request = new AudioEffectFlangeRequest(AudioEffectFlangeRequest_VOICES, (void *)requestBody);
    AudioEffectFlangeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectFlangeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectFlange.voices(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioEffectFlangeVoicesResponse *result = (AudioEffectFlangeVoicesResponse *)response->body;
    boolean returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}