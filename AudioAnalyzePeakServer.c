#
#  AudioAnalyzePeakServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioAnalyzePeakServer:
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
            request = connection.read(AudioAnalyzePeakResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioAnalyzePeakAvailableRequest):
                result = self.handler.available()
                response = AudioAnalyzePeakAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzePeakReadRequest):
                result = self.handler.read()
                response = AudioAnalyzePeakReadResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzePeakReadpeaktopeakRequest):
                result = self.handler.readPeakToPeak()
                response = AudioAnalyzePeakReadpeaktopeakResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioAnalyzePeakError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return