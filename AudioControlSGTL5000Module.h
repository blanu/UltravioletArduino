//
// AudioControlSGTL5000Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlSGTL5000Module_h_
#define AudioControlSGTL5000Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioControlSGTL5000Messages.h"

class AudioControlSGTL5000Module
{
    public:
        AudioControlSGTL5000Module(AudioControlSGTL5000 *component) : logic(component) {}

        AudioControlSGTL5000 *logic;
        AudioControlSGTL5000Response *handle(AudioControlSGTL5000Request *request);
};

#endif