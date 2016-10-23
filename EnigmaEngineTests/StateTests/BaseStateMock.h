// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include "stdafx.h"

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

private:

	int OnEnterCalls;
	int OnUpdateCalls;
	int OnExitCalls;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
