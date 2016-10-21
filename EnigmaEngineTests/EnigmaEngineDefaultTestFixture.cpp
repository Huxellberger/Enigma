// Copyright (C) Threetee Gang, Jake Huxell 2016

#include "stdafx.h"
#include "CppUnitTest.h"

#include <../EnigmaEngine/BaseEntity/BaseEntity.h>
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EnigmaEngineDefaultTestFixture
{		
	TEST_CLASS(EnigmaEngineDefaultTestFixture)
	{
	public:
		
		TEST_METHOD(EnigmaEngineDefaultTestFixtureMethod)
		{
			unsigned TestId = 2;
			BaseEntity* TestEntity;
			TestEntity = new BaseEntity(TestId);

			Assert::AreEqual(TestId, TestEntity->GetId());

			delete TestEntity;
		}

	};
}