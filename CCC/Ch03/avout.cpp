#include <cstdio>
#include "avout.h"

void Avout::announce() const
{
    printf("Avout %s is set to year %d\n",
           this->name, this->apert.get_year());
}