//
// AudioSynthWaveformDcModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformDcModule_h_
#define AudioSynthWaveformDcModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthWaveformDcMessages.h"

class AudioSynthWaveformDcModule
{
    public:
        AudioSynthWaveformDcModule(AudioSynthWaveformDc *component) : logic(component) {}

        AudioSynthWaveformDc *logic;
        AudioSynthWaveformDcResponse *handle(AudioSynthWaveformDcRequest *request);
};

#endif