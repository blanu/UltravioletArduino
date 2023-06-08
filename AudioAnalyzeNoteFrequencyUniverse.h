//
// AudioAnalyzeNoteFrequencyUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeNoteFrequencyUniverse_h_
#define AudioAnalyzeNoteFrequencyUniverse_h_

#include "AudioAnalyzeNoteFrequencyMessages.h"
#include "AudioAnalyzeNoteFrequencyModule.h"

class AudioAnalyzeNoteFrequencyUniverse
{
    public:
        AudioAnalyzeNoteFrequencyUniverse(AudioAnalyzeNoteFrequencyModule *handler) : module(handler) {}

        AudioAnalyzeNoteFrequencyModule *module;

         AudioAnalyzeNoteFrequency();
        void begin(float threshold);
        void threshold(float p);
        bool available();
        float read();
        float probability();
};

#endif