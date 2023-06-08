//
// AudioOutputAnalogStereoModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputAnalogStereoModule_h_
#define AudioOutputAnalogStereoModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioOutputAnalogStereoMessages.h"

class AudioOutputAnalogStereoModule
{
    public:
        AudioOutputAnalogStereoModule(AudioOutputAnalogStereo *component) : logic(component) {}

        AudioOutputAnalogStereo *logic;
        AudioOutputAnalogStereoResponse *handle(AudioOutputAnalogStereoRequest *request);
};

#endif