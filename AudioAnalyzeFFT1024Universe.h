//
// AudioAnalyzeFFT1024Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT1024Universe_h_
#define AudioAnalyzeFFT1024Universe_h_

#include "AudioAnalyzeFFT1024Messages.h"
#include "AudioAnalyzeFFT1024Module.h"

class AudioAnalyzeFFT1024Universe
{
    public:
        AudioAnalyzeFFT1024Universe(AudioAnalyzeFFT1024Module *handler) : module(handler) {}

        AudioAnalyzeFFT1024Module *module;

         window();
        float read(unsigned int binNumber);
        void averageTogether(uint8_t n);
};

#endif