//
//  AudioEffectBitcrusherMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectBitcrusherMessages_h_
#define AudioEffectBitcrusherMessages_h_

#include <Arduino.h>

class AudioEffectBitcrusherRequest
{
    public:
        AudioEffectBitcrusherRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectBitcrusherResponse
{
    public:
        AudioEffectBitcrusherResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectBitcrusherRequestType {AudioEffectBitcrusherRequest_BITS, AudioEffectBitcrusherRequest_SAMPLERATE};

class AudioEffectBitcrusherBitsRequest
{
    public:
        AudioEffectBitcrusherBitsRequest(uint8_t b)
        {
            this->b = b;
        }

        uint8_t b;
};

class AudioEffectBitcrusherSamplerateRequest
{
    public:
        AudioEffectBitcrusherSamplerateRequest(float hz)
        {
            this->hz = hz;
        }

        float hz;
};

enum AudioEffectBitcrusherResponseType {AudioEffectBitcrusherResponse_ERROR, AudioEffectBitcrusherResponse_BITS, AudioEffectBitcrusherResponse_SAMPLERATE};



#endif