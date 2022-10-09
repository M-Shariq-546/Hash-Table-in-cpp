#include<iostream>
#include<strings.h>
using namespace std;
class hashtable
{
    int size = 10;
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
                    //For Inserting value on an Empty index
                    if(arr[x] == -9999)
                    {
                        arr[x] = v;
                        count++;
                    }
                    else{
                        //Linear Probing due to collision
                        for(int i=0 ; i<size ; i++)
                        {
                            if(arr[x] != -9999)
                            {
                                while(arr[x + 1] == -9999)
                                {
                                    x++;
                                }
                                arr[x]  = v;
                            }
                        }
                        count++;
                    }
        }
        void getValue(int k)
        {
            int x = k % size;
            if(arr[x] != -9999)
            {
                //Value Found 
                cout<<"The value is : "<<arr[x]<<endl;
            }
            else{
                //Value Not Found Exception
                cout<<"No value Found"<<endl;
            }
        }
        void print()
        {
            cout<<"Sr No."<<endl;
            for(int i=0 ; i<size ; i++)
            {
                //Printing Values in regular way by showing their indeces 
                cout<<i<<":- "<<arr[i]<<"\n";
            }
        }
        void deleteElement(int k)
        {
            int x = k % size;
            if(arr[x] == -9999)
            {
                //Already Empty space Exception
                cout<<"The space is Already Empty . Nothing found ."<<endl;
            }
            else{
                int y = arr[x];
                arr[x] = -9999;
                cout<<"The element \""<<y<<"\" is successfully deleted."<<endl;
                count--;
            }
        }
        void percentage()
        {
            //Weight of a hash table according to values
            cout<<"The Total values in array are : "<<count <<endl;
            float per = (float(count) / size) * 100;
            cout<<"The Percentage Weight of this array is : "<<per<<"%"<<endl;
            if(per >= 50)
            {
                size * 2;
            }
        }
};
int main()
{
    hashtable ht;
    ht.welcomeMessage();
    ht.initialArray();
    ht.add(20 , 5);
    ht.add(21 , 4);
    ht.add(11 , 8);
    ht.add(35 , 6);
    ht.print();
    ht.getValue(35);
    ht.getValue(38);
    ht.getValue(11);
    ht.percentage();
    ht.deleteElement(21);
    ht.print();
    ht.percentage();
    return 0;
}
