//
// AudioSynthKarplusStrongModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthKarplusStrongModule_h_
#define AudioSynthKarplusStrongModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioSynthKarplusStrongMessages.h"

class AudioSynthKarplusStrongModule
{
    public:
        AudioSynthKarplusStrongModule(AudioSynthKarplusStrong *component) : logic(component) {}

        AudioSynthKarplusStrong *logic;
        AudioSynthKarplusStrongResponse *handle(AudioSynthKarplusStrongRequest *request);
};

#endif