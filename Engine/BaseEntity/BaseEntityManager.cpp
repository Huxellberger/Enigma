// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "Engine/BaseEntity/BaseEntityManager.h"

#include "Engine/BaseEntity/BaseEntity.h"

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