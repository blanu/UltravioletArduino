//
//  AudioMixer4Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioMixer4Module.h"

AudioMixer4Response *AudioMixer4Module::handle(AudioMixer4Request *request)
{
    switch (request->type)
    {
        case AudioMixer4Request_GAIN:
            {
                AudioMixer4GainRequest *parameters = (AudioMixer4GainRequest *)request->body;
                this->logic->gain(parameters->channel, parameters->gain);
                
                Serial.println("AudioMixer4.gain -> void");
                return new AudioMixer4Response(AudioMixer4Request_GAIN, NULL);
            }
    }

    return new AudioMixer4Response(AudioMixer4Response_ERROR, NULL);
};