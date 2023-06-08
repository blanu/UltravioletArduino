//
//  AudioAnalyzePrintMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioAnalyzePrintMessages_h_
#define AudioAnalyzePrintMessages_h_

#include <Arduino.h>

class AudioAnalyzePrintRequest
{
    public:
        AudioAnalyzePrintRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioAnalyzePrintResponse
{
    public:
        AudioAnalyzePrintResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioAnalyzePrintRequestType {AudioAnalyzePrintRequest_TRIGGER};



enum AudioAnalyzePrintResponseType {AudioAnalyzePrintResponse_ERROR, AudioAnalyzePrintResponse_TRIGGER};



#endif