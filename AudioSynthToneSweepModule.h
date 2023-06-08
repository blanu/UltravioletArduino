//
// AudioSynthToneSweepModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthToneSweepModule_h_
#define AudioSynthToneSweepModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthToneSweepMessages.h"

class AudioSynthToneSweepModule
{
    public:
        AudioSynthToneSweepModule(AudioSynthToneSweep *component) : logic(component) {}

        AudioSynthToneSweep *logic;
        AudioSynthToneSweepResponse *handle(AudioSynthToneSweepRequest *request);
};

#endif