#pragma once

struct Socialite
{
    const char *birthname;
};

struct Valet
{
    const char *surname;
};

struct Acquaintance
{
    const char *nickname;
};

struct EscapeCapsule
{
    EscapeCapsule(int weight_kg) : weight_kg(weight_kg) {}
    int weight_kg;
};

struct BugblatterBeast
{
    BugblatterBeast()
        : is_ravenous{true}, weight_kg{600}
    {
    }

    bool is_ravenous;
    int weight_kg;
};
