// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include "stdafx.h"

#include <../EnigmaEngine/BaseEntity/BaseEntity.h>
#include <../EnigmaEngine/BaseEntity/BaseEntityManager.h>

#include <unordered_map>

//------------------------------------------------------------------

class BaseEntityManagerMock
	: public BaseEntityManager
{
public:
	
	BaseEntityManagerMock()
		: BaseEntityManager()
	{
	}

	~BaseEntityManagerMock(){}

	bool IsIdRegistered(unsigned ChosenId)
	{
		if (Entities.count(ChosenId) == 1)
		{
			return true;
		}
		return false;
	}

	unsigned GetNextAllocatedId() const
	{
		return NextAllocatedId;
	}

	BaseEntity* GetBaseEntity(unsigned IdNumber)
	{
		std::unordered_map<unsigned, BaseEntity>::iterator Entity = Entities.find(IdNumber);
		return &Entity->second;
	}

private:

	// Disable copy/move constructor
	BaseEntityManagerMock(const BaseEntityManager& obj);
	BaseEntityManagerMock(BaseEntityManager&&);
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
