target_include_directories (TinySearchEngine 
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include"
)

target_sources(TinySearchEngine 
    PRIVATE
        tiny-search-engine.cpp
        indexer.cpp
)