// Copyright (C) Threetee Gang, Jake Huxell 2016

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
