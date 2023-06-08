#
#  AudioSynthKarplusStrongServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioSynthKarplusStrongServer:
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
            request = connection.read(AudioSynthKarplusStrongResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Noteon):
                self.handler.noteOn(frequency, velocity)
                response = AudioSynthKarplusStrongNoteonResponse()
                self.connection.write(response)

            if isinstance(request, Noteoff):
                self.handler.noteOff(velocity)
                response = AudioSynthKarplusStrongNoteoffResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthKarplusStrongError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return