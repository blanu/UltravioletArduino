#
#  AudioSynthWaveformSineServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioSynthWaveformSineServer:
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
            request = connection.read(AudioSynthWaveformSineResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Frequency):
                self.handler.frequency(freq)
                response = AudioSynthWaveformSineFrequencyResponse()
                self.connection.write(response)

            if isinstance(request, Phase):
                self.handler.phase(angle)
                response = AudioSynthWaveformSinePhaseResponse()
                self.connection.write(response)

            if isinstance(request, Amplitude):
                self.handler.amplitude(n)
                response = AudioSynthWaveformSineAmplitudeResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthWaveformSineError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return