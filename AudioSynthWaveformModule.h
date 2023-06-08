//
// AudioSynthWaveformModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformModule_h_
#define AudioSynthWaveformModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthWaveformMessages.h"

class AudioSynthWaveformModule
{
    public:
        AudioSynthWaveformModule(AudioSynthWaveform *component) : logic(component) {}

        AudioSynthWaveform *logic;
        AudioSynthWaveformResponse *handle(AudioSynthWaveformRequest *request);
};

#endif