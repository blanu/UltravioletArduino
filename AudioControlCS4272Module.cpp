//
//  AudioControlCS4272Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlCS4272Module.h"

AudioControlCS4272Response *AudioControlCS4272Module::handle(AudioControlCS4272Request *request)
{
    switch (request->type)
    {
        case AudioControlCS4272Request_ENABLE:
            {
                
                bool result = this->logic->enable();
                AudioControlCS4272EnableResponse response = AudioControlCS4272EnableResponse(result);
                Serial.println("AudioControlCS4272.enable -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_ENABLE, (void *)&response);
            }

        case AudioControlCS4272Request_VOLUME:
            {
                AudioControlCS4272VolumeRequest *parameters = (AudioControlCS4272VolumeRequest *)request->body;
                bool result = this->logic->volume(parameters->left, parameters->right);
                AudioControlCS4272VolumeResponse response = AudioControlCS4272VolumeResponse(result);
                Serial.println("AudioControlCS4272.volume -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_VOLUME, (void *)&response);
            }

        case AudioControlCS4272Request_DACVOLUME:
            {
                AudioControlCS4272DacvolumeRequest *parameters = (AudioControlCS4272DacvolumeRequest *)request->body;
                bool result = this->logic->dacVolume(parameters->left, parameters->right);
                AudioControlCS4272DacvolumeResponse response = AudioControlCS4272DacvolumeResponse(result);
                Serial.println("AudioControlCS4272.dacVolume -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_DACVOLUME, (void *)&response);
            }

        case AudioControlCS4272Request_MUTEOUTPUT:
            {
                
                bool result = this->logic->muteOutput();
                AudioControlCS4272MuteoutputResponse response = AudioControlCS4272MuteoutputResponse(result);
                Serial.println("AudioControlCS4272.muteOutput -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_MUTEOUTPUT, (void *)&response);
            }

        case AudioControlCS4272Request_UNMUTEOUTPUT:
            {
                
                bool result = this->logic->unmuteOutput();
                AudioControlCS4272UnmuteoutputResponse response = AudioControlCS4272UnmuteoutputResponse(result);
                Serial.println("AudioControlCS4272.unmuteOutput -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_UNMUTEOUTPUT, (void *)&response);
            }

        case AudioControlCS4272Request_MUTEINPUT:
            {
                
                bool result = this->logic->muteInput();
                AudioControlCS4272MuteinputResponse response = AudioControlCS4272MuteinputResponse(result);
                Serial.println("AudioControlCS4272.muteInput -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_MUTEINPUT, (void *)&response);
            }

        case AudioControlCS4272Request_UNMUTEINPUT:
            {
                
                bool result = this->logic->unmuteInput();
                AudioControlCS4272UnmuteinputResponse response = AudioControlCS4272UnmuteinputResponse(result);
                Serial.println("AudioControlCS4272.unmuteInput -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_UNMUTEINPUT, (void *)&response);
            }

        case AudioControlCS4272Request_ENABLEDITHER:
            {
                
                bool result = this->logic->enableDither();
                AudioControlCS4272EnableditherResponse response = AudioControlCS4272EnableditherResponse(result);
                Serial.println("AudioControlCS4272.enableDither -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_ENABLEDITHER, (void *)&response);
            }

        case AudioControlCS4272Request_DISABLEDITHER:
            {
                
                bool result = this->logic->disableDither();
                AudioControlCS4272DisableditherResponse response = AudioControlCS4272DisableditherResponse(result);
                Serial.println("AudioControlCS4272.disableDither -> bool");
                return new AudioControlCS4272Response(AudioControlCS4272Request_DISABLEDITHER, (void *)&response);
            }
    }

    return new AudioControlCS4272Response(AudioControlCS4272Response_ERROR, NULL);
};