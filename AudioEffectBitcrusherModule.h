//
// AudioEffectBitcrusherModule.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

#ifndef AudioEffectBitcrusherModule_h_
#define AudioEffectBitcrusherModule_h_

#include <Arduino.h>
#include "Audio.h"
#include "AudioEffectBitcrusherMessages.h"

class AudioEffectBitcrusherModule
{
    public:
        AudioEffectBitcrusherModule(AudioEffectBitcrusher *component) : logic(component) {}

        AudioEffectBitcrusher *logic;
        AudioEffectBitcrusherResponse *handle(AudioEffectBitcrusherRequest *request);
};

#endif