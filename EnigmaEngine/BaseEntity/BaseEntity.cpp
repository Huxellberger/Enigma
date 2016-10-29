// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "BaseEntity/BaseEntity.h"
#include "BaseState/BaseState.h"
#include "Events/EventCommunicationInterface.h"

#include <iostream>
#include <memory>

//------------------------------------------------------------------

BaseEntity::BaseEntity(const unsigned InId)
	: CurrentState(nullptr)
	, GlobalState(nullptr)
	, Id(InId)
{

}

//------------------------------------------------------------------

BaseEntity::BaseEntity(const unsigned InId, std::shared_ptr<BaseState> InGlobalState)
	: CurrentState(nullptr)
	, GlobalState(InGlobalState)
	, Id(InId)
{

}

//------------------------------------------------------------------

BaseEntity::~BaseEntity()
{
	if (CurrentState)
	{
		CurrentState.reset();
	}

	if (GlobalState)
	{
		GlobalState.reset();
	}
}

//------------------------------------------------------------------

void BaseEntity::Init(EventCommunicationInterface* InEventCommunicationInterface)
{
	EventInterface = InEventCommunicationInterface;
}

//------------------------------------------------------------------

void BaseEntity::Update()
{
	// Not all entities have to keep a global state.
	if (GlobalState)
	{
		GlobalState->OnUpdate(this);
	}
	
	CurrentState->OnUpdate(this);
}

//------------------------------------------------------------------

void BaseEntity::ChangeState(std::shared_ptr<BaseState> NewState)
{
	if (CurrentState)
	{
		CurrentState->OnExit(this);
	}
	CurrentState = NewState;

	if (CurrentState)
	{
		CurrentState->OnEnter(this);
	}
	else
	{
		throw std::invalid_argument("Cannot have a nullptr state.");
	}
}

//------------------------------------------------------------------

std::shared_ptr<BaseState> BaseEntity::GetCurrentState() const
{
	return CurrentState;
}

//------------------------------------------------------------------

EventCommunicationInterface* BaseEntity::GetEventCommunicationInterface() const
{
	return EventInterface;
}

//------------------------------------------------------------------

unsigned BaseEntity::GetId() const
{
	return Id;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
