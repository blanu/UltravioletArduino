//
//  AudioAnalyzeFFT256Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeFFT256Module.h"

AudioAnalyzeFFT256Response *AudioAnalyzeFFT256Module::handle(AudioAnalyzeFFT256Request *request)
{
    switch (request->type)
    {
        case AudioAnalyzeFFT256Request_WINDOW:
            {
                
                 result = this->logic->window();
                AudioAnalyzeFFT256WindowResponse response = AudioAnalyzeFFT256WindowResponse(result);
                Serial.println("AudioAnalyzeFFT256.window -> ");
                return new AudioAnalyzeFFT256Response(AudioAnalyzeFFT256Request_WINDOW, (void *)&response);
            }

        case AudioAnalyzeFFT256Request_READ:
            {
                AudioAnalyzeFFT256ReadRequest *parameters = (AudioAnalyzeFFT256ReadRequest *)request->body;
                float result = this->logic->read(parameters->binNumber);
                AudioAnalyzeFFT256ReadResponse response = AudioAnalyzeFFT256ReadResponse(result);
                Serial.println("AudioAnalyzeFFT256.read -> float");
                return new AudioAnalyzeFFT256Response(AudioAnalyzeFFT256Request_READ, (void *)&response);
            }

        case AudioAnalyzeFFT256Request_AVERAGETOGETHER:
            {
                AudioAnalyzeFFT256AveragetogetherRequest *parameters = (AudioAnalyzeFFT256AveragetogetherRequest *)request->body;
                this->logic->averageTogether(parameters->n);
                
                Serial.println("AudioAnalyzeFFT256.averageTogether -> void");
                return new AudioAnalyzeFFT256Response(AudioAnalyzeFFT256Request_AVERAGETOGETHER, NULL);
            }
    }

    return new AudioAnalyzeFFT256Response(AudioAnalyzeFFT256Response_ERROR, NULL);
};