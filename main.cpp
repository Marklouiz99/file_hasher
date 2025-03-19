#include"cxxopts/include/cxxopts.hpp"
#include"HashTask.hpp"
#include<thread>

struct Configuration {
    std::string directory;
    bool verbose;
};

Configuration parseArguments(int argc, char* argv[]) {
    cxxopts::Options options("FileHasher", "Concurrent file hashing tool");
    options.add_options()
        ("d,directory", "Directory to scan for files", cxxopts::value<std::string>())
        ("v,verbose", "Enable verbose output", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print help");
    
    auto result = options.parse(argc, argv);
    
    if (result.count("help") || !result.count("directory")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    
    Configuration config;
    config.directory = result["directory"].as<std::string>();
    config.verbose = result["verbose"].as<bool>();
    return config;
}

int main(int argc, char* argv[]) {
    Configuration config = parseArguments(argc, argv);
    
    std::cout << "Scanning directory: " << config.directory << "\n";
    if (config.verbose) {
        std::cout << "Verbose mode enabled.\n";
    }
    
    std::vector<fs::path> filePaths;
    try {
    for (const auto& entry : fs::recursive_directory_iterator(config.directory)) {
        if (fs::is_regular_file(entry.path()))
            filePaths.push_back(entry.path());
    }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << "\n";
        exit(1);
    }

    if (config.verbose) {
        std::cout << "Found " << filePaths.size() << " files.\n";
    }
    
    ResultCollector collector;
    
    std::vector<HashTask> tasks;
    for (const auto& path : filePaths) {
        tasks.emplace_back(path, collector);
    }
    
    std::vector<std::jthread> threads;
    for (auto& task : tasks) {
        threads.emplace_back([&task]() {
            task.execute();
        });
    }
    collector.outputResults();
    
    return 0;
}