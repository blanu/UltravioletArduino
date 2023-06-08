//
//  AudioAnalyzePeakMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePeakMessages_h_
#define AudioAnalyzePeakMessages_h_

#include <Arduino.h>

class AudioAnalyzePeakRequest
{
    public:
        AudioAnalyzePeakRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzePeakResponse
{
    public:
        AudioAnalyzePeakResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzePeakRequestType {AudioAnalyzePeakRequest_AVAILABLE, AudioAnalyzePeakRequest_READ, AudioAnalyzePeakRequest_READPEAKTOPEAK};



enum AudioAnalyzePeakResponseType {AudioAnalyzePeakResponse_ERROR, AudioAnalyzePeakResponse_AVAILABLE, AudioAnalyzePeakResponse_READ, AudioAnalyzePeakResponse_READPEAKTOPEAK};

class AudioAnalyzePeakAvailableResponse
{
    public:
        AudioAnalyzePeakAvailableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioAnalyzePeakReadResponse
{
    public:
        AudioAnalyzePeakReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

class AudioAnalyzePeakReadpeaktopeakResponse
{
    public:
        AudioAnalyzePeakReadpeaktopeakResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif