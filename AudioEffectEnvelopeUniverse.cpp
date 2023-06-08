//
//  AudioEffectEnvelopeUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectEnvelopeUniverse.h"

void AudioEffectEnvelopeUniverse::delay(float milliseconds)
{
    AudioEffectEnvelopeDelayRequest *requestBody = new AudioEffectEnvelopeDelayRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_DELAY, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.delay(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::attack(float milliseconds)
{
    AudioEffectEnvelopeAttackRequest *requestBody = new AudioEffectEnvelopeAttackRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_ATTACK, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.attack(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::hold(float milliseconds)
{
    AudioEffectEnvelopeHoldRequest *requestBody = new AudioEffectEnvelopeHoldRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_HOLD, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.hold(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::decay(float milliseconds)
{
    AudioEffectEnvelopeDecayRequest *requestBody = new AudioEffectEnvelopeDecayRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_DECAY, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.decay(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::sustain(float level)
{
    AudioEffectEnvelopeSustainRequest *requestBody = new AudioEffectEnvelopeSustainRequest(level);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_SUSTAIN, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.sustain(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::release(float milliseconds)
{
    AudioEffectEnvelopeReleaseRequest *requestBody = new AudioEffectEnvelopeReleaseRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_RELEASE, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.release(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void AudioEffectEnvelopeUniverse::releaseNoteOn(float milliseconds)
{
    AudioEffectEnvelopeReleasenoteonRequest *requestBody = new AudioEffectEnvelopeReleasenoteonRequest(milliseconds);
    AudioEffectEnvelopeRequest *request = new AudioEffectEnvelopeRequest(AudioEffectEnvelopeRequest_RELEASENOTEON, (void *)requestBody);
    AudioEffectEnvelopeResponse *response = this->module->handle(request);
    if (response->type == AudioEffectEnvelopeResponse_ERROR)
    {
        Serial.println("ERROR in AudioEffectEnvelope.releaseNoteOn(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}