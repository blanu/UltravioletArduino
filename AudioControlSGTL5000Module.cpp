//
//  AudioControlSGTL5000Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlSGTL5000Module.h"

AudioControlSGTL5000Response *AudioControlSGTL5000Module::handle(AudioControlSGTL5000Request *request)
{
    switch (request->type)
    {
        case AudioControlSGTL5000Request_SETADDRESS:
            {
                AudioControlSGTL5000SetaddressRequest *parameters = (AudioControlSGTL5000SetaddressRequest *)request->body;
                this->logic->setAddress(parameters->level);
                
                Serial.println("AudioControlSGTL5000.setAddress -> void");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_SETADDRESS, NULL);
            }

        case AudioControlSGTL5000Request_ENABLE:
            {
                
                bool result = this->logic->enable();
                AudioControlSGTL5000EnableResponse response = AudioControlSGTL5000EnableResponse(result);
                Serial.println("AudioControlSGTL5000.enable -> bool");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_INPUTSELECT:
            {
                AudioControlSGTL5000InputselectRequest *parameters = (AudioControlSGTL5000InputselectRequest *)request->body;
                bool result = this->logic->inputSelect(parameters->n);
                AudioControlSGTL5000InputselectResponse response = AudioControlSGTL5000InputselectResponse(result);
                Serial.println("AudioControlSGTL5000.inputSelect -> bool");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_INPUTSELECT, (void *)&response);
            }

        case AudioControlSGTL5000Request_VOLUME:
            {
                AudioControlSGTL5000VolumeRequest *parameters = (AudioControlSGTL5000VolumeRequest *)request->body;
                bool result = this->logic->volume(parameters->left, parameters->right);
                AudioControlSGTL5000VolumeResponse response = AudioControlSGTL5000VolumeResponse(result);
                Serial.println("AudioControlSGTL5000.volume -> bool");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_VOLUME, (void *)&response);
            }

        case AudioControlSGTL5000Request_MICGAIN:
            {
                AudioControlSGTL5000MicgainRequest *parameters = (AudioControlSGTL5000MicgainRequest *)request->body;
                bool result = this->logic->micGain(parameters->dB);
                AudioControlSGTL5000MicgainResponse response = AudioControlSGTL5000MicgainResponse(result);
                Serial.println("AudioControlSGTL5000.micGain -> bool");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_MICGAIN, (void *)&response);
            }

        case AudioControlSGTL5000Request_LINEINLEVEL:
            {
                AudioControlSGTL5000LineinlevelRequest *parameters = (AudioControlSGTL5000LineinlevelRequest *)request->body;
                bool result = this->logic->lineInLevel(parameters->left, parameters->right);
                AudioControlSGTL5000LineinlevelResponse response = AudioControlSGTL5000LineinlevelResponse(result);
                Serial.println("AudioControlSGTL5000.lineInLevel -> bool");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_LINEINLEVEL, (void *)&response);
            }

        case AudioControlSGTL5000Request_LINEOUTLEVEL:
            {
                AudioControlSGTL5000LineoutlevelRequest *parameters = (AudioControlSGTL5000LineoutlevelRequest *)request->body;
                unsigned short result = this->logic->lineOutLevel(parameters->n);
                AudioControlSGTL5000LineoutlevelResponse response = AudioControlSGTL5000LineoutlevelResponse(result);
                Serial.println("AudioControlSGTL5000.lineOutLevel -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_LINEOUTLEVEL, (void *)&response);
            }

        case AudioControlSGTL5000Request_DACVOLUME:
            {
                AudioControlSGTL5000DacvolumeRequest *parameters = (AudioControlSGTL5000DacvolumeRequest *)request->body;
                unsigned short result = this->logic->dacVolume(parameters->n);
                AudioControlSGTL5000DacvolumeResponse response = AudioControlSGTL5000DacvolumeResponse(result);
                Serial.println("AudioControlSGTL5000.dacVolume -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_DACVOLUME, (void *)&response);
            }

        case AudioControlSGTL5000Request_ADCHIGHPASSFILTERENABLE:
            {
                
                unsigned short result = this->logic->adcHighPassFilterEnable();
                AudioControlSGTL5000AdchighpassfilterenableResponse response = AudioControlSGTL5000AdchighpassfilterenableResponse(result);
                Serial.println("AudioControlSGTL5000.adcHighPassFilterEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ADCHIGHPASSFILTERENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_ADCHIGHPASSFILTERFREEZE:
            {
                
                unsigned short result = this->logic->adcHighPassFilterFreeze();
                AudioControlSGTL5000AdchighpassfilterfreezeResponse response = AudioControlSGTL5000AdchighpassfilterfreezeResponse(result);
                Serial.println("AudioControlSGTL5000.adcHighPassFilterFreeze -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ADCHIGHPASSFILTERFREEZE, (void *)&response);
            }

        case AudioControlSGTL5000Request_ADCHIGHPASSFILTERDISABLE:
            {
                
                unsigned short result = this->logic->adcHighPassFilterDisable();
                AudioControlSGTL5000AdchighpassfilterdisableResponse response = AudioControlSGTL5000AdchighpassfilterdisableResponse(result);
                Serial.println("AudioControlSGTL5000.adcHighPassFilterDisable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ADCHIGHPASSFILTERDISABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_AUDIOPREPROCESSORENABLE:
            {
                
                unsigned short result = this->logic->audioPreProcessorEnable();
                AudioControlSGTL5000AudiopreprocessorenableResponse response = AudioControlSGTL5000AudiopreprocessorenableResponse(result);
                Serial.println("AudioControlSGTL5000.audioPreProcessorEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUDIOPREPROCESSORENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_AUDIOPOSTPROCESSORENABLE:
            {
                
                unsigned short result = this->logic->audioPostProcessorEnable();
                AudioControlSGTL5000AudiopostprocessorenableResponse response = AudioControlSGTL5000AudiopostprocessorenableResponse(result);
                Serial.println("AudioControlSGTL5000.audioPostProcessorEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUDIOPOSTPROCESSORENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_AUDIOPROCESSORDISABLE:
            {
                
                unsigned short result = this->logic->audioProcessorDisable();
                AudioControlSGTL5000AudioprocessordisableResponse response = AudioControlSGTL5000AudioprocessordisableResponse(result);
                Serial.println("AudioControlSGTL5000.audioProcessorDisable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUDIOPROCESSORDISABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_EQFILTERCOUNT:
            {
                AudioControlSGTL5000EqfiltercountRequest *parameters = (AudioControlSGTL5000EqfiltercountRequest *)request->body;
                unsigned short result = this->logic->eqFilterCount(parameters->n);
                AudioControlSGTL5000EqfiltercountResponse response = AudioControlSGTL5000EqfiltercountResponse(result);
                Serial.println("AudioControlSGTL5000.eqFilterCount -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_EQFILTERCOUNT, (void *)&response);
            }

        case AudioControlSGTL5000Request_EQSELECT:
            {
                AudioControlSGTL5000EqselectRequest *parameters = (AudioControlSGTL5000EqselectRequest *)request->body;
                unsigned short result = this->logic->eqSelect(parameters->n);
                AudioControlSGTL5000EqselectResponse response = AudioControlSGTL5000EqselectResponse(result);
                Serial.println("AudioControlSGTL5000.eqSelect -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_EQSELECT, (void *)&response);
            }

        case AudioControlSGTL5000Request_EQBAND:
            {
                AudioControlSGTL5000EqbandRequest *parameters = (AudioControlSGTL5000EqbandRequest *)request->body;
                unsigned short result = this->logic->eqBand(parameters->bandNum, parameters->n);
                AudioControlSGTL5000EqbandResponse response = AudioControlSGTL5000EqbandResponse(result);
                Serial.println("AudioControlSGTL5000.eqBand -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_EQBAND, (void *)&response);
            }

        case AudioControlSGTL5000Request_EQBANDS:
            {
                AudioControlSGTL5000EqbandsRequest *parameters = (AudioControlSGTL5000EqbandsRequest *)request->body;
                this->logic->eqBands(parameters->bass, parameters->mid_bass, parameters->midrange, parameters->mid_treble, parameters->treble);
                
                Serial.println("AudioControlSGTL5000.eqBands -> void");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_EQBANDS, NULL);
            }

        case AudioControlSGTL5000Request_AUTOVOLUMECONTROL:
            {
                AudioControlSGTL5000AutovolumecontrolRequest *parameters = (AudioControlSGTL5000AutovolumecontrolRequest *)request->body;
                unsigned short result = this->logic->autoVolumeControl(parameters->maxGain, parameters->lbiResponse, parameters->hardLimit, parameters->threshold, parameters->attack, parameters->decay);
                AudioControlSGTL5000AutovolumecontrolResponse response = AudioControlSGTL5000AutovolumecontrolResponse(result);
                Serial.println("AudioControlSGTL5000.autoVolumeControl -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUTOVOLUMECONTROL, (void *)&response);
            }

        case AudioControlSGTL5000Request_AUTOVOLUMEENABLE:
            {
                
                unsigned short result = this->logic->autoVolumeEnable();
                AudioControlSGTL5000AutovolumeenableResponse response = AudioControlSGTL5000AutovolumeenableResponse(result);
                Serial.println("AudioControlSGTL5000.autoVolumeEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUTOVOLUMEENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_AUTOVOLUMEDISABLE:
            {
                
                unsigned short result = this->logic->autoVolumeDisable();
                AudioControlSGTL5000AutovolumedisableResponse response = AudioControlSGTL5000AutovolumedisableResponse(result);
                Serial.println("AudioControlSGTL5000.autoVolumeDisable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_AUTOVOLUMEDISABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_ENHANCEBASS:
            {
                AudioControlSGTL5000EnhancebassRequest *parameters = (AudioControlSGTL5000EnhancebassRequest *)request->body;
                unsigned short result = this->logic->enhanceBass(parameters->lr_lev, parameters->bass_lev);
                AudioControlSGTL5000EnhancebassResponse response = AudioControlSGTL5000EnhancebassResponse(result);
                Serial.println("AudioControlSGTL5000.enhanceBass -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ENHANCEBASS, (void *)&response);
            }

        case AudioControlSGTL5000Request_ENHANCEBASSENABLE:
            {
                
                unsigned short result = this->logic->enhanceBassEnable();
                AudioControlSGTL5000EnhancebassenableResponse response = AudioControlSGTL5000EnhancebassenableResponse(result);
                Serial.println("AudioControlSGTL5000.enhanceBassEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ENHANCEBASSENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_ENHANCEBASSDISABLE:
            {
                
                unsigned short result = this->logic->enhanceBassDisable();
                AudioControlSGTL5000EnhancebassdisableResponse response = AudioControlSGTL5000EnhancebassdisableResponse(result);
                Serial.println("AudioControlSGTL5000.enhanceBassDisable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_ENHANCEBASSDISABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_SURROUNDSOUND:
            {
                AudioControlSGTL5000SurroundsoundRequest *parameters = (AudioControlSGTL5000SurroundsoundRequest *)request->body;
                unsigned short result = this->logic->surroundSound(parameters->width);
                AudioControlSGTL5000SurroundsoundResponse response = AudioControlSGTL5000SurroundsoundResponse(result);
                Serial.println("AudioControlSGTL5000.surroundSound -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_SURROUNDSOUND, (void *)&response);
            }

        case AudioControlSGTL5000Request_SURROUNDSOUNDENABLE:
            {
                
                unsigned short result = this->logic->surroundSoundEnable();
                AudioControlSGTL5000SurroundsoundenableResponse response = AudioControlSGTL5000SurroundsoundenableResponse(result);
                Serial.println("AudioControlSGTL5000.surroundSoundEnable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_SURROUNDSOUNDENABLE, (void *)&response);
            }

        case AudioControlSGTL5000Request_SURROUNDSOUNDDISABLE:
            {
                
                unsigned short result = this->logic->surroundSoundDisable();
                AudioControlSGTL5000SurroundsounddisableResponse response = AudioControlSGTL5000SurroundsounddisableResponse(result);
                Serial.println("AudioControlSGTL5000.surroundSoundDisable -> unsigned short");
                return new AudioControlSGTL5000Response(AudioControlSGTL5000Request_SURROUNDSOUNDDISABLE, (void *)&response);
            }
    }

    return new AudioControlSGTL5000Response(AudioControlSGTL5000Response_ERROR, NULL);
};