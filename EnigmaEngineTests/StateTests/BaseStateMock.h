// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include "stdafx.h"

#include <../EnigmaEngine/BaseEntity/BaseEntity.h>
#include <../EnigmaEngine/BaseState/BaseState.h>

//------------------------------------------------------------------

class BaseStateMock
	: public BaseState
{
public:

	BaseStateMock()
		: BaseState()
		, OnEnterCalls(0)
		, OnUpdateCalls(0)
		, OnExitCalls(0)
		, OnEventRecievedCalls(0)
		, LastRecievedEntityId(97)
	{

	}

	virtual void OnEnter(BaseEntity* Entity) override
	{
		OnEnterCalls++;
	}

	virtual void OnUpdate(BaseEntity* Entity) override
	{
		OnUpdateCalls++;
	}

	virtual void OnExit(BaseEntity* Entity) override
	{
		OnExitCalls++;
	}

	virtual void OnEventRecieved(BaseEntity* RecipientEntity, BaseState* SenderState) override
	{
		OnEventRecievedCalls++;

		LastRecievedEntityId = RecipientEntity->GetId();
	}

	int GetOnEnterCalls() const
	{
		return OnEnterCalls;
	}

	int GetOnUpdateCalls() const
	{
		return OnUpdateCalls;
	}

	int GetOnExitCalls() const
	{
		return OnExitCalls;
	}

	int GetOnEventRecievedCalls() const
	{
		return OnEventRecievedCalls;
	}

	unsigned GetLastRecievedEntityId() const
	{
		return LastRecievedEntityId;
	}

private:

	int OnEnterCalls;
	int OnUpdateCalls;
	int OnExitCalls;
	int OnEventRecievedCalls;

	unsigned LastRecievedEntityId;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
