//
//  AudioControlCS4272Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlCS4272Messages_h_
#define AudioControlCS4272Messages_h_

#include <Arduino.h>

class AudioControlCS4272Request
{
    public:
        AudioControlCS4272Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioControlCS4272Response
{
    public:
        AudioControlCS4272Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioControlCS4272RequestType {AudioControlCS4272Request_ENABLE, AudioControlCS4272Request_VOLUME, AudioControlCS4272Request_DACVOLUME, AudioControlCS4272Request_MUTEOUTPUT, AudioControlCS4272Request_UNMUTEOUTPUT, AudioControlCS4272Request_MUTEINPUT, AudioControlCS4272Request_UNMUTEINPUT, AudioControlCS4272Request_ENABLEDITHER, AudioControlCS4272Request_DISABLEDITHER};

class AudioControlCS4272VolumeRequest
{
    public:
        AudioControlCS4272VolumeRequest(float left, float right)
        {
            this->left = left;
            this->right = right;
        }

        float left;
        float right;
};

class AudioControlCS4272DacvolumeRequest
{
    public:
        AudioControlCS4272DacvolumeRequest(float left, float right)
        {
            this->left = left;
            this->right = right;
        }

        float left;
        float right;
};

enum AudioControlCS4272ResponseType {AudioControlCS4272Response_ERROR, AudioControlCS4272Response_ENABLE, AudioControlCS4272Response_VOLUME, AudioControlCS4272Response_DACVOLUME, AudioControlCS4272Response_MUTEOUTPUT, AudioControlCS4272Response_UNMUTEOUTPUT, AudioControlCS4272Response_MUTEINPUT, AudioControlCS4272Response_UNMUTEINPUT, AudioControlCS4272Response_ENABLEDITHER, AudioControlCS4272Response_DISABLEDITHER};

class AudioControlCS4272EnableResponse
{
    public:
        AudioControlCS4272EnableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272VolumeResponse
{
    public:
        AudioControlCS4272VolumeResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272DacvolumeResponse
{
    public:
        AudioControlCS4272DacvolumeResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272MuteoutputResponse
{
    public:
        AudioControlCS4272MuteoutputResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272UnmuteoutputResponse
{
    public:
        AudioControlCS4272UnmuteoutputResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272MuteinputResponse
{
    public:
        AudioControlCS4272MuteinputResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272UnmuteinputResponse
{
    public:
        AudioControlCS4272UnmuteinputResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272EnableditherResponse
{
    public:
        AudioControlCS4272EnableditherResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlCS4272DisableditherResponse
{
    public:
        AudioControlCS4272DisableditherResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

#endif