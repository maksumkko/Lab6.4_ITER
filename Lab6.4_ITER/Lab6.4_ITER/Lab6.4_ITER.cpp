#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateA(int a[], int n, int min, int max);
void printA(int a[], int n);
void productA(int a[], int n, int& product);
int sumBetweenZeros(int a[], int n);
void rearrangeArray(int a[], int n);

int main()
{
    int n;
    cout << "Input N: "; cin >> n;
    int* a = new int[n];
    int product = 1;

    generateA(a, n, -10, 20);
    cout << "a=";
    printA(a, n);

    productA(a, n, product);
    cout << "Product: " << product << endl;

    int sum = sumBetweenZeros(a, n);
    if (sum != -1) {
        cout << "Sum between first and last zeros: " << sum << endl;
    }
    else {
        cout << "There are not enough zeros to calculate the sum." << endl;
    }

    rearrangeArray(a, n);
    cout << "Rearranged array: ";
    printA(a, n);

    delete[] a;
    return 0;
}

void generateA(int a[], int n, int min, int max)
{
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i)
    {
        a[i] = std::rand() % (max - min + 1) + min;
    }
}

void printA(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << std::setw(4) << a[i];
    }
    cout << std::endl;
}

void productA(int a[], int n, int& product)
{
    product = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            product *= a[i];
        }
    }
}
int sumBetweenZeros(int a[], int n)
{
    int firstZero = -1;
    int lastZero = -1;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            firstZero = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == 0)
        {
            lastZero = i;
            break;
        }
    }

    if (firstZero == -1 || lastZero == -1 || firstZero == lastZero)
    {
        return -1;
    }

    int sum = 0;
    for (int i = firstZero + 1; i < lastZero; ++i)
    {
        sum += a[i];
    }

    return sum;
}

void rearrangeArray(int a[], int n)
{
    int* temp = new int[n];
    int index = 0;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
        {
            temp[index++] = a[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            temp[index++] = a[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        a[i] = temp[i];
    }

    delete[] temp;
}