//
//  AudioAnalyzeRMSMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzeRMSMessages_h_
#define AudioAnalyzeRMSMessages_h_

#include <Arduino.h>

class AudioAnalyzeRMSRequest
{
    public:
        AudioAnalyzeRMSRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzeRMSResponse
{
    public:
        AudioAnalyzeRMSResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzeRMSRequestType {AudioAnalyzeRMSRequest_AVAILABLE, AudioAnalyzeRMSRequest_READ};



enum AudioAnalyzeRMSResponseType {AudioAnalyzeRMSResponse_ERROR, AudioAnalyzeRMSResponse_AVAILABLE, AudioAnalyzeRMSResponse_READ};

class AudioAnalyzeRMSAvailableResponse
{
    public:
        AudioAnalyzeRMSAvailableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioAnalyzeRMSReadResponse
{
    public:
        AudioAnalyzeRMSReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif