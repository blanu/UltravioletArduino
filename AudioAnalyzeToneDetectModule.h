//
// AudioAnalyzeToneDetectModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeToneDetectModule_h_
#define AudioAnalyzeToneDetectModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzeToneDetectMessages.h"

class AudioAnalyzeToneDetectModule
{
    public:
        AudioAnalyzeToneDetectModule(AudioAnalyzeToneDetect *component) : logic(component) {}

        AudioAnalyzeToneDetect *logic;
        AudioAnalyzeToneDetectResponse *handle(AudioAnalyzeToneDetectRequest *request);
};

#endif