//
// AudioPlayMemoryServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioPlayMemoryServerInit(int listener,
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
            request = connection.read(AudioPlayMemoryResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioPlayMemoryStopRequest):
                self.handler.stop()
                response = AudioPlayMemoryStopResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlayMemoryPositionmillisRequest):
                result = self.handler.positionMillis()
                response = AudioPlayMemoryPositionmillisResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioPlayMemoryLengthmillisRequest):
                result = self.handler.lengthMillis()
                response = AudioPlayMemoryLengthmillisResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioPlayMemoryError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return