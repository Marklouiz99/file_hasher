#ifndef HASHTASK_HPP
#define HASHTASK_HPP

#include"HashTask.hpp"

#endif

HashTask::HashTask(const fs::path& filePath, ResultCollector& resultCollector): filePath{filePath}, resultCollector{resultCollector}
{

}

 void HashTask::execute() 
 {
    try {
        FileMapper mapper(filePath);
        std::string hashValue = Hasher::computeHash(mapper.data(), mapper.size());
        resultCollector.addResult(filePath, hashValue);
    } catch (const std::exception& e) {
        resultCollector.addResult(filePath, std::string("Error: ") + e.what());
    }
}