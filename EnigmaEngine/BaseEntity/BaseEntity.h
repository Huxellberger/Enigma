// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <memory>

//------------------------------------------------------------------

class BaseState;
class EventCommunicationInterface;

//------------------------------------------------------------------

class BaseEntity
{
public:

	BaseEntity() = delete;
	BaseEntity(const unsigned InId);
	~BaseEntity();
	BaseEntity(const BaseEntity& obj) = default;

	void Init(EventCommunicationInterface* InEventCommunicationInterface);
	void Update();
	void ChangeState(std::shared_ptr<BaseState> NewState);

	std::shared_ptr<BaseState> GetCurrentState() const;
	EventCommunicationInterface* GetEventCommunicationInterface() const;

	unsigned GetId() const;
private:

	std::shared_ptr<BaseState> CurrentState;
	// Has to be raw pointer, shared tries to instantiate abstract class
	EventCommunicationInterface* EventInterface;
	unsigned Id;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
