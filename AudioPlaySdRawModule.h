//
// AudioPlaySdRawModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlaySdRawModule_h_
#define AudioPlaySdRawModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioPlaySdRawMessages.h"

class AudioPlaySdRawModule
{
    public:
        AudioPlaySdRawModule(AudioPlaySdRaw *component) : logic(component) {}

        AudioPlaySdRaw *logic;
        AudioPlaySdRawResponse *handle(AudioPlaySdRawRequest *request);
};

#endif