//
//  AudioInputI2SMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioInputI2SMessages_h_
#define AudioInputI2SMessages_h_

#include <Arduino.h>

class AudioInputI2SRequest
{
    public:
        AudioInputI2SRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioInputI2SResponse
{
    public:
        AudioInputI2SResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioInputI2SRequestType {AudioInputI2SRequest_BEGIN};



enum AudioInputI2SResponseType {AudioInputI2SResponse_ERROR, AudioInputI2SResponse_BEGIN};



#endif