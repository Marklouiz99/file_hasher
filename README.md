# FileHasher
FileHasher is a high-performance concurrent file hashing tool built using C++20, Linux, and OpenSSL. It recursively scans a given directory, uses memory-mapped I/O for efficient file access, and computes the SHA-256 hash of each file. The tool features a user-friendly command-line interface implemented with the header-only cxxopts library.

Features
Concurrent Processing: Uses modern C++20 concurrency features (like std::jthread) to process files in parallel.
Efficient I/O: Leverages POSIX mmap for fast, efficient file reading.
Robust Error Handling: Gracefully handles errors such as missing files or permission issues.
User-Friendly CLI: Command-line options are parsed using the header-only cxxopts library.
OpenSSL Integration: Uses OpenSSL to compute SHA-256 hashes.
Requirements
Linux (tested on Ubuntu 22.04 LTS)
C++20 Compiler (GCC 11 or later recommended)
OpenSSL (libssl-dev)
cxxopts (included as a header file; see installation instructions)
(Optional) CMake for a more robust build system
Installation
Clone the Repository:

bash
Copy
Edit
git clone https://github.com/yourusername/FileHasher.git
cd FileHasher
Download cxxopts:

If not already included, clone or download cxxopts and place the cxxopts.hpp file into an include folder in your project:

bash
Copy
Edit
mkdir include
cd include
git clone https://github.com/jarro2783/cxxopts.git
cp cxxopts/include/cxxopts.hpp .
cd ..
Building
You can build the project using a terminal or Visual Studio Code.

Using g++ from the Terminal
bash
Copy
Edit
g++ -std=c++20 -I./include filehasher.cpp -o filehasher -lssl -lcrypto
Using Visual Studio Code
Create a file named tasks.json in the .vscode directory with the following content:

json
Copy
Edit
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build filehasher",
      "type": "shell",
      "command": "g++",
      "args": [
        "-std=c++20",
        "-I./include",
        "filehasher.cpp",
        "-o", "filehasher",
        "-lssl", "-lcrypto"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
Running
After building, run the application from the terminal:

bash
Copy
Edit
./filehasher -d /path/to/your/directory -v
Where:

-d or --directory specifies the directory to scan.
-v or --verbose enables verbose output.
Acknowledgements
cxxopts: Special thanks to Jarrod Hawkins for developing the excellent header-only cxxopts library for command-line parsing.
OpenSSL: Thanks to the OpenSSL team for providing robust cryptographic functions.
License
This project is licensed under the MIT License. See the LICENSE file for details.
