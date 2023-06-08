//
//  AudioEffectFlangeMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFlangeMessages_h_
#define AudioEffectFlangeMessages_h_

#include <Arduino.h>

class AudioEffectFlangeRequest
{
    public:
        AudioEffectFlangeRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectFlangeResponse
{
    public:
        AudioEffectFlangeResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectFlangeRequestType {AudioEffectFlangeRequest_VOICES};

class AudioEffectFlangeVoicesRequest
{
    public:
        AudioEffectFlangeVoicesRequest(int delay_offset, int d_depth, float delay_rate)
        {
            this->delay_offset = delay_offset;
            this->d_depth = d_depth;
            this->delay_rate = delay_rate;
        }

        int delay_offset;
        int d_depth;
        float delay_rate;
};

enum AudioEffectFlangeResponseType {AudioEffectFlangeResponse_ERROR, AudioEffectFlangeResponse_VOICES};

class AudioEffectFlangeVoicesResponse
{
    public:
        AudioEffectFlangeVoicesResponse(boolean value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        boolean value;
};

#endif