//
// AudioControlCS42448Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS42448Module_h_
#define AudioControlCS42448Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioControlCS42448Messages.h"

class AudioControlCS42448Module
{
    public:
        AudioControlCS42448Module(AudioControlCS42448 *component) : logic(component) {}

        AudioControlCS42448 *logic;
        AudioControlCS42448Response *handle(AudioControlCS42448Request *request);
};

#endif