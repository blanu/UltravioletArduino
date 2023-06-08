//
//  AudioSynthSimpleDrumModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthSimpleDrumModule.h"

AudioSynthSimpleDrumResponse *AudioSynthSimpleDrumModule::handle(AudioSynthSimpleDrumRequest *request)
{
    switch (request->type)
    {
        case AudioSynthSimpleDrumRequest_LENGTH:
            {
                
                 result = this->logic->length();
                AudioSynthSimpleDrumLengthResponse response = AudioSynthSimpleDrumLengthResponse(result);
                Serial.println("AudioSynthSimpleDrum.length -> ");
                return new AudioSynthSimpleDrumResponse(AudioSynthSimpleDrumRequest_LENGTH, (void *)&response);
            }

        case AudioSynthSimpleDrumRequest_FREQUENCY:
            {
                
                 result = this->logic->frequency();
                AudioSynthSimpleDrumFrequencyResponse response = AudioSynthSimpleDrumFrequencyResponse(result);
                Serial.println("AudioSynthSimpleDrum.frequency -> ");
                return new AudioSynthSimpleDrumResponse(AudioSynthSimpleDrumRequest_FREQUENCY, (void *)&response);
            }

        case AudioSynthSimpleDrumRequest_PITCHMOD:
            {
                
                 result = this->logic->pitchMod();
                AudioSynthSimpleDrumPitchmodResponse response = AudioSynthSimpleDrumPitchmodResponse(result);
                Serial.println("AudioSynthSimpleDrum.pitchMod -> ");
                return new AudioSynthSimpleDrumResponse(AudioSynthSimpleDrumRequest_PITCHMOD, (void *)&response);
            }

        case AudioSynthSimpleDrumRequest_SECONDMIX:
            {
                AudioSynthSimpleDrumSecondmixRequest *parameters = (AudioSynthSimpleDrumSecondmixRequest *)request->body;
                this->logic->secondMix(parameters->level);
                
                Serial.println("AudioSynthSimpleDrum.secondMix -> void");
                return new AudioSynthSimpleDrumResponse(AudioSynthSimpleDrumRequest_SECONDMIX, NULL);
            }
    }

    return new AudioSynthSimpleDrumResponse(AudioSynthSimpleDrumResponse_ERROR, NULL);
};