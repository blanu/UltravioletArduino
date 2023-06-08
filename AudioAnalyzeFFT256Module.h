//
// AudioAnalyzeFFT256Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeFFT256Module_h_
#define AudioAnalyzeFFT256Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzeFFT256Messages.h"

class AudioAnalyzeFFT256Module
{
    public:
        AudioAnalyzeFFT256Module(AudioAnalyzeFFT256 *component) : logic(component) {}

        AudioAnalyzeFFT256 *logic;
        AudioAnalyzeFFT256Response *handle(AudioAnalyzeFFT256Request *request);
};

#endif