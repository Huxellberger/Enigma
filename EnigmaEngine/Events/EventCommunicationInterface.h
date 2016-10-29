// Copyright (C) Threetee Gang, Jake Huxell 2016

/*********************************************************
An interface used by the BaseEntityManager. This means
BaseEntities won't have explicit access to all the usual
public bits of a BaseEntityManager, but can still tell it
when they want to fire an event.
**********************************************************/

#pragma once

//------------------------------------------------------------------

class BaseState;

//------------------------------------------------------------------

class EventCommunicationInterface
{
public:

	virtual ~EventCommunicationInterface() {};

	// Derive meaning of message from state it was fired in. 
	virtual void FireEvent(unsigned SenderId, unsigned RecipientId, BaseState* SenderState) = 0;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
