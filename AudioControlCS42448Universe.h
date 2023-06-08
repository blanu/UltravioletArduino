//
// AudioControlCS42448Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS42448Universe_h_
#define AudioControlCS42448Universe_h_

#include "AudioControlCS42448Messages.h"
#include "AudioControlCS42448Module.h"

class AudioControlCS42448Universe
{
    public:
        AudioControlCS42448Universe(AudioControlCS42448Module *handler) : module(handler) {}

        AudioControlCS42448Module *module;

        void setAddress(uint8_t addr);
        bool enable();
        bool disable();
        bool volume(float level);
        return volumeInteger();
        bool inputLevel(float level);
        return inputLevelInteger();
        bool inputSelect(int n);
};

#endif