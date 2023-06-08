//
// AudioEffectBitcrusherUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectBitcrusherUniverse_h_
#define AudioEffectBitcrusherUniverse_h_

#include "AudioEffectBitcrusherMessages.h"
#include "AudioEffectBitcrusherModule.h"

class AudioEffectBitcrusherUniverse
{
    public:
        AudioEffectBitcrusherUniverse(AudioEffectBitcrusherModule *handler) : module(handler) {}

        AudioEffectBitcrusherModule *module;

        void bits(uint8_t b);
        void sampleRate(float hz);
};

#endif