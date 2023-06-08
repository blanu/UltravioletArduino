//
// AudioAnalyzePeakUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePeakUniverse_h_
#define AudioAnalyzePeakUniverse_h_

#include "AudioAnalyzePeakMessages.h"
#include "AudioAnalyzePeakModule.h"

class AudioAnalyzePeakUniverse
{
    public:
        AudioAnalyzePeakUniverse(AudioAnalyzePeakModule *handler) : module(handler) {}

        AudioAnalyzePeakModule *module;

        bool available();
        float read();
        float readPeakToPeak();
};

#endif