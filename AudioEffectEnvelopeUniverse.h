//
// AudioEffectEnvelopeUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectEnvelopeUniverse_h_
#define AudioEffectEnvelopeUniverse_h_

#include "AudioEffectEnvelopeMessages.h"
#include "AudioEffectEnvelopeModule.h"

class AudioEffectEnvelopeUniverse
{
    public:
        AudioEffectEnvelopeUniverse(AudioEffectEnvelopeModule *handler) : module(handler) {}

        AudioEffectEnvelopeModule *module;

        void delay(float milliseconds);
        void attack(float milliseconds);
        void hold(float milliseconds);
        void decay(float milliseconds);
        void sustain(float level);
        void release(float milliseconds);
        void releaseNoteOn(float milliseconds);
};

#endif