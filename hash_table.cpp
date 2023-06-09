#include<iostream>
#include<strings.h>
using namespace std;
class hashtable
{
    int size = 16;
    int arr[16];
    int count = 0;
    public:
        void welcomeMessage()
        {
            cout<<"Welcome to Hash Table by \"M. Shariq Shafiq\""<<endl;
            cout<<"Roll Number \"546\""<<endl;
            cout<<"\"-9999\" stands for empty space in the array "<<endl;
            cout<<"So Enjoy the code"<<endl;
        }
        void initialArray()
        {
            for(int i=0 ; i<size; i++)
            {
                arr[i] = -9999;
            }
        }
        int hashFunction(int k)
        {
            return k % size;
        }
        void add(int k , int v)
        {
            int x = hashFunction(k);
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
        void Search(int k)
        {
            int x = hashFunction(k);
            if(arr[x] != -9999)
            {
                //Value Found 
                cout<<"The value is : "<<arr[x]<<"\tat the key of : "<<k<<endl;
            }
            else{
                //Value Not Found Exception
                cout<<"No value Found at key : "<<k<<endl;
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
            int x = hashFunction(k);
            if(arr[x] == -9999)
            {
                //Already Empty space Exception
                cout<<"The space is Already Empty . Nothing found ."<<endl;
            }
            else{
                int y = arr[x];
                arr[x] = -9999;
                cout<<"The element \""<<y<<"\" is successfully deleted. Respected to key : "<<k<<endl;
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
    //Adding key value Pair
    ht.add(0 , 5);
    ht.add(1 , 4);
    ht.add(4 , 6);
    ht.add(5 , 0);
    ht.add(8 , 4);
    ht.add(13 , 5);
    ht.add(11 , 2);
    ht.add(12 , 2);
    ht.add(15 , 6);
    ht.print();
    //Searching on key base
    ht.Search(5);
    ht.Search(8);
    ht.Search(1);
    ht.percentage();
    //Delete on key base
    ht.deleteElement(12);
    ht.print();
    ht.percentage();
    return 0;
}
