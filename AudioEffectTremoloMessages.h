//
//  AudioEffectTremoloMessages.h
//
//
//  Created by Clockwork on Jun 5, 2023.
//

#ifndef AudioEffectTremoloMessages_h_
#define AudioEffectTremoloMessages_h_

#include <Arduino.h>

class AudioEffectTremoloRequest
{
    public:
        AudioEffectTremoloRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectTremoloResponse
{
    public:
        AudioEffectTremoloResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectTremoloRequestType {AudioEffectTremoloRequest_BEGIN};

class AudioEffectTremoloBeginRequest
{
    public:
        AudioEffectTremoloBeginRequest(uint32_t milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        uint32_t milliseconds;
};

enum AudioEffectTremoloResponseType {AudioEffectTremoloResponse_ERROR, AudioEffectTremoloResponse_BEGIN};



#endif