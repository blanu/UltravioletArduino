//
// AudioInputI2SServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioInputI2SServerInit(int listener,
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
            request = connection.read(AudioInputI2SResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioInputI2SBeginRequest):
                self.handler.begin()
                response = AudioInputI2SBeginResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioInputI2SError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return