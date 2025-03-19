#pragma once
#include<mutex>
#include <filesystem>
#include <vector>
#include <mutex>
#include<iostream>

namespace fs = std::filesystem;

class ResultCollector
{
private:
    mutable std::mutex mutex_;
    std::vector<std::pair<std::string, std::string>> resultscollection;
public:
    void addResult(const fs::path& filePath, const std::string& hashValue);
    void outputResults() const;
};

