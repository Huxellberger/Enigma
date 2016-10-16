// Copyright (C) Threetee Gang, Jake Huxell 2016

#pragma once

#include <memory>

//------------------------------------------------------------------

class BaseEntityManager;

//------------------------------------------------------------------

class EnigmaEngine
{
public:

	EnigmaEngine();
	~EnigmaEngine();

	void Initialise();
	void ShutDown();
private:

	// Disable copy/move constructor
	EnigmaEngine(const EnigmaEngine& obj);
	EnigmaEngine(EnigmaEngine&&);

	std::unique_ptr<BaseEntityManager> EntityManager;
};

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------