// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

//------------------------------------------------------------------

class BaseEntity;

//------------------------------------------------------------------

class BaseState
{
public:

	virtual void OnEnter(BaseEntity* Entity) = 0;
	virtual void OnUpdate(BaseEntity* Entity) = 0;
	virtual void OnExit(BaseEntity* Entity) = 0;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
