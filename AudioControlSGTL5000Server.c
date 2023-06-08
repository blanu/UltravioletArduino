#
#  AudioControlSGTL5000Server.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioControlSGTL5000Server:
    def __init__(self, listener, handler):
        self.listener = listener
        self.handler = handler

        self.accept()

    def shutdown(self):
        pass

    def accept(self):
        connection = self.listener.accept()
        self.handleConnection(connection)

    def handleConnection(self, connection):
        try:
            request = connection.read(AudioControlSGTL5000Response)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Setaddress):
                self.handler.setAddress(level)
                response = AudioControlSGTL5000SetaddressResponse()
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000EnableRequest):
                result = self.handler.enable()
                response = AudioControlSGTL5000EnableResponse(result)
                self.connection.write(response)

            if isinstance(request, Inputselect):
                result = self.handler.inputSelect(n)
                response = AudioControlSGTL5000InputselectResponse(result)
                self.connection.write(response)

            if isinstance(request, Volume):
                result = self.handler.volume(left, right)
                response = AudioControlSGTL5000VolumeResponse(result)
                self.connection.write(response)

            if isinstance(request, Micgain):
                result = self.handler.micGain(dB)
                response = AudioControlSGTL5000MicgainResponse(result)
                self.connection.write(response)

            if isinstance(request, Lineinlevel):
                result = self.handler.lineInLevel(left, right)
                response = AudioControlSGTL5000LineinlevelResponse(result)
                self.connection.write(response)

            if isinstance(request, Lineoutlevel):
                result = self.handler.lineOutLevel(n)
                response = AudioControlSGTL5000LineoutlevelResponse(result)
                self.connection.write(response)

            if isinstance(request, Dacvolume):
                result = self.handler.dacVolume(n)
                response = AudioControlSGTL5000DacvolumeResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AdchighpassfilterenableRequest):
                result = self.handler.adcHighPassFilterEnable()
                response = AudioControlSGTL5000AdchighpassfilterenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AdchighpassfilterfreezeRequest):
                result = self.handler.adcHighPassFilterFreeze()
                response = AudioControlSGTL5000AdchighpassfilterfreezeResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AdchighpassfilterdisableRequest):
                result = self.handler.adcHighPassFilterDisable()
                response = AudioControlSGTL5000AdchighpassfilterdisableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AudiopreprocessorenableRequest):
                result = self.handler.audioPreProcessorEnable()
                response = AudioControlSGTL5000AudiopreprocessorenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AudiopostprocessorenableRequest):
                result = self.handler.audioPostProcessorEnable()
                response = AudioControlSGTL5000AudiopostprocessorenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AudioprocessordisableRequest):
                result = self.handler.audioProcessorDisable()
                response = AudioControlSGTL5000AudioprocessordisableResponse(result)
                self.connection.write(response)

            if isinstance(request, Eqfiltercount):
                result = self.handler.eqFilterCount(n)
                response = AudioControlSGTL5000EqfiltercountResponse(result)
                self.connection.write(response)

            if isinstance(request, Eqselect):
                result = self.handler.eqSelect(n)
                response = AudioControlSGTL5000EqselectResponse(result)
                self.connection.write(response)

            if isinstance(request, Eqband):
                result = self.handler.eqBand(bandNum, n)
                response = AudioControlSGTL5000EqbandResponse(result)
                self.connection.write(response)

            if isinstance(request, Eqbands):
                self.handler.eqBands(bass, mid_bass, midrange, mid_treble, treble)
                response = AudioControlSGTL5000EqbandsResponse()
                self.connection.write(response)

            if isinstance(request, Autovolumecontrol):
                result = self.handler.autoVolumeControl(maxGain, lbiResponse, hardLimit, threshold, attack, decay)
                response = AudioControlSGTL5000AutovolumecontrolResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AutovolumeenableRequest):
                result = self.handler.autoVolumeEnable()
                response = AudioControlSGTL5000AutovolumeenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000AutovolumedisableRequest):
                result = self.handler.autoVolumeDisable()
                response = AudioControlSGTL5000AutovolumedisableResponse(result)
                self.connection.write(response)

            if isinstance(request, Enhancebass):
                result = self.handler.enhanceBass(lr_lev, bass_lev)
                response = AudioControlSGTL5000EnhancebassResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000EnhancebassenableRequest):
                result = self.handler.enhanceBassEnable()
                response = AudioControlSGTL5000EnhancebassenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000EnhancebassdisableRequest):
                result = self.handler.enhanceBassDisable()
                response = AudioControlSGTL5000EnhancebassdisableResponse(result)
                self.connection.write(response)

            if isinstance(request, Surroundsound):
                result = self.handler.surroundSound(width)
                response = AudioControlSGTL5000SurroundsoundResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000SurroundsoundenableRequest):
                result = self.handler.surroundSoundEnable()
                response = AudioControlSGTL5000SurroundsoundenableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlSGTL5000SurroundsounddisableRequest):
                result = self.handler.surroundSoundDisable()
                response = AudioControlSGTL5000SurroundsounddisableResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioControlSGTL5000Error(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return