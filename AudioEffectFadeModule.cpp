//
//  AudioEffectFadeModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectFadeModule.h"

AudioEffectFadeResponse *AudioEffectFadeModule::handle(AudioEffectFadeRequest *request)
{
    switch (request->type)
    {
        case AudioEffectFadeRequest_FADEIN:
            {
                AudioEffectFadeFadeinRequest *parameters = (AudioEffectFadeFadeinRequest *)request->body;
                this->logic->fadeIn(parameters->milliseconds);
                
                Serial.println("AudioEffectFade.fadeIn -> void");
                return new AudioEffectFadeResponse(AudioEffectFadeRequest_FADEIN, NULL);
            }

        case AudioEffectFadeRequest_FADEOUT:
            {
                AudioEffectFadeFadeoutRequest *parameters = (AudioEffectFadeFadeoutRequest *)request->body;
                this->logic->fadeOut(parameters->milliseconds);
                
                Serial.println("AudioEffectFade.fadeOut -> void");
                return new AudioEffectFadeResponse(AudioEffectFadeRequest_FADEOUT, NULL);
            }
    }

    return new AudioEffectFadeResponse(AudioEffectFadeResponse_ERROR, NULL);
};