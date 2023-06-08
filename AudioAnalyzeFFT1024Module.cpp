//
//  AudioAnalyzeFFT1024Module.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioAnalyzeFFT1024Module.h"

AudioAnalyzeFFT1024Response *AudioAnalyzeFFT1024Module::handle(AudioAnalyzeFFT1024Request *request)
{
    switch (request->type)
    {
        case AudioAnalyzeFFT1024Request_WINDOW:
            {
                
                 result = this->logic->window();
                AudioAnalyzeFFT1024WindowResponse response = AudioAnalyzeFFT1024WindowResponse(result);
                Serial.println("AudioAnalyzeFFT1024.window -> ");
                return new AudioAnalyzeFFT1024Response(AudioAnalyzeFFT1024Request_WINDOW, (void *)&response);
            }

        case AudioAnalyzeFFT1024Request_READ:
            {
                AudioAnalyzeFFT1024ReadRequest *parameters = (AudioAnalyzeFFT1024ReadRequest *)request->body;
                float result = this->logic->read(parameters->binNumber);
                AudioAnalyzeFFT1024ReadResponse response = AudioAnalyzeFFT1024ReadResponse(result);
                Serial.println("AudioAnalyzeFFT1024.read -> float");
                return new AudioAnalyzeFFT1024Response(AudioAnalyzeFFT1024Request_READ, (void *)&response);
            }

        case AudioAnalyzeFFT1024Request_AVERAGETOGETHER:
            {
                AudioAnalyzeFFT1024AveragetogetherRequest *parameters = (AudioAnalyzeFFT1024AveragetogetherRequest *)request->body;
                this->logic->averageTogether(parameters->n);
                
                Serial.println("AudioAnalyzeFFT1024.averageTogether -> void");
                return new AudioAnalyzeFFT1024Response(AudioAnalyzeFFT1024Request_AVERAGETOGETHER, NULL);
            }
    }

    return new AudioAnalyzeFFT1024Response(AudioAnalyzeFFT1024Response_ERROR, NULL);
};