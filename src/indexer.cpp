#include "indexer.hpp"
#include <fstream>

namespace ix
{
    void Indexer::InsertKey(const std::string keyword,
                            const IndexedDocument document)
    {
        if (m_index.find(keyword) != m_index.end())
        {
            m_index.emplace(keyword, std::vector<IndexedDocument>{document});
        }
        else
        {
            m_index.at(keyword).push_back(document);
        }
    }

    void Indexer::IndexDocument(const std::string document_name, const std::string keyword)
    {
        auto document = ix::IndexedDocument{document_name, std::vector<int>{}};

        auto ifs = std::ifstream(document_name);
        auto current_line = 0;
        auto line = std::string();
        while (std::getline(ifs, line))
        {
            current_line++;
            if (line.find(keyword, 0) != std::string::npos)
            {
                document.occurances.push_back(current_line);
            }
        }

        InsertKey(keyword, document);
    }

    std::vector<IndexedDocument> Indexer::GetKey(const std::string keyword)
    {
        return m_index[keyword];
    }

} // namespace ix