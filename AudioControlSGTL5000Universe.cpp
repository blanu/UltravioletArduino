//
//  AudioControlSGTL5000Universe.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlSGTL5000Universe.h"

void AudioControlSGTL5000Universe::setAddress(uint8_t level)
{
    AudioControlSGTL5000SetaddressRequest *requestBody = new AudioControlSGTL5000SetaddressRequest(level);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_SETADDRESS, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.setAddress(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

bool AudioControlSGTL5000Universe::enable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.enable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EnableResponse *result = (AudioControlSGTL5000EnableResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlSGTL5000Universe::inputSelect(int n)
{
    AudioControlSGTL5000InputselectRequest *requestBody = new AudioControlSGTL5000InputselectRequest(n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_INPUTSELECT, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.inputSelect(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000InputselectResponse *result = (AudioControlSGTL5000InputselectResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlSGTL5000Universe::volume(float left, float right)
{
    AudioControlSGTL5000VolumeRequest *requestBody = new AudioControlSGTL5000VolumeRequest(left, right);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_VOLUME, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.volume(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000VolumeResponse *result = (AudioControlSGTL5000VolumeResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlSGTL5000Universe::micGain(unsigned int dB)
{
    AudioControlSGTL5000MicgainRequest *requestBody = new AudioControlSGTL5000MicgainRequest(dB);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_MICGAIN, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.micGain(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000MicgainResponse *result = (AudioControlSGTL5000MicgainResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

bool AudioControlSGTL5000Universe::lineInLevel(uint8_t left, uint8_t right)
{
    AudioControlSGTL5000LineinlevelRequest *requestBody = new AudioControlSGTL5000LineinlevelRequest(left, right);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_LINEINLEVEL, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.lineInLevel(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000LineinlevelResponse *result = (AudioControlSGTL5000LineinlevelResponse *)response->body;
    bool returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::lineOutLevel(uint8_t n)
{
    AudioControlSGTL5000LineoutlevelRequest *requestBody = new AudioControlSGTL5000LineoutlevelRequest(n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_LINEOUTLEVEL, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.lineOutLevel(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000LineoutlevelResponse *result = (AudioControlSGTL5000LineoutlevelResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::dacVolume(float n)
{
    AudioControlSGTL5000DacvolumeRequest *requestBody = new AudioControlSGTL5000DacvolumeRequest(n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_DACVOLUME, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.dacVolume(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000DacvolumeResponse *result = (AudioControlSGTL5000DacvolumeResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::adcHighPassFilterEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ADCHIGHPASSFILTERENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.adcHighPassFilterEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AdchighpassfilterenableResponse *result = (AudioControlSGTL5000AdchighpassfilterenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::adcHighPassFilterFreeze()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ADCHIGHPASSFILTERFREEZE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.adcHighPassFilterFreeze(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AdchighpassfilterfreezeResponse *result = (AudioControlSGTL5000AdchighpassfilterfreezeResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::adcHighPassFilterDisable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ADCHIGHPASSFILTERDISABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.adcHighPassFilterDisable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AdchighpassfilterdisableResponse *result = (AudioControlSGTL5000AdchighpassfilterdisableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::audioPreProcessorEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUDIOPREPROCESSORENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.audioPreProcessorEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AudiopreprocessorenableResponse *result = (AudioControlSGTL5000AudiopreprocessorenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::audioPostProcessorEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUDIOPOSTPROCESSORENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.audioPostProcessorEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AudiopostprocessorenableResponse *result = (AudioControlSGTL5000AudiopostprocessorenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::audioProcessorDisable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUDIOPROCESSORDISABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.audioProcessorDisable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AudioprocessordisableResponse *result = (AudioControlSGTL5000AudioprocessordisableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::eqFilterCount(uint8_t n)
{
    AudioControlSGTL5000EqfiltercountRequest *requestBody = new AudioControlSGTL5000EqfiltercountRequest(n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_EQFILTERCOUNT, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.eqFilterCount(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EqfiltercountResponse *result = (AudioControlSGTL5000EqfiltercountResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::eqSelect(uint8_t n)
{
    AudioControlSGTL5000EqselectRequest *requestBody = new AudioControlSGTL5000EqselectRequest(n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_EQSELECT, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.eqSelect(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EqselectResponse *result = (AudioControlSGTL5000EqselectResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::eqBand(uint8_t bandNum, float n)
{
    AudioControlSGTL5000EqbandRequest *requestBody = new AudioControlSGTL5000EqbandRequest(bandNum, n);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_EQBAND, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.eqBand(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EqbandResponse *result = (AudioControlSGTL5000EqbandResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

void AudioControlSGTL5000Universe::eqBands(float bass, float mid_bass, float midrange, float mid_treble, float treble)
{
    AudioControlSGTL5000EqbandsRequest *requestBody = new AudioControlSGTL5000EqbandsRequest(bass, mid_bass, midrange, mid_treble, treble);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_EQBANDS, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.eqBands(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    delete request;
    delete requestBody;
    delete response;
}

unsigned short AudioControlSGTL5000Universe::autoVolumeControl(uint8_t maxGain, uint8_t lbiResponse, uint8_t hardLimit, float threshold, float attack, float decay)
{
    AudioControlSGTL5000AutovolumecontrolRequest *requestBody = new AudioControlSGTL5000AutovolumecontrolRequest(maxGain, lbiResponse, hardLimit, threshold, attack, decay);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUTOVOLUMECONTROL, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.autoVolumeControl(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AutovolumecontrolResponse *result = (AudioControlSGTL5000AutovolumecontrolResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::autoVolumeEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUTOVOLUMEENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.autoVolumeEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AutovolumeenableResponse *result = (AudioControlSGTL5000AutovolumeenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::autoVolumeDisable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_AUTOVOLUMEDISABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.autoVolumeDisable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000AutovolumedisableResponse *result = (AudioControlSGTL5000AutovolumedisableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::enhanceBass(float lr_lev, float bass_lev)
{
    AudioControlSGTL5000EnhancebassRequest *requestBody = new AudioControlSGTL5000EnhancebassRequest(lr_lev, bass_lev);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ENHANCEBASS, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.enhanceBass(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EnhancebassResponse *result = (AudioControlSGTL5000EnhancebassResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::enhanceBassEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ENHANCEBASSENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.enhanceBassEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EnhancebassenableResponse *result = (AudioControlSGTL5000EnhancebassenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::enhanceBassDisable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_ENHANCEBASSDISABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.enhanceBassDisable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000EnhancebassdisableResponse *result = (AudioControlSGTL5000EnhancebassdisableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::surroundSound(uint8_t width)
{
    AudioControlSGTL5000SurroundsoundRequest *requestBody = new AudioControlSGTL5000SurroundsoundRequest(width);
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_SURROUNDSOUND, (void *)requestBody);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.surroundSound(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000SurroundsoundResponse *result = (AudioControlSGTL5000SurroundsoundResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete requestBody;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::surroundSoundEnable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_SURROUNDSOUNDENABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.surroundSoundEnable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000SurroundsoundenableResponse *result = (AudioControlSGTL5000SurroundsoundenableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}

unsigned short AudioControlSGTL5000Universe::surroundSoundDisable()
{
    AudioControlSGTL5000Request *request = new AudioControlSGTL5000Request(AudioControlSGTL5000Request_SURROUNDSOUNDDISABLE, NULL);
    AudioControlSGTL5000Response *response = this->module->handle(request);
    if (response->type == AudioControlSGTL5000Response_ERROR)
    {
        Serial.println("ERROR in AudioControlSGTL5000.surroundSoundDisable(). Program halted.");
        while(1)
        {
            // We can't return because we don't have a valid return value, so we enter an infinite loop instead.
        }
    }
    AudioControlSGTL5000SurroundsounddisableResponse *result = (AudioControlSGTL5000SurroundsounddisableResponse *)response->body;
    unsigned short returnValue = result->value; // Because this is a value type, this will be a copy.
    delete request;
    delete result;
    delete response;
    return returnValue;
}