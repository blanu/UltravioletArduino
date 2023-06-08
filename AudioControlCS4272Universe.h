//
// AudioControlCS4272Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS4272Universe_h_
#define AudioControlCS4272Universe_h_

#include "AudioControlCS4272Messages.h"
#include "AudioControlCS4272Module.h"

class AudioControlCS4272Universe
{
    public:
        AudioControlCS4272Universe(AudioControlCS4272Module *handler) : module(handler) {}

        AudioControlCS4272Module *module;

        bool enable();
        bool volume(float left, float right);
        bool dacVolume(float left, float right);
        bool muteOutput();
        bool unmuteOutput();
        bool muteInput();
        bool unmuteInput();
        bool enableDither();
        bool disableDither();
};

#endif