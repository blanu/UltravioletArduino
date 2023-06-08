//
// AudioOutputI2SModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputI2SModule_h_
#define AudioOutputI2SModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioOutputI2SMessages.h"

class AudioOutputI2SModule
{
    public:
        AudioOutputI2SModule(AudioOutputI2S *component) : logic(component) {}

        AudioOutputI2S *logic;
        AudioOutputI2SResponse *handle(AudioOutputI2SRequest *request);
};

#endif