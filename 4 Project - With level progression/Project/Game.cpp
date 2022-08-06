#include "Game.h"
#include <thread>

Game::Game()
	: m_pStateMachine(nullptr)
{

}

void Game::Initialize(GameStateMachine* pStateMachine)
{
	if (pStateMachine != nullptr)
	{
		pStateMachine->Init();
		m_pStateMachine = pStateMachine;
	}
}

void Game::RunGameLoop()
{
	isGameOver = false;

	// create the input thread
	std::thread InputThread(&Game::InputThread, this);

	while (!isGameOver)
	{
		// update with no input
		Update(false);
		// Draw
		Draw();

		// slow down the update, too flickery
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	// game ending, cancel the thread
	InputThread.join();

	Draw();
}

void Game::InputThread()
{
	while (!isGameOver)
	{
		// Update with input
		isGameOver = Update();
	}
}

void Game::Deinitialize()
{
	if (m_pStateMachine != nullptr)
		m_pStateMachine->Cleanup();
}

bool Game::Update(bool processInput)
{
	return m_pStateMachine->UpdateCurrentState(processInput);
}

void Game::Draw()
{
	m_pStateMachine->DrawCurrentState();
}
