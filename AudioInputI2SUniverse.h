//
// AudioInputI2SUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioInputI2SUniverse_h_
#define AudioInputI2SUniverse_h_

#include "AudioInputI2SMessages.h"
#include "AudioInputI2SModule.h"

class AudioInputI2SUniverse
{
    public:
        AudioInputI2SUniverse(AudioInputI2SModule *handler) : module(handler) {}

        AudioInputI2SModule *module;

        void begin();
};

#endif