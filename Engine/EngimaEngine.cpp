// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "Engine/EngimaEngine.h"

#include "Engine/BaseEntity/BaseEntityManager.h"

#include <memory>

//------------------------------------------------------------------

EnigmaEngine::EnigmaEngine()
	: EntityManager(nullptr)
{

}

//------------------------------------------------------------------

EnigmaEngine::~EnigmaEngine()
{
	EntityManager.reset();
}

//------------------------------------------------------------------

void EnigmaEngine::Initialise()
{
	EntityManager = std::make_unique<BaseEntityManager>();
}

//------------------------------------------------------------------

void EnigmaEngine::ShutDown()
{

}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------