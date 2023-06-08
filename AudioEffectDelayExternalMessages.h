//
//  AudioEffectDelayExternalMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectDelayExternalMessages_h_
#define AudioEffectDelayExternalMessages_h_

#include <Arduino.h>

class AudioEffectDelayExternalRequest
{
    public:
        AudioEffectDelayExternalRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectDelayExternalResponse
{
    public:
        AudioEffectDelayExternalResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectDelayExternalRequestType {AudioEffectDelayExternalRequest_DELAY, AudioEffectDelayExternalRequest_DISABLE};

class AudioEffectDelayExternalDelayRequest
{
    public:
        AudioEffectDelayExternalDelayRequest(uint8_t channel, float milliseconds)
        {
            this->channel = channel;
            this->milliseconds = milliseconds;
        }

        uint8_t channel;
        float milliseconds;
};

class AudioEffectDelayExternalDisableRequest
{
    public:
        AudioEffectDelayExternalDisableRequest(uint8_t channel)
        {
            this->channel = channel;
        }

        uint8_t channel;
};

enum AudioEffectDelayExternalResponseType {AudioEffectDelayExternalResponse_ERROR, AudioEffectDelayExternalResponse_DELAY, AudioEffectDelayExternalResponse_DISABLE};



#endif