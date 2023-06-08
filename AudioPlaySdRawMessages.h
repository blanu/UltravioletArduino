//
//  AudioPlaySdRawMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlaySdRawMessages_h_
#define AudioPlaySdRawMessages_h_

#include <Arduino.h>

class AudioPlaySdRawRequest
{
    public:
        AudioPlaySdRawRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioPlaySdRawResponse
{
    public:
        AudioPlaySdRawResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioPlaySdRawRequestType {AudioPlaySdRawRequest_BEGIN, AudioPlaySdRawRequest_STOP, AudioPlaySdRawRequest_POSITIONMILLIS, AudioPlaySdRawRequest_LENGTHMILLIS};



enum AudioPlaySdRawResponseType {AudioPlaySdRawResponse_ERROR, AudioPlaySdRawResponse_BEGIN, AudioPlaySdRawResponse_STOP, AudioPlaySdRawResponse_POSITIONMILLIS, AudioPlaySdRawResponse_LENGTHMILLIS};

class AudioPlaySdRawPositionmillisResponse
{
    public:
        AudioPlaySdRawPositionmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

class AudioPlaySdRawLengthmillisResponse
{
    public:
        AudioPlaySdRawLengthmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

#endif