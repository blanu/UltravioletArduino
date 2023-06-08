//
// AudioEffectTremoloUniverse.h
//
//
//  Created by Clockwork on Jun 5, 2023.
//

#ifndef AudioEffectTremoloUniverse_h_
#define AudioEffectTremoloUniverse_h_

#include "AudioEffectTremoloMessages.h"
#include "AudioEffectTremoloModule.h"

class AudioEffectTremoloUniverse
{
    public:
        AudioEffectTremoloUniverse(AudioEffectTremoloModule *handler) : module(handler) {}

        AudioEffectTremoloModule *module;

        void begin(uint32_t milliseconds);
};

#endif