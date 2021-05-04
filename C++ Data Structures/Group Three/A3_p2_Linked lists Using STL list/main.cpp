#include <iostream>
#include <list>
using namespace std;
void merge_sort_list(list<int>&list1, list<int>list2)
{
    list<int>::iterator list1_iterator = list1.begin(); // pointer of it list 1 indicate first element
    list<int>::iterator list2_iterator = list2.begin();  // pointer of it list 2 indicate first element

    while (list1_iterator != list1.end() && list2_iterator != list2.end())
    {
        if (*list1_iterator > *list2_iterator)  //check the element in the first  list less than in the next list {
        {
            list1.insert(list1_iterator, *list2_iterator);  // take position and value
            ++list2_iterator; //increment pointer of list 2
        }
        else if (*list1_iterator < *list2_iterator)
        {

            ++list1_iterator;
        }
    // take value without duplicate
        else
        {
            ++list1_iterator;
            ++list2_iterator;
        }
    }
    while (list2_iterator != list2.end())
    {
        list1.push_back(*list2_iterator); //put value in the second list in the list merged two list
        ++list2_iterator;
    }
}

int main()
{
    list<int> list1;

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(7);
    list1.sort();

    list<int> list2;
    list2.push_back(1);
    list2.push_back(3);
    list2.push_back(8);
    list2.push_back(2);
    list2.push_back(24);
    list2.sort();

    merge_sort_list(list1, list2);

    for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
