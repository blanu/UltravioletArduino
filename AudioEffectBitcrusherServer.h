//
// AudioEffectBitcrusherServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioEffectBitcrusherServerInit(int listener,
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
            request = connection.read(AudioEffectBitcrusherResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Bits):
                self.handler.bits(b)
                response = AudioEffectBitcrusherBitsResponse()
                self.connection.write(response)

            if isinstance(request, Samplerate):
                self.handler.sampleRate(hz)
                response = AudioEffectBitcrusherSamplerateResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioEffectBitcrusherError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return