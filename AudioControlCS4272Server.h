//
// AudioControlCS4272Server.h
//
//
//  Created by Clockwork on Jun 8, 2023.
//

void AudioControlCS4272ServerInit(int listener,
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
            request = connection.read(AudioControlCS4272Response)
            if not request:
                raise Exception("request read failed")

            if isinstance(request, AudioControlCS4272EnableRequest):
                result = self.handler.enable()
                response = AudioControlCS4272EnableResponse(result)
                self.connection.write(response)

            if isinstance(request, Volume):
                result = self.handler.volume(left, right)
                response = AudioControlCS4272VolumeResponse(result)
                self.connection.write(response)

            if isinstance(request, Dacvolume):
                result = self.handler.dacVolume(left, right)
                response = AudioControlCS4272DacvolumeResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272MuteoutputRequest):
                result = self.handler.muteOutput()
                response = AudioControlCS4272MuteoutputResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272UnmuteoutputRequest):
                result = self.handler.unmuteOutput()
                response = AudioControlCS4272UnmuteoutputResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272MuteinputRequest):
                result = self.handler.muteInput()
                response = AudioControlCS4272MuteinputResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272UnmuteinputRequest):
                result = self.handler.unmuteInput()
                response = AudioControlCS4272UnmuteinputResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272EnableditherRequest):
                result = self.handler.enableDither()
                response = AudioControlCS4272EnableditherResponse(result)
                self.connection.write(response)

            if isinstance(request, AudioControlCS4272DisableditherRequest):
                result = self.handler.disableDither()
                response = AudioControlCS4272DisableditherResponse(result)
                self.connection.write(response)
        except Exception as e:
            print(e)

            error = AudioControlCS4272Error(str(e))
            try:
                connection.write(error)
            except Exception as e2:
                print(e2)

            return