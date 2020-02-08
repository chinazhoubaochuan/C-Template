#include "mylist.h"
#include <iostream>
using namespace easy_list;
int main()
{

    int arr1[] = {12,34,56,87};
    int arr2[] = {54,23,93,17};
    list<int> mylist1(arr1,sizeof(arr1)/sizeof(int));
    list<int> mylist2(arr2,sizeof(arr1)/sizeof(int));
    if(mylist1.find(12)) printf("12 has been find!");
    if(mylist1.find(13)) printf("13 has been find!");
    mylist1.Insert(34,78);
    mylist1.test_print();
    mylist1.Merge_List(mylist2);
    mylist1.Merge_arrange();
    mylist1.test_print();
    mylist1.add_back(103);
    mylist1.test_print();
    mylist1.Change(103,102);
    mylist1.test_print();
    mylist1.List_Delete(102);
    mylist1.List_Delete(56);
    mylist1.test_print();
    return 0;
}