//
//  AudioPlayQueueMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayQueueMessages_h_
#define AudioPlayQueueMessages_h_

#include <Arduino.h>

class AudioPlayQueueRequest
{
    public:
        AudioPlayQueueRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioPlayQueueResponse
{
    public:
        AudioPlayQueueResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioPlayQueueRequestType {AudioPlayQueueRequest_PLAY, AudioPlayQueueRequest_AVAILABLE, AudioPlayQueueRequest_PLAYBUFFER, AudioPlayQueueRequest_STOP};

class AudioPlayQueuePlayRequest
{
    public:
        AudioPlayQueuePlayRequest(int16_t data)
        {
            this->data = data;
        }

        int16_t data;
};

enum AudioPlayQueueResponseType {AudioPlayQueueResponse_ERROR, AudioPlayQueueResponse_PLAY, AudioPlayQueueResponse_AVAILABLE, AudioPlayQueueResponse_PLAYBUFFER, AudioPlayQueueResponse_STOP};

class AudioPlayQueueAvailableResponse
{
    public:
        AudioPlayQueueAvailableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

#endif