//
//  AudioControlWM8731Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioControlWM8731Module.h"

AudioControlWM8731Response *AudioControlWM8731Module::handle(AudioControlWM8731Request *request)
{
    switch (request->type)
    {
        case AudioControlWM8731Request_ENABLE:
            {
                
                bool result = this->logic->enable();
                AudioControlWM8731EnableResponse response = AudioControlWM8731EnableResponse(result);
                Serial.println("AudioControlWM8731.enable -> bool");
                return new AudioControlWM8731Response(AudioControlWM8731Request_ENABLE, (void *)&response);
            }
    }

    return new AudioControlWM8731Response(AudioControlWM8731Response_ERROR, NULL);
};