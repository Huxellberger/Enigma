// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include <Engine/BaseEntity/BaseEntity.h>
#include <memory>

//------------------------------------------------------------------

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//------------------------------------------------------------------

namespace BaseEntityTestFixture
{
	TEST_CLASS(BaseEntityTestFixture)
	{
	public:

		TEST_METHOD(GivenBaseEntity_WhenInitialised_SuccessfullyTakesIdValue)
		{
			unsigned Id = 2;
			std::unique_ptr<BaseEntity>	TestEntity;
			TestEntity = std::make_unique<BaseEntity>(Id);

			Assert::AreEqual(Id, TestEntity->GetId());

			TestEntity.reset();
		}
	};
}

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------