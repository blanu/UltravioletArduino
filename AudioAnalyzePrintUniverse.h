//
// AudioAnalyzePrintUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePrintUniverse_h_
#define AudioAnalyzePrintUniverse_h_

#include "AudioAnalyzePrintMessages.h"
#include "AudioAnalyzePrintModule.h"

class AudioAnalyzePrintUniverse
{
    public:
        AudioAnalyzePrintUniverse(AudioAnalyzePrintModule *handler) : module(handler) {}

        AudioAnalyzePrintModule *module;

        void trigger();
};

#endif