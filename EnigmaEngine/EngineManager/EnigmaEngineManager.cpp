// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "pch.h"

#include "EngineManager/EnigmaEngineManager.h"
#include "BaseEntity/BaseEntityManager.h"

#include <memory>

//------------------------------------------------------------------

EnigmaEngineManager::EnigmaEngineManager()
	: EntityManager(nullptr)
{

}

//------------------------------------------------------------------

EnigmaEngineManager::~EnigmaEngineManager()
{
	EntityManager.reset();
}

//------------------------------------------------------------------

void EnigmaEngineManager::Initialise()
{
	EntityManager = std::make_unique<BaseEntityManager>();
}

//------------------------------------------------------------------

void EnigmaEngineManager::ShutDown()
{
	EntityManager.reset();
}

//------------------------------------------------------------------

void EnigmaEngineManager::Tick()
{
	EntityManager->Update();
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------