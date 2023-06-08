//
//  AudioSynthToneSweepModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthToneSweepModule.h"

AudioSynthToneSweepResponse *AudioSynthToneSweepModule::handle(AudioSynthToneSweepRequest *request)
{
    switch (request->type)
    {
        case AudioSynthToneSweepRequest_PLAY:
            {
                AudioSynthToneSweepPlayRequest *parameters = (AudioSynthToneSweepPlayRequest *)request->body;
                boolean result = this->logic->play(parameters->t_amp, parameters->t_lo, parameters->t_hi, parameters->t_time);
                AudioSynthToneSweepPlayResponse response = AudioSynthToneSweepPlayResponse(result);
                Serial.println("AudioSynthToneSweep.play -> boolean");
                return new AudioSynthToneSweepResponse(AudioSynthToneSweepRequest_PLAY, (void *)&response);
            }

        case AudioSynthToneSweepRequest_ISPLAYING:
            {
                
                unsigned char result = this->logic->isPlaying();
                AudioSynthToneSweepIsplayingResponse response = AudioSynthToneSweepIsplayingResponse(result);
                Serial.println("AudioSynthToneSweep.isPlaying -> unsigned char");
                return new AudioSynthToneSweepResponse(AudioSynthToneSweepRequest_ISPLAYING, (void *)&response);
            }
    }

    return new AudioSynthToneSweepResponse(AudioSynthToneSweepResponse_ERROR, NULL);
};