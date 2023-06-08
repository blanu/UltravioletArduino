//
//  AudioAnalyzeRMSModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeRMSModule.h"

AudioAnalyzeRMSResponse *AudioAnalyzeRMSModule::handle(AudioAnalyzeRMSRequest *request)
{
    switch (request->type)
    {
        case AudioAnalyzeRMSRequest_AVAILABLE:
            {
                
                bool result = this->logic->available();
                AudioAnalyzeRMSAvailableResponse response = AudioAnalyzeRMSAvailableResponse(result);
                Serial.println("AudioAnalyzeRMS.available -> bool");
                return new AudioAnalyzeRMSResponse(AudioAnalyzeRMSRequest_AVAILABLE, (void *)&response);
            }

        case AudioAnalyzeRMSRequest_READ:
            {
                
                float result = this->logic->read();
                AudioAnalyzeRMSReadResponse response = AudioAnalyzeRMSReadResponse(result);
                Serial.println("AudioAnalyzeRMS.read -> float");
                return new AudioAnalyzeRMSResponse(AudioAnalyzeRMSRequest_READ, (void *)&response);
            }
    }

    return new AudioAnalyzeRMSResponse(AudioAnalyzeRMSResponse_ERROR, NULL);
};