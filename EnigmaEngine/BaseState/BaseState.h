// Copyright (C) Threetee Gang, Jake Huxell 2016

/*********************************************************
Represents the behaviour of a BaseEntity in the game. A
BaseEntity can be in one state at a time (ignoring the global
state). A state is what responds to events recieved by the 
BaseEntityManager as they represent how the Entity should
react in a given scenario. 

Only one copy of a state needs to exist for all entities (static). 
**********************************************************/

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

	virtual void OnEventRecieved(BaseEntity* RecipientEntity, BaseState* SenderState) = 0;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
