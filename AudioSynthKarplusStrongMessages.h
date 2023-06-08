//
//  AudioSynthKarplusStrongMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthKarplusStrongMessages_h_
#define AudioSynthKarplusStrongMessages_h_

#include <Arduino.h>

class AudioSynthKarplusStrongRequest
{
    public:
        AudioSynthKarplusStrongRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthKarplusStrongResponse
{
    public:
        AudioSynthKarplusStrongResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthKarplusStrongRequestType {AudioSynthKarplusStrongRequest_NOTEON, AudioSynthKarplusStrongRequest_NOTEOFF};

class AudioSynthKarplusStrongNoteonRequest
{
    public:
        AudioSynthKarplusStrongNoteonRequest(float frequency, float velocity)
        {
            this->frequency = frequency;
            this->velocity = velocity;
        }

        float frequency;
        float velocity;
};

class AudioSynthKarplusStrongNoteoffRequest
{
    public:
        AudioSynthKarplusStrongNoteoffRequest(float velocity)
        {
            this->velocity = velocity;
        }

        float velocity;
};

enum AudioSynthKarplusStrongResponseType {AudioSynthKarplusStrongResponse_ERROR, AudioSynthKarplusStrongResponse_NOTEON, AudioSynthKarplusStrongResponse_NOTEOFF};



#endif