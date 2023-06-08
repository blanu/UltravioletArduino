//
//  AudioEffectReverbUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectReverbUniverse.h"

 AudioEffectReverbUniverse::AudioEffectReverb()
{
    AudioEffectReverbRequest *request = new AudioEffectReverbRequest(AudioEffectReverbRequest_AUDIOEFFECTREVERB, NULL);
    AudioEffectReverbResponse *response = this->module->handle(request);
    if (response->type == AudioEffectReverbResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectReverb.AudioEffectReverb(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioEffectReverbAudioeffectreverbResponse *result = (AudioEffectReverbAudioeffectreverbResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

 AudioEffectReverbUniverse::reverbTime()
{
    AudioEffectReverbRequest *request = new AudioEffectReverbRequest(AudioEffectReverbRequest_REVERBTIME, NULL);
    AudioEffectReverbResponse *response = this->module->handle(request);
    if (response->type == AudioEffectReverbResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectReverb.reverbTime(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioEffectReverbReverbtimeResponse *result = (AudioEffectReverbReverbtimeResponse *)response->body;
     returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}