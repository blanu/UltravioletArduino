#
#  AudioAnalyzeNoteFrequencyServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioAnalyzeNoteFrequencyServer:
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
            request = connection.read(AudioAnalyzeNoteFrequencyResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyRequest):
                result = self.handler.AudioAnalyzeNoteFrequency()
                response = AudioAnalyzeNoteFrequencyAudioanalyzenotefrequencyResponse(result)
                self.connection.write(response)

            if isinstance(request, Begin):
                self.handler.begin(threshold)
                response = AudioAnalyzeNoteFrequencyBeginResponse()
                self.connection.write(response)

            if isinstance(request, Threshold):
                self.handler.threshold(p)
                response = AudioAnalyzeNoteFrequencyThresholdResponse()
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeNoteFrequencyAvailableRequest):
                result = self.handler.available()
                response = AudioAnalyzeNoteFrequencyAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeNoteFrequencyReadRequest):
                result = self.handler.read()
                response = AudioAnalyzeNoteFrequencyReadResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioAnalyzeNoteFrequencyProbabilityRequest):
                result = self.handler.probability()
                response = AudioAnalyzeNoteFrequencyProbabilityResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioAnalyzeNoteFrequencyError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return