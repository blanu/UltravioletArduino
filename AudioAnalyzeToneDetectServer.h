//
// AudioAnalyzeToneDetectServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioAnalyzeToneDetectServerInit(int listener,
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
            request = connection.read(AudioAnalyzeToneDetectResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Frequency):
                self.handler.frequency(freq, cycles=10)
                response = AudioAnalyzeToneDetectFrequencyResponse()
                self.connection.write(response)

            if isinstance(request, Set_Params):
                self.handler.set_params(coef, cycles, len)
                response = AudioAnalyzeToneDetectSet_ParamsResponse()
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeToneDetectAvailableRequest):
                result = self.handler.available()
                response = AudioAnalyzeToneDetectAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeToneDetectReadRequest):
                result = self.handler.read()
                response = AudioAnalyzeToneDetectReadResponse(result)
                self.connection.write(response)

            if isinstance(request, Threshold):
                self.handler.threshold(level)
                response = AudioAnalyzeToneDetectThresholdResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioAnalyzeToneDetectError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return