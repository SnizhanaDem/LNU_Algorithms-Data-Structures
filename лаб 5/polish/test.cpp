#include "pch.h"

TEST(PriorityTest, OperatorPriority) {
    EXPECT_EQ(priority('+'), 1);
    EXPECT_EQ(priority('-'), 1);
    EXPECT_EQ(priority('*'), 2);
    EXPECT_EQ(priority('/'), 2);
    EXPECT_EQ(priority('^'), 3);
    EXPECT_EQ(priority('#'), 0);
    EXPECT_EQ(priority('('), 0);
    EXPECT_EQ(priority(')'), 0);
    EXPECT_EQ(priority('A'), -1); 
}

TEST(toInfixTest, ConvetrToInfix) {
    EXPECT_EQ(toInfix("23+5*"), "((2+3)*5)");
    EXPECT_EQ(toInfix("123++"), "(1+(2+3))");
}
TEST(IsDigitTest, CheckIfDigit) {
    EXPECT_TRUE(isDigital('0'));
    EXPECT_TRUE(isDigital('5'));
    EXPECT_TRUE(isDigital('9'));
    EXPECT_FALSE(isDigital('A'));
    EXPECT_FALSE(isDigital('*'));
    EXPECT_FALSE(isDigital('('));
}

TEST(IsOperandTest, CheckIfOperand) {
    EXPECT_TRUE(isOperand('+'));
    EXPECT_TRUE(isOperand('-'));
    EXPECT_TRUE(isOperand('*'));
    EXPECT_TRUE(isOperand('/'));
    EXPECT_TRUE(isOperand('^'));
    EXPECT_TRUE(isOperand('('));
    EXPECT_TRUE(isOperand(')'));
    EXPECT_FALSE(isOperand('A'));
    EXPECT_FALSE(isOperand('0'));
}

TEST(ApplyOperatorTest, OperatorApplication) {
    EXPECT_DOUBLE_EQ(applyOperator(3, 2, '+'), 5);
    EXPECT_DOUBLE_EQ(applyOperator(3, 2, '-'), 1);
    EXPECT_DOUBLE_EQ(applyOperator(3, 2, '*'), 6);
    EXPECT_DOUBLE_EQ(applyOperator(3, 2, '/'), 1.5);
    EXPECT_DOUBLE_EQ(applyOperator(3, 2, '^'), 9);
}

TEST(ToPostfixTest, ConvertToPostfix) {
    EXPECT_EQ(toPostfix("3+2*5"), "325*+");
    EXPECT_EQ(toPostfix("((3+2)*5)"), "32+5*");
    EXPECT_EQ(toPostfix("3^2*5"), "32^5*");
}

TEST(CalculateTest, EvaluatePostfix) {
    EXPECT_EQ(calculate("325*+"), 13);
    EXPECT_EQ(calculate("32+5*"), 25);
    EXPECT_EQ(calculate("32^5*"), 45);
}