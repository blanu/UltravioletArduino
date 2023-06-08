#
#  AudioAnalyzeFFT256Server.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioAnalyzeFFT256Server:
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
            request = connection.read(AudioAnalyzeFFT256Response)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioAnalyzeFFT256WindowRequest):
                result = self.handler.window()
                response = AudioAnalyzeFFT256WindowResponse(result)
                self.connection.write(response)

            if isinstance(request, Read):
                result = self.handler.read(binNumber)
                response = AudioAnalyzeFFT256ReadResponse(result)
                self.connection.write(response)

            if isinstance(request, Averagetogether):
                self.handler.averageTogether(n)
                response = AudioAnalyzeFFT256AveragetogetherResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioAnalyzeFFT256Error(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return