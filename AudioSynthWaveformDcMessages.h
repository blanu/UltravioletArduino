//
//  AudioSynthWaveformDcMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthWaveformDcMessages_h_
#define AudioSynthWaveformDcMessages_h_

#include <Arduino.h>

class AudioSynthWaveformDcRequest
{
    public:
        AudioSynthWaveformDcRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthWaveformDcResponse
{
    public:
        AudioSynthWaveformDcResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthWaveformDcRequestType {AudioSynthWaveformDcRequest_AMPLITUDE, AudioSynthWaveformDcRequest_READ};

class AudioSynthWaveformDcAmplitudeRequest
{
    public:
        AudioSynthWaveformDcAmplitudeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

enum AudioSynthWaveformDcResponseType {AudioSynthWaveformDcResponse_ERROR, AudioSynthWaveformDcResponse_AMPLITUDE, AudioSynthWaveformDcResponse_READ};

class AudioSynthWaveformDcReadResponse
{
    public:
        AudioSynthWaveformDcReadResponse(float value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        float value;
};

#endif