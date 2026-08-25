// clang++ -std=c++17 -Wall -Wextra -pedantic structured_bindings.cpp -o structured_bindings
#include <cstdio>

struct TextFile
{
    bool success;
    const char *data;
    std::size_t n_bytes;
};

TextFile read_text_file(const char *path)
{
    (void)path;
    const static char contents[] = {"Sometimes the goat is you."};
    return TextFile
    {
        true,
        contents,
        sizeof(contents)
    };
}

int main(void)
{
    char path[]{ "README.txt" };
    const auto [success, contents, length] = read_text_file(path);
    if (success)
    {
        printf("Read %zu bytes: %s\n", length, contents);
    }
    else
    {
        printf("Failed to open %s\n", path);
    }
}
