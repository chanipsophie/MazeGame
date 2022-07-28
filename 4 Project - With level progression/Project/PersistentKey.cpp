#include <iostream>
#include <windows.h>

#include "PersistentKey.h"

void PersistentKey::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "KEY";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
