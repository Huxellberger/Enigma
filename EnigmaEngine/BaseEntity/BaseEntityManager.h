// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include "Events/EventCommunicationInterface.h"

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
