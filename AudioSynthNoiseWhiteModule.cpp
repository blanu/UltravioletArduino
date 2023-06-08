//
//  AudioSynthNoiseWhiteModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthNoiseWhiteModule.h"

AudioSynthNoiseWhiteResponse *AudioSynthNoiseWhiteModule::handle(AudioSynthNoiseWhiteRequest *request)
{
    switch (request->type)
    {
        case AudioSynthNoiseWhiteRequest_AMPLITUDE:
            {
                AudioSynthNoiseWhiteAmplitudeRequest *parameters = (AudioSynthNoiseWhiteAmplitudeRequest *)request->body;
                this->logic->amplitude(parameters->n);
                
                Serial.println("AudioSynthNoiseWhite.amplitude -> void");
                return new AudioSynthNoiseWhiteResponse(AudioSynthNoiseWhiteRequest_AMPLITUDE, NULL);
            }
    }

    return new AudioSynthNoiseWhiteResponse(AudioSynthNoiseWhiteResponse_ERROR, NULL);
};