#include <iostream>
#include <list>
#include<string>
using namespace std;

class HashTable
{
    int x;
    list<int>* table;

public:

    HashTable(int V)
    {
        int s = prime(V);
        this->x = s;
        table = new list<int>[x];
    }


    void insertion(int key, int data)
    {
        int in = hash(key);
        table[in].push_back(data);
    }


    void deletion(int key)
    {
        int in = hash(key);

        list<int>::iterator i;
        for (i = table[in].begin();
            i != table[in].end(); i++)
        {
            if (*i == key)
                break;
        }

        if (i != table[in].end())
        {
            table[in].erase(i);
        }

    }


    int check_prime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }

        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }

        return 1;
    }


    int prime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }

        while (!check_prime(n))
        {
            n += 2;
        }
        return n;
    }


    int hash(int k)
    {
        return (k % x);
    }


    void display()
    {
        for (int i = 0; i < x; i++)
        {
            cout << "Table[" << i << "]:";
            for (auto x : table[i])
            {
                cout << " ---- " << x;
            }
            cout << endl;
        }
    }

};


int main()
{
    int key[] = { 25 , 21 , 22 , 32 , 43 , 62 , 73 , 93 };
    int data[] = { 23 , 32 , 53 , 3 , 42 , 1 , 64 , 92 };
    int size = sizeof(key) / sizeof(key[0]);

    cout << "Enter the size:" << endl;
    cin >> size;
    HashTable obj(size);

    for (int i = 0; i < size; i++)
    {
        obj.insertion(key[i], data[i]);
    }


    obj.display();

    system("Pause");
    return 0;
}