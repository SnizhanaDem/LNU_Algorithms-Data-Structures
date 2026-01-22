//
// pch.cpp
//

#include "pch.h"

CharSet::CharSet(string s) {
    for (char t : s) {
        add(t);
    }
}

CharSet::~CharSet() {}

void CharSet::add(char a) {
    sets[a - 'a'] = sets[a - 'a'] | (1 << (a - 'a'));
}

void CharSet::deletee(char a) {
    sets[a - 'a'] = sets[a - 'a'] & (~(1 << (a - 'a')));
}

bool CharSet::test(char a) {
    return ((sets[a - 'a'] >> (a - 'a')) & 1) != 0;
}

CharSet CharSet::association(CharSet& set) {
    CharSet result;
    for (size_t i = 0; i < 26; i++) {
        result.sets[i] = this->sets[i] | set.sets[i];
    }
    return result;
}

CharSet CharSet::intersection(CharSet& set) {
    CharSet result;
    for (size_t i = 0; i < 26; i++) {
        result.sets[i] = this->sets[i] & set.sets[i];
    }
    return result;
}

CharSet CharSet::difference(CharSet& set) {
    CharSet result;
    for (size_t i = 0; i < 26; i++) {
        result.sets[i] = this->sets[i] & (~set.sets[i]);
    }
    return result;
}

bool operator==(CharSet& t1, CharSet& t2) {
    bool result = true;
    for (size_t i = 0; i < 26; i++) {
        if (t1.sets[i] != t2.sets[i]) result = false;
    }
    return result;
}
bool CharSet::isEmpty() const {
    for (int i = 0; i < 26; ++i) {
        if (sets[i] != 0) {
            return false; 
        }
    }
    return true;
}

void CharSet::print() {
    cout << "{ ";
    for (size_t i = 0; i < 26; i++) {
        if (((sets[i] >> i) & 1) != 0) {
            cout << (char)('a' + i) << " ";
        }
    }
    cout << "} {";
    for (int i = 25; i >= 0; --i) {
        cout << ((sets[i] >> i) & 1);
    }
    cout << "}";
}

int main(int argc, char** argv) {
    CharSet s1;
    CharSet s2("xyz");

    cout << "s1: ";
    s1.print();
    cout << endl;

    cout << "s2: ";
    s2.print();
    cout << endl;

    cout << "Is 's' in s1? " << (s1.test('s') ? "Yes" : "No") << endl;
    cout << "Is 'z' in s1? " << (s1.test('z') ? "Yes" : "No") << endl;

    // Add 's' and 'n' to s1
    s1.add('s');
    cout << "Added 's' to s1" << endl;
    s1.add('n');
    cout << "Added 'n' to s1" << endl;
    cout << "Is 's' in s1? " << (s1.test('s') ? "Yes" : "No") << endl;

    // Delete 'c' from s1
    s1.deletee('c');
    cout << "Deleted 'c' from s1" << endl;

    cout << "Updated s1: ";
    s1.print();
    cout << endl;

    CharSet sUnion = s1.association(s2);
    CharSet sIntersection = s1.intersection(s2);
    CharSet sDifference = s1.difference(s2);

    cout << "Union of s1 and s2: ";
    sUnion.print();
    cout << endl;

    cout << "Intersection of s1 and s2: ";
    sIntersection.print();
    cout << endl;

    cout << "Difference of s1 and s2: ";
    sDifference.print();
    cout << endl;

    if (s1.isEmpty()) {
        cout << "Set s1 is empty." << endl;
    }
    else {
        cout << "Set s1 is not empty." << endl;
    }
    cout << "Deleting s and n from s1\n";
    s1.deletee('s');
    s1.deletee('n');
    if (s1.isEmpty()) {
        cout << "Set s1 is empty." << endl;
    }
    else {
        cout << "Set s1 is not empty." << endl;
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

