//
//  AudioEffectEnvelopeMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectEnvelopeMessages_h_
#define AudioEffectEnvelopeMessages_h_

#include <Arduino.h>

class AudioEffectEnvelopeRequest
{
    public:
        AudioEffectEnvelopeRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectEnvelopeResponse
{
    public:
        AudioEffectEnvelopeResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectEnvelopeRequestType {AudioEffectEnvelopeRequest_DELAY, AudioEffectEnvelopeRequest_ATTACK, AudioEffectEnvelopeRequest_HOLD, AudioEffectEnvelopeRequest_DECAY, AudioEffectEnvelopeRequest_SUSTAIN, AudioEffectEnvelopeRequest_RELEASE, AudioEffectEnvelopeRequest_RELEASENOTEON};

class AudioEffectEnvelopeDelayRequest
{
    public:
        AudioEffectEnvelopeDelayRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

class AudioEffectEnvelopeAttackRequest
{
    public:
        AudioEffectEnvelopeAttackRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

class AudioEffectEnvelopeHoldRequest
{
    public:
        AudioEffectEnvelopeHoldRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

class AudioEffectEnvelopeDecayRequest
{
    public:
        AudioEffectEnvelopeDecayRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

class AudioEffectEnvelopeSustainRequest
{
    public:
        AudioEffectEnvelopeSustainRequest(float level)
        {
            this->level = level;
        }

        float level;
};

class AudioEffectEnvelopeReleaseRequest
{
    public:
        AudioEffectEnvelopeReleaseRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

class AudioEffectEnvelopeReleasenoteonRequest
{
    public:
        AudioEffectEnvelopeReleasenoteonRequest(float milliseconds)
        {
            this->milliseconds = milliseconds;
        }

        float milliseconds;
};

enum AudioEffectEnvelopeResponseType {AudioEffectEnvelopeResponse_ERROR, AudioEffectEnvelopeResponse_DELAY, AudioEffectEnvelopeResponse_ATTACK, AudioEffectEnvelopeResponse_HOLD, AudioEffectEnvelopeResponse_DECAY, AudioEffectEnvelopeResponse_SUSTAIN, AudioEffectEnvelopeResponse_RELEASE, AudioEffectEnvelopeResponse_RELEASENOTEON};



#endif