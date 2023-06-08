//
//  AudioEffectBitcrusherModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectBitcrusherModule.h"

AudioEffectBitcrusherResponse *AudioEffectBitcrusherModule::handle(AudioEffectBitcrusherRequest *request)
{
    switch (request->type)
    {
        case AudioEffectBitcrusherRequest_BITS:
            {
                AudioEffectBitcrusherBitsRequest *parameters = (AudioEffectBitcrusherBitsRequest *)request->body;
                this->logic->bits(parameters->b);
                
                Serial.println("AudioEffectBitcrusher.bits -> void");
                return new AudioEffectBitcrusherResponse(AudioEffectBitcrusherRequest_BITS, NULL);
            }

        case AudioEffectBitcrusherRequest_SAMPLERATE:
            {
                AudioEffectBitcrusherSamplerateRequest *parameters = (AudioEffectBitcrusherSamplerateRequest *)request->body;
                this->logic->sampleRate(parameters->hz);
                
                Serial.println("AudioEffectBitcrusher.sampleRate -> void");
                return new AudioEffectBitcrusherResponse(AudioEffectBitcrusherRequest_SAMPLERATE, NULL);
            }
    }

    return new AudioEffectBitcrusherResponse(AudioEffectBitcrusherResponse_ERROR, NULL);
};