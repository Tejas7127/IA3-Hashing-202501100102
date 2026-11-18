#include <iostream>
using namespace std;

#define SIZE 23
#define N 20

class HashTable
{
    int table[SIZE];

public:
    HashTable()
    {
        for(int i=0;i<SIZE;i++)
            table[i]=-1;
    }

    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insert(int key)
    {
        int index=hashFunction(key);
        int start=index;

        while(table[index]!=-1)
        {
            index=(index+1)%SIZE;

            if(index==start)
            {
                cout<<"Hash Table Full\n";
                return;
            }
        }

        table[index]=key;

        cout<<"\nInserted "<<key
            <<" at index "<<index;
        display();
    }

    void display()
    {
        cout<<"\nIndex : Value\n";

        for(int i=0;i<SIZE;i++)
        {
            cout<<i<<" : ";

            if(table[i]==-1)
                cout<<"Empty";
            else
                cout<<table[i];

            cout<<"\n";
        }
    }
};

int main()
{
    int data[N]={
        2,15,28,41,54,67,80,93,6,19,
        32,45,58,71,84,97,10,23,36,49
    };

    HashTable h;

    cout<<"MANGO VARIETY HASH TABLE\n";
    cout<<"PRN: 202501100102\n";
    cout<<"Hash Function: key % 23\n";
    cout<<"Collision Method: Linear Probing\n";

    for(int i=0;i<N;i++)
        h.insert(data[i]);

    cout<<"\nFINAL HASH TABLE\n";
    h.display();

    return 0;
}a
