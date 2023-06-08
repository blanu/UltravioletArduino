//
//  AudioAnalyzePeakModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzePeakModule.h"

AudioAnalyzePeakResponse *AudioAnalyzePeakModule::handle(AudioAnalyzePeakRequest *request)
{
    switch (request->type)
    {
        case AudioAnalyzePeakRequest_AVAILABLE:
            {
                
                bool result = this->logic->available();
                AudioAnalyzePeakAvailableResponse response = AudioAnalyzePeakAvailableResponse(result);
                Serial.println("AudioAnalyzePeak.available -> bool");
                return new AudioAnalyzePeakResponse(AudioAnalyzePeakRequest_AVAILABLE, (void *)&response);
            }

        case AudioAnalyzePeakRequest_READ:
            {
                
                float result = this->logic->read();
                AudioAnalyzePeakReadResponse response = AudioAnalyzePeakReadResponse(result);
                Serial.println("AudioAnalyzePeak.read -> float");
                return new AudioAnalyzePeakResponse(AudioAnalyzePeakRequest_READ, (void *)&response);
            }

        case AudioAnalyzePeakRequest_READPEAKTOPEAK:
            {
                
                float result = this->logic->readPeakToPeak();
                AudioAnalyzePeakReadpeaktopeakResponse response = AudioAnalyzePeakReadpeaktopeakResponse(result);
                Serial.println("AudioAnalyzePeak.readPeakToPeak -> float");
                return new AudioAnalyzePeakResponse(AudioAnalyzePeakRequest_READPEAKTOPEAK, (void *)&response);
            }
    }

    return new AudioAnalyzePeakResponse(AudioAnalyzePeakResponse_ERROR, NULL);
};