//
//  AudioMixer4Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioMixer4Universe.h"

void AudioMixer4Universe::gain(unsigned int channel, float gain)
{
    AudioMixer4GainRequest *requestBody = new AudioMixer4GainRequest(channel, gain);
    AudioMixer4Request *request = new AudioMixer4Request(AudioMixer4Request_GAIN, (void *)requestBody);
    AudioMixer4Response *response = this->module->handle(request);
    if (response->type == AudioMixer4Response_ERROR)
    {
        Serial.println("ERROR in AudioMixer4.gain(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}