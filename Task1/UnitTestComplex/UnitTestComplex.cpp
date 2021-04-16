#include "../Complex/complex_number.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestComplex
{
	TEST_CLASS(UnitTestComplex)
	{
	public:

		TEST_METHOD(create_get_conjugate_fail)
		{
            //Arrange
            const auto expected = complex_number(5, -23);
            const auto existing = complex_number(5, 23);

            //Act
            const auto actual = existing.get_conjugate();

            //Assert
            Assert::AreEqual(expected, actual);
		}
	};
}
