#include "mylist.h"
#include <iostream>
using namespace easy_list;
template <typename type>
list<type>::list()
{
    head ->next = NULL;
    tail = head;
    count = 0;
}
template <typename type>
list<type>::list(type data)
{
    head = new datastruct<type>;
    head ->data = data;
    head ->next = tail;
    tail->next = NULL;
}
template <typename type>
list<type>::list(type * data,int len)
{
    count = len;
    if ( data != NULL )
    {//这里用list(*data) 就跳过去了
        head = new datastruct<type>;
        head ->data = *data;
        head ->next = NULL;
        tail = head;
    }
    else return;
    for( ; len>1; len--)
    {
        data++;
        tail->next = new datastruct<type>;
        tail = tail->next;
        tail->data = *data;
    }
    tail ->next = NULL;
}

template <typename type>
datastruct<type> * list<type>::find(type data)
{
    datastruct<type> * pdata = head;
    while (pdata->next != NULL)
    {
        if (pdata->data == data)   return pdata;
        pdata++;//少写了这一句
    }
    return NULL;
}

template <typename type>
void list<type>::add_back(type data)
{
    tail ->next = new datastruct<type>;
    tail = tail ->next;
    tail ->data = data;
    tail ->next = NULL;
}

template <typename type>
datastruct<type> *list<type>::Insert(type data,type insertdata)
{
    if (head == NULL) return NULL;
        datastruct<type> * pdatafrist = head;
        datastruct<type> * pdatabehind;
        datastruct<type> * pdatainsert;
        if (pdatafrist->data == data) return pdatafrist;
        while ( pdatafrist->next != NULL)
        {
            if(pdatafrist->next->data == data) 
            {
                pdatainsert = new datastruct<type>;
                pdatabehind = pdatafrist -> next;
                pdatafrist ->next = pdatainsert;
                pdatainsert ->next = pdatabehind;
                pdatainsert ->data = data;
                return pdatainsert;
            }
        }
    return NULL;
}

template <typename type>
void list<type>::Merge_List(list Right_List)
{
    tail->next = Right_List.head;
    tail = Right_List.tail;
}

template <typename type>
void list<type>::add_back(type * arrdata,int len)
{
    for( int i=0; i<len ; i++ )
    {
        tail = new datastruct<type>;
        tail -> data = arrdata++;
        tail = tail -> next;
    }
}

template <typename type>
int list<type>::List_Delete(type data)
{
    datastruct<type> * pdatafrist = head;
    datastruct<type> * pdatabehind;
    datastruct<type> * pdatadelete;
    if (head == NULL) return 0;
    if (pdatafrist->data == data) return 1;
    while ( pdatafrist->next != NULL)
    {
        if(pdatafrist->next->data == data) 
        {
            pdatadelete = pdatafrist -> next;
            //如果删除的是最后一个元素，那就必须要重设置尾指针
            if(pdatadelete ->next == NULL) 
            {
                tail = pdatafrist;
                tail ->next = NULL;
                delete pdatadelete;
                return 1;
            }
            pdatabehind = pdatadelete -> next;
            pdatafrist -> next = pdatabehind;
            delete pdatadelete;
            return 1;
        }
        pdatafrist = pdatafrist -> next;
    }
    return 0;
}

template <typename type>
datastruct<type> * list<type>::Change(type finddata , type exdata)
{
    datastruct<type> *Pfinddata = head;
    while (Pfinddata != NULL)
        {
            if(Pfinddata ->data == finddata) 
            {
                Pfinddata -> data = exdata;
                return Pfinddata;
            }
            Pfinddata = Pfinddata ->next;
        }
        return NULL;
}

template <typename type>
void list<type>::Merge_arrange()
{
    //1.结束条件
    //2.分治方法
    //3.合并规则
    //对于两个序列，采取不同的规则
    head = Merge_arrange(head);
    tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
}

template <typename type>
datastruct<type> * list<type>::Merge_arrange(datastruct<type> *PMerge)
{
    if(PMerge->next == NULL)
                return PMerge;
            else
            {
                //fast slow functions way :
                datastruct<type> *Pfast = PMerge;
                datastruct<type> *Pslow = PMerge;
                while ( Pfast->next != NULL)
                {
                    Pfast = Pfast->next;
                    if(Pfast->next == NULL) break;
                    Pfast = Pfast->next;
                    Pslow = Pslow->next;
                }
                Pfast = Pslow->next;
                Pslow->next=NULL;//断表
                datastruct<type> *PLeft = Merge_arrange(PMerge);//改成一个可以接受的头，前面写的是head，想了半天，发现是Pmerge
                datastruct<type> *PRight = Merge_arrange(Pfast);
                //f(n) = f([0 - n/2]) + f([n/2+1 - n])
                datastruct<type> *Pnewhead;
                datastruct<type> *Pnewtable;
                if(PLeft->data > PRight->data)
                {
                    Pnewtable = PRight;
                    PRight = PRight->next; 
                }
                else
                {
                    Pnewtable = PLeft;
                    PLeft = PLeft->next;
                }
                //详细的指针用法还是不太清楚
                Pnewhead = Pnewtable;
                while (PLeft != NULL && PRight != NULL)
                {
                    if(PLeft->data > PRight->data)
                    {
                        Pnewtable->next = PRight;
                        PRight = PRight->next; 
                    }
                    else
                    {
                        Pnewtable->next = PLeft;
                        PLeft = PLeft->next;
                    }
                    Pnewtable = Pnewtable->next;
                }
                if(PLeft == NULL)
                {
                    Pnewtable->next = PRight;
                }
                else
                {
                    Pnewtable->next = PLeft;
                }
                return Pnewhead;
            }
}

template<typename type>
void list<type>::test_print()
{
    datastruct<type> *pdata;
    pdata = head;
    while (pdata != NULL)
    {
        std::cout<<pdata->data<<"--";
        pdata = pdata->next;
    }
    std::cout<<"end"<<std::endl;
}

//int main()
//{
//    int arr1[] = {12,34,56,87};
//    int arr2[] = {54,23,93,17};
 //   list<int> mylist1(arr1,sizeof(arr1)/sizeof(int));
   // list<int> mylist2(arr2,sizeof(arr1)/sizeof(int));
    //if(mylist1.find(12)) printf("12 has been find!");
    //if(mylist1.find(13)) printf("13 has been find!");
    //mylist1.Insert(34,78);
    //mylist1.test_print();
    //mylist1.Merge_List(mylist2);
    //mylist1.Merge_arrange();
    //mylist1.test_print();
    //mylist1.add_back(103);
    //mylist1.test_print();
    //mylist1.Change(103,102);
    //mylist1.test_print();
    //mylist1.List_Delete(102);
    //mylist1.List_Delete(56);
    //mylist1.test_print();
    //return 0;
//}