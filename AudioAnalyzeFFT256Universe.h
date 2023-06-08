//
// AudioAnalyzeFFT256Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT256Universe_h_
#define AudioAnalyzeFFT256Universe_h_

#include "AudioAnalyzeFFT256Messages.h"
#include "AudioAnalyzeFFT256Module.h"

class AudioAnalyzeFFT256Universe
{
    public:
        AudioAnalyzeFFT256Universe(AudioAnalyzeFFT256Module *handler) : module(handler) {}

        AudioAnalyzeFFT256Module *module;

         window();
        float read(unsigned int binNumber);
        void averageTogether(uint8_t n);
};

#endif