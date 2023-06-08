//
//  AudioControlCS42448Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS42448Messages_h_
#define AudioControlCS42448Messages_h_

#include <Arduino.h>

class AudioControlCS42448Request
{
    public:
        AudioControlCS42448Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioControlCS42448Response
{
    public:
        AudioControlCS42448Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioControlCS42448RequestType {AudioControlCS42448Request_SETADDRESS, AudioControlCS42448Request_ENABLE, AudioControlCS42448Request_DISABLE, AudioControlCS42448Request_VOLUME, AudioControlCS42448Request_VOLUMEINTEGER, AudioControlCS42448Request_INPUTLEVEL, AudioControlCS42448Request_INPUTLEVELINTEGER, AudioControlCS42448Request_INPUTSELECT};

class AudioControlCS42448SetaddressRequest
{
    public:
        AudioControlCS42448SetaddressRequest(uint8_t addr)
        {
            this->addr = addr;
        }

        uint8_t addr;
};

class AudioControlCS42448VolumeRequest
{
    public:
        AudioControlCS42448VolumeRequest(float level)
        {
            this->level = level;
        }

        float level;
};

class AudioControlCS42448InputlevelRequest
{
    public:
        AudioControlCS42448InputlevelRequest(float level)
        {
            this->level = level;
        }

        float level;
};

class AudioControlCS42448InputselectRequest
{
    public:
        AudioControlCS42448InputselectRequest(int n)
        {
            this->n = n;
        }

        int n;
};

enum AudioControlCS42448ResponseType {AudioControlCS42448Response_ERROR, AudioControlCS42448Response_SETADDRESS, AudioControlCS42448Response_ENABLE, AudioControlCS42448Response_DISABLE, AudioControlCS42448Response_VOLUME, AudioControlCS42448Response_VOLUMEINTEGER, AudioControlCS42448Response_INPUTLEVEL, AudioControlCS42448Response_INPUTLEVELINTEGER, AudioControlCS42448Response_INPUTSELECT};

class AudioControlCS42448EnableResponse
{
    public:
        AudioControlCS42448EnableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS42448DisableResponse
{
    public:
        AudioControlCS42448DisableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS42448VolumeResponse
{
    public:
        AudioControlCS42448VolumeResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS42448VolumeintegerResponse
{
    public:
        AudioControlCS42448VolumeintegerResponse(return value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        return value;
};

class AudioControlCS42448InputlevelResponse
{
    public:
        AudioControlCS42448InputlevelResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS42448InputlevelintegerResponse
{
    public:
        AudioControlCS42448InputlevelintegerResponse(return value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        return value;
};

class AudioControlCS42448InputselectResponse
{
    public:
        AudioControlCS42448InputselectResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

#endif