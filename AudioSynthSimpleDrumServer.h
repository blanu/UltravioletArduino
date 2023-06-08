//
// AudioSynthSimpleDrumServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioSynthSimpleDrumServerInit(int listener,
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
            request = connection.read(AudioSynthSimpleDrumResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioSynthSimpleDrumLengthRequest):
                result = self.handler.length()
                response = AudioSynthSimpleDrumLengthResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioSynthSimpleDrumFrequencyRequest):
                result = self.handler.frequency()
                response = AudioSynthSimpleDrumFrequencyResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioSynthSimpleDrumPitchmodRequest):
                result = self.handler.pitchMod()
                response = AudioSynthSimpleDrumPitchmodResponse(result)
                self.connection.write(response)

            if isinstance(request, Secondmix):
                self.handler.secondMix(level)
                response = AudioSynthSimpleDrumSecondmixResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthSimpleDrumError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return