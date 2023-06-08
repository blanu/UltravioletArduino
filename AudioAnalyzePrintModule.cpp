//
//  AudioAnalyzePrintModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzePrintModule.h"

AudioAnalyzePrintResponse *AudioAnalyzePrintModule::handle(AudioAnalyzePrintRequest *request)
{
    switch (request->type)
    {
        case AudioAnalyzePrintRequest_TRIGGER:
            {
                
                this->logic->trigger();
                
                Serial.println("AudioAnalyzePrint.trigger -> void");
                return new AudioAnalyzePrintResponse(AudioAnalyzePrintRequest_TRIGGER, NULL);
            }
    }

    return new AudioAnalyzePrintResponse(AudioAnalyzePrintResponse_ERROR, NULL);
};