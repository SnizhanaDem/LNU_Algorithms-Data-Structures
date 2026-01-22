//#include "pch.h"
//TEST(MarkovTest, FirstRuleSet) {
//    string rulesIn[] = { "|b","ab","b","*|","*","|c","ac","c" };
//    string rulesOut[] = { "ba|","ba","","b*","c","c","c|","." };
//    Markov m(rulesIn, rulesOut, 8);
//
//    EXPECT_EQ(m.process("|*||"), "||");
//    EXPECT_EQ(m.process("|||*|||"), "|||||||||");
//}
//
//TEST(MarkovTest, SecondRuleSet) {
//    string rulesIn[] = { "washington", "I", "T", "C", "USA", "." };
//    string rulesOut[] = { "Washington", "is", "the", "capital", "United States of America", "" };
//    Markov m(rulesIn, rulesOut, 6);
//
//    EXPECT_EQ(m.process("I am from washington."), "is am from Washington");
//    EXPECT_EQ(m.process("USA is a country."), "United States of America is a country");
//}
//
//TEST(MarkovTest, ThirdRuleSet) {
//    string rulesIn[] = { "1","|0","0" };
//    string rulesOut[] = { "0|", "0||", "" };
//    Markov m(rulesIn, rulesOut, 3);
//
//    EXPECT_EQ(m.process("111"), "|||||||");
//    EXPECT_EQ(m.process("110"), "||||||");
//}
//
//TEST(MarkovTest, AdditionalTest) {
//    string rulesIn[] = { "a", "c", "m" };
//    string rulesOut[] = { "b", "f", "n" };
//    Markov m(rulesIn, rulesOut, 3);
//
//    EXPECT_EQ(m.process("ma"), "nb");
//    EXPECT_EQ(m.process("cat"), "fbt");
//}
