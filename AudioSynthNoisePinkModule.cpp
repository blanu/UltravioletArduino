//
//  AudioSynthNoisePinkModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthNoisePinkModule.h"

AudioSynthNoisePinkResponse *AudioSynthNoisePinkModule::handle(AudioSynthNoisePinkRequest *request)
{
    switch (request->type)
    {
        case AudioSynthNoisePinkRequest_AMPLITUDE:
            {
                AudioSynthNoisePinkAmplitudeRequest *parameters = (AudioSynthNoisePinkAmplitudeRequest *)request->body;
                this->logic->amplitude(parameters->n);
                
                Serial.println("AudioSynthNoisePink.amplitude -> void");
                return new AudioSynthNoisePinkResponse(AudioSynthNoisePinkRequest_AMPLITUDE, NULL);
            }
    }

    return new AudioSynthNoisePinkResponse(AudioSynthNoisePinkResponse_ERROR, NULL);
};