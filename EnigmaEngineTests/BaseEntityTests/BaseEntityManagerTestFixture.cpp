// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include "BaseEntityTests/BaseEntityManagerMock.h"

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
	};
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------