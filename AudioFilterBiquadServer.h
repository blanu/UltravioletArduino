//
// AudioFilterBiquadServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioFilterBiquadServerInit(int listener,
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
            request = connection.read(AudioFilterBiquadResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Setlowpass):
                self.handler.setLowpass(stage, frequency, 0.7071)
                response = AudioFilterBiquadSetlowpassResponse()
                self.connection.write(response)

            if isinstance(request, Sethighpass):
                self.handler.setHighpass(stage, frequency, 0.7071)
                response = AudioFilterBiquadSethighpassResponse()
                self.connection.write(response)

            if isinstance(request, Setbandpass):
                self.handler.setBandpass(stage, frequency, 1.0)
                response = AudioFilterBiquadSetbandpassResponse()
                self.connection.write(response)

            if isinstance(request, Setnotch):
                self.handler.setNotch(stage, frequency, 1.0)
                response = AudioFilterBiquadSetnotchResponse()
                self.connection.write(response)

            if isinstance(request, Setlowshelf):
                self.handler.setLowShelf(stage, frequency, gain, 1.0f)
                response = AudioFilterBiquadSetlowshelfResponse()
                self.connection.write(response)

            if isinstance(request, Sethighshelf):
                self.handler.setHighShelf(stage, frequency, gain, 1.0f)
                response = AudioFilterBiquadSethighshelfResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioFilterBiquadError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return