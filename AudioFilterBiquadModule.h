//
// AudioFilterBiquadModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterBiquadModule_h_
#define AudioFilterBiquadModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioFilterBiquadMessages.h"

class AudioFilterBiquadModule
{
    public:
        AudioFilterBiquadModule(AudioFilterBiquad *component) : logic(component) {}

        AudioFilterBiquad *logic;
        AudioFilterBiquadResponse *handle(AudioFilterBiquadRequest *request);
};

#endif