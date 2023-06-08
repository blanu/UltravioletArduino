//
// AudioEffectEnvelopeServer.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioEffectEnvelopeServerInit(int listener,
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
            request = connection.read(AudioEffectEnvelopeResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Delay):
                self.handler.delay(milliseconds)
                response = AudioEffectEnvelopeDelayResponse()
                self.connection.write(response)

            if isinstance(request, Attack):
                self.handler.attack(milliseconds)
                response = AudioEffectEnvelopeAttackResponse()
                self.connection.write(response)

            if isinstance(request, Hold):
                self.handler.hold(milliseconds)
                response = AudioEffectEnvelopeHoldResponse()
                self.connection.write(response)

            if isinstance(request, Decay):
                self.handler.decay(milliseconds)
                response = AudioEffectEnvelopeDecayResponse()
                self.connection.write(response)

            if isinstance(request, Sustain):
                self.handler.sustain(level)
                response = AudioEffectEnvelopeSustainResponse()
                self.connection.write(response)

            if isinstance(request, Release):
                self.handler.release(milliseconds)
                response = AudioEffectEnvelopeReleaseResponse()
                self.connection.write(response)

            if isinstance(request, Releasenoteon):
                self.handler.releaseNoteOn(milliseconds)
                response = AudioEffectEnvelopeReleasenoteonResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioEffectEnvelopeError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return