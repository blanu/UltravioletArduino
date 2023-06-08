//
//  AudioSynthToneSweepUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthToneSweepUniverse.h"

boolean AudioSynthToneSweepUniverse::play(float t_amp, int t_lo, int t_hi, float t_time)
{
    AudioSynthToneSweepPlayRequest *requestBody = new AudioSynthToneSweepPlayRequest(t_amp, t_lo, t_hi, t_time);
    AudioSynthToneSweepRequest *request = new AudioSynthToneSweepRequest(AudioSynthToneSweepRequest_PLAY, (void *)requestBody);
    AudioSynthToneSweepResponse *response = this->module->handle(request);
    if (response->type == AudioSynthToneSweepResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthToneSweep.play(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthToneSweepPlayResponse *result = (AudioSynthToneSweepPlayResponse *)response->body;
    boolean returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned char AudioSynthToneSweepUniverse::isPlaying()
{
    AudioSynthToneSweepRequest *request = new AudioSynthToneSweepRequest(AudioSynthToneSweepRequest_ISPLAYING, NULL);
    AudioSynthToneSweepResponse *response = this->module->handle(request);
    if (response->type == AudioSynthToneSweepResponse_ERROR)
    {
        Serial.println("ERROR in AudioSynthToneSweep.isPlaying(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioSynthToneSweepIsplayingResponse *result = (AudioSynthToneSweepIsplayingResponse *)response->body;
    unsigned char returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}