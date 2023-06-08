//
//  AudioFilterBiquadMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterBiquadMessages_h_
#define AudioFilterBiquadMessages_h_

#include <Arduino.h>

class AudioFilterBiquadRequest
{
    public:
        AudioFilterBiquadRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioFilterBiquadResponse
{
    public:
        AudioFilterBiquadResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioFilterBiquadRequestType {AudioFilterBiquadRequest_SETLOWPASS, AudioFilterBiquadRequest_SETHIGHPASS, AudioFilterBiquadRequest_SETBANDPASS, AudioFilterBiquadRequest_SETNOTCH, AudioFilterBiquadRequest_SETLOWSHELF, AudioFilterBiquadRequest_SETHIGHSHELF};

class AudioFilterBiquadSetlowpassRequest
{
    public:
        AudioFilterBiquadSetlowpassRequest(uint32_t stage, float frequency, float q = 0.7071)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->0.7071 = 0.7071;
        }

        uint32_t stage;
        float frequency;
        float q = 0.7071;
};

class AudioFilterBiquadSethighpassRequest
{
    public:
        AudioFilterBiquadSethighpassRequest(uint32_t stage, float frequency, float q = 0.7071)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->0.7071 = 0.7071;
        }

        uint32_t stage;
        float frequency;
        float q = 0.7071;
};

class AudioFilterBiquadSetbandpassRequest
{
    public:
        AudioFilterBiquadSetbandpassRequest(uint32_t stage, float frequency, float q = 1.0)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->1.0 = 1.0;
        }

        uint32_t stage;
        float frequency;
        float q = 1.0;
};

class AudioFilterBiquadSetnotchRequest
{
    public:
        AudioFilterBiquadSetnotchRequest(uint32_t stage, float frequency, float q = 1.0)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->1.0 = 1.0;
        }

        uint32_t stage;
        float frequency;
        float q = 1.0;
};

class AudioFilterBiquadSetlowshelfRequest
{
    public:
        AudioFilterBiquadSetlowshelfRequest(uint32_t stage, float frequency, float gain, float slope = 1.0f)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->gain = gain;
            this->1.0f = 1.0f;
        }

        uint32_t stage;
        float frequency;
        float gain;
        float slope = 1.0f;
};

class AudioFilterBiquadSethighshelfRequest
{
    public:
        AudioFilterBiquadSethighshelfRequest(uint32_t stage, float frequency, float gain, float slope = 1.0f)
        {
            this->stage = stage;
            this->frequency = frequency;
            this->gain = gain;
            this->1.0f = 1.0f;
        }

        uint32_t stage;
        float frequency;
        float gain;
        float slope = 1.0f;
};

enum AudioFilterBiquadResponseType {AudioFilterBiquadResponse_ERROR, AudioFilterBiquadResponse_SETLOWPASS, AudioFilterBiquadResponse_SETHIGHPASS, AudioFilterBiquadResponse_SETBANDPASS, AudioFilterBiquadResponse_SETNOTCH, AudioFilterBiquadResponse_SETLOWSHELF, AudioFilterBiquadResponse_SETHIGHSHELF};



#endif