//
//  AudioAnalyzeFFT256Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT256Messages_h_
#define AudioAnalyzeFFT256Messages_h_

#include <Arduino.h>

class AudioAnalyzeFFT256Request
{
    public:
        AudioAnalyzeFFT256Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzeFFT256Response
{
    public:
        AudioAnalyzeFFT256Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzeFFT256RequestType {AudioAnalyzeFFT256Request_WINDOW, AudioAnalyzeFFT256Request_READ, AudioAnalyzeFFT256Request_AVERAGETOGETHER};

class AudioAnalyzeFFT256ReadRequest
{
    public:
        AudioAnalyzeFFT256ReadRequest(unsigned int binNumber)
        {
            this->binNumber = binNumber;
        }

        unsigned int binNumber;
};

class AudioAnalyzeFFT256AveragetogetherRequest
{
    public:
        AudioAnalyzeFFT256AveragetogetherRequest(uint8_t n)
        {
            this->n = n;
        }

        uint8_t n;
};

enum AudioAnalyzeFFT256ResponseType {AudioAnalyzeFFT256Response_ERROR, AudioAnalyzeFFT256Response_WINDOW, AudioAnalyzeFFT256Response_READ, AudioAnalyzeFFT256Response_AVERAGETOGETHER};

class AudioAnalyzeFFT256WindowResponse
{
    public:
        AudioAnalyzeFFT256WindowResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioAnalyzeFFT256ReadResponse
{
    public:
        AudioAnalyzeFFT256ReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif