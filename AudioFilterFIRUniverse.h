//
// AudioFilterFIRUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterFIRUniverse_h_
#define AudioFilterFIRUniverse_h_

#include "AudioFilterFIRMessages.h"
#include "AudioFilterFIRModule.h"

class AudioFilterFIRUniverse
{
    public:
        AudioFilterFIRUniverse(AudioFilterFIRModule *handler) : module(handler) {}

        AudioFilterFIRModule *module;

        void end();
};

#endif