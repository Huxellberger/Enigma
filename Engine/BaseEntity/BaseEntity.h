// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

//------------------------------------------------------------------

class BaseEntity
{
public:

	BaseEntity() = delete;
	BaseEntity(const unsigned InId);
	~BaseEntity();
	BaseEntity(const BaseEntity& obj) = default;

	void Update();
private:

	unsigned Id;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
