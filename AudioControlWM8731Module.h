//
// AudioControlWM8731Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlWM8731Module_h_
#define AudioControlWM8731Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioControlWM8731Messages.h"

class AudioControlWM8731Module
{
    public:
        AudioControlWM8731Module(AudioControlWM8731 *component) : logic(component) {}

        AudioControlWM8731 *logic;
        AudioControlWM8731Response *handle(AudioControlWM8731Request *request);
};

#endif