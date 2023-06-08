//
// AudioControlWM8731Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlWM8731Universe_h_
#define AudioControlWM8731Universe_h_

#include "AudioControlWM8731Messages.h"
#include "AudioControlWM8731Module.h"

class AudioControlWM8731Universe
{
    public:
        AudioControlWM8731Universe(AudioControlWM8731Module *handler) : module(handler) {}

        AudioControlWM8731Module *module;

        bool enable();
};

#endif