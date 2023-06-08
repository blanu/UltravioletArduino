#
#  AudioAnalyzeRMSServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioAnalyzeRMSServer:
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
            request = connection.read(AudioAnalyzeRMSResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioAnalyzeRMSAvailableRequest):
                result = self.handler.available()
                response = AudioAnalyzeRMSAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeRMSReadRequest):
                result = self.handler.read()
                response = AudioAnalyzeRMSReadResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioAnalyzeRMSError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return