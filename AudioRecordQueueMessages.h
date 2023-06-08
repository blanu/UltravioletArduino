//
//  AudioRecordQueueMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioRecordQueueMessages_h_
#define AudioRecordQueueMessages_h_

#include <Arduino.h>

class AudioRecordQueueRequest
{
    public:
        AudioRecordQueueRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioRecordQueueResponse
{
    public:
        AudioRecordQueueResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioRecordQueueRequestType {AudioRecordQueueRequest_BEGIN, AudioRecordQueueRequest_AVAILABLE, AudioRecordQueueRequest_CLEAR, AudioRecordQueueRequest_FREEBUFFER, AudioRecordQueueRequest_END};



enum AudioRecordQueueResponseType {AudioRecordQueueResponse_ERROR, AudioRecordQueueResponse_BEGIN, AudioRecordQueueResponse_AVAILABLE, AudioRecordQueueResponse_CLEAR, AudioRecordQueueResponse_FREEBUFFER, AudioRecordQueueResponse_END};

class AudioRecordQueueAvailableResponse
{
    public:
        AudioRecordQueueAvailableResponse(int value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        int value;
};

#endif