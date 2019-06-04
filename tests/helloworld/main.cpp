//premake.vpath=.
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/weak_ptr.hpp"
#include "boost/shared_ptr.hpp"

#include <cstdio>
#include <iostream>

struct Test
{
    Test()
    {
        printf("Test\n");
    }

    ~Test()
    {
        printf("~Test\n");
    }

    void fun_0()
    {
        printf("fun_0\n");
    }

    void fun_1(int a)
    {
        printf("fun_1, a=%d\n", a);
    }

    void fun_2(int a1, int a2)
    {
        printf("fun_2, a1=%d, a2=%d\n", a1, a2);
    }

    void fun_3(int a1, int a2, int a3)
    {
        printf("fun_3, a1=%d, a2=%d, a3=%d\n", a1, a2, a3);
    }

};

void test_f0()
{
    printf("test_f0\n");
}

void test_call_f0(const boost::function<void ()>& f)
{
    f();
}

QTrue _test_f(void ());
QFalse _test_f(...);

//QFalse _test_f(void (*)());

int main(int argc, char** argv)
{
    boost::shared_ptr<Test> t(new Test());

    boost::function<void ()> f;
    f = test_f0;
    f();

    printf("%d\n", IsFunctionPrototype<void (void)>::value);
    printf("%d\n", IsFunctionPrototype<void (*)(void)>::value);
    printf("%d\n", IsFunctionPointer<void (*)(void)>::value);
    printf("%d\n", IsFunctionPointer<void (void)>::value);
    printf("%d\n", IsFunctionPrototypeOrPointer<void (void)>::value);
    printf("%d\n", IsFunctionPrototypeOrPointer<void (*)(void)>::value);

    test_call_f0(test_f0);

    f = boost::bind(&Test::fun_0, t);
    f();

    f = boost::bind(&Test::fun_1, t, 1);
    f();

    f = boost::bind(&Test::fun_2, t, 1, 2);
    f();

    return 0;
}