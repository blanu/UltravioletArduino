//
// AudioFilterStateVariableUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterStateVariableUniverse_h_
#define AudioFilterStateVariableUniverse_h_

#include "AudioFilterStateVariableMessages.h"
#include "AudioFilterStateVariableModule.h"

class AudioFilterStateVariableUniverse
{
    public:
        AudioFilterStateVariableUniverse(AudioFilterStateVariableModule *handler) : module(handler) {}

        AudioFilterStateVariableModule *module;

        void frequency(float freq);
        void resonance(float q);
        void octaveControl(float n);
};

#endif