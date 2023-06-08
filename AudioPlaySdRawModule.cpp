//
//  AudioPlaySdRawModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlaySdRawModule.h"

AudioPlaySdRawResponse *AudioPlaySdRawModule::handle(AudioPlaySdRawRequest *request)
{
    switch (request->type)
    {
        case AudioPlaySdRawRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioPlaySdRaw.begin -> void");
                return new AudioPlaySdRawResponse(AudioPlaySdRawRequest_BEGIN, NULL);
            }

        case AudioPlaySdRawRequest_STOP:
            {
                
                this->logic->stop();
                
                Serial.println("AudioPlaySdRaw.stop -> void");
                return new AudioPlaySdRawResponse(AudioPlaySdRawRequest_STOP, NULL);
            }

        case AudioPlaySdRawRequest_POSITIONMILLIS:
            {
                
                uint32_t result = this->logic->positionMillis();
                AudioPlaySdRawPositionmillisResponse response = AudioPlaySdRawPositionmillisResponse(result);
                Serial.println("AudioPlaySdRaw.positionMillis -> uint32_t");
                return new AudioPlaySdRawResponse(AudioPlaySdRawRequest_POSITIONMILLIS, (void *)&response);
            }

        case AudioPlaySdRawRequest_LENGTHMILLIS:
            {
                
                uint32_t result = this->logic->lengthMillis();
                AudioPlaySdRawLengthmillisResponse response = AudioPlaySdRawLengthmillisResponse(result);
                Serial.println("AudioPlaySdRaw.lengthMillis -> uint32_t");
                return new AudioPlaySdRawResponse(AudioPlaySdRawRequest_LENGTHMILLIS, (void *)&response);
            }
    }

    return new AudioPlaySdRawResponse(AudioPlaySdRawResponse_ERROR, NULL);
};