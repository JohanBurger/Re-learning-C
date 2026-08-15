#include <cstdio>

struct Tracer
{
    Tracer(const char *name) : name(name)
    {
        std::printf("Tracer %s constructed\n", name);
    }

    ~Tracer()
    {
        std::printf("Tracer %s destructed\n", name);
    }

private:
    const char *name;
};

static Tracer t1{"Static variable t1"};
thread_local Tracer t2{"Thread-local variable t2"};

int main(void)
{
    const auto t2_ptr = &t2;
    std::printf("A\n");
    Tracer t3{"Automatic variable t3"};
    std::printf("B\n");
    const auto *t4 = new Tracer{"Dynamic variable t4"};
    std::printf("C\n");
}

/* Output:
Tracer Static variable t1 constructed
Tracer Thread-local variable t2 constructed
A
Tracer Automatic variable t3 constructed
B
Tracer Dynamic variable t4 constructed
C
Tracer Automatic variable t3 destructed
Tracer Thread-local variable t2 destructed
Tracer Static variable t1 destructed
*/
