#pragma once

#ifdef GAMELIFT_NET_EXPORTS
#define GLAPI __declspec( dllexport )
#else
#define GLAPI __declspec( dllimport )
#endif

extern "C" {
	struct PlayerSession {

	};
	struct GameSession {

	};

	GLAPI bool GL_Initialize(
		int listenPort,
		void (*onStartGameSession)(GameSession *),
		void (*onProcesTerminate)(),
		bool (*onHealthCheck)());
	GLAPI void GL_ProcessEnding();
	GLAPI void GL_Destroy();

	GLAPI void GL_ActivateGameSession();
	GLAPI void GL_TerminateGameSession();

	GLAPI bool GL_AcceptPlayerSession(const char *playerSessionId);
	GLAPI bool GL_RemovePlayerSession(const char *playerSessionId);
}