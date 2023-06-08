//
// AudioControlSGTL5000Universe.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlSGTL5000Universe_h_
#define AudioControlSGTL5000Universe_h_

#include "AudioControlSGTL5000Messages.h"
#include "AudioControlSGTL5000Module.h"

class AudioControlSGTL5000Universe
{
    public:
        AudioControlSGTL5000Universe(AudioControlSGTL5000Module *handler) : module(handler) {}

        AudioControlSGTL5000Module *module;

        void setAddress(uint8_t level);
        bool enable();
        bool inputSelect(int n);
        bool volume(float left, float right);
        bool micGain(unsigned int dB);
        bool lineInLevel(uint8_t left, uint8_t right);
        unsigned short lineOutLevel(uint8_t n);
        unsigned short dacVolume(float n);
        unsigned short adcHighPassFilterEnable();
        unsigned short adcHighPassFilterFreeze();
        unsigned short adcHighPassFilterDisable();
        unsigned short audioPreProcessorEnable();
        unsigned short audioPostProcessorEnable();
        unsigned short audioProcessorDisable();
        unsigned short eqFilterCount(uint8_t n);
        unsigned short eqSelect(uint8_t n);
        unsigned short eqBand(uint8_t bandNum, float n);
        void eqBands(float bass, float mid_bass, float midrange, float mid_treble, float treble);
        unsigned short autoVolumeControl(uint8_t maxGain, uint8_t lbiResponse, uint8_t hardLimit, float threshold, float attack, float decay);
        unsigned short autoVolumeEnable();
        unsigned short autoVolumeDisable();
        unsigned short enhanceBass(float lr_lev, float bass_lev);
        unsigned short enhanceBassEnable();
        unsigned short enhanceBassDisable();
        unsigned short surroundSound(uint8_t width);
        unsigned short surroundSoundEnable();
        unsigned short surroundSoundDisable();
};

#endif