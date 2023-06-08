#
#  AudioEffectReverbServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioEffectReverbServer:
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
            request = connection.read(AudioEffectReverbResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioEffectReverbAudioeffectreverbRequest):
                result = self.handler.AudioEffectReverb()
                response = AudioEffectReverbAudioeffectreverbResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioEffectReverbReverbtimeRequest):
                result = self.handler.reverbTime()
                response = AudioEffectReverbReverbtimeResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioEffectReverbError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return