#pragma once

#include <optional>

class TheMatrix 
{
public:
    TheMatrix(int x) :iteration{x} {}
    const int iteration;
};

enum Pill{Red, Blue};

std::optional<TheMatrix> take(Pill);
