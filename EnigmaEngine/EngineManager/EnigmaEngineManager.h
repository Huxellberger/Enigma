// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <memory>

//------------------------------------------------------------------

class BaseEntityManager;

//------------------------------------------------------------------

class EnigmaEngineManager
{
public:

	EnigmaEngineManager();
	~EnigmaEngineManager();

	void Initialise();
	void Tick();
	void ShutDown();
private:

	// Disable copy/move constructor
	EnigmaEngineManager(const EnigmaEngineManager& obj);
	EnigmaEngineManager(EnigmaEngineManager&&);

	std::unique_ptr<BaseEntityManager> EntityManager;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------