#include <cstddef>
#include <cstdio>

struct College
{
    char name[256];
};

void print_name(const College *college_ptr)
{
    std::printf("%s College\n", college_ptr->name);
}

void print_names(const College *college_ptr, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i)
    {
        std::printf("%s College\n", college_ptr[i].name);
    }
}

int main(void)
{
    College oxford[]{
        {"Magdalen"},
        {"Nuffield"},
        {"Kellogg"}};

    print_name(oxford);
    print_names(oxford, sizeof(oxford) / sizeof(College));

    College *third_college_ptr = &oxford[2];
    print_name(third_college_ptr);

    char lower[] = "abc?e";
    char upper[] = "ABC?E";

    char *upper_ptr = upper;
    lower[3] = 'd';
    upper_ptr[3] = 'D';

    char letter_d = lower[3];
    char letter_D = upper_ptr[3];

    std::printf("%c %c\n", letter_d, letter_D);

    // (The array only has 6 elements, including the null terminator).
    // lower[7] = 'g'; // <- This would be a buffer overflow.
}