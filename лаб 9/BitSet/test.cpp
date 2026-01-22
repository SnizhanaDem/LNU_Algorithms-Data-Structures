#include "pch.h"

TEST(CharSetTest, AddTest) {
    CharSet set;
    set.add('a');
    ASSERT_TRUE(set.test('a'));
}

TEST(CharSetTest, DeleteTest) {
    CharSet set("abc");
    set.deletee('a');
    ASSERT_FALSE(set.test('a'));
}

TEST(CharSetTest, TestTest) {
    CharSet set("abc");
    ASSERT_TRUE(set.test('a'));
    ASSERT_TRUE(set.test('b'));
    ASSERT_TRUE(set.test('c'));
    ASSERT_FALSE(set.test('d'));
}

TEST(CharSetTest, AssociationTest) {
    CharSet set1("abc");
    CharSet set2("bcd");
    CharSet association = set1.association(set2);
    ASSERT_TRUE(association.test('a'));
    ASSERT_TRUE(association.test('b'));
    ASSERT_TRUE(association.test('c'));
    ASSERT_TRUE(association.test('d'));
    ASSERT_FALSE(association.test('e'));
}

TEST(CharSetTest, IntersectionTest) {
    CharSet set1("abc");
    CharSet set2("bcd");
    CharSet intersection = set1.intersection(set2);
    ASSERT_TRUE(intersection.test('b'));
    ASSERT_FALSE(intersection.test('a'));
    ASSERT_TRUE(intersection.test('c'));
}

TEST(CharSetTest, DifferenceTest) {
    CharSet set1("abc");
    CharSet set2("bcd");
    CharSet difference = set1.difference(set2);
    ASSERT_TRUE(difference.test('a'));
    ASSERT_FALSE(difference.test('b'));
    ASSERT_FALSE(difference.test('c'));
}

TEST(CharSetTest, EqualityTest) {
    CharSet set1("abc");
    CharSet set2("abc");
    ASSERT_TRUE(set1 == set2);

    CharSet set3("bcd");
    ASSERT_FALSE(set1 == set3);
}

