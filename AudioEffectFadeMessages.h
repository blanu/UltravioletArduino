//
//  AudioEffectFadeMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFadeMessages_h_
#define AudioEffectFadeMessages_h_

#include <Arduino.h>

class AudioEffectFadeRequest
{
    public:
        AudioEffectFadeRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectFadeResponse
{
    public:
        AudioEffectFadeResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectFadeRequestType {AudioEffectFadeRequest_FADEIN, AudioEffectFadeRequest_FADEOUT};

class AudioEffectFadeFadeinRequest
{
    public:
        AudioEffectFadeFadeinRequest(uint32_t milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        uint32_t milliseconds;
};

class AudioEffectFadeFadeoutRequest
{
    public:
        AudioEffectFadeFadeoutRequest(uint32_t milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        uint32_t milliseconds;
};

enum AudioEffectFadeResponseType {AudioEffectFadeResponse_ERROR, AudioEffectFadeResponse_FADEIN, AudioEffectFadeResponse_FADEOUT};



#endif