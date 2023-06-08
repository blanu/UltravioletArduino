//
// AudioMixer4Module.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioMixer4Module_h_
#define AudioMixer4Module_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioMixer4Messages.h"

class AudioMixer4Module
{
    public:
        AudioMixer4Module(AudioMixer4 *component) : logic(component) {}

        AudioMixer4 *logic;
        AudioMixer4Response *handle(AudioMixer4Request *request);
};

#endif