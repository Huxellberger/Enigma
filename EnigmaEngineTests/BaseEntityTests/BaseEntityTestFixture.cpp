// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include <../EnigmaEngine/BaseEntity/BaseEntity.h>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

	};
}