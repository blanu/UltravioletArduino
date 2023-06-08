//
// AudioPlayQueueServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioPlayQueueServerInit(int listener,
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
            request = connection.read(AudioPlayQueueResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Play):
                self.handler.play(data)
                response = AudioPlayQueuePlayResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlayQueueAvailableRequest):
                result = self.handler.available()
                response = AudioPlayQueueAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioPlayQueuePlaybufferRequest):
                self.handler.playBuffer()
                response = AudioPlayQueuePlaybufferResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlayQueueStopRequest):
                self.handler.stop()
                response = AudioPlayQueueStopResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioPlayQueueError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return