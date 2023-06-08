//
//  AudioSynthNoiseWhiteMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoiseWhiteMessages_h_
#define AudioSynthNoiseWhiteMessages_h_

#include <Arduino.h>

class AudioSynthNoiseWhiteRequest
{
    public:
        AudioSynthNoiseWhiteRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthNoiseWhiteResponse
{
    public:
        AudioSynthNoiseWhiteResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthNoiseWhiteRequestType {AudioSynthNoiseWhiteRequest_AMPLITUDE};

class AudioSynthNoiseWhiteAmplitudeRequest
{
    public:
        AudioSynthNoiseWhiteAmplitudeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioSynthNoiseWhiteResponseType {AudioSynthNoiseWhiteResponse_ERROR, AudioSynthNoiseWhiteResponse_AMPLITUDE};



#endif