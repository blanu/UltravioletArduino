//
//  AudioPlayMemoryMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayMemoryMessages_h_
#define AudioPlayMemoryMessages_h_

#include <Arduino.h>

class AudioPlayMemoryRequest
{
    public:
        AudioPlayMemoryRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioPlayMemoryResponse
{
    public:
        AudioPlayMemoryResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioPlayMemoryRequestType {AudioPlayMemoryRequest_STOP, AudioPlayMemoryRequest_POSITIONMILLIS, AudioPlayMemoryRequest_LENGTHMILLIS};



enum AudioPlayMemoryResponseType {AudioPlayMemoryResponse_ERROR, AudioPlayMemoryResponse_STOP, AudioPlayMemoryResponse_POSITIONMILLIS, AudioPlayMemoryResponse_LENGTHMILLIS};

class AudioPlayMemoryPositionmillisResponse
{
    public:
        AudioPlayMemoryPositionmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

class AudioPlayMemoryLengthmillisResponse
{
    public:
        AudioPlayMemoryLengthmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

#endif