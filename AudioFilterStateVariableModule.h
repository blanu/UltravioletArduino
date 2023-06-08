//
// AudioFilterStateVariableModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterStateVariableModule_h_
#define AudioFilterStateVariableModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioFilterStateVariableMessages.h"

class AudioFilterStateVariableModule
{
    public:
        AudioFilterStateVariableModule(AudioFilterStateVariable *component) : logic(component) {}

        AudioFilterStateVariable *logic;
        AudioFilterStateVariableResponse *handle(AudioFilterStateVariableRequest *request);
};

#endif