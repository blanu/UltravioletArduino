#
#  AudioOutputI2SServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioOutputI2SServer:
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
            request = connection.read(AudioOutputI2SResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioOutputI2SBeginRequest):
                self.handler.begin()
                response = AudioOutputI2SBeginResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioOutputI2SError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return