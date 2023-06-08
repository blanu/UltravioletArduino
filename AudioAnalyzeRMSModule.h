//
// AudioAnalyzeRMSModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeRMSModule_h_
#define AudioAnalyzeRMSModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioAnalyzeRMSMessages.h"

class AudioAnalyzeRMSModule
{
    public:
        AudioAnalyzeRMSModule(AudioAnalyzeRMS *component) : logic(component) {}

        AudioAnalyzeRMS *logic;
        AudioAnalyzeRMSResponse *handle(AudioAnalyzeRMSRequest *request);
};

#endif