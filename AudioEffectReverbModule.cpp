//
//  AudioEffectReverbModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioEffectReverbModule.h"

AudioEffectReverbResponse *AudioEffectReverbModule::handle(AudioEffectReverbRequest *request)
{
    switch (request->type)
    {
        case AudioEffectReverbRequest_AUDIOEFFECTREVERB:
            {
                
                 result = this->logic->AudioEffectReverb();
                AudioEffectReverbAudioeffectreverbResponse response = AudioEffectReverbAudioeffectreverbResponse(result);
                Serial.println("AudioEffectReverb.AudioEffectReverb -> ");
                return new AudioEffectReverbResponse(AudioEffectReverbRequest_AUDIOEFFECTREVERB, (void *)&response);
            }

        case AudioEffectReverbRequest_REVERBTIME:
            {
                
                 result = this->logic->reverbTime();
                AudioEffectReverbReverbtimeResponse response = AudioEffectReverbReverbtimeResponse(result);
                Serial.println("AudioEffectReverb.reverbTime -> ");
                return new AudioEffectReverbResponse(AudioEffectReverbRequest_REVERBTIME, (void *)&response);
            }
    }

    return new AudioEffectReverbResponse(AudioEffectReverbResponse_ERROR, NULL);
};