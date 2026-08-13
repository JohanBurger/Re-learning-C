// clang++ -std=c++17 -Wall -Wextra -pedantic simple_string_use.cpp simple_string.cpp  -o ssu
#include <cstdio>
#include <utility>

#include "simple_string.h"

void foo(SimpleString s)
{
    s.append_line("Change lost");
}

int main()
{
    SimpleString s(115);
    s.append_line("Starbuck, whaddya hear?");
    s.append_line("Nothin' but the rain.");
    s.print("A");

    s.append_line("Grab your gun and bring the cat in.");
    s.append_line("Aye-aye, sir, coming home.");
    s.print("B");

    if (!s.append_line("Galatica!"))
    {
        printf("String was not big enough to append another message.");
    }

    SimpleString a{50};
    a.append_line("We apologize for the");
    SimpleString a_copy{a};
    a.append_line("inconvenience.");
    a_copy.append_line("incontinence.");
    a.print("a");
    a_copy.print("a_copy");

    SimpleString pass_by_value{20};
    foo(pass_by_value);
    pass_by_value.print("pass_by_value");

    SimpleString original{50};
    original.append_line("Original");
    SimpleString copy{50};
    copy.append_line("Copy");
    original.print("original");
    copy.print("copy");

    copy = original;
    original.print("original");
    copy.print("copy");

    auto moved_from = SimpleString{50};
    moved_from.append_line("Moved from");

    auto moved_to = SimpleString{50};
    moved_to.append_line("Moved to");

    moved_from.print("moved_from");
    moved_to.print("moved_to");

    moved_to = std::move(moved_from);
    moved_to.print("moved_to");

    return 0;
}