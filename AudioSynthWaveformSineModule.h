//
// AudioSynthWaveformSineModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformSineModule_h_
#define AudioSynthWaveformSineModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthWaveformSineMessages.h"

class AudioSynthWaveformSineModule
{
    public:
        AudioSynthWaveformSineModule(AudioSynthWaveformSine *component) : logic(component) {}

        AudioSynthWaveformSine *logic;
        AudioSynthWaveformSineResponse *handle(AudioSynthWaveformSineRequest *request);
};

#endif