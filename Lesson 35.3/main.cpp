#include <iostream>
#include <filesystem>
#include <memory>


auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path& path,
           const std::string extension) {

            std::vector<std::string> files;
            for (auto& p: std::filesystem::recursive_directory_iterator(path)) {
                auto ext = p.path().extension();
                if (p.is_regular_file() && ext.compare(extension) == 0) {
                    files.push_back(p.path().filename().generic_string());
                }
            }

            std::unique_ptr<std::vector<std::string>> uptr =
                    std::make_unique<std::vector<std::string>> (files.begin(), files.end());
            return uptr;
        };

int main() {

    auto path = std::filesystem::path("C:/Devs/cpp/api");
    auto r = recursiveGetFileNamesByExtension(path, ".txt");
    for (auto &file: *r) {
        std::cout << file << std::endl;
    }
}