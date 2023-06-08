//
//  AudioSynthWaveformMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformMessages_h_
#define AudioSynthWaveformMessages_h_

#include <Arduino.h>

class AudioSynthWaveformRequest
{
    public:
        AudioSynthWaveformRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthWaveformResponse
{
    public:
        AudioSynthWaveformResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthWaveformRequestType {AudioSynthWaveformRequest_FREQUENCY, AudioSynthWaveformRequest_PHASE, AudioSynthWaveformRequest_OFFSET, AudioSynthWaveformRequest_BEGIN};

class AudioSynthWaveformFrequencyRequest
{
    public:
        AudioSynthWaveformFrequencyRequest(float t_freq)
        {
            this->t_freq = t_freq;
        }

        float t_freq;
};

class AudioSynthWaveformPhaseRequest
{
    public:
        AudioSynthWaveformPhaseRequest(float angle)
        {
            this->angle = angle;
        }

        float angle;
};

class AudioSynthWaveformOffsetRequest
{
    public:
        AudioSynthWaveformOffsetRequest(float n)
        {
            this->n = n;
        }

        float n;
};

class AudioSynthWaveformBeginRequest
{
    public:
        AudioSynthWaveformBeginRequest(short t_type)
        {
            this->t_type = t_type;
        }

        short t_type;
};

enum AudioSynthWaveformResponseType {AudioSynthWaveformResponse_ERROR, AudioSynthWaveformResponse_FREQUENCY, AudioSynthWaveformResponse_PHASE, AudioSynthWaveformResponse_OFFSET, AudioSynthWaveformResponse_BEGIN};



#endif