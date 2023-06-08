//
//  AudioSynthWaveformModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthWaveformModule.h"

AudioSynthWaveformResponse *AudioSynthWaveformModule::handle(AudioSynthWaveformRequest *request)
{
    switch (request->type)
    {
        case AudioSynthWaveformRequest_FREQUENCY:
            {
                AudioSynthWaveformFrequencyRequest *parameters = (AudioSynthWaveformFrequencyRequest *)request->body;
                this->logic->frequency(parameters->t_freq);
                
                Serial.println("AudioSynthWaveform.frequency -> void");
                return new AudioSynthWaveformResponse(AudioSynthWaveformRequest_FREQUENCY, NULL);
            }

        case AudioSynthWaveformRequest_PHASE:
            {
                AudioSynthWaveformPhaseRequest *parameters = (AudioSynthWaveformPhaseRequest *)request->body;
                this->logic->phase(parameters->angle);
                
                Serial.println("AudioSynthWaveform.phase -> void");
                return new AudioSynthWaveformResponse(AudioSynthWaveformRequest_PHASE, NULL);
            }

        case AudioSynthWaveformRequest_OFFSET:
            {
                AudioSynthWaveformOffsetRequest *parameters = (AudioSynthWaveformOffsetRequest *)request->body;
                this->logic->offset(parameters->n);
                
                Serial.println("AudioSynthWaveform.offset -> void");
                return new AudioSynthWaveformResponse(AudioSynthWaveformRequest_OFFSET, NULL);
            }

        case AudioSynthWaveformRequest_BEGIN:
            {
                AudioSynthWaveformBeginRequest *parameters = (AudioSynthWaveformBeginRequest *)request->body;
                this->logic->begin(parameters->t_type);
                
                Serial.println("AudioSynthWaveform.begin -> void");
                return new AudioSynthWaveformResponse(AudioSynthWaveformRequest_BEGIN, NULL);
            }
    }

    return new AudioSynthWaveformResponse(AudioSynthWaveformResponse_ERROR, NULL);
};