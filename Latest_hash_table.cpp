
#include <iostream>
#include <string>
using namespace std;
class hashtable
{
private:
    int size = 10;
    int arr[10];
    int count =0;
    public:
    
    int hashfunction(int k)
    {
        return k % size;
    }
    
    void insert(int n , int k)
    {
        int x = hashfunction(k);
        if(arr[x] == -999)
        {
            arr[x] = n;
            count++;
        }
        else{
            if(arr[x] != -999)
            {
                while(arr[x+1] == -999)
                {
                    x++;
                }
                arr[x]= n;
            }
            count++;
        }
    }

    void initialize()
    {
        for(int i=0 ; i<size; i++)
        {
            arr[i]=-999;
        }
    }
    
    void print()
    {
        for(int i=0 ; i<=size;i++)
        {
            cout<<"The Numbers are "<<arr[i]<<"\n";
        }
    }
    
    int totalsize()
    {
        return count;
    }
    
    void search(int k)
    {
        int x = hashfunction(k);
        if(arr[x] != -999)
        {
            cout<<"The Number at key : "<<k<<"  are : "<<arr[x]<<endl;
        }
        else
        {
            cout<<"Nothing against the : "<<k<<endl;
        }
    }
    
};

int main()
{
  hashtable h;
  h.initialize();
  h.insert(8 , 5);
  h.insert(19 , 0);
  h.insert(22 , 7);
  h.print();
  cout<<"Total Inserted Elements : "<<h.totalsize()<<"\n";
  h.search(0);
  h.search(6);
  h.insert(99 , 6);
  h.print();
  h.search(6);
}
