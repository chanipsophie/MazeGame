#include <iostream>

#include "Player.h"
#include "Key.h"
#include "PersistentKey.h"
#include "AudioManager.h"

using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0, 0)
	, m_pCurrentKey(nullptr)
	, m_pCurrentPKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasPKey()
{
	return m_pCurrentPKey != nullptr;
}

bool Player::HasKey(ActorColor color)
{
	return true;// HasKey() && m_pCurrentKey->GetColor() == color;
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::PickupPKey(PersistentKey* pkey)
{
	m_pCurrentPKey = pkey;
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::UsePKey()
{
	if (m_pCurrentPKey)
	{
		// Persistent Key will not be removed after each use.
		//m_pCurrentPKey->Remove();
		//m_pCurrentPKey = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::DropPKey()
{
	if (m_pCurrentPKey)
	{
		AudioManager::GetInstance()->PlayKeyDropSound();
		m_pCurrentPKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentPKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}
