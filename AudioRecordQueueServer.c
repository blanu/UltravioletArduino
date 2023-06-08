#
#  AudioRecordQueueServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class AudioRecordQueueServer:
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
            request = connection.read(AudioRecordQueueResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioRecordQueueBeginRequest):
                self.handler.begin()
                response = AudioRecordQueueBeginResponse()
                self.connection.write(response)

            if isinstance(request, AudioRecordQueueAvailableRequest):
                result = self.handler.available()
                response = AudioRecordQueueAvailableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioRecordQueueClearRequest):
                self.handler.clear()
                response = AudioRecordQueueClearResponse()
                self.connection.write(response)

            if isinstance(request, AudioRecordQueueFreebufferRequest):
                self.handler.freeBuffer()
                response = AudioRecordQueueFreebufferResponse()
                self.connection.write(response)

            if isinstance(request, AudioRecordQueueEndRequest):
                self.handler.end()
                response = AudioRecordQueueEndResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioRecordQueueError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return