//
//  AudioOutputAnalogStereoMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioOutputAnalogStereoMessages_h_
#define AudioOutputAnalogStereoMessages_h_

#include <Arduino.h>

class AudioOutputAnalogStereoRequest
{
    public:
        AudioOutputAnalogStereoRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioOutputAnalogStereoResponse
{
    public:
        AudioOutputAnalogStereoResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioOutputAnalogStereoRequestType {AudioOutputAnalogStereoRequest_BEGIN, AudioOutputAnalogStereoRequest_ANALOGREFERENCE};

class AudioOutputAnalogStereoAnalogreferenceRequest
{
    public:
        AudioOutputAnalogStereoAnalogreferenceRequest(int ref)
        {
            this->ref = ref;
        }

        int ref;
};

enum AudioOutputAnalogStereoResponseType {AudioOutputAnalogStereoResponse_ERROR, AudioOutputAnalogStereoResponse_BEGIN, AudioOutputAnalogStereoResponse_ANALOGREFERENCE};



#endif