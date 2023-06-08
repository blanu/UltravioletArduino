//
// AudioOutputAnalogStereoUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputAnalogStereoUniverse_h_
#define AudioOutputAnalogStereoUniverse_h_

#include "AudioOutputAnalogStereoMessages.h"
#include "AudioOutputAnalogStereoModule.h"

class AudioOutputAnalogStereoUniverse
{
    public:
        AudioOutputAnalogStereoUniverse(AudioOutputAnalogStereoModule *handler) : module(handler) {}

        AudioOutputAnalogStereoModule *module;

        void begin();
        void analogReference(int ref);
};

#endif