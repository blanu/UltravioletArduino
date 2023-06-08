//
// AudioOutputI2SUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputI2SUniverse_h_
#define AudioOutputI2SUniverse_h_

#include "AudioOutputI2SMessages.h"
#include "AudioOutputI2SModule.h"

class AudioOutputI2SUniverse
{
    public:
        AudioOutputI2SUniverse(AudioOutputI2SModule *handler) : module(handler) {}

        AudioOutputI2SModule *module;

        void begin();
};

#endif