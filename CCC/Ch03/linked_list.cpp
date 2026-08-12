#include <cstdio>

struct Element
{
    Element *next{nullptr}; // This must be a pointer, and not a reference...

    void insert_after(Element *new_element)
    {
        new_element->next = this->next;
        this->next = new_element; // because here the pointer gets reseated.
        // References cannot be reseated.
    }

    char prefix[2];
    short operating_number;
};

int main(void)
{
    Element trooper1, trooper2, trooper3;

    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    trooper1.insert_after(&trooper2);

    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);

    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;

    for (Element *cursor = &trooper1; cursor != nullptr; cursor = cursor->next)
    {
        printf("%c%c-%03d\n",
               cursor->prefix[0], cursor->prefix[1],
               cursor->operating_number);
    }
}