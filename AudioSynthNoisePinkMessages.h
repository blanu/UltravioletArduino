//
//  AudioSynthNoisePinkMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoisePinkMessages_h_
#define AudioSynthNoisePinkMessages_h_

#include <Arduino.h>

class AudioSynthNoisePinkRequest
{
    public:
        AudioSynthNoisePinkRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthNoisePinkResponse
{
    public:
        AudioSynthNoisePinkResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthNoisePinkRequestType {AudioSynthNoisePinkRequest_AMPLITUDE};

class AudioSynthNoisePinkAmplitudeRequest
{
    public:
        AudioSynthNoisePinkAmplitudeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioSynthNoisePinkResponseType {AudioSynthNoisePinkResponse_ERROR, AudioSynthNoisePinkResponse_AMPLITUDE};



#endif