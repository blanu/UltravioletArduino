#
#  MutableIntegerServer.c
#
#
#  Created by Clockwork on Jun 8, 2023.
#

class MutableIntegerServer:
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
            request = connection.read(MutableIntegerResponse)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Set):
                self.handler.set(newState)
                response = MutableIntegerSetResponse()
                self.connection.write(response)

            if isinstance(request, Setint):
                self.handler.setInt(newState)
                response = MutableIntegerSetintResponse()
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = MutableIntegerError(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return