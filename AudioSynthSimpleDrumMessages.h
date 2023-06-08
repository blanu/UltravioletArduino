//
//  AudioSynthSimpleDrumMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioSynthSimpleDrumMessages_h_
#define AudioSynthSimpleDrumMessages_h_

#include <Arduino.h>

class AudioSynthSimpleDrumRequest
{
    public:
        AudioSynthSimpleDrumRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioSynthSimpleDrumResponse
{
    public:
        AudioSynthSimpleDrumResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioSynthSimpleDrumRequestType {AudioSynthSimpleDrumRequest_LENGTH, AudioSynthSimpleDrumRequest_FREQUENCY, AudioSynthSimpleDrumRequest_PITCHMOD, AudioSynthSimpleDrumRequest_SECONDMIX};

class AudioSynthSimpleDrumSecondmixRequest
{
    public:
        AudioSynthSimpleDrumSecondmixRequest(float level)
        {
            this->level = level;
        }

        float level;
};

enum AudioSynthSimpleDrumResponseType {AudioSynthSimpleDrumResponse_ERROR, AudioSynthSimpleDrumResponse_LENGTH, AudioSynthSimpleDrumResponse_FREQUENCY, AudioSynthSimpleDrumResponse_PITCHMOD, AudioSynthSimpleDrumResponse_SECONDMIX};

class AudioSynthSimpleDrumLengthResponse
{
    public:
        AudioSynthSimpleDrumLengthResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioSynthSimpleDrumFrequencyResponse
{
    public:
        AudioSynthSimpleDrumFrequencyResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioSynthSimpleDrumPitchmodResponse
{
    public:
        AudioSynthSimpleDrumPitchmodResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

#endif