// Copyright (C) Threetee Gang, Jake Huxell 2016

/*********************************************************
A Class to handle the updating of all base entities within
a game. Also provides the message bus for all BaseEntities 
to communicate with each other
**********************************************************/

#pragma once

#include "../Events/EventCommunicationInterface.h"

#include <unordered_map>

//------------------------------------------------------------------

class BaseEntity;
class BaseState;

//------------------------------------------------------------------

class BaseEntityManager
	: public EventCommunicationInterface
{
public:

	BaseEntityManager();
	virtual ~BaseEntityManager();

	void Update();

	void AddNewEntity();

	// EventCommunicationInterface
	virtual void FireEvent(unsigned SenderId, unsigned RecipientId, BaseState* SenderState) override;
	// ~EventCommunicationInterface
protected:

	std::unordered_map<unsigned, BaseEntity> Entities;
	static unsigned NextAllocatedId;
private:

	// Disable copy/move constructor
	BaseEntityManager(const BaseEntityManager& obj);
	BaseEntityManager(BaseEntityManager&&);
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
