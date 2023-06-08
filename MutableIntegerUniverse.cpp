//
//  MutableIntegerUniverse.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "MutableIntegerUniverse.h"

void MutableIntegerUniverse::set(Num newState)
{
    MutableIntegerSetRequest *requestBody = new MutableIntegerSetRequest(newState);
    MutableIntegerRequest *request = new MutableIntegerRequest(MutableIntegerRequest_SET, (void *)requestBody);
    MutableIntegerResponse *response = this->module->handle(request);
    if (response->type == MutableIntegerResponse_ERROR)
    {
        Serial.println("ERROR in MutableInteger.set(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

void MutableIntegerUniverse::setInt(int newState)
{
    MutableIntegerSetintRequest *requestBody = new MutableIntegerSetintRequest(newState);
    MutableIntegerRequest *request = new MutableIntegerRequest(MutableIntegerRequest_SETINT, (void *)requestBody);
    MutableIntegerResponse *response = this->module->handle(request);
    if (response->type == MutableIntegerResponse_ERROR)
    {
        Serial.println("ERROR in MutableInteger.setInt(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}