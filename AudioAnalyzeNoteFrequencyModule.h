//
// AudioAnalyzeNoteFrequencyModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeNoteFrequencyModule_h_
#define AudioAnalyzeNoteFrequencyModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzeNoteFrequencyMessages.h"

class AudioAnalyzeNoteFrequencyModule
{
    public:
        AudioAnalyzeNoteFrequencyModule(AudioAnalyzeNoteFrequency *component) : logic(component) {}

        AudioAnalyzeNoteFrequency *logic;
        AudioAnalyzeNoteFrequencyResponse *handle(AudioAnalyzeNoteFrequencyRequest *request);
};

#endif