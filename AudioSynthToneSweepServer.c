#
#  AudioSynthToneSweepServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioSynthToneSweepServer:
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
            request = connection.read(AudioSynthToneSweepResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Play):
                result = self.handler.play(t_amp, t_lo, t_hi, t_time)
                response = AudioSynthToneSweepPlayResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioSynthToneSweepIsplayingRequest):
                result = self.handler.isPlaying()
                response = AudioSynthToneSweepIsplayingResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioSynthToneSweepError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return