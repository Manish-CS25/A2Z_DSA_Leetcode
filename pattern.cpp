#include <bits/stdc++.h>

using namespace std;
void pattern1(int k)
{
    for (int i = 0; i < k; i++)

    {
        for (int j = 0; j < k; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int k)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(int k)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5(int k)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = k; j >= i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int k)
{
    for (int i = k; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern7(int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            cout << " ";
        }
        for (int k1 = 0; k1 < 2 * i + 1; k1++)
        {
            cout << "*";
        }
        for (int k2 = 0; k2 < k - i - 1; k2++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k1 = 0; k1 < 2 * (n - i - 1) + 1; k1++)
        {
            cout << "*";
        }
        for (int k2 = 0; k2 < i; k2++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void nStarDiamond(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k1 = 0; k1 < 2 * i + 1; k1++)
        {
            cout << "*";
        }
        for (int k2 = 0; k2 < n - i - 1; k2++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k1 = 0; k1 < 2 * (n - i - 1) + 1; k1++)
        {
            cout << "*";
        }
        for (int k2 = 0; k2 < i; k2++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void nStarTriangle(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void nBinaryTriangle(int n)
{
    // Write your code here.
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void numberCrown(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        for (int j = 0; j <= n - i; j++)
        {
            cout << " "
                 << " ";
        }
        int h1 = i + 1;
        for (int j = 0; j <= i; j++)
        {

            cout << h1 << " ";
            h1 = h1 - 1;
        }
        for (int j = 0; j < 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void nNumberTriangle(int n)
{
    // Write your code here.
    int jk = 1;
    for (int i = 1; i <= n; i++)
    {
        int p = jk;
        for (int j = 1; j <= i; j++)
        {
            cout << p << " ";
            p = p + 1;
            jk = jk + 1;
        }
        cout << endl;
    }
}

void nLetterTriangle(int n)
{
    // Write your code here.

    for (int i = 1; i <= n; i++)
    {
        char abcd = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << abcd << " ";
            abcd++;
        }
        cout << endl;
    }
}

void nLetterTriangle2(int n)
{
    // Write your code here.
    for (int i = 1; i <= n; i++)
    {
        char abcd = 'A';
        for (int j = n; j >= i; j--)
        {
            cout << abcd << " ";
            abcd++;
        }
        cout << endl;
    }
}

void alphaRamp(int n)
{
    // Write your code here.
    char abcd = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << abcd << " ";
        }
        cout << endl;
        abcd++;
    }
}

void alphaHill(int n)
{
    // Write your code here.

    for (int i = 0; i < n; i++)
    {
        char abcd = 'A';
        for (int j = 1; j <= n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i + 1; j++)
        {
            cout << abcd << " ";
            abcd++;
        }
        abcd = abcd - 2;
        for (int j = 1; j <= i; j++)
        {
            cout << abcd << " ";
            abcd--;
        }

        for (int j = 1; j <= n - i - 1; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }
}

void alphaTriangle(int n)
{
    // Write your code here.

    for (int i = 1; i <= n; i++)
    {
        char abcd = 'A' + n - 1;

        for (int j = 1; j <= i; j++)
        {
            cout << abcd << " ";
            abcd--;
        }

        cout << endl;
    }
}

void symmetry(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void symmetry(int n)
{
    // Write your code here.

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * (i - 1); j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2 * (i + 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void getStarPattern(int n)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
            cout << endl;
        }

        else
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0 || j == n - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
}

void getNumberPattern(int n)
{
    // Write your code here.
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 1) - 1 - j;
            int bottom = (2 * n - 1) - 1 - i;
            cout << (n - min(min(top, bottom), min(left, right)));
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    // pattern1(n);
    // pattern8(n);
    nBinaryTriangle(n);
    numberCrown(n);
    return 0;
}