#include<iostream>

using namespace std;

class Heap
{
private:
    int* h;
    int maxSize;
    int n;
public:
    Heap(int* arr, int ms, int sz)
    {
        h = arr; 
        maxSize = ms; 
        n = sz;            
    }

    Heap(int ms)
    {
        maxSize = ms;
        h = new int[maxSize + 1];
        n = 0;
    }

    void Insert(int x)
    {
        if (n == maxSize)
        {
            cout << "***HEAP IS FULL***" << endl;
            return;
        }

        n++;
        int i;
        for (i = n; i > 1; i = i / 2)
        {
            if (x >= h[i / 2])
                break;

            h[i] = h[i / 2];
            // h[i/2] = x;       
        }
        h[i] = x;
    }


    void Display()
    {
        for (int i = 1; i <= n; i++)
            cout << h[i] << "\t";
        cout << endl;
    }

    int DeleteMin()
    {
        if (n == 0)
        {
            cout << "***HEAP IS EMPTY***" << endl;
            return 0;
        }

        int x = h[1];
        int last = h[n];
        n--;
        int i, j;
        for (i = 1, j = 2; j <= n; i = j, j *= 2)
        {
            if (j < n)
                if (h[j] > h[j + 1])
                    j++;   

            if (last <= h[j]) 
                break;
            h[i] = h[j]; 
        }
        h[i] = last;
        return x;
    }


    int DeleteMinHeap()
    {
        int root = h[1];
        h[1] = h[n]; 
        n--;
        heapify(1);
        return root;
    }

    void heapify(int i)
    {
        int smallest = i; 
        int l = 2 * i; 
        int r = 2 * i + 1; 
        if (l <= n && h[l] < h[smallest])
            smallest = l;

    
        if (r <= n && h[r] < h[smallest])
            smallest = r;

     
        if (smallest != i)
        {
            swap(h[i], h[smallest]);   
            heapify(smallest);
        }
    }

    void BuildHeap()
    {
     
        int Start_index = (n / 2);
        for (int i = Start_index; i > 0; i--)
            heapify(i);
    }


};


int main()
{
    Heap h1(15);
    h1.Insert(13);
    h1.Insert(16);
    h1.Insert(14);
    h1.Insert(21);
    h1.Insert(19);
    h1.Insert(32);
    h1.Insert(68);
    h1.Insert(65);
    h1.Insert(26);
    h1.Insert(31);
    h1.Insert(22);
    h1.Display();
    h1.DeleteMinHeap();
    h1.Display();

    Heap h2(15);
    h2.Insert(65);
    h2.Insert(26);
    h2.Insert(32);
    h2.Insert(24);
    h2.Insert(31);
    h2.Insert(19);
    h2.Insert(68);
    h2.Insert(21);
    h2.Insert(16);
    h2.Insert(13);
    h2.Insert(22);
    h2.Display();
    h2.DeleteMinHeap();
    h2.Display();


    int arr[] = { 0, 65, 31, 32, 26, 21, 19, 68, 13, 24, 15, 14, 16, 5, 70, 12 };
    int arr_sz = sizeof(arr) / sizeof(int);
    cout << "ARRAY SIZE: " << arr_sz << endl;
    Heap h3(arr, arr_sz, arr_sz - 1);
    cout << "BEFORE HEAP: " << endl;
    h3.Display();
    h3.BuildHeap();
    cout << "AFTER HEAP: " << endl;
    h3.Display();
    
    system("pause");
    return 0;
}