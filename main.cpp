#include "MyString.h"
#include <vector>
#include <algorithm>

int main(int argc, char * argv[])
{
    /* if argc less or equal '1', it means that no additional arguments wasn't passed */
    if (argc <= 1) return 0;

    std::vector<MyString> args;
    args.reserve(argc);

    /* collects data */
    for (int i = 1; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }

    /* sorts in reverse lexicographical order */
    std::sort(args.begin(), args.end(), std::greater<MyString>());

    /* prints result */
    for (const auto& arg : args) {
        std::cout << arg << '\n';
    }
    return 0;
}