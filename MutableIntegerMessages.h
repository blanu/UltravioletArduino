//
//  MutableIntegerMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef MutableIntegerMessages_h_
#define MutableIntegerMessages_h_

#include <Arduino.h>

class MutableIntegerRequest
{
    public:
        MutableIntegerRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class MutableIntegerResponse
{
    public:
        MutableIntegerResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum MutableIntegerRequestType {MutableIntegerRequest_SET, MutableIntegerRequest_SETINT};

class MutableIntegerSetRequest
{
    public:
        MutableIntegerSetRequest(Num newState)
        {
            this->newState = newState;
        }

        Num newState;
};

class MutableIntegerSetintRequest
{
    public:
        MutableIntegerSetintRequest(int newState)
        {
            this->newState = newState;
        }

        int newState;
};

enum MutableIntegerResponseType {MutableIntegerResponse_ERROR, MutableIntegerResponse_SET, MutableIntegerResponse_SETINT};



#endif