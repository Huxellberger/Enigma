// Copyright (C) Threetee Gang, Jake Huxell 2016

/*********************************************************
The fundamental building block of Enigma that represents 
a thin or person in the world. Each has a state it exists in 
that defines its behaviour. Besides this an Entity also
currently has a unique Id it is identified by. 
**********************************************************/

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
	BaseEntity(const unsigned InId, std::shared_ptr<BaseState> InGlobalState);
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
	std::shared_ptr<BaseState> GlobalState;
	// Has to be raw pointer, shared tries to instantiate abstract class
	EventCommunicationInterface* EventInterface;
	unsigned Id;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
