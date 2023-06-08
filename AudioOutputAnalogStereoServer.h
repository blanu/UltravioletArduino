//
// AudioOutputAnalogStereoServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioOutputAnalogStereoServerInit(int listener,
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
            request = connection.read(AudioOutputAnalogStereoResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioOutputAnalogStereoBeginRequest):
                self.handler.begin()
                response = AudioOutputAnalogStereoBeginResponse()
                self.connection.write(response)

            if isinstance(request, Analogreference):
                self.handler.analogReference(ref)
                response = AudioOutputAnalogStereoAnalogreferenceResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioOutputAnalogStereoError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return