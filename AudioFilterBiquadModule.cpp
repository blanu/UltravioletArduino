//
//  AudioFilterBiquadModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterBiquadModule.h"

AudioFilterBiquadResponse *AudioFilterBiquadModule::handle(AudioFilterBiquadRequest *request)
{
    switch (request->type)
    {
        case AudioFilterBiquadRequest_SETLOWPASS:
            {
                AudioFilterBiquadSetlowpassRequest *parameters = (AudioFilterBiquadSetlowpassRequest *)request->body;
                this->logic->setLowpass(parameters->stage, parameters->frequency, parameters->0.7071);
                
                Serial.println("AudioFilterBiquad.setLowpass -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETLOWPASS, NULL);
            }

        case AudioFilterBiquadRequest_SETHIGHPASS:
            {
                AudioFilterBiquadSethighpassRequest *parameters = (AudioFilterBiquadSethighpassRequest *)request->body;
                this->logic->setHighpass(parameters->stage, parameters->frequency, parameters->0.7071);
                
                Serial.println("AudioFilterBiquad.setHighpass -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETHIGHPASS, NULL);
            }

        case AudioFilterBiquadRequest_SETBANDPASS:
            {
                AudioFilterBiquadSetbandpassRequest *parameters = (AudioFilterBiquadSetbandpassRequest *)request->body;
                this->logic->setBandpass(parameters->stage, parameters->frequency, parameters->1.0);
                
                Serial.println("AudioFilterBiquad.setBandpass -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETBANDPASS, NULL);
            }

        case AudioFilterBiquadRequest_SETNOTCH:
            {
                AudioFilterBiquadSetnotchRequest *parameters = (AudioFilterBiquadSetnotchRequest *)request->body;
                this->logic->setNotch(parameters->stage, parameters->frequency, parameters->1.0);
                
                Serial.println("AudioFilterBiquad.setNotch -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETNOTCH, NULL);
            }

        case AudioFilterBiquadRequest_SETLOWSHELF:
            {
                AudioFilterBiquadSetlowshelfRequest *parameters = (AudioFilterBiquadSetlowshelfRequest *)request->body;
                this->logic->setLowShelf(parameters->stage, parameters->frequency, parameters->gain, parameters->1.0f);
                
                Serial.println("AudioFilterBiquad.setLowShelf -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETLOWSHELF, NULL);
            }

        case AudioFilterBiquadRequest_SETHIGHSHELF:
            {
                AudioFilterBiquadSethighshelfRequest *parameters = (AudioFilterBiquadSethighshelfRequest *)request->body;
                this->logic->setHighShelf(parameters->stage, parameters->frequency, parameters->gain, parameters->1.0f);
                
                Serial.println("AudioFilterBiquad.setHighShelf -> void");
                return new AudioFilterBiquadResponse(AudioFilterBiquadRequest_SETHIGHSHELF, NULL);
            }
    }

    return new AudioFilterBiquadResponse(AudioFilterBiquadResponse_ERROR, NULL);
};