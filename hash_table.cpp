#include<iostream>
#include<strings.h>
using namespace std;
class hashtable
{
    const int size = 10;
    int arr[10];
    int count = 0;
    public:
        void welcomeMessage()
        {
            cout<<"Welcome to Hash Table by M. Shariq Shafiq"<<endl;
            cout<<"-9999 stands for empty space in the array "<<endl;
            cout<<"So Enjoy the code"<<endl;
        }
        void initialArray()
        {
            for(int i=0 ; i<size; i++)
            {
                arr[i] = -9999;
            }
        }
        void add(int k , int v)
        {
            int x = k % size;
                    if(arr[x] == -9999)
                    {
                        arr[x] = v;
                        count++;
                    }
                    else{
                        for(int i=0 ; i<size ; i++)
                        {
                            while(arr[x] == -9999)
                            {
                                x++;
                            }
                        }
                        arr[x] =  v;
                        count++;
                    }
        }
        void getValue(int k)
        {
            int x = k % size;
            if(arr[x] != -9999)
            {
                cout<<"The value is : "<<arr[x]<<endl;
            }
            else{
                cout<<"No value Found"<<endl;
            }
        }
        void print()
        {
            for(int i=0 ; i<size ; i++)
            {
                cout<<arr[i]<<"\n";
            }
        }
        void percentage()
        {
            float per = (float(count) / size) * 100;
            cout<<"The Percentage Weight of this array is : "<<per<<"%"<<endl;
        }
};
int main()
{
    hashtable ht;
    ht.welcomeMessage();
    ht.initialArray();
    ht.add(20 , 5);
    ht.add(21 , 4);
    ht.add(35 , 6);
    ht.print();
    ht.getValue(35);
    ht.getValue(38);
    ht.percentage();
}