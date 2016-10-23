// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include "StateTests/BaseStateMock.h"

#include <../EnigmaEngine/BaseEntity/BaseEntity.h>

#include <functional>
#include <memory>

//------------------------------------------------------------------

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//------------------------------------------------------------------

namespace BaseEntityTestFixture
{
	TEST_CLASS(BaseEntityTestFixture)
	{
	public:

		TEST_METHOD(GivenBaseEntity_WhenInitialised_TakesIdValue)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity; 
			TestEntity = new BaseEntity(TestId);

			Assert::AreEqual(TestId, TestEntity->GetId());

			delete TestEntity;
		}

		TEST_METHOD(GivenBaseEntity_WhenChangedToNullState_ExceptionOccurs)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity;
			TestEntity = new BaseEntity(TestId);

			std::function<void()> TestFunction = [TestEntity]() { TestEntity->ChangeState(nullptr); };
			Assert::ExpectException<std::invalid_argument>(TestFunction);

			delete TestEntity;
		}

		TEST_METHOD(GivenBaseEntity_WhenChangedToState_OnEnterCalled)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity;
			TestEntity = new BaseEntity(TestId);
			std::shared_ptr<BaseStateMock> StateMock = std::make_shared<BaseStateMock>();

			TestEntity->ChangeState(StateMock);
			Assert::AreEqual(1, StateMock->GetOnEnterCalls());
			Assert::AreEqual(0, StateMock->GetOnUpdateCalls());
			Assert::AreEqual(0, StateMock->GetOnExitCalls());

			StateMock.reset();
			delete TestEntity;
		}

		TEST_METHOD(GivenBaseEntity_WhenUpdated_OnUpdateCalled)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity;
			TestEntity = new BaseEntity(TestId);
			std::shared_ptr<BaseStateMock> StateMock = std::make_shared<BaseStateMock>();

			TestEntity->ChangeState(StateMock);
			Assert::AreEqual(0, StateMock->GetOnUpdateCalls());

			TestEntity->Update();
			Assert::AreEqual(1, StateMock->GetOnUpdateCalls());

			StateMock.reset();
			delete TestEntity;
		}

		TEST_METHOD(GivenBaseEntity_WhenStateRemoved_OnExitCalled)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity;
			TestEntity = new BaseEntity(TestId);
			std::shared_ptr<BaseStateMock> StateMock = std::make_shared<BaseStateMock>();
			std::shared_ptr<BaseStateMock> SecondState = std::make_shared<BaseStateMock>();

			TestEntity->ChangeState(StateMock);
			Assert::AreEqual(0, StateMock->GetOnExitCalls());

			TestEntity->ChangeState(SecondState);
			Assert::AreEqual(1, StateMock->GetOnExitCalls());

			SecondState.reset();
			StateMock.reset();
			delete TestEntity;
		}

	};
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------