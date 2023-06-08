//
//  AudioEffectEnvelopeModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectEnvelopeModule.h"

AudioEffectEnvelopeResponse *AudioEffectEnvelopeModule::handle(AudioEffectEnvelopeRequest *request)
{
    switch (request->type)
    {
        case AudioEffectEnvelopeRequest_DELAY:
            {
                AudioEffectEnvelopeDelayRequest *parameters = (AudioEffectEnvelopeDelayRequest *)request->body;
                this->logic->delay(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.delay -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_DELAY, NULL);
            }

        case AudioEffectEnvelopeRequest_ATTACK:
            {
                AudioEffectEnvelopeAttackRequest *parameters = (AudioEffectEnvelopeAttackRequest *)request->body;
                this->logic->attack(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.attack -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_ATTACK, NULL);
            }

        case AudioEffectEnvelopeRequest_HOLD:
            {
                AudioEffectEnvelopeHoldRequest *parameters = (AudioEffectEnvelopeHoldRequest *)request->body;
                this->logic->hold(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.hold -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_HOLD, NULL);
            }

        case AudioEffectEnvelopeRequest_DECAY:
            {
                AudioEffectEnvelopeDecayRequest *parameters = (AudioEffectEnvelopeDecayRequest *)request->body;
                this->logic->decay(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.decay -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_DECAY, NULL);
            }

        case AudioEffectEnvelopeRequest_SUSTAIN:
            {
                AudioEffectEnvelopeSustainRequest *parameters = (AudioEffectEnvelopeSustainRequest *)request->body;
                this->logic->sustain(parameters->level);
                
                Serial.println("AudioEffectEnvelope.sustain -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_SUSTAIN, NULL);
            }

        case AudioEffectEnvelopeRequest_RELEASE:
            {
                AudioEffectEnvelopeReleaseRequest *parameters = (AudioEffectEnvelopeReleaseRequest *)request->body;
                this->logic->release(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.release -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_RELEASE, NULL);
            }

        case AudioEffectEnvelopeRequest_RELEASENOTEON:
            {
                AudioEffectEnvelopeReleasenoteonRequest *parameters = (AudioEffectEnvelopeReleasenoteonRequest *)request->body;
                this->logic->releaseNoteOn(parameters->milliseconds);
                
                Serial.println("AudioEffectEnvelope.releaseNoteOn -> void");
                return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeRequest_RELEASENOTEON, NULL);
            }
    }

    return new AudioEffectEnvelopeResponse(AudioEffectEnvelopeResponse_ERROR, NULL);
};