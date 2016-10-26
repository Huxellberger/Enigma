// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include "BaseEntityTests/BaseEntityManagerMock.h"
#include "StateTests/BaseStateMock.h"

#include <memory>

//------------------------------------------------------------------

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//------------------------------------------------------------------

namespace BaseEntityManagerTestFixture
{
	TEST_CLASS(BaseEntityManagerTestFixture)
	{
	public:

		TEST_METHOD(GivenBaseEntityManager_WhenEntityCreated_IDsIncremented)
		{
			BaseEntityManagerMock* EntityManager = new BaseEntityManagerMock();
			unsigned StartingId = EntityManager->GetNextAllocatedId();
			EntityManager->AddNewEntity();
			Assert::AreEqual(StartingId + 1, EntityManager->GetNextAllocatedId());
			delete EntityManager;
		}

		TEST_METHOD(GivenBaseEntityManager_WhenEntityCreated_InsertedById)
		{
			BaseEntityManagerMock* EntityManager = new BaseEntityManagerMock();
			unsigned StartingId = EntityManager->GetNextAllocatedId();
			EntityManager->AddNewEntity();
			Assert::IsTrue(EntityManager->IsIdRegistered(StartingId));
			delete EntityManager;
		}

		TEST_METHOD(GivenBaseEntityManager_WhenEventFired_SentToEntity)
		{
			BaseEntityManagerMock* EntityManager = new BaseEntityManagerMock();
			BaseStateMock* TestState = new BaseStateMock();
			std::shared_ptr<BaseStateMock> ChosenState = std::make_shared<BaseStateMock>();
			unsigned StartingId = EntityManager->GetNextAllocatedId();
			EntityManager->AddNewEntity();
			EntityManager->GetBaseEntity(StartingId)->ChangeState(ChosenState);
			EntityManager->FireEvent(StartingId, StartingId, TestState);

			Assert::AreEqual(1, ChosenState->GetOnEventRecievedCalls());
			Assert::AreEqual(StartingId, ChosenState->GetLastRecievedEntityId());
			delete EntityManager;
		}
	};
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------