#include <iostream>

class Foo
{
public:

    Foo(int n)
    {
        f_n = n;
        f_mas = new int[f_n];

        for (int i = 0; i < f_n; i++)
            f_mas[i] = (rand() % 100);
    }
    
    virtual ~Foo() {
        delete[] f_mas; 
    }

    //Copy constructor
    Foo (const Foo& mas)
    {
        f_n = mas.f_n;
        f_mas = new int[f_n];

        for (int i = 0; i < f_n; i++)
            f_mas[i] = mas.f_mas[i];  
    }

    Foo& operator=(const Foo& mas)
    {
        f_n = mas.f_n;

        for (int i = 0; i < f_n; i++)
            f_mas[i] = mas.f_mas[i];
        
        return *this;
    }

    void Correct_or_not()
    {
        for (int i = 0; i < f_n; i++)
            std::cout << f_mas[i] << std::endl;
    }

    int Array_size()
    {
        return f_n;
    }

private:
    int* f_mas;
    int f_n;
};

class Bar : public Foo
{
public:
    Bar(int n) : Foo(n)
    { 
        mas = new char[n]; 
    }
    virtual ~Bar() 
    { 
        delete[] mas; 
    }

private:
    char* mas;
};


int main()
{
    Foo* f = new Foo(1);
    Foo* b = new Bar(2);
    
    f->Correct_or_not();
    std::cout << std::endl;
    b->Correct_or_not();
    std::cout << std::endl;
    
    if (f->Array_size() == b->Array_size())
    {
        *f = *b;
        f->Correct_or_not();
    }

    else
        std::cout << "Operation is not supported because of difference in arrays` sizes!";

    delete f;
    delete b;

    return 0;
}
