//
//  AudioPlayFSWavModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioPlayFSWavModule.h"

AudioPlayFSWavResponse *AudioPlayFSWavModule::handle(AudioPlayFSWavRequest *request)
{
    switch (request->type)
    {
        case AudioPlayFSWavRequest_BEGIN:
            {
                
                this->logic->begin();
                
                Serial.println("AudioPlayFSWav.begin -> void");
                return new AudioPlayFSWavResponse(AudioPlayFSWavRequest_BEGIN, NULL);
            }

        case AudioPlayFSWavRequest_ISPLAYING:
            {
                
                bool result = this->logic->isPlaying();
                AudioPlayFSWavIsplayingResponse response = AudioPlayFSWavIsplayingResponse(result);
                Serial.println("AudioPlayFSWav.isPlaying -> bool");
                return new AudioPlayFSWavResponse(AudioPlayFSWavRequest_ISPLAYING, (void *)&response);
            }

        case AudioPlayFSWavRequest_POSITIONMILLIS:
            {
                
                uint32_t result = this->logic->positionMillis();
                AudioPlayFSWavPositionmillisResponse response = AudioPlayFSWavPositionmillisResponse(result);
                Serial.println("AudioPlayFSWav.positionMillis -> uint32_t");
                return new AudioPlayFSWavResponse(AudioPlayFSWavRequest_POSITIONMILLIS, (void *)&response);
            }

        case AudioPlayFSWavRequest_LENGTHMILLIS:
            {
                
                uint32_t result = this->logic->lengthMillis();
                AudioPlayFSWavLengthmillisResponse response = AudioPlayFSWavLengthmillisResponse(result);
                Serial.println("AudioPlayFSWav.lengthMillis -> uint32_t");
                return new AudioPlayFSWavResponse(AudioPlayFSWavRequest_LENGTHMILLIS, (void *)&response);
            }
    }

    return new AudioPlayFSWavResponse(AudioPlayFSWavResponse_ERROR, NULL);
};