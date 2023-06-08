//
// AudioSynthWaveformPWMModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformPWMModule_h_
#define AudioSynthWaveformPWMModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthWaveformPWMMessages.h"

class AudioSynthWaveformPWMModule
{
    public:
        AudioSynthWaveformPWMModule(AudioSynthWaveformPWM *component) : logic(component) {}

        AudioSynthWaveformPWM *logic;
        AudioSynthWaveformPWMResponse *handle(AudioSynthWaveformPWMRequest *request);
};

#endif