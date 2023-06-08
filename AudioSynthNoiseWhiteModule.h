//
// AudioSynthNoiseWhiteModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthNoiseWhiteModule_h_
#define AudioSynthNoiseWhiteModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthNoiseWhiteMessages.h"

class AudioSynthNoiseWhiteModule
{
    public:
        AudioSynthNoiseWhiteModule(AudioSynthNoiseWhite *component) : logic(component) {}

        AudioSynthNoiseWhite *logic;
        AudioSynthNoiseWhiteResponse *handle(AudioSynthNoiseWhiteRequest *request);
};

#endif