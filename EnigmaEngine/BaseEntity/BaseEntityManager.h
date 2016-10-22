// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <unordered_map>

//------------------------------------------------------------------

class BaseEntity;

//------------------------------------------------------------------

class BaseEntityManager
{
public:

	BaseEntityManager();
	virtual ~BaseEntityManager();

	void Update();

	void AddNewEntity();
protected:

	std::unordered_map<unsigned, BaseEntity> Entities;
	static unsigned NextAllocatedId;
private:

	// Disable copy/move constructor
	BaseEntityManager(const BaseEntityManager& obj);
	BaseEntityManager(BaseEntityManager&&);
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
