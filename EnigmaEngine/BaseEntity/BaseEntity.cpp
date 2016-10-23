// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "BaseEntity/BaseEntity.h"
#include "BaseState/BaseState.h"

#include <iostream>
#include <memory>

//------------------------------------------------------------------

BaseEntity::BaseEntity(const unsigned InId)
	: CurrentState(nullptr)
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
}

//------------------------------------------------------------------

void BaseEntity::Update()
{
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

unsigned BaseEntity::GetId() const
{
	return Id;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
