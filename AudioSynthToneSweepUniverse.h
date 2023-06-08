//
// AudioSynthToneSweepUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthToneSweepUniverse_h_
#define AudioSynthToneSweepUniverse_h_

#include "AudioSynthToneSweepMessages.h"
#include "AudioSynthToneSweepModule.h"

class AudioSynthToneSweepUniverse
{
    public:
        AudioSynthToneSweepUniverse(AudioSynthToneSweepModule *handler) : module(handler) {}

        AudioSynthToneSweepModule *module;

        boolean play(float t_amp, int t_lo, int t_hi, float t_time);
        unsigned char isPlaying();
};

#endif