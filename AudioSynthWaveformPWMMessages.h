//
//  AudioSynthWaveformPWMMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformPWMMessages_h_
#define AudioSynthWaveformPWMMessages_h_

#include <Arduino.h>

class AudioSynthWaveformPWMRequest
{
    public:
        AudioSynthWaveformPWMRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthWaveformPWMResponse
{
    public:
        AudioSynthWaveformPWMResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthWaveformPWMRequestType {AudioSynthWaveformPWMRequest_FREQUENCY, AudioSynthWaveformPWMRequest_AMPLITUDE};

class AudioSynthWaveformPWMFrequencyRequest
{
    public:
        AudioSynthWaveformPWMFrequencyRequest(float freq)
        {
            this->freq = freq;
        }

        float freq;
};

class AudioSynthWaveformPWMAmplitudeRequest
{
    public:
        AudioSynthWaveformPWMAmplitudeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioSynthWaveformPWMResponseType {AudioSynthWaveformPWMResponse_ERROR, AudioSynthWaveformPWMResponse_FREQUENCY, AudioSynthWaveformPWMResponse_AMPLITUDE};



#endif