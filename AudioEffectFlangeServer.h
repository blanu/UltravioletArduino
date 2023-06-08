//
// AudioEffectFlangeServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioEffectFlangeServerInit(int listener,
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
            request = connection.read(AudioEffectFlangeResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Voices):
                result = self.handler.voices(delay_offset, d_depth, delay_rate)
                response = AudioEffectFlangeVoicesResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioEffectFlangeError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return