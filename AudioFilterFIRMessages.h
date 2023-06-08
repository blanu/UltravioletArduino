//
//  AudioFilterFIRMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterFIRMessages_h_
#define AudioFilterFIRMessages_h_

#include <Arduino.h>

class AudioFilterFIRRequest
{
    public:
        AudioFilterFIRRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioFilterFIRResponse
{
    public:
        AudioFilterFIRResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioFilterFIRRequestType {AudioFilterFIRRequest_END};



enum AudioFilterFIRResponseType {AudioFilterFIRResponse_ERROR, AudioFilterFIRResponse_END};



#endif