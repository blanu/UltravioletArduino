//
//  AudioFilterStateVariableModule.cpp
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#include "AudioFilterStateVariableModule.h"

AudioFilterStateVariableResponse *AudioFilterStateVariableModule::handle(AudioFilterStateVariableRequest *request)
{
    switch (request->type)
    {
        case AudioFilterStateVariableRequest_FREQUENCY:
            {
                AudioFilterStateVariableFrequencyRequest *parameters = (AudioFilterStateVariableFrequencyRequest *)request->body;
                this->logic->frequency(parameters->freq);
                
                Serial.println("AudioFilterStateVariable.frequency -> void");
                return new AudioFilterStateVariableResponse(AudioFilterStateVariableRequest_FREQUENCY, NULL);
            }

        case AudioFilterStateVariableRequest_RESONANCE:
            {
                AudioFilterStateVariableResonanceRequest *parameters = (AudioFilterStateVariableResonanceRequest *)request->body;
                this->logic->resonance(parameters->q);
                
                Serial.println("AudioFilterStateVariable.resonance -> void");
                return new AudioFilterStateVariableResponse(AudioFilterStateVariableRequest_RESONANCE, NULL);
            }

        case AudioFilterStateVariableRequest_OCTAVECONTROL:
            {
                AudioFilterStateVariableOctavecontrolRequest *parameters = (AudioFilterStateVariableOctavecontrolRequest *)request->body;
                this->logic->octaveControl(parameters->n);
                
                Serial.println("AudioFilterStateVariable.octaveControl -> void");
                return new AudioFilterStateVariableResponse(AudioFilterStateVariableRequest_OCTAVECONTROL, NULL);
            }
    }

    return new AudioFilterStateVariableResponse(AudioFilterStateVariableResponse_ERROR, NULL);
};