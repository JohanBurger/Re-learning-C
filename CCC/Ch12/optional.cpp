#include "optional.h"

std::optional<TheMatrix> take(Pill pill){
    if (pill == Pill::Blue) 
    {
        return TheMatrix{6};
    }
    return std::nullopt;
}
