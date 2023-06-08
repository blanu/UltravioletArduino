//
// AudioAnalyzePeakModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePeakModule_h_
#define AudioAnalyzePeakModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzePeakMessages.h"

class AudioAnalyzePeakModule
{
    public:
        AudioAnalyzePeakModule(AudioAnalyzePeak *component) : logic(component) {}

        AudioAnalyzePeak *logic;
        AudioAnalyzePeakResponse *handle(AudioAnalyzePeakRequest *request);
};

#endif