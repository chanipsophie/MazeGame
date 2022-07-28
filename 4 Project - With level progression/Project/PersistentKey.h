#pragma once
#include "PlacableActor.h"
class PersistentKey : public PlacableActor
{
public:
	PersistentKey(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Key; }
	virtual void Draw() override;
};