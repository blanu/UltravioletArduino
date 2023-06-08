//
// AudioControlCS42448Server.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioControlCS42448ServerInit(int listener,
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
            request = connection.read(AudioControlCS42448Response)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, Setaddress):
                self.handler.setAddress(addr)
                response = AudioControlCS42448SetaddressResponse()
                self.connection.write(response)

            if isinstance(request, AudioControlCS42448EnableRequest):
                result = self.handler.enable()
                response = AudioControlCS42448EnableResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS42448DisableRequest):
                result = self.handler.disable()
                response = AudioControlCS42448DisableResponse(result)
                self.connection.write(response)

            if isinstance(request, Volume):
                result = self.handler.volume(level)
                response = AudioControlCS42448VolumeResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS42448VolumeintegerRequest):
                result = self.handler.volumeInteger()
                response = AudioControlCS42448VolumeintegerResponse(result)
                self.connection.write(response)

            if isinstance(request, Inputlevel):
                result = self.handler.inputLevel(level)
                response = AudioControlCS42448InputlevelResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS42448InputlevelintegerRequest):
                result = self.handler.inputLevelInteger()
                response = AudioControlCS42448InputlevelintegerResponse(result)
                self.connection.write(response)

            if isinstance(request, Inputselect):
                result = self.handler.inputSelect(n)
                response = AudioControlCS42448InputselectResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioControlCS42448Error(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return