//
//  AudioEffectDelayMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayMessages_h_
#define AudioEffectDelayMessages_h_

#include <Arduino.h>

class AudioEffectDelayRequest
{
    public:
        AudioEffectDelayRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectDelayResponse
{
    public:
        AudioEffectDelayResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectDelayRequestType {AudioEffectDelayRequest_DELAY, AudioEffectDelayRequest_DISABLE};

class AudioEffectDelayDelayRequest
{
    public:
        AudioEffectDelayDelayRequest(uint8_t channel, float milliseconds)
        {
            this->channel = channel;
            this->milliseconds = milliseconds;
        }

        uint8_t channel;
        float milliseconds;
};

class AudioEffectDelayDisableRequest
{
    public:
        AudioEffectDelayDisableRequest(uint8_t channel)
        {
            this->channel = channel;
        }

        uint8_t channel;
};

enum AudioEffectDelayResponseType {AudioEffectDelayResponse_ERROR, AudioEffectDelayResponse_DELAY, AudioEffectDelayResponse_DISABLE};



#endif