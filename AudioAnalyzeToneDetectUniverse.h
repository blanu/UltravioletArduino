//
// AudioAnalyzeToneDetectUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeToneDetectUniverse_h_
#define AudioAnalyzeToneDetectUniverse_h_

#include "AudioAnalyzeToneDetectMessages.h"
#include "AudioAnalyzeToneDetectModule.h"

class AudioAnalyzeToneDetectUniverse
{
    public:
        AudioAnalyzeToneDetectUniverse(AudioAnalyzeToneDetectModule *handler) : module(handler) {}

        AudioAnalyzeToneDetectModule *module;

        void frequency(float freq, uint16_t cycles=10);
        void set_params(int32_t coef, uint16_t cycles, uint16_t len);
        bool available();
        float read();
        void threshold(float level);
};

#endif