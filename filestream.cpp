#include "filestream.h"

//#include <string>

void filestream::listFiles(const std::string& foldername)
{
    try {
        std::cout << "(INFO) | SortingByColor.cpp | listFiles() | Files in folder: " << std::endl;
        std::filesystem::path curPath = std::filesystem::current_path();
        this->path = curPath.u8string() + foldername;
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            std::string pathFile = entry.path().u8string();
            if (checkExtension(pathFile))
            {

               //++ this->imagesMap.insert(std::pair<std::string, int>(pathFile, 0));

            }
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "(EXCEPTION) | SortingByColor.cpp | listFiles() | Unable to find path " << e.what() << std::endl;
    }
}

bool filestream::checkExtension(const std::string& filename)
{
    try {
        std::size_t found;
        found = filename.find_last_of(".");
        if (found >= 500)
            return false;
        std::string extenstion((filename.begin() + filename.find_last_of(".") + 1), filename.end());
        std::for_each(extenstion.begin(), extenstion.end(), [](char& c) {
            c = ::toupper(c);
            });
        for (std::list<std::string>::iterator it = extenstionList.begin(); it != extenstionList.end(); it++)
        {

            if (extenstion.compare(*it) == 0)
            {
                // cout << extenstion << " " << *it << endl;
                return true;
            }
        }
        return false;
    }
    catch (const std::exception& e)
    {
        std::cout << "(EXCEPTION) | SortingByColor.cpp | checkExtension() | Unable to find path " << e.what() << std::endl;
    }
}

void filestream::addFolderName(const std::string& foldername) {
    this->folderName = foldername;
}