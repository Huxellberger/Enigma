// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "BaseEntity/BaseEntityManager.h"

#include "BaseEntity/BaseEntity.h"

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
	Entities.insert_or_assign(NextAllocatedId, BaseEntity(NextAllocatedId));
	NextAllocatedId++;
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
