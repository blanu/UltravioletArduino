//
// AudioAnalyzeRMSUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeRMSUniverse_h_
#define AudioAnalyzeRMSUniverse_h_

#include "AudioAnalyzeRMSMessages.h"
#include "AudioAnalyzeRMSModule.h"

class AudioAnalyzeRMSUniverse
{
    public:
        AudioAnalyzeRMSUniverse(AudioAnalyzeRMSModule *handler) : module(handler) {}

        AudioAnalyzeRMSModule *module;

        bool available();
        float read();
};

#endif