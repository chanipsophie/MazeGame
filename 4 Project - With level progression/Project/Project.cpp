#include <iostream>
#include "Game.h"
#include "AudioManager.h"
#include "StateMachineExampleGame.h"
#include <thread>

using namespace std;

int main()
{
	Game myGame;

	StateMachineExampleGame gameStateMachine(&myGame);

	myGame.Initialize(&gameStateMachine);

	myGame.RunGameLoop();

	myGame.Deinitialize();

	thread DestroyInstance(AudioManager::DestroyInstance);

	DestroyInstance.join();

	return 0;
}