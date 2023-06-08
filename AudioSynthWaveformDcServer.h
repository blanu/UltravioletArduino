//
// AudioSynthWaveformDcServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioSynthWaveformDcServerInit(int listener,
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
            request = connection.read(AudioSynthWaveformDcResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Amplitude):
                self.handler.amplitude(n)
                response = AudioSynthWaveformDcAmplitudeResponse()
                self.connection.write(response)

            if isinstance(request, AudioSynthWaveformDcReadRequest):
                result = self.handler.read()
                response = AudioSynthWaveformDcReadResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthWaveformDcError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return