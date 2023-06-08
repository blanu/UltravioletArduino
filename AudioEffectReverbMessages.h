//
//  AudioEffectReverbMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectReverbMessages_h_
#define AudioEffectReverbMessages_h_

#include <Arduino.h>

class AudioEffectReverbRequest
{
    public:
        AudioEffectReverbRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioEffectReverbResponse
{
    public:
        AudioEffectReverbResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioEffectReverbRequestType {AudioEffectReverbRequest_AUDIOEFFECTREVERB, AudioEffectReverbRequest_REVERBTIME};



enum AudioEffectReverbResponseType {AudioEffectReverbResponse_ERROR, AudioEffectReverbResponse_AUDIOEFFECTREVERB, AudioEffectReverbResponse_REVERBTIME};

class AudioEffectReverbAudioeffectreverbResponse
{
    public:
        AudioEffectReverbAudioeffectreverbResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

class AudioEffectReverbReverbtimeResponse
{
    public:
        AudioEffectReverbReverbtimeResponse( value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

         value;
};

#endif