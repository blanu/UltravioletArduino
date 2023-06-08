//
// AudioFilterBiquadUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterBiquadUniverse_h_
#define AudioFilterBiquadUniverse_h_

#include "AudioFilterBiquadMessages.h"
#include "AudioFilterBiquadModule.h"

class AudioFilterBiquadUniverse
{
    public:
        AudioFilterBiquadUniverse(AudioFilterBiquadModule *handler) : module(handler) {}

        AudioFilterBiquadModule *module;

        void setLowpass(uint32_t stage, float frequency, float q = 0.7071);
        void setHighpass(uint32_t stage, float frequency, float q = 0.7071);
        void setBandpass(uint32_t stage, float frequency, float q = 1.0);
        void setNotch(uint32_t stage, float frequency, float q = 1.0);
        void setLowShelf(uint32_t stage, float frequency, float gain, float slope = 1.0f);
        void setHighShelf(uint32_t stage, float frequency, float gain, float slope = 1.0f);
};

#endif