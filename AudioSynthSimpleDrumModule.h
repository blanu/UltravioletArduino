//
// AudioSynthSimpleDrumModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthSimpleDrumModule_h_
#define AudioSynthSimpleDrumModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthSimpleDrumMessages.h"

class AudioSynthSimpleDrumModule
{
    public:
        AudioSynthSimpleDrumModule(AudioSynthSimpleDrum *component) : logic(component) {}

        AudioSynthSimpleDrum *logic;
        AudioSynthSimpleDrumResponse *handle(AudioSynthSimpleDrumRequest *request);
};

#endif