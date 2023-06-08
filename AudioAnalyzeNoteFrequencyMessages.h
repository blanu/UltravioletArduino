//
//  AudioAnalyzeNoteFrequencyMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeNoteFrequencyMessages_h_
#define AudioAnalyzeNoteFrequencyMessages_h_

#include <Arduino.h>

class AudioAnalyzeNoteFrequencyRequest
{
    public:
        AudioAnalyzeNoteFrequencyRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzeNoteFrequencyResponse
{
    public:
        AudioAnalyzeNoteFrequencyResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzeNoteFrequencyRequestType {AudioAnalyzeNoteFrequencyRequest_AUDIOANALYZENOTEFREQUENCY, AudioAnalyzeNoteFrequencyRequest_BEGIN, AudioAnalyzeNoteFrequencyRequest_THRESHOLD, AudioAnalyzeNoteFrequencyRequest_AVAILABLE, AudioAnalyzeNoteFrequencyRequest_READ, AudioAnalyzeNoteFrequencyRequest_PROBABILITY};

class AudioAnalyzeNoteFrequencyBeginRequest
{
    public:
        AudioAnalyzeNoteFrequencyBeginRequest(float threshold)
        {
            this->threshold = threshold;
        }

        float threshold;
};

class AudioAnalyzeNoteFrequencyThresholdRequest
{
    public:
        AudioAnalyzeNoteFrequencyThresholdRequest(float p)
        {
            this->p = p;
        }

        float p;
};

enum AudioAnalyzeNoteFrequencyResponseType {AudioAnalyzeNoteFrequencyResponse_ERROR, AudioAnalyzeNoteFrequencyResponse_AUDIOANALYZENOTEFREQUENCY, AudioAnalyzeNoteFrequencyResponse_BEGIN, AudioAnalyzeNoteFrequencyResponse_THRESHOLD, AudioAnalyzeNoteFrequencyResponse_AVAILABLE, AudioAnalyzeNoteFrequencyResponse_READ, AudioAnalyzeNoteFrequencyResponse_PROBABILITY};

class AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse
{
    public:
        AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioAnalyzeNoteFrequencyAvailableResponse
{
    public:
        AudioAnalyzeNoteFrequencyAvailableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioAnalyzeNoteFrequencyReadResponse
{
    public:
        AudioAnalyzeNoteFrequencyReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

class AudioAnalyzeNoteFrequencyProbabilityResponse
{
    public:
        AudioAnalyzeNoteFrequencyProbabilityResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif