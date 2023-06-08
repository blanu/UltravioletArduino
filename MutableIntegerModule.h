//
// MutableIntegerModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef MutableIntegerModule_h_
#define MutableIntegerModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "MutableIntegerMessages.h"

class MutableIntegerModule
{
    public:
        MutableIntegerModule(MutableInteger *component) : logic(component) {}

        MutableInteger *logic;
        MutableIntegerResponse *handle(MutableIntegerRequest *request);
};

#endif