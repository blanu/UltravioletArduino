//
// AudioControlCS4272Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS4272Module_h_
#define AudioControlCS4272Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioControlCS4272Messages.h"

class AudioControlCS4272Module
{
    public:
        AudioControlCS4272Module(AudioControlCS4272 *component) : logic(component) {}

        AudioControlCS4272 *logic;
        AudioControlCS4272Response *handle(AudioControlCS4272Request *request);
};

#endif