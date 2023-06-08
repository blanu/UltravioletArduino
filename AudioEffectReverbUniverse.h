//
// AudioEffectReverbUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectReverbUniverse_h_
#define AudioEffectReverbUniverse_h_

#include "AudioEffectReverbMessages.h"
#include "AudioEffectReverbModule.h"

class AudioEffectReverbUniverse
{
    public:
        AudioEffectReverbUniverse(AudioEffectReverbModule *handler) : module(handler) {}

        AudioEffectReverbModule *module;

         AudioEffectReverb();
         reverbTime();
};

#endif