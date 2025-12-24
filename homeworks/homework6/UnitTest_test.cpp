#include "pch.h"
#include "CppUnitTest.h"
#include "..\\UnitTest_code\\Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestotladka
{
    TEST_CLASS(UnitTestotladka)
    {
    public:
        // Нормальная работа ctg(pi/4*x)
        TEST_METHOD(TestMethod1)
        {
            double x = 1;
            double result = calculate_R(x);
            double expected = std::cos(3.1415 / 4.0 * x) /
                std::sin(3.1415 / 4.0 * x);
            Assert::AreEqual(expected, result);
        }
        // Ненормальная работа ctg(pi/4*x): ctgx неопределён
        TEST_METHOD(TestMethod2)
        {
            double x = 4;
            double result = calculate_R(x);
            double expected = std::cos(3.1415 / 4.0 * x) /
                std::sin(3.1415 / 4.0 * x);
            Assert::AreEqual(expected, result);
        }
        // Нормальная работа y^1/4 * 2^(1/y)
        TEST_METHOD(TestMethod3)
        {
            double y = 1;
            double result = calculate_S(y);
            double expected = sqrt(sqrt(y)) * pow(2, 1 / y);
            Assert::AreEqual(expected, result);
        }
        // Ненормальная работа y^1/4 * 2^(1/y): под корнем отриц значение
        TEST_METHOD(TestMethod4)
        {
            double y = -1;
            double result = calculate_S(y);
            double expected = sqrt(sqrt(y)) * pow(2, 1 / y);
            Assert::AreEqual(expected, result);
        }
        // Ненормальная работа y^1/4 * 2^(1/y): у = 0 - деление на ноль
        TEST_METHOD(TestMethod5)
        {
            double y = 0;
            double result = calculate_S(y);
            double expected = sqrt(sqrt(y)) * pow(2, 1 / y);
            Assert::AreEqual(expected, result);
        };
    };
};