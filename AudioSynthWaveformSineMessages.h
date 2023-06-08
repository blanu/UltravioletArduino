//
//  AudioSynthWaveformSineMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformSineMessages_h_
#define AudioSynthWaveformSineMessages_h_

#include <Arduino.h>

class AudioSynthWaveformSineRequest
{
    public:
        AudioSynthWaveformSineRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthWaveformSineResponse
{
    public:
        AudioSynthWaveformSineResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthWaveformSineRequestType {AudioSynthWaveformSineRequest_FREQUENCY, AudioSynthWaveformSineRequest_PHASE, AudioSynthWaveformSineRequest_AMPLITUDE};

class AudioSynthWaveformSineFrequencyRequest
{
    public:
        AudioSynthWaveformSineFrequencyRequest(float freq)
        {
            this->freq = freq;
        }

        float freq;
};

class AudioSynthWaveformSinePhaseRequest
{
    public:
        AudioSynthWaveformSinePhaseRequest(float angle)
        {
            this->angle = angle;
        }

        float angle;
};

class AudioSynthWaveformSineAmplitudeRequest
{
    public:
        AudioSynthWaveformSineAmplitudeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioSynthWaveformSineResponseType {AudioSynthWaveformSineResponse_ERROR, AudioSynthWaveformSineResponse_FREQUENCY, AudioSynthWaveformSineResponse_PHASE, AudioSynthWaveformSineResponse_AMPLITUDE};



#endif