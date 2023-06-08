//
//  AudioAnalyzeNoteFrequencyModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeNoteFrequencyModule.h"

AudioAnalyzeNoteFrequencyResponse *AudioAnalyzeNoteFrequencyModule::handle(AudioAnalyzeNoteFrequencyRequest *request)
{
    switch (request->type)
    {
        case AudioAnalyzeNoteFrequencyRequest_AUDIOANALYZENOTEFREQUENCY:
            {
                
                 result = this->logic->AudioAnalyzeNoteFrequency();
                AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse response = AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse(result);
                Serial.println("AudioAnalyzeNoteFrequency.AudioAnalyzeNoteFrequency -> ");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_AUDIOANALYZENOTEFREQUENCY, (void *)&response);
            }

        case AudioAnalyzeNoteFrequencyRequest_BEGIN:
            {
                AudioAnalyzeNoteFrequencyBeginRequest *parameters = (AudioAnalyzeNoteFrequencyBeginRequest *)request->body;
                this->logic->begin(parameters->threshold);
                
                Serial.println("AudioAnalyzeNoteFrequency.begin -> void");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_BEGIN, NULL);
            }

        case AudioAnalyzeNoteFrequencyRequest_THRESHOLD:
            {
                AudioAnalyzeNoteFrequencyThresholdRequest *parameters = (AudioAnalyzeNoteFrequencyThresholdRequest *)request->body;
                this->logic->threshold(parameters->p);
                
                Serial.println("AudioAnalyzeNoteFrequency.threshold -> void");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_THRESHOLD, NULL);
            }

        case AudioAnalyzeNoteFrequencyRequest_AVAILABLE:
            {
                
                bool result = this->logic->available();
                AudioAnalyzeNoteFrequencyAvailableResponse response = AudioAnalyzeNoteFrequencyAvailableResponse(result);
                Serial.println("AudioAnalyzeNoteFrequency.available -> bool");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_AVAILABLE, (void *)&response);
            }

        case AudioAnalyzeNoteFrequencyRequest_READ:
            {
                
                float result = this->logic->read();
                AudioAnalyzeNoteFrequencyReadResponse response = AudioAnalyzeNoteFrequencyReadResponse(result);
                Serial.println("AudioAnalyzeNoteFrequency.read -> float");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_READ, (void *)&response);
            }

        case AudioAnalyzeNoteFrequencyRequest_PROBABILITY:
            {
                
                float result = this->logic->probability();
                AudioAnalyzeNoteFrequencyProbabilityResponse response = AudioAnalyzeNoteFrequencyProbabilityResponse(result);
                Serial.println("AudioAnalyzeNoteFrequency.probability -> float");
                return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyRequest_PROBABILITY, (void *)&response);
            }
    }

    return new AudioAnalyzeNoteFrequencyResponse(AudioAnalyzeNoteFrequencyResponse_ERROR, NULL);
};