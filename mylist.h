#ifndef __MYLIST_H
#define __MYLIST_H
namespace easy_list
{
    template<typename type>
    struct datastruct
    {
        type data;
        datastruct * next;
    };
    template<typename type>
    struct list
    {
        int count;
        datastruct<type> * head;
        datastruct<type> * tail;
        list();
        list(type data);
        list(type * data,int len);
        datastruct<type> * find(type data);
        void add_back(type data);
        datastruct<type> * Insert(type data,type insertdata);
        void Merge_List(list Right_List);
        void add_back(type * arrdata,int len);
        int List_Delete(type data);
        datastruct<type> * Change(type finddata , type exdata);
        void Merge_arrange();
        datastruct<type> * Merge_arrange(datastruct<type> *PMerge);
        void test_print();
    };
}
#include "mylist.cpp"
//编译指令： g++ -g new.cpp mylist.h -o new.exe
//采取包含编译方式
#endif