#include "include/tiny-search-engine.hpp"
#include <iostream>

namespace {

void PrintResults(const std::vector<ix::IndexedDocument> results)
{
    std::cout << "Search results:\n" << std::endl;
}

} // namespace

int main(int argc, char *argv[])
{
    std::cout << "Go ahead, search for a keyword:" << std::endl;

    auto keyword = std::string();
    std::cin >> keyword;

    auto results = search::Search(keyword);

    PrintResults(results);

    return 0;
}