//
//  AudioControlCS42448Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlCS42448Module.h"

AudioControlCS42448Response *AudioControlCS42448Module::handle(AudioControlCS42448Request *request)
{
    switch (request->type)
    {
        case AudioControlCS42448Request_SETADDRESS:
            {
                AudioControlCS42448SetaddressRequest *parameters = (AudioControlCS42448SetaddressRequest *)request->body;
                this->logic->setAddress(parameters->addr);
                
                Serial.println("AudioControlCS42448.setAddress -> void");
                return new AudioControlCS42448Response(AudioControlCS42448Request_SETADDRESS, NULL);
            }

        case AudioControlCS42448Request_ENABLE:
            {
                
                bool result = this->logic->enable();
                AudioControlCS42448EnableResponse response = AudioControlCS42448EnableResponse(result);
                Serial.println("AudioControlCS42448.enable -> bool");
                return new AudioControlCS42448Response(AudioControlCS42448Request_ENABLE, (void *)&response);
            }

        case AudioControlCS42448Request_DISABLE:
            {
                
                bool result = this->logic->disable();
                AudioControlCS42448DisableResponse response = AudioControlCS42448DisableResponse(result);
                Serial.println("AudioControlCS42448.disable -> bool");
                return new AudioControlCS42448Response(AudioControlCS42448Request_DISABLE, (void *)&response);
            }

        case AudioControlCS42448Request_VOLUME:
            {
                AudioControlCS42448VolumeRequest *parameters = (AudioControlCS42448VolumeRequest *)request->body;
                bool result = this->logic->volume(parameters->level);
                AudioControlCS42448VolumeResponse response = AudioControlCS42448VolumeResponse(result);
                Serial.println("AudioControlCS42448.volume -> bool");
                return new AudioControlCS42448Response(AudioControlCS42448Request_VOLUME, (void *)&response);
            }

        case AudioControlCS42448Request_VOLUMEINTEGER:
            {
                
                return result = this->logic->volumeInteger();
                AudioControlCS42448VolumeintegerResponse response = AudioControlCS42448VolumeintegerResponse(result);
                Serial.println("AudioControlCS42448.volumeInteger -> return");
                return new AudioControlCS42448Response(AudioControlCS42448Request_VOLUMEINTEGER, (void *)&response);
            }

        case AudioControlCS42448Request_INPUTLEVEL:
            {
                AudioControlCS42448InputlevelRequest *parameters = (AudioControlCS42448InputlevelRequest *)request->body;
                bool result = this->logic->inputLevel(parameters->level);
                AudioControlCS42448InputlevelResponse response = AudioControlCS42448InputlevelResponse(result);
                Serial.println("AudioControlCS42448.inputLevel -> bool");
                return new AudioControlCS42448Response(AudioControlCS42448Request_INPUTLEVEL, (void *)&response);
            }

        case AudioControlCS42448Request_INPUTLEVELINTEGER:
            {
                
                return result = this->logic->inputLevelInteger();
                AudioControlCS42448InputlevelintegerResponse response = AudioControlCS42448InputlevelintegerResponse(result);
                Serial.println("AudioControlCS42448.inputLevelInteger -> return");
                return new AudioControlCS42448Response(AudioControlCS42448Request_INPUTLEVELINTEGER, (void *)&response);
            }

        case AudioControlCS42448Request_INPUTSELECT:
            {
                AudioControlCS42448InputselectRequest *parameters = (AudioControlCS42448InputselectRequest *)request->body;
                bool result = this->logic->inputSelect(parameters->n);
                AudioControlCS42448InputselectResponse response = AudioControlCS42448InputselectResponse(result);
                Serial.println("AudioControlCS42448.inputSelect -> bool");
                return new AudioControlCS42448Response(AudioControlCS42448Request_INPUTSELECT, (void *)&response);
            }
    }

    return new AudioControlCS42448Response(AudioControlCS42448Response_ERROR, NULL);
};