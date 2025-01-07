#include <iostream>
#include <list>
using namespace std;

template <typename T>
void printList(const list<T>& lst) {
    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << endl;
}

template <typename T>
list<T> strandSort(list<T> unsorted)
{
    if (unsorted.size() <= 1)
    {
        return unsorted;
    }
    list<T> sorted;
    list<T> sublist;

    int step = 1;

    while (!unsorted.empty())
    {
        sublist.push_back(unsorted.front());
        unsorted.pop_front();

        for (auto it = unsorted.begin(); it != unsorted.end();)
        {
            if (sublist.back() <= *it)
            {
                sublist.push_back(*it);
                it = unsorted.erase(it);
            }
            else
            {
                it++;
            }
        }
        cout << "Step " << step++ << ": ";
        printList(sublist);

        sorted.merge(sublist);
    }
    return sorted;
}

int main() {
    list<int> unsorted = { 52, 0, -7, 6, 1, 9, 4,-3 };

    cout << "Unsorted list: ";
    printList(unsorted);

    auto sorted = strandSort(unsorted);

    cout << "Sorted list: ";
    printList(sorted);

    return 0;
}
