#
#  AudioFilterStateVariableServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioFilterStateVariableServer:
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
            request = connection.read(AudioFilterStateVariableResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Frequency):
                self.handler.frequency(freq)
                response = AudioFilterStateVariableFrequencyResponse()
                self.connection.write(response)

            if isinstance(request, Resonance):
                self.handler.resonance(q)
                response = AudioFilterStateVariableResonanceResponse()
                self.connection.write(response)

            if isinstance(request, Octavecontrol):
                self.handler.octaveControl(n)
                response = AudioFilterStateVariableOctavecontrolResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioFilterStateVariableError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return