#ifndef SEARCH_ENGINE
#define SEARCH_ENGINE

#include "indexer.hpp"

namespace search {

// TODO: cache recent searches


// just start with searching for a single keyword
// seach with queries later
std::vector<ix::IndexedDocument> Search(const std::string keyword);

} // namespace search

#endif