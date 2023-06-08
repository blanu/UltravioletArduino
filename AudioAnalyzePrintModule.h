//
// AudioAnalyzePrintModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePrintModule_h_
#define AudioAnalyzePrintModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzePrintMessages.h"

class AudioAnalyzePrintModule
{
    public:
        AudioAnalyzePrintModule(AudioAnalyzePrint *component) : logic(component) {}

        AudioAnalyzePrint *logic;
        AudioAnalyzePrintResponse *handle(AudioAnalyzePrintRequest *request);
};

#endif