#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 ructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // ANTS 

    static const int CAPACITY = 20;

    // RUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint()
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            data_[i] = 0;
        }
    }

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(string s)
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            data_[i] = 0;
        }

        int num = stoi(s);
        int i = 0;
        
        while (num > 0 && i < CAPACITY)
        {
            int v = num % 10;
            data_[i] = v;
            num /= 10;
            i++;
        }
    }

    // ANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](int pos)
    {
        return data_[pos];
    }

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(biguint b)
    {
        string s = "";
        for (int i = CAPACITY-1; i >= 0; i--)
        {
            s += to_string(data_[i]);
        }
      
        string S = "";
        for (int i = CAPACITY-1; i >= 0; i--)
        {
            S += to_string(b.data_[i]);
        }
 

        if (s > S)
        return 1;
        else if (s == S)
        return 0;
        else
        return -1;
    }



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (biguint b)
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            if (data_[i] + b.data_[i] < 10)
            data_[i] += b.data_[i];
            else
            {
                data_[i+1]++;
                data_[i] = (data_[i] + b.data_[i]) % 10;
            }
        }
    }
    void operator -= (biguint b)
    {
        for (int i = 0; i < CAPACITY; i++)
        {
            if (data_[i] - b.data_[i] >= 0)
            data_[i] -= b.data_[i];
            else
            {
                data_[i] = (data_[i] + 10 - b.data_[i]);
                data_[i + 1] -= 1;
            }
        }
    }

private:
    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + ( biguint b1,  biguint b2)
{
    b1 += b2;
    return b1;
}

biguint operator - ( biguint b1,  biguint b2)
{
    b1 -= b2;
    return b1;
}

bool operator < ( biguint b1,  biguint b2)
{
   return b1.compare(b2) == -1;
}
bool operator <= ( biguint b1,  biguint b2);
bool operator != ( biguint b1,  biguint b2);
bool operator == ( biguint b1,  biguint b2);
bool operator >= ( biguint b1,  biguint b2);
bool operator > ( biguint b1,  biguint b2);
std::ostream& operator <<(std::ostream&,  biguint b);

int main()
{
    biguint b = biguint("521");
    biguint c = biguint("4320");
    biguint d = biguint("5211");

    b += c;
    for (int i = 0; i < b.CAPACITY; i++) cout << b[i];
    
    cout << endl; 

    d -= c;    
    for (int i = 0; i < b.CAPACITY; i++) cout << d[i];

    cout << endl;

    cout << b.compare(c) << endl;

    biguint x = biguint("521");
    biguint y = biguint("4320");
    biguint z = biguint("5211");

    biguint a1 = x + y;
    for (int i = 0; i < b.CAPACITY; i++) cout << a1[i];
    cout << endl;
    biguint a2 = z - y;
    for (int i = 0; i < b.CAPACITY; i++) cout << a2[i];
cout << endl;
cout << endl;
    if (x < y)
    cout << "x < y" << endl;

    return 0;
}


