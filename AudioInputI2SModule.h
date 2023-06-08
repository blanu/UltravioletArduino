//
// AudioInputI2SModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioInputI2SModule_h_
#define AudioInputI2SModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioInputI2SMessages.h"

class AudioInputI2SModule
{
    public:
        AudioInputI2SModule(AudioInputI2S *component) : logic(component) {}

        AudioInputI2S *logic;
        AudioInputI2SResponse *handle(AudioInputI2SRequest *request);
};

#endif