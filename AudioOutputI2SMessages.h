//
//  AudioOutputI2SMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputI2SMessages_h_
#define AudioOutputI2SMessages_h_

#include <Arduino.h>

class AudioOutputI2SRequest
{
    public:
        AudioOutputI2SRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioOutputI2SResponse
{
    public:
        AudioOutputI2SResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioOutputI2SRequestType {AudioOutputI2SRequest_BEGIN};



enum AudioOutputI2SResponseType {AudioOutputI2SResponse_ERROR, AudioOutputI2SResponse_BEGIN};



#endif