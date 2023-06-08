//
//  AudioSynthKarplusStrongModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioSynthKarplusStrongModule.h"

AudioSynthKarplusStrongResponse *AudioSynthKarplusStrongModule::handle(AudioSynthKarplusStrongRequest *request)
{
    switch (request->type)
    {
        case AudioSynthKarplusStrongRequest_NOTEON:
            {
                AudioSynthKarplusStrongNoteonRequest *parameters = (AudioSynthKarplusStrongNoteonRequest *)request->body;
                this->logic->noteOn(parameters->frequency, parameters->velocity);
                
                Serial.println("AudioSynthKarplusStrong.noteOn -> void");
                return new AudioSynthKarplusStrongResponse(AudioSynthKarplusStrongRequest_NOTEON, NULL);
            }

        case AudioSynthKarplusStrongRequest_NOTEOFF:
            {
                AudioSynthKarplusStrongNoteoffRequest *parameters = (AudioSynthKarplusStrongNoteoffRequest *)request->body;
                this->logic->noteOff(parameters->velocity);
                
                Serial.println("AudioSynthKarplusStrong.noteOff -> void");
                return new AudioSynthKarplusStrongResponse(AudioSynthKarplusStrongRequest_NOTEOFF, NULL);
            }
    }

    return new AudioSynthKarplusStrongResponse(AudioSynthKarplusStrongResponse_ERROR, NULL);
};