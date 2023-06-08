//
// AudioAnalyzeFFT1024Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT1024Module_h_
#define AudioAnalyzeFFT1024Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzeFFT1024Messages.h"

class AudioAnalyzeFFT1024Module
{
    public:
        AudioAnalyzeFFT1024Module(AudioAnalyzeFFT1024 *component) : logic(component) {}

        AudioAnalyzeFFT1024 *logic;
        AudioAnalyzeFFT1024Response *handle(AudioAnalyzeFFT1024Request *request);
};

#endif