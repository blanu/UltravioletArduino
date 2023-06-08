//
//  AudioMixer4Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioMixer4Messages_h_
#define AudioMixer4Messages_h_

#include <Arduino.h>

class AudioMixer4Request
{
    public:
        AudioMixer4Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioMixer4Response
{
    public:
        AudioMixer4Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioMixer4RequestType {AudioMixer4Request_GAIN};

class AudioMixer4GainRequest
{
    public:
        AudioMixer4GainRequest(unsigned int channel, float gain)
        {
            this->channel = channel;
            this->gain = gain;
        }

        unsigned int channel;
        float gain;
};

enum AudioMixer4ResponseType {AudioMixer4Response_ERROR, AudioMixer4Response_GAIN};



#endif