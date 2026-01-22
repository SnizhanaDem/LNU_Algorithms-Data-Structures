#include "pch.h"

TEST(TableTest, InsertAndFind) {
    Table table;
    table.insert("key1", 10);
    table.insert("key2", 20);
    table.insert("key3", 30);

    EXPECT_EQ(table.find("key1"), 10);
    EXPECT_EQ(table.find("key2"), 20);
    EXPECT_EQ(table.find("key3"), 30);
}

TEST(TableTest, Replace) {
    Table table;
    table.insert("key1", 10);
    table.replace("key1", 20);

    EXPECT_EQ(table.find("key1"), 20);
}

TEST(TableTest, Erase) {
    Table table;
    table.insert("key1", 10);
    table.erase("key1");

    EXPECT_EQ(table.find("key1"), -1);
}

TEST(TableTest, Size) {
    Table table;
    table.insert("key1", 10);
    table.insert("key2", 20);
    table.insert("key3", 30);

    EXPECT_EQ(table.tableSize(), 3);

    table.erase("key2");
    EXPECT_EQ(table.tableSize(), 2);
}
TEST(TableTest, IsEmpty) {
    Table table;
    EXPECT_TRUE(table.isEmpty());

    table.insert("key1", 10);
    EXPECT_FALSE(table.isEmpty());

    table.erase("key1");
    EXPECT_TRUE(table.isEmpty());
}

TEST(TableTest, ClearTable) {
    Table table;
    table.insert("key1", 10);
    table.insert("key2", 20);

    EXPECT_FALSE(table.isEmpty());

    table.clearTable();
    EXPECT_TRUE(table.isEmpty());
    EXPECT_EQ(table.tableSize(), 0);
}