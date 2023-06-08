//
// AudioPlayFSWavServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioPlayFSWavServerInit(int listener,
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
            request = connection.read(AudioPlayFSWavResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioPlayFSWavBeginRequest):
                self.handler.begin()
                response = AudioPlayFSWavBeginResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlayFSWavIsplayingRequest):
                result = self.handler.isPlaying()
                response = AudioPlayFSWavIsplayingResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioPlayFSWavPositionmillisRequest):
                result = self.handler.positionMillis()
                response = AudioPlayFSWavPositionmillisResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioPlayFSWavLengthmillisRequest):
                result = self.handler.lengthMillis()
                response = AudioPlayFSWavLengthmillisResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioPlayFSWavError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return