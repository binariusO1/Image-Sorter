#include "SortingByColor.h"
#include <filesystem>	//C++ 17

using namespace std;
namespace fs = std::filesystem;

void SortingByColor::listFiles(const string& folder)
{
    try {
        cout << "(INFO) | SortingByColor.cpp | listFiles() | Files in folder: " << endl;
        fs::path curPath = fs::current_path();
        std::string path = curPath.u8string() + "\\" + folder;
        for (const auto& entry : fs::directory_iterator(path))
        {
            string temp = entry.path().u8string();
            if (checkExtension(temp) )
            {
                std::size_t found;
                found = temp.find_last_of("\\");
                if (found != std::string::npos)
                {
                    string filename((temp.begin() + found+1), temp.end());
                    cout << filename << endl;
                    imagesList.push_back(filename);
                }
            }
        }
        //throw 42;
    }
    catch (const std::exception& e)
    {
        cout << "(EXCEPTION) | SortingByColor.cpp | listFiles() | Unable to find path" << endl;
    }
}
bool SortingByColor::checkExtension(const string& filename)
{
        std::size_t found;
        found = filename.find_last_of(".");
        //if (found != std::string::npos)
            //td::cout << "place: " << found << '\n';
        //string::iterator it = temp.begin() + temp.find_last_of(".");
        string extenstion((filename.begin() + filename.find_last_of(".") + 1), filename.end());
        std::for_each(extenstion.begin(), extenstion.end(), [](char& c) {
            c = ::toupper(c);
            });
        for (std::list<string>::iterator it = extenstionList.begin(); it != extenstionList.end(); it++)
        {

            if (extenstion.compare(*it) == 0)
            {
                //cout << extenstion << " " << *it << endl;
                return true;
            }
        }
        return false;
}
