//
// AudioPlaySdRawServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioPlaySdRawServerInit(int listener,
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
            request = connection.read(AudioPlaySdRawResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioPlaySdRawBeginRequest):
                self.handler.begin()
                response = AudioPlaySdRawBeginResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlaySdRawStopRequest):
                self.handler.stop()
                response = AudioPlaySdRawStopResponse()
                self.connection.write(response)

            if isinstance(request, AudioPlaySdRawPositionmillisRequest):
                result = self.handler.positionMillis()
                response = AudioPlaySdRawPositionmillisResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioPlaySdRawLengthmillisRequest):
                result = self.handler.lengthMillis()
                response = AudioPlaySdRawLengthmillisResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioPlaySdRawError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return