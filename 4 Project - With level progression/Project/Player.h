#pragma once
#include "PlacableActor.h"

class Key;
class PersistentKey;

class Player : public PlacableActor
{
public:
	Player();

	bool HasKey();
	bool HasPKey();
	bool HasKey(ActorColor color);
	void PickupKey(Key* key);
	void PickupPKey(PersistentKey* pkey);
	void UseKey();
	void UsePKey();
	void DropKey();
	void DropPKey();
	Key* GetKey() { return m_pCurrentKey; }
	PersistentKey* GetPKey() { return m_pCurrentPKey; }

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	int GetLives() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual ActorType GetType() override { return ActorType::Player; }
	virtual void Draw() override;
private:
	Key* m_pCurrentKey;
	PersistentKey* m_pCurrentPKey;
	int m_money;
	int m_lives;
};
