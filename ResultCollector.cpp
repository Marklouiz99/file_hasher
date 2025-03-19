#ifndef RESULTCOLLECTOR_HPP
#define RESULTCOLLECTOR_HPP

#include"ResultCollector.hpp"

#endif

void ResultCollector::addResult(const fs::path& filePath, const std::string& hashValue)
{
    std::lock_guard<std::mutex> lock(mutex_);
    resultscollection.emplace_back(filePath.string(), hashValue);
}

void ResultCollector::outputResults() const
{
     for (const auto& [file, hash] : resultscollection) {
            std::cout << file << " : " << hash << "\n";
    }
}