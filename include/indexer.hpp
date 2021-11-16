#ifndef INDEXER
#define INDEXER

#include <string>
#include <unordered_map>
#include <vector>

namespace ix {

struct IndexedDocument {
  std::string location;

  // List of the lines a keyword appears on
  std::vector<int> occurances;
};

class Indexer {

public:
  // Inserts a key into the indexer with the given document
  void InsertKey(const std::string keyword, const IndexedDocument document);

  // Indexes a document
  void IndexDocument(const std::string document_name, const std::string keyword);

  std::vector<IndexedDocument> GetKey(const std::string keyword);

private:
  std::unordered_map<std::string, std::vector<IndexedDocument> > m_index;
};

} // namespace ix

#endif