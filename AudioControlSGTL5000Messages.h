//
//  AudioControlSGTL5000Messages.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioControlSGTL5000Messages_h_
#define AudioControlSGTL5000Messages_h_

#include <Arduino.h>

class AudioControlSGTL5000Request
{
    public:
        AudioControlSGTL5000Request(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

class AudioControlSGTL5000Response
{
    public:
        AudioControlSGTL5000Response(int type, void *body)
        {
            this->type = type;
            this->body = body;
        }

        int type;
        void *body;
};

enum AudioControlSGTL5000RequestType {AudioControlSGTL5000Request_SETADDRESS, AudioControlSGTL5000Request_ENABLE, AudioControlSGTL5000Request_INPUTSELECT, AudioControlSGTL5000Request_VOLUME, AudioControlSGTL5000Request_MICGAIN, AudioControlSGTL5000Request_LINEINLEVEL, AudioControlSGTL5000Request_LINEOUTLEVEL, AudioControlSGTL5000Request_DACVOLUME, AudioControlSGTL5000Request_ADCHIGHPASSFILTERENABLE, AudioControlSGTL5000Request_ADCHIGHPASSFILTERFREEZE, AudioControlSGTL5000Request_ADCHIGHPASSFILTERDISABLE, AudioControlSGTL5000Request_AUDIOPREPROCESSORENABLE, AudioControlSGTL5000Request_AUDIOPOSTPROCESSORENABLE, AudioControlSGTL5000Request_AUDIOPROCESSORDISABLE, AudioControlSGTL5000Request_EQFILTERCOUNT, AudioControlSGTL5000Request_EQSELECT, AudioControlSGTL5000Request_EQBAND, AudioControlSGTL5000Request_EQBANDS, AudioControlSGTL5000Request_AUTOVOLUMECONTROL, AudioControlSGTL5000Request_AUTOVOLUMEENABLE, AudioControlSGTL5000Request_AUTOVOLUMEDISABLE, AudioControlSGTL5000Request_ENHANCEBASS, AudioControlSGTL5000Request_ENHANCEBASSENABLE, AudioControlSGTL5000Request_ENHANCEBASSDISABLE, AudioControlSGTL5000Request_SURROUNDSOUND, AudioControlSGTL5000Request_SURROUNDSOUNDENABLE, AudioControlSGTL5000Request_SURROUNDSOUNDDISABLE};

class AudioControlSGTL5000SetaddressRequest
{
    public:
        AudioControlSGTL5000SetaddressRequest(uint8_t level)
        {
            this->level = level;
        }

        uint8_t level;
};

class AudioControlSGTL5000InputselectRequest
{
    public:
        AudioControlSGTL5000InputselectRequest(int n)
        {
            this->n = n;
        }

        int n;
};

class AudioControlSGTL5000VolumeRequest
{
    public:
        AudioControlSGTL5000VolumeRequest(float left, float right)
        {
            this->left = left;
            this->right = right;
        }

        float left;
        float right;
};

class AudioControlSGTL5000MicgainRequest
{
    public:
        AudioControlSGTL5000MicgainRequest(unsigned int dB)
        {
            this->dB = dB;
        }

        unsigned int dB;
};

class AudioControlSGTL5000LineinlevelRequest
{
    public:
        AudioControlSGTL5000LineinlevelRequest(uint8_t left, uint8_t right)
        {
            this->left = left;
            this->right = right;
        }

        uint8_t left;
        uint8_t right;
};

class AudioControlSGTL5000LineoutlevelRequest
{
    public:
        AudioControlSGTL5000LineoutlevelRequest(uint8_t n)
        {
            this->n = n;
        }

        uint8_t n;
};

class AudioControlSGTL5000DacvolumeRequest
{
    public:
        AudioControlSGTL5000DacvolumeRequest(float n)
        {
            this->n = n;
        }

        float n;
};

class AudioControlSGTL5000EqfiltercountRequest
{
    public:
        AudioControlSGTL5000EqfiltercountRequest(uint8_t n)
        {
            this->n = n;
        }

        uint8_t n;
};

class AudioControlSGTL5000EqselectRequest
{
    public:
        AudioControlSGTL5000EqselectRequest(uint8_t n)
        {
            this->n = n;
        }

        uint8_t n;
};

class AudioControlSGTL5000EqbandRequest
{
    public:
        AudioControlSGTL5000EqbandRequest(uint8_t bandNum, float n)
        {
            this->bandNum = bandNum;
            this->n = n;
        }

        uint8_t bandNum;
        float n;
};

class AudioControlSGTL5000EqbandsRequest
{
    public:
        AudioControlSGTL5000EqbandsRequest(float bass, float mid_bass, float midrange, float mid_treble, float treble)
        {
            this->bass = bass;
            this->mid_bass = mid_bass;
            this->midrange = midrange;
            this->mid_treble = mid_treble;
            this->treble = treble;
        }

        float bass;
        float mid_bass;
        float midrange;
        float mid_treble;
        float treble;
};

class AudioControlSGTL5000AutovolumecontrolRequest
{
    public:
        AudioControlSGTL5000AutovolumecontrolRequest(uint8_t maxGain, uint8_t lbiResponse, uint8_t hardLimit, float threshold, float attack, float decay)
        {
            this->maxGain = maxGain;
            this->lbiResponse = lbiResponse;
            this->hardLimit = hardLimit;
            this->threshold = threshold;
            this->attack = attack;
            this->decay = decay;
        }

        uint8_t maxGain;
        uint8_t lbiResponse;
        uint8_t hardLimit;
        float threshold;
        float attack;
        float decay;
};

class AudioControlSGTL5000EnhancebassRequest
{
    public:
        AudioControlSGTL5000EnhancebassRequest(float lr_lev, float bass_lev)
        {
            this->lr_lev = lr_lev;
            this->bass_lev = bass_lev;
        }

        float lr_lev;
        float bass_lev;
};

class AudioControlSGTL5000SurroundsoundRequest
{
    public:
        AudioControlSGTL5000SurroundsoundRequest(uint8_t width)
        {
            this->width = width;
        }

        uint8_t width;
};

enum AudioControlSGTL5000ResponseType {AudioControlSGTL5000Response_ERROR, AudioControlSGTL5000Response_SETADDRESS, AudioControlSGTL5000Response_ENABLE, AudioControlSGTL5000Response_INPUTSELECT, AudioControlSGTL5000Response_VOLUME, AudioControlSGTL5000Response_MICGAIN, AudioControlSGTL5000Response_LINEINLEVEL, AudioControlSGTL5000Response_LINEOUTLEVEL, AudioControlSGTL5000Response_DACVOLUME, AudioControlSGTL5000Response_ADCHIGHPASSFILTERENABLE, AudioControlSGTL5000Response_ADCHIGHPASSFILTERFREEZE, AudioControlSGTL5000Response_ADCHIGHPASSFILTERDISABLE, AudioControlSGTL5000Response_AUDIOPREPROCESSORENABLE, AudioControlSGTL5000Response_AUDIOPOSTPROCESSORENABLE, AudioControlSGTL5000Response_AUDIOPROCESSORDISABLE, AudioControlSGTL5000Response_EQFILTERCOUNT, AudioControlSGTL5000Response_EQSELECT, AudioControlSGTL5000Response_EQBAND, AudioControlSGTL5000Response_EQBANDS, AudioControlSGTL5000Response_AUTOVOLUMECONTROL, AudioControlSGTL5000Response_AUTOVOLUMEENABLE, AudioControlSGTL5000Response_AUTOVOLUMEDISABLE, AudioControlSGTL5000Response_ENHANCEBASS, AudioControlSGTL5000Response_ENHANCEBASSENABLE, AudioControlSGTL5000Response_ENHANCEBASSDISABLE, AudioControlSGTL5000Response_SURROUNDSOUND, AudioControlSGTL5000Response_SURROUNDSOUNDENABLE, AudioControlSGTL5000Response_SURROUNDSOUNDDISABLE};

class AudioControlSGTL5000EnableResponse
{
    public:
        AudioControlSGTL5000EnableResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlSGTL5000InputselectResponse
{
    public:
        AudioControlSGTL5000InputselectResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlSGTL5000VolumeResponse
{
    public:
        AudioControlSGTL5000VolumeResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlSGTL5000MicgainResponse
{
    public:
        AudioControlSGTL5000MicgainResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlSGTL5000LineinlevelResponse
{
    public:
        AudioControlSGTL5000LineinlevelResponse(bool value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        bool value;
};

class AudioControlSGTL5000LineoutlevelResponse
{
    public:
        AudioControlSGTL5000LineoutlevelResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000DacvolumeResponse
{
    public:
        AudioControlSGTL5000DacvolumeResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AdchighpassfilterenableResponse
{
    public:
        AudioControlSGTL5000AdchighpassfilterenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AdchighpassfilterfreezeResponse
{
    public:
        AudioControlSGTL5000AdchighpassfilterfreezeResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AdchighpassfilterdisableResponse
{
    public:
        AudioControlSGTL5000AdchighpassfilterdisableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AudiopreprocessorenableResponse
{
    public:
        AudioControlSGTL5000AudiopreprocessorenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AudiopostprocessorenableResponse
{
    public:
        AudioControlSGTL5000AudiopostprocessorenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AudioprocessordisableResponse
{
    public:
        AudioControlSGTL5000AudioprocessordisableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EqfiltercountResponse
{
    public:
        AudioControlSGTL5000EqfiltercountResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EqselectResponse
{
    public:
        AudioControlSGTL5000EqselectResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EqbandResponse
{
    public:
        AudioControlSGTL5000EqbandResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AutovolumecontrolResponse
{
    public:
        AudioControlSGTL5000AutovolumecontrolResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AutovolumeenableResponse
{
    public:
        AudioControlSGTL5000AutovolumeenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000AutovolumedisableResponse
{
    public:
        AudioControlSGTL5000AutovolumedisableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EnhancebassResponse
{
    public:
        AudioControlSGTL5000EnhancebassResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EnhancebassenableResponse
{
    public:
        AudioControlSGTL5000EnhancebassenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000EnhancebassdisableResponse
{
    public:
        AudioControlSGTL5000EnhancebassdisableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000SurroundsoundResponse
{
    public:
        AudioControlSGTL5000SurroundsoundResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000SurroundsoundenableResponse
{
    public:
        AudioControlSGTL5000SurroundsoundenableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

class AudioControlSGTL5000SurroundsounddisableResponse
{
    public:
        AudioControlSGTL5000SurroundsounddisableResponse(unsigned short value)
        {
            // value is a value type and not a pointer, so this->value should be a copy.
            this->value = value;
        }

        unsigned short value;
};

#endif