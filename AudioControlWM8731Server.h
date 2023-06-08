//
// AudioControlWM8731Server.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioControlWM8731ServerInit(int listener,
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
            request = connection.read(AudioControlWM8731Response)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioControlWM8731EnableRequest):
                result = self.handler.enable()
                response = AudioControlWM8731EnableResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioControlWM8731Error(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return