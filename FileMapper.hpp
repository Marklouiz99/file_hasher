#pragma once
#include <stdexcept>
#include <filesystem>
#include <cstdio>    
#include <fcntl.h>   
#include <unistd.h>  
#include <sys/mman.h>

namespace fs = std::filesystem;

class FileMapper
{
private:
    int filedirectory;
    void* dataptr;
    size_t size_;
public:
    FileMapper(const fs::path& filePath);
    ~FileMapper();
    const void* data() const;
    size_t size() const;
};


