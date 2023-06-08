//
//  AudioFilterStateVariableMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioFilterStateVariableMessages_h_
#define AudioFilterStateVariableMessages_h_

#include <Arduino.h>

class AudioFilterStateVariableRequest
{
    public:
        AudioFilterStateVariableRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioFilterStateVariableResponse
{
    public:
        AudioFilterStateVariableResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioFilterStateVariableRequestType {AudioFilterStateVariableRequest_FREQUENCY, AudioFilterStateVariableRequest_RESONANCE, AudioFilterStateVariableRequest_OCTAVECONTROL};

class AudioFilterStateVariableFrequencyRequest
{
    public:
        AudioFilterStateVariableFrequencyRequest(float freq)
        {
            this->freq = freq;
        }

        float freq;
};

class AudioFilterStateVariableResonanceRequest
{
    public:
        AudioFilterStateVariableResonanceRequest(float q)
        {
            this->q = q;
        }

        float q;
};

class AudioFilterStateVariableOctavecontrolRequest
{
    public:
        AudioFilterStateVariableOctavecontrolRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioFilterStateVariableResponseType {AudioFilterStateVariableResponse_ERROR, AudioFilterStateVariableResponse_FREQUENCY, AudioFilterStateVariableResponse_RESONANCE, AudioFilterStateVariableResponse_OCTAVECONTROL};



#endif