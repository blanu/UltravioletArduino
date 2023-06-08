//
// AudioSynthSimpleDrumUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthSimpleDrumUniverse_h_
#define AudioSynthSimpleDrumUniverse_h_

#include "AudioSynthSimpleDrumMessages.h"
#include "AudioSynthSimpleDrumModule.h"

class AudioSynthSimpleDrumUniverse
{
    public:
        AudioSynthSimpleDrumUniverse(AudioSynthSimpleDrumModule *handler) : module(handler) {}

        AudioSynthSimpleDrumModule *module;

         length();
         frequency();
         pitchMod();
        void secondMix(float level);
};

#endif