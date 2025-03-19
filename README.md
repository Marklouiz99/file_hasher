# FileHasher

## Table of Contents
- [Project Description](#project-description)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Building](#building)
- [Usage](#usage)
- [Acknowledgements](#acknowledgements)
- [Contributing](#contributing)
- [License](#license)

---

## Project Description
**FileHasher** is a high-performance concurrent file hashing tool built using C++20, Linux, and OpenSSL. It recursively scans a given directory, uses memory-mapped I/O for efficient file access, and computes the SHA-256 hash of each file. The tool demonstrates modern concurrency features (such as `std::jthread`) and integrates OpenSSL for robust cryptographic operations. A user-friendly command-line interface is implemented using the header-only [cxxopts](https://github.com/jarro2783/cxxopts) library.

---

---

## Prerequisites
To build and run **FileHasher**, you need the following:
- Linux (tested on Ubuntu 22.04 LTS)
- A C++20 compiler (GCC 11 or later recommended)
- OpenSSL development libraries (`libssl-dev`)
- [cxxopts](https://github.com/jarro2783/cxxopts) (included as a header file)
- *(Optional)* Visual Studio Code for an enhanced development experience

---

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Marklouiz99/file_hasher.git
   cd file_hasher
   ```
 2. **Install OpenSSL Development Libraries:**
    On Ubuntu, run:
    ```bash
    sudo apt-get update
    sudo apt-get install libssl-dev
    ```
---
## Building
You can build the project using a terminal or Visual Studio Code.
1. **Using g++ from the Terminal:**
2. **Using Visual Studio Code**
   Create a file named tasks.json in the .vscode directory with the following content:
   ```json
   {
    "version": "2.0.0",
    "tasks": [
      {
        "label": "build filehasher",
        "type": "shell",
        "command": "g++",
        "args": [
          "-std=c++20",
          "-I./cxxopts/include",          
          "main.cpp",
          "HashTask.cpp",
          "Hasher.cpp",
          "FileMapper.cpp",
          "ResultCollector.cpp",
          "-o", "filehasher",
          "-lssl", "-lcrypto"      // Link OpenSSL libraries
          ],
        "group": {
          "kind": "build",
          "isDefault": true
          }
        }
      ]
    }
  ```
---
## Usage
After building the project, run the application from the terminal:

```bash
./filehasher -d /path/to/your/directory -v
```
Where:

-d or --directory specifies the directory to scan.
-v or --verbose enables verbose output.

---
## Acknowledgements
cxxopts: Special thanks to Jarrod Hawkins for developing the excellent header-only cxxopts library for command-line parsing.
OpenSSL: Thanks to the OpenSSL team for providing robust cryptographic functions.
---
## Contributing
Contributions are welcome! Please fork the repository, make improvements, and open a pull request. For suggestions or bug reports, feel free to open an issue on GitHub.
---
## License
This project is licensed under the MIT License. See the LICENSE file for details.
---

      
    
