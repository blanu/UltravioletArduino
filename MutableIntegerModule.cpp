//
//  MutableIntegerModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "MutableIntegerModule.h"

MutableIntegerResponse *MutableIntegerModule::handle(MutableIntegerRequest *request)
{
    switch (request->type)
    {
        case MutableIntegerRequest_SET:
            {
                MutableIntegerSetRequest *parameters = (MutableIntegerSetRequest *)request->body;
                this->logic->set(parameters->newState);
                
                Serial.println("MutableInteger.set -> void");
                return new MutableIntegerResponse(MutableIntegerRequest_SET, NULL);
            }

        case MutableIntegerRequest_SETINT:
            {
                MutableIntegerSetintRequest *parameters = (MutableIntegerSetintRequest *)request->body;
                this->logic->setInt(parameters->newState);
                
                Serial.println("MutableInteger.setInt -> void");
                return new MutableIntegerResponse(MutableIntegerRequest_SETINT, NULL);
            }
    }

    return new MutableIntegerResponse(MutableIntegerResponse_ERROR, NULL);
};