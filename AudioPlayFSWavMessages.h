//
//  AudioPlayFSWavMessages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioPlayFSWavMessages_h_
#define AudioPlayFSWavMessages_h_

#include <Arduino.h>

class AudioPlayFSWavRequest
{
    public:
        AudioPlayFSWavRequest(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioPlayFSWavResponse
{
    public:
        AudioPlayFSWavResponse(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioPlayFSWavRequestType {AudioPlayFSWavRequest_BEGIN, AudioPlayFSWavRequest_ISPLAYING, AudioPlayFSWavRequest_POSITIONMILLIS, AudioPlayFSWavRequest_LENGTHMILLIS};



enum AudioPlayFSWavResponseType {AudioPlayFSWavResponse_ERROR, AudioPlayFSWavResponse_BEGIN, AudioPlayFSWavResponse_ISPLAYING, AudioPlayFSWavResponse_POSITIONMILLIS, AudioPlayFSWavResponse_LENGTHMILLIS};

class AudioPlayFSWavIsplayingResponse
{
    public:
        AudioPlayFSWavIsplayingResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioPlayFSWavPositionmillisResponse
{
    public:
        AudioPlayFSWavPositionmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

class AudioPlayFSWavLengthmillisResponse
{
    public:
        AudioPlayFSWavLengthmillisResponse(uint32_t value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        uint32_t value;
};

#endif