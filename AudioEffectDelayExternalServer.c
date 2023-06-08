#
#  AudioEffectDelayExternalServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioEffectDelayExternalServer:
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
            request = connection.read(AudioEffectDelayExternalResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Delay):
                self.handler.delay(channel, milliseconds)
                response = AudioEffectDelayExternalDelayResponse()
                self.connection.write(response)

            if isinstance(request, Disable):
                self.handler.disable(channel)
                response = AudioEffectDelayExternalDisableResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioEffectDelayExternalError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return