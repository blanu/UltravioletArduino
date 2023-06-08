//
// AudioEffectFlangeUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectFlangeUniverse_h_
#define AudioEffectFlangeUniverse_h_

#include "AudioEffectFlangeMessages.h"
#include "AudioEffectFlangeModule.h"

class AudioEffectFlangeUniverse
{
    public:
        AudioEffectFlangeUniverse(AudioEffectFlangeModule *handler) : module(handler) {}

        AudioEffectFlangeModule *module;

        boolean voices(int delay_offset, int d_depth, float delay_rate);
};

#endif