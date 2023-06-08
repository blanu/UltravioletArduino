//
//  AudioSynthWaveformPWMModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformPWMModule.h"

AudioSynthWaveformPWMResponse *AudioSynthWaveformPWMModule::handle(AudioSynthWaveformPWMRequest *request)
{
    switch (request->type)
    {
        case AudioSynthWaveformPWMRequest_FREQUENCY:
            {
                AudioSynthWaveformPWMFrequencyRequest *parameters = (AudioSynthWaveformPWMFrequencyRequest *)request->body;
                this->logic->frequency(parameters->freq);
                
                Serial.println("AudioSynthWaveformPWM.frequency -> void");
                return new AudioSynthWaveformPWMResponse(AudioSynthWaveformPWMRequest_FREQUENCY, NULL);
            }

        case AudioSynthWaveformPWMRequest_AMPLITUDE:
            {
                AudioSynthWaveformPWMAmplitudeRequest *parameters = (AudioSynthWaveformPWMAmplitudeRequest *)request->body;
                this->logic->amplitude(parameters->n);
                
                Serial.println("AudioSynthWaveformPWM.amplitude -> void");
                return new AudioSynthWaveformPWMResponse(AudioSynthWaveformPWMRequest_AMPLITUDE, NULL);
            }
    }

    return new AudioSynthWaveformPWMResponse(AudioSynthWaveformPWMResponse_ERROR, NULL);
};