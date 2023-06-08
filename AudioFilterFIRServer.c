#
#  AudioFilterFIRServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioFilterFIRServer:
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
            request = connection.read(AudioFilterFIRResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioFilterFIREndRequest):
                self.handler.end()
                response = AudioFilterFIREndResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioFilterFIRError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return