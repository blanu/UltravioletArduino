//
// AudioSynthWaveformServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioSynthWaveformServerInit(int listener,
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
            request = connection.read(AudioSynthWaveformResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Frequency):
                self.handler.frequency(t_freq)
                response = AudioSynthWaveformFrequencyResponse()
                self.connection.write(response)

            if isinstance(request, Phase):
                self.handler.phase(angle)
                response = AudioSynthWaveformPhaseResponse()
                self.connection.write(response)

            if isinstance(request, Offset):
                self.handler.offset(n)
                response = AudioSynthWaveformOffsetResponse()
                self.connection.write(response)

            if isinstance(request, Begin):
                self.handler.begin(t_type)
                response = AudioSynthWaveformBeginResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthWaveformError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return