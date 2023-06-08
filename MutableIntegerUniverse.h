//
// MutableIntegerUniverse.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef MutableIntegerUniverse_h_
#define MutableIntegerUniverse_h_

#include "MutableIntegerMessages.h"
#include "MutableIntegerModule.h"

class MutableIntegerUniverse
{
    public:
        MutableIntegerUniverse(MutableIntegerModule *handler) : module(handler) {}

        MutableIntegerModule *module;

        void set(Num newState);
        void setInt(int newState);
};

#endif