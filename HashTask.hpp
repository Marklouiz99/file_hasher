#pragma once
#include"FileMapper.hpp"
#include"Hasher.hpp"
#include"ResultCollector.hpp"

class HashTask{
private:
    fs::path filePath;
    ResultCollector& resultCollector;
public:
    HashTask(const fs::path& filePath, ResultCollector& resultCollector);
    void execute();
};