#include <Arduino.h>
#include "Audio.h"
#include "main.hpp"
#include "AudioControlSGTL5000Module.h"
#include "AudioControlSGTL5000Universe.h"
#include "AudioInputI2SModule.h"
#include "AudioInputI2SUniverse.h"
#include "AudioEffectTremoloModule.h"
#include "AudioEffectTremoloUniverse.h"
#include "AudioMixer4Module.h"
#include "AudioMixer4Universe.h"
#include "AudioOutputI2SModule.h"
#include "AudioOutputI2SUniverse.h"

AudioControlSGTL5000 codec;
AudioControlSGTL5000Module codecModule(&codec);
AudioControlSGTL5000Universe codecUniverse(&codecModule);
AudioInputI2S input;
AudioInputI2SModule inputModule(&input);
AudioInputI2SUniverse inputUniverse(&inputModule);
AudioEffectTremolo tremolo;
AudioEffectTremoloModule tremoloModule(&tremolo);
AudioEffectTremoloUniverse tremoloUniverse(&tremoloModule);
AudioMixer4 mixer;
AudioMixer4Module mixerModule(&mixer);
AudioMixer4Universe mixerUniverse(&mixerModule);
AudioOutputI2S output;
AudioOutputI2SModule outputModule(&output);
AudioOutputI2SUniverse outputUniverse(&outputModule);

Main mainInstance(&codecUniverse, &mixerUniverse, &tremoloUniverse);

AudioConnection connection0_0a(input, 0, tremolo, 0);
AudioConnection connection0_0b(input, 1, tremolo, 1);
AudioConnection connection0_1a(tremolo, 0, mixer, 0);
AudioConnection connection0_1b(tremolo, 1, mixer, 1);
AudioConnection connection0_2a(mixer, 0, output, 0);
AudioConnection connection0_2b(mixer, 1, output, 1);
AudioConnection connection1_0a(input, 0, mixer, 0);
AudioConnection connection1_0b(input, 1, mixer, 1);

void setup()
{
    mainInstance.setup();
}

void loop()
{

}
