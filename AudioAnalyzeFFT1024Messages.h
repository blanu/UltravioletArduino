//
//  AudioAnalyzeFFT1024Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT1024Messages_h_
#define AudioAnalyzeFFT1024Messages_h_

#include <Arduino.h>

class AudioAnalyzeFFT1024Request
{
    public:
        AudioAnalyzeFFT1024Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzeFFT1024Response
{
    public:
        AudioAnalyzeFFT1024Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzeFFT1024RequestType {AudioAnalyzeFFT1024Request_WINDOW, AudioAnalyzeFFT1024Request_READ, AudioAnalyzeFFT1024Request_AVERAGETOGETHER};

class AudioAnalyzeFFT1024ReadRequest
{
    public:
        AudioAnalyzeFFT1024ReadRequest(unsigned int binNumber)
        {
            this->binNumber = binNumber;
        }

        unsigned int binNumber;
};

class AudioAnalyzeFFT1024AveragetogetherRequest
{
    public:
        AudioAnalyzeFFT1024AveragetogetherRequest(uint8_t n)
        {
            this->n = n;
        }

        uint8_t n;
};

enum AudioAnalyzeFFT1024ResponseType {AudioAnalyzeFFT1024Response_ERROR, AudioAnalyzeFFT1024Response_WINDOW, AudioAnalyzeFFT1024Response_READ, AudioAnalyzeFFT1024Response_AVERAGETOGETHER};

class AudioAnalyzeFFT1024WindowResponse
{
    public:
        AudioAnalyzeFFT1024WindowResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioAnalyzeFFT1024ReadResponse
{
    public:
        AudioAnalyzeFFT1024ReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif