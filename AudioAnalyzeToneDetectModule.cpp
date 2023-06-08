//
//  AudioAnalyzeToneDetectModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeToneDetectModule.h"

AudioAnalyzeToneDetectResponse *AudioAnalyzeToneDetectModule::handle(AudioAnalyzeToneDetectRequest *request)
{
    switch (request->type)
    {
        case AudioAnalyzeToneDetectRequest_FREQUENCY:
            {
                AudioAnalyzeToneDetectFrequencyRequest *parameters = (AudioAnalyzeToneDetectFrequencyRequest *)request->body;
                this->logic->frequency(parameters->freq, parameters->cycles=10);
                
                Serial.println("AudioAnalyzeToneDetect.frequency -> void");
                return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectRequest_FREQUENCY, NULL);
            }

        case AudioAnalyzeToneDetectRequest_SET_PARAMS:
            {
                AudioAnalyzeToneDetectSet_ParamsRequest *parameters = (AudioAnalyzeToneDetectSet_ParamsRequest *)request->body;
                this->logic->set_params(parameters->coef, parameters->cycles, parameters->len);
                
                Serial.println("AudioAnalyzeToneDetect.set_params -> void");
                return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectRequest_SET_PARAMS, NULL);
            }

        case AudioAnalyzeToneDetectRequest_AVAILABLE:
            {
                
                bool result = this->logic->available();
                AudioAnalyzeToneDetectAvailableResponse response = AudioAnalyzeToneDetectAvailableResponse(result);
                Serial.println("AudioAnalyzeToneDetect.available -> bool");
                return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectRequest_AVAILABLE, (void *)&response);
            }

        case AudioAnalyzeToneDetectRequest_READ:
            {
                
                float result = this->logic->read();
                AudioAnalyzeToneDetectReadResponse response = AudioAnalyzeToneDetectReadResponse(result);
                Serial.println("AudioAnalyzeToneDetect.read -> float");
                return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectRequest_READ, (void *)&response);
            }

        case AudioAnalyzeToneDetectRequest_THRESHOLD:
            {
                AudioAnalyzeToneDetectThresholdRequest *parameters = (AudioAnalyzeToneDetectThresholdRequest *)request->body;
                this->logic->threshold(parameters->level);
                
                Serial.println("AudioAnalyzeToneDetect.threshold -> void");
                return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectRequest_THRESHOLD, NULL);
            }
    }

    return new AudioAnalyzeToneDetectResponse(AudioAnalyzeToneDetectResponse_ERROR, NULL);
};