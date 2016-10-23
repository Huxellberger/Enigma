// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <memory>

//------------------------------------------------------------------

class BaseState;

//------------------------------------------------------------------

class BaseEntity
{
public:

	BaseEntity() = delete;
	BaseEntity(const unsigned InId);
	~BaseEntity();
	BaseEntity(const BaseEntity& obj) = default;

	void Update();
	void ChangeState(std::shared_ptr<BaseState> NewState);

	unsigned GetId() const;
private:

	std::shared_ptr<BaseState> CurrentState;
	unsigned Id;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
