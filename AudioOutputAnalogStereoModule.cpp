//
//  AudioOutputAnalogStereoModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioOutputAnalogStereoModule.h"

AudioOutputAnalogStereoResponse *AudioOutputAnalogStereoModule::handle(AudioOutputAnalogStereoRequest *request)
{
    switch (request->type)
    {
        case AudioOutputAnalogStereoRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioOutputAnalogStereo.begin -> void");
                return new AudioOutputAnalogStereoResponse(AudioOutputAnalogStereoRequest_BEGIN, NULL);
            }

        case AudioOutputAnalogStereoRequest_ANALOGREFERENCE:
            {
                AudioOutputAnalogStereoAnalogreferenceRequest *parameters = (AudioOutputAnalogStereoAnalogreferenceRequest *)request->body;
                this->logic->analogReference(parameters->ref);
                
                Serial.println("AudioOutputAnalogStereo.analogReference -> void");
                return new AudioOutputAnalogStereoResponse(AudioOutputAnalogStereoRequest_ANALOGREFERENCE, NULL);
            }
    }

    return new AudioOutputAnalogStereoResponse(AudioOutputAnalogStereoResponse_ERROR, NULL);
};