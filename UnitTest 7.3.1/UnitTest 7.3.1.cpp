#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3.1/Lab 7.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:

        TEST_METHOD(TestFindSameRowAndColumn)
        {
            int matrix[3][3] = { { 1, 2, 3 },
                                { 2, 5, 6 },
                                { 3, 6, 9 } };
            int* matrixPtr[3];
            for (int i = 0; i < 3; ++i) {
                matrixPtr[i] = matrix[i];
            }

            std::stringstream capturedOutput;
            std::streambuf* originalOutput = std::cout.rdbuf(capturedOutput.rdbuf());

            FindSameRowAndColumn(matrixPtr, 3);

            std::string output = capturedOutput.str();

            std::string expectedOutput = "Rows and columns that are the same:\nRow 0 and Column 0\nRow 1 and Column 1\nRow 2 and Column 2\n";

            Assert::AreEqual(output, expectedOutput);
            std::cout.rdbuf(originalOutput);
        }

        TEST_METHOD(TestSumRowsWithNegativeElements)
        {
            int matrix[3][3] = { { -2, -1, 2 },
                                { -3, 1, -4 },
                                { 1, 2, 3 } };
            int* matrixPtr[3];
            for (int i = 0; i < 3; ++i) {
                matrixPtr[i] = matrix[i];
            }

            int result = SumRowsWithNegativeElements(matrixPtr, 3);
            int expected = -7;

            Assert::AreEqual(result, expected);
        }
    };
}
