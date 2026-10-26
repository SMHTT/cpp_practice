// This program implements a Polynomial class using an array of terms.
// It supports adding, removing, and searching for terms in a polynomial.


#include <iostream>
using namespace std;

class Term
{
public:
    int exp;
    float coef;
};

class Polynomial
{
private:
    int max_term;
    int terms;
    Term term[100];

public:
    Polynomial(int MT);

    bool addterm(int e, float c);
    bool removeterm(int e);
    bool searchterm(int e);
    bool add(Polynomial other);
    bool sub(Polynomial other);
    bool mult(Polynomial other);
    void print();

    ~Polynomial();
};

Polynomial::Polynomial(int MT)
{
    max_term = MT;
    terms = 0;
}

bool Polynomial::addterm(int e, float c)
{
    for (int i = 0; i < terms; i++)
    {
        
        if (term[i].exp == e)
        {
            term[i].coef += c;
            return true;
        }
    }

    if (terms >= max_term)
        return false;

    term[terms].exp = e;
    term[terms].coef = c;
    terms++;

    return true;
}

bool Polynomial::removeterm(int e)
{
    for (int i = 0; i < terms; i++)
    {
        if (term[i].exp == e)
        {
            for (int j = i; j < terms - 1; j++)
            {
                term[j] = term[j + 1];
            }

            terms--;
            return true;
        }
    }

    return false;
}

bool Polynomial::searchterm(int e)
{
    int left = 0;
    int right = terms - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (term[mid].exp == e)
            return true;

        if (term[mid].exp < e)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

bool Polynomial::add(Polynomial other)
{
    for (int i = 0; i < other.terms; i++)
    {
        if (!addterm(other.term[i].exp , other.term[i].coef))
        {
            return false;
        }
    }

    return true;
}

bool Polynomial::sub(Polynomial other)
{
    for (int i = 0; i < other.terms; i++)
    {
        if (!addterm(other.term[i].exp,-other.term[i].coef))
        {
            return false;
        }
    }

    return true;
}

bool Polynomial::mult(Polynomial other)
{
    Polynomial result(max_term);

    for (int i = 0; i < terms; i++)
    {
        for (int j = 0; j < other.terms; j++)
        {
            int e = term[i].exp + other.term[j].exp;
            float c = term[i].coef * other.term[j].coef;

            if (!result.addterm(e, c))
                return false;
        }
    }

    terms = result.terms;

    for (int i = 0; i < terms; i++)
    {
        term[i] = result.term[i];
    }

    return true;
}

void Polynomial::print()
{
    for (int i = 0; i < terms; i++)
    {
        cout << term[i].coef << "x^" << term[i].exp << " ";
    }
    cout << endl;
}

Polynomial::~Polynomial()
{
}

int main()
{
    Polynomial A(100), B(100);

    A.addterm(2, 2);
    A.addterm(1, 3);
    A.addterm(0, 1);

    B.addterm(1, 4);
    B.addterm(0, 2);

    cout << "A: ";
    A.print();

    cout << "B: ";
    B.print();

    Polynomial C = A;
    C.add(B);
    cout << "A + B: ";
    C.print();

    Polynomial D = A;
    D.sub(B);
    cout << "A - B: ";
    D.print();

    Polynomial E = A;
    E.mult(B);
    cout << "A * B: ";
    E.print();

    return 0;
}