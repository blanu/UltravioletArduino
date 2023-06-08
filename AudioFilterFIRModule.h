//
// AudioFilterFIRModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterFIRModule_h_
#define AudioFilterFIRModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioFilterFIRMessages.h"

class AudioFilterFIRModule
{
    public:
        AudioFilterFIRModule(AudioFilterFIR *component) : logic(component) {}

        AudioFilterFIR *logic;
        AudioFilterFIRResponse *handle(AudioFilterFIRRequest *request);
};

#endif