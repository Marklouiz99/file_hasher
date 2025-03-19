#ifndef FILEMAPPER_HPP
#define FILEMAPPER_HPP

#include"FileMapper.hpp"

#endif

FileMapper::FileMapper(const fs::path& filePath) : filedirectory{-1}, dataptr{nullptr}, size_{0} {
        filedirectory = open(filePath.c_str(), O_RDONLY);
        if (filedirectory == -1) {
            throw std::runtime_error("Failed to open file: " + filePath.string());
        }
        // Get file size
        size_ = lseek(filedirectory, 0, SEEK_END);
        if (size_ == static_cast<size_t>(-1)) {
            close(filedirectory);
            throw std::runtime_error("Failed to determine file size: " + filePath.string());
        }
        // Reset file offset to beginning
        lseek(filedirectory, 0, SEEK_SET);
        // Memory-map the file
        dataptr = mmap(nullptr, size_, PROT_READ, MAP_PRIVATE, filedirectory, 0);
        if (dataptr == MAP_FAILED) {
            close(filedirectory);
            throw std::runtime_error("Failed to mmap file: " + filePath.string());
        }
}

FileMapper::~FileMapper(){
    if (dataptr && dataptr != MAP_FAILED) {
            munmap(dataptr, size_);
        }
        if (filedirectory != -1) {
            close(filedirectory);
        }
}

const void* FileMapper::data() const{
    return dataptr;
}

size_t FileMapper::size() const { 
    return size_; 
}

