/*Implement all the function of dictionary(ADT) using hashing data.*/


#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 128;


class HashEntry
{
    public:
        int key;
        int value;
        HashEntry(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class HashMap
{
    private:
        HashEntry **table;
    public:
        HashMap()
    {
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
        
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }
        
    void Insert(int key, int value)
    {
            int hash = HashFunc(key);
            while (table[hash] != NULL && table[hash]->key != key)
            {
                hash = HashFunc(hash + 1);
            }
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
    }
       
        int Search(int key)
    {
        int  hash = HashFunc(key);
        while (table[hash] != NULL && table[hash]->key != key)
        {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->value;
        }

        
        void Remove(int key)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == key)
                break;
            hash = HashFunc(hash + 1);
        }
            if (table[hash] == NULL)
        {
                cout<<"No Element found at key "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Element Deleted"<<endl;
        }
        ~HashMap()
    {
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    HashMap hash;
    int key, value;
    int choice;
    while (1)
    {
        cout<<"----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"n----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element at a key"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.Insert(key, value);
            break;
        case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            if (hash.Search(key) == -1)
            {
            cout<<"No element found at key "<<key<<endl;
            continue;
        }
        else
        {
            cout<<"Element at key "<<key<<" : ";
            cout<<hash.Search(key)<<endl;
        }
            break;
        case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.Remove(key);
            break;
        case 4:
            exit(1);
        default:
           cout<<"nEnter correct optionn";
       }
    }
    return 0;
}

/******************output*****************
carchana@ubuntu:~$ cd Desktop
archana@ubuntu:~/Desktop$ g++ hash1.cpp
archana@ubuntu:~/Desktop$ ./a.out
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 1
Enter element to be inserted: 23
Enter key at which element to be inserted: 1
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 1
Enter element to be inserted: 41
Enter key at which element to be inserted: 4
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 1
Enter element to be inserted: 12
Enter key at which element to be inserted: 2
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 2
Enter key of the element to be searched: 12
No element found at key 12
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 2
Enter key of the element to be searched: 4
Element at key 4 : 41
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 3
Enter key of the element to be deleted: 2
Element Deleted
----------------------
Operations on Hash Table
n----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 4 */
