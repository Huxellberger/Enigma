// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "BaseEntity/BaseEntityManager.h"

#include "BaseEntity/BaseEntity.h"

#include <vector>

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
		Entity.Update();
	}
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------