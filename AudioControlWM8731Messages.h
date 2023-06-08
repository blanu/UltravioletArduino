//
//  AudioControlWM8731Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlWM8731Messages_h_
#define AudioControlWM8731Messages_h_

#include <Arduino.h>

class AudioControlWM8731Request
{
    public:
        AudioControlWM8731Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioControlWM8731Response
{
    public:
        AudioControlWM8731Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioControlWM8731RequestType {AudioControlWM8731Request_ENABLE};



enum AudioControlWM8731ResponseType {AudioControlWM8731Response_ERROR, AudioControlWM8731Response_ENABLE};

class AudioControlWM8731EnableResponse
{
    public:
        AudioControlWM8731EnableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

#endif