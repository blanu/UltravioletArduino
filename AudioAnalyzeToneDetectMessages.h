//
//  AudioAnalyzeToneDetectMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeToneDetectMessages_h_
#define AudioAnalyzeToneDetectMessages_h_

#include <Arduino.h>

class AudioAnalyzeToneDetectRequest
{
    public:
        AudioAnalyzeToneDetectRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzeToneDetectResponse
{
    public:
        AudioAnalyzeToneDetectResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzeToneDetectRequestType {AudioAnalyzeToneDetectRequest_FREQUENCY, AudioAnalyzeToneDetectRequest_SET_PARAMS, AudioAnalyzeToneDetectRequest_AVAILABLE, AudioAnalyzeToneDetectRequest_READ, AudioAnalyzeToneDetectRequest_THRESHOLD};

class AudioAnalyzeToneDetectFrequencyRequest
{
    public:
        AudioAnalyzeToneDetectFrequencyRequest(float freq, uint16_t cycles=10)
        {
            this->freq = freq;
            this->cycles=10 = cycles=10;
        }

        float freq;
        uint16_t cycles=10;
};

class AudioAnalyzeToneDetectSet_ParamsRequest
{
    public:
        AudioAnalyzeToneDetectSet_ParamsRequest(int32_t coef, uint16_t cycles, uint16_t len)
        {
            this->coef = coef;
            this->cycles = cycles;
            this->len = len;
        }

        int32_t coef;
        uint16_t cycles;
        uint16_t len;
};

class AudioAnalyzeToneDetectThresholdRequest
{
    public:
        AudioAnalyzeToneDetectThresholdRequest(float level)
        {
            this->level = level;
        }

        float level;
};

enum AudioAnalyzeToneDetectResponseType {AudioAnalyzeToneDetectResponse_ERROR, AudioAnalyzeToneDetectResponse_FREQUENCY, AudioAnalyzeToneDetectResponse_SET_PARAMS, AudioAnalyzeToneDetectResponse_AVAILABLE, AudioAnalyzeToneDetectResponse_READ, AudioAnalyzeToneDetectResponse_THRESHOLD};

class AudioAnalyzeToneDetectAvailableResponse
{
    public:
        AudioAnalyzeToneDetectAvailableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioAnalyzeToneDetectReadResponse
{
    public:
        AudioAnalyzeToneDetectReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif