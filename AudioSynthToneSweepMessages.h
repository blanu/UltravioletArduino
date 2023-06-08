//
//  AudioSynthToneSweepMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthToneSweepMessages_h_
#define AudioSynthToneSweepMessages_h_

#include <Arduino.h>

class AudioSynthToneSweepRequest
{
    public:
        AudioSynthToneSweepRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthToneSweepResponse
{
    public:
        AudioSynthToneSweepResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthToneSweepRequestType {AudioSynthToneSweepRequest_PLAY, AudioSynthToneSweepRequest_ISPLAYING};

class AudioSynthToneSweepPlayRequest
{
    public:
        AudioSynthToneSweepPlayRequest(float t_amp, int t_lo, int t_hi, float t_time)
        {
            this->t_amp = t_amp;
            this->t_lo = t_lo;
            this->t_hi = t_hi;
            this->t_time = t_time;
        }

        float t_amp;
        int t_lo;
        int t_hi;
        float t_time;
};

enum AudioSynthToneSweepResponseType {AudioSynthToneSweepResponse_ERROR, AudioSynthToneSweepResponse_PLAY, AudioSynthToneSweepResponse_ISPLAYING};

class AudioSynthToneSweepPlayResponse
{
    public:
        AudioSynthToneSweepPlayResponse(boolean value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        boolean value;
};

class AudioSynthToneSweepIsplayingResponse
{
    public:
        AudioSynthToneSweepIsplayingResponse(unsigned char value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned char value;
};

#endif