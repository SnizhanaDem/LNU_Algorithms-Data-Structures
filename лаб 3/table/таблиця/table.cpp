//
// table.cpp
//
#include "pch.h"

Table::Table() {}


void Table::insert(const string& key, int value) {
    for (const auto& pair : pairs) {
        if (pair.key == key) {
            cout << "Key \"" << key << "\" already exists. Cannot insert." << endl;
            return;
        }
    }

    Pair pair{ key, value };
    pairs.push_back(pair);
}

void Table::replace(const string& key, int newValue) {
    for (auto& pair : pairs) {
        if (pair.key == key) {
            pair.value = newValue;
            return;
        }
    }
}

void Table::erase(const string& key) {
    for (auto it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->key == key) {
            pairs.erase(it);
            return;
        }
    }
}

int Table::find(const std::string& key) const {
    for (const auto& pair : pairs) {
        if (pair.key == key) {
            return pair.value;
        }
    }
    return -1; // if key not found
}

void Table::print() const {
    if (isEmpty()) {
        cout << "Table is empty." << endl;
    }
    else {
        for (const auto& pair : pairs) {
            cout << "Key: " << pair.key << " |, Value: " << pair.value << endl;
            cout << "---------------------------\n";
        }
    }
}

void Table::clearTable() {
    pairs.clear();
}


size_t Table::tableSize() const {
    return pairs.size();
}

bool Table::isEmpty() const {
    return pairs.empty();
}

int main(int argc, char** argv) {
    Table table;

    table.insert("key1", 10);
    table.insert("key2", 20);
    table.insert("key3", 30);

    cout << "Value for key1: " << table.find("key1") << '\n';
    cout << "Value for key2: " << table.find("key2") << '\n';
    cout << "Value for key3: " << table.find("key3") << '\n';
    cout << "Size of table: " << table.tableSize() << '\n';
    cout << '\n';

    table.replace("key1", 100);
    cout << "The value of key1 is replaced. The value of key1 after change: " << table.find("key1") << '\n';
    cout << "---------------------------\n";
    table.print();
    cout << "Size of table: " << table.tableSize() << '\n';
    cout << '\n';

    table.erase("key2");
    cout << "Deleted the value for key2. Table after erasure:\n";
    cout << "---------------------------\n";
    table.print();
    table.insert("key1", 80);
    cout << "Size of table: " << table.tableSize() << '\n';
    cout << '\n';

    table.insert("key5", 80);
    cout << "Added a new key.The final content of table:" << '\n';
    cout << "---------------------------\n";
    table.print();
    cout << "Size of table: " << table.tableSize() << '\n';
    
    table.clearTable();
    cout << "Table after cleaning:\n";
    table.print();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
 
}
