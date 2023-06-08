//
//  AudioSynthWaveformSineModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformSineModule.h"

AudioSynthWaveformSineResponse *AudioSynthWaveformSineModule::handle(AudioSynthWaveformSineRequest *request)
{
    switch (request->type)
    {
        case AudioSynthWaveformSineRequest_FREQUENCY:
            {
                AudioSynthWaveformSineFrequencyRequest *parameters = (AudioSynthWaveformSineFrequencyRequest *)request->body;
                this->logic->frequency(parameters->freq);
                
                Serial.println("AudioSynthWaveformSine.frequency -> void");
                return new AudioSynthWaveformSineResponse(AudioSynthWaveformSineRequest_FREQUENCY, NULL);
            }

        case AudioSynthWaveformSineRequest_PHASE:
            {
                AudioSynthWaveformSinePhaseRequest *parameters = (AudioSynthWaveformSinePhaseRequest *)request->body;
                this->logic->phase(parameters->angle);
                
                Serial.println("AudioSynthWaveformSine.phase -> void");
                return new AudioSynthWaveformSineResponse(AudioSynthWaveformSineRequest_PHASE, NULL);
            }

        case AudioSynthWaveformSineRequest_AMPLITUDE:
            {
                AudioSynthWaveformSineAmplitudeRequest *parameters = (AudioSynthWaveformSineAmplitudeRequest *)request->body;
                this->logic->amplitude(parameters->n);
                
                Serial.println("AudioSynthWaveformSine.amplitude -> void");
                return new AudioSynthWaveformSineResponse(AudioSynthWaveformSineRequest_AMPLITUDE, NULL);
            }
    }

    return new AudioSynthWaveformSineResponse(AudioSynthWaveformSineResponse_ERROR, NULL);
};