// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <vector>

//------------------------------------------------------------------

class BaseEntity;

//------------------------------------------------------------------

class BaseEntityManager
{
public:

	BaseEntityManager();
	~BaseEntityManager();

	void Update();
private:

	// Disable copy/move constructor
	BaseEntityManager(const BaseEntityManager& obj);
	BaseEntityManager(BaseEntityManager&&);

	std::vector<BaseEntity> Entities;

	static unsigned NextAllocatedId;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
