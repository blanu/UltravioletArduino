//
//  AudioSynthWaveformDcModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformDcModule.h"

AudioSynthWaveformDcResponse *AudioSynthWaveformDcModule::handle(AudioSynthWaveformDcRequest *request)
{
    switch (request->type)
    {
        case AudioSynthWaveformDcRequest_AMPLITUDE:
            {
                AudioSynthWaveformDcAmplitudeRequest *parameters = (AudioSynthWaveformDcAmplitudeRequest *)request->body;
                this->logic->amplitude(parameters->n);
                
                Serial.println("AudioSynthWaveformDc.amplitude -> void");
                return new AudioSynthWaveformDcResponse(AudioSynthWaveformDcRequest_AMPLITUDE, NULL);
            }

        case AudioSynthWaveformDcRequest_READ:
            {
                
                float result = this->logic->read();
                AudioSynthWaveformDcReadResponse response = AudioSynthWaveformDcReadResponse(result);
                Serial.println("AudioSynthWaveformDc.read -> float");
                return new AudioSynthWaveformDcResponse(AudioSynthWaveformDcRequest_READ, (void *)&response);
            }
    }

    return new AudioSynthWaveformDcResponse(AudioSynthWaveformDcResponse_ERROR, NULL);
};