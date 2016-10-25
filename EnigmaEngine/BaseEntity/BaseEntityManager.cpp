// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "BaseEntity/BaseEntityManager.h"

#include "BaseEntity/BaseEntity.h"
#include "BaseState/BaseState.h"

#include <unordered_map>

//------------------------------------------------------------------

unsigned BaseEntityManager::NextAllocatedId = 0;

//------------------------------------------------------------------

BaseEntityManager::BaseEntityManager()
	:Entities()
{

}

//------------------------------------------------------------------

BaseEntityManager::~BaseEntityManager()
{
	Entities.clear();
}

//------------------------------------------------------------------

void BaseEntityManager::Update()
{
	for (auto& Entity : Entities)
	{
		Entity.second.Update();
	}
}

//------------------------------------------------------------------

void BaseEntityManager::AddNewEntity()
{
	BaseEntity NewEntity = BaseEntity(NextAllocatedId);
	NewEntity.Init(this);
	Entities.insert_or_assign(NextAllocatedId, NewEntity);
	NextAllocatedId++;
}

//------------------------------------------------------------------

void BaseEntityManager::FireEvent(unsigned SenderId, unsigned RecipientId, BaseState* SenderState)
{
	std::unordered_map<unsigned, BaseEntity>::iterator Entity = Entities.find(SenderId);
	Entity->second.GetCurrentState()->OnEventRecieved(&Entity->second, SenderState);
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
