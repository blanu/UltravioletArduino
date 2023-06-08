//
//  AudioEffectFlangeModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectFlangeModule.h"

AudioEffectFlangeResponse *AudioEffectFlangeModule::handle(AudioEffectFlangeRequest *request)
{
    switch (request->type)
    {
        case AudioEffectFlangeRequest_VOICES:
            {
                AudioEffectFlangeVoicesRequest *parameters = (AudioEffectFlangeVoicesRequest *)request->body;
                boolean result = this->logic->voices(parameters->delay_offset, parameters->d_depth, parameters->delay_rate);
                AudioEffectFlangeVoicesResponse response = AudioEffectFlangeVoicesResponse(result);
                Serial.println("AudioEffectFlange.voices -> boolean");
                return new AudioEffectFlangeResponse(AudioEffectFlangeRequest_VOICES, (void *)&response);
            }
    }

    return new AudioEffectFlangeResponse(AudioEffectFlangeResponse_ERROR, NULL);
};