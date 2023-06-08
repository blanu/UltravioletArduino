//
//  AudioFilterFIRModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterFIRModule.h"

AudioFilterFIRResponse *AudioFilterFIRModule::handle(AudioFilterFIRRequest *request)
{
    switch (request->type)
    {
        case AudioFilterFIRRequest_END:
            {
                
                this->logic->end();
                
                Serial.println("AudioFilterFIR.end -> void");
                return new AudioFilterFIRResponse(AudioFilterFIRRequest_END, NULL);
            }
    }

    return new AudioFilterFIRResponse(AudioFilterFIRResponse_ERROR, NULL);
};