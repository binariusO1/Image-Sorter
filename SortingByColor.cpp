#include "SortingByColor.h"
//#include <filesystem>	//C++ 17

using namespace std;
namespace fs = std::filesystem;

void SortingByColor::sortByBiggestColor(const int&r, const  int&g, const int&b, const int&ra, const bool&fileName)
{
    this->R = r;
    this->G = g;
    this->B = b;
    this->RANGE = ra;
    this->isshowFileName = fileName;
    sortingByBiggest();
}

void SortingByColor::sortingByBiggest() {
    cout << "processing... " << endl;
    for (auto x : this->imagesMap) {

        cv::String filename(x.first);
        cv::Mat fileMat = cv::imread(cv::samples::findFile(filename), cv::IMREAD_COLOR);

        int temp_rows = fileMat.rows;
        int temp_cols = fileMat.cols;
        double pixel = static_cast<double>(1 / (double)(temp_rows * temp_cols));
        //cout << pixel << endl;
        double sumValue = 0;
        int cR, cB, cG, rR,rB,rG,sR,sG,sB;
        for (int i = 0; i <static_cast<int>(temp_rows); i++)	//y
        {
            for (int j = 0; j < static_cast<int>(temp_cols); j++)	//x
            {
                cv::Vec3b temp = fileMat.at<cv::Vec3b>(i, j);
                cB = (static_cast<int>(temp[0])); //BLUE
                cG = (static_cast<int>(temp[1])); //GREEN
                cR = (static_cast<int>(temp[2])); //RED
                rR = ((((this->R-cR)>0 ? this->R - cR : (-1)*(this->R - cR))));
                sR = (rR <= RANGE) ? (rR - RANGE) * (-1) : -1;
                //cout << cR << " "<< rR<< " "<< sR << " ; ";
                rB = ((((this->B - cB) > 0 ? this->B - cB : (-1) * (this->B - cB))));
                sB = (rB <= RANGE) ? (rB - RANGE) * (-1) : -1;
                // cout << cB << " " << rB << " " << sB << " ; ";
                rG = ((((this->G - cG) > 0 ? this->G - cG : (-1) * (this->G - cG))));
                sG = (rG <= RANGE) ? (rG - RANGE) * (-1) : -1;
                //cout << cG << " " << rG << " " << sG << " ; ";

                if (sR != -1 && sB != -1 && sG != -1)
                {
                    sumValue += static_cast<double>(sR + sB + sG)*pixel*100;
                }
               //cout << " "<<sumValue;
                //cout << endl;

            }
        }
        imagesMap[filename] = sumValue;
        if (this->isshowFileName) {
            //showFileNameP(x.first);
            //cout << "Value of color: " << sumValue << endl;
        }

    }
    invertMap<string, double>();



}

void SortingByColor::listFiles(const string& folder)
{
    try {
        cout << "(INFO) | SortingByColor.cpp | listFiles() | Files in folder: " << endl;
        fs::path curPath = fs::current_path();
        this->path = curPath.u8string() + "\\" + folder;
        for (const auto& entry : fs::directory_iterator(path))
        {
            string pathFile = entry.path().u8string();
            if (checkExtension(pathFile) )
            {

                imagesMap.insert(pair<string, int>(pathFile,0));

            }
        }
      }
    catch (const std::exception& e)
    {
        cout << "(EXCEPTION) | SortingByColor.cpp | listFiles() | Unable to find path" << endl;
    }
}

void SortingByColor::getMapRGB(const string& name)
{
    cv::String filename(name);
    cv::Mat fileMat = cv::imread(cv::samples::findFile(filename), cv::IMREAD_COLOR);
    //RGB color;
    int temp_rows = fileMat.rows;
    int temp_cols = fileMat.cols;

    if (!CheckIfEmpty(fileMat))
        cout << "(EXCEPTION) | SortingByColor.cpp | readChannels() | File is empty" << endl;

    for (int i = 0; i < static_cast<int>(temp_rows); i++)	//y
    {
        for (int j = 0; j < static_cast<int>(temp_cols); j++)	//x
        {
            cv::Vec3b temp = fileMat.at<cv::Vec3b>(i, j);

           // color.red = (static_cast<int>(temp[0]));
            //color.green = (static_cast<int>(temp[1]));
            //color.blue = (static_cast<int>(temp[2]));

        }
    }

}

bool SortingByColor::checkExtension(const string& filename)
{
    try {
        std::size_t found;
        found = filename.find_last_of(".");
        if (found >= 500)
            return false;
        string extenstion((filename.begin() + filename.find_last_of(".") + 1), filename.end());
        std::for_each(extenstion.begin(), extenstion.end(), [](char& c) {
            c = ::toupper(c);
            });
        for (std::list<string>::iterator it = extenstionList.begin(); it != extenstionList.end(); it++)
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
        cout << "(EXCEPTION) | SortingByColor.cpp | checkExtension() | Unable to find path" << endl;
    }
}

void SortingByColor::showFileName(const bool& state) 
{

    this->isshowFileName = state;
}

void SortingByColor::showFileNameP(const string& filename)
{

    //for (auto& x : imagesMap) {
        //string filename = x.first;
        cout << filename << endl;
        std::size_t found;
        found = filename.find_last_of("\\");
        if (found != std::string::npos)
        {
            string filenameShort((filename.begin() + found + 1), filename.end());
            cout << filenameShort << endl;
            //string* wsk = filename;
            cout << "XY: "<< GetImageRows(&filename) << " " << GetImageCols(&filename) << endl;
        }
   // }
}

void SortingByColor::showFileNameRGB()
{
    for (auto& x : imagesMap) 
    {
            string name = x.first;
            cv::String filename(name);
            // cout << filename << endl;
            std::size_t found;
            found = filename.find_last_of("\\");
            if (found != std::string::npos)
            {
                string filenameShort((filename.begin() + found + 1), filename.end());
                cout << filenameShort << endl;
                //string* wsk = filename;
                cout << GetImageRows(&filename) << " " << GetImageCols(&filename) << endl;
            }



            cv::Mat fileMat = cv::imread(cv::samples::findFile(filename), cv::IMREAD_COLOR);
            //cout << sizeof(fileMat) << endl;
            int temp_rows = fileMat.rows;
            int temp_cols = fileMat.cols;

            if (!CheckIfEmpty(fileMat))
                cout << "(EXCEPTION) | SortingByColor.cpp | readChannels() | File is empty" << endl;

            for (int i = 0; i < static_cast<int>(temp_rows); i++)	//y
            {
                for (int j = 0; j < static_cast<int>(temp_cols); j++)	//x
                {
                    cv::Vec3b color = fileMat.at<cv::Vec3b>(i, j);
                    cout << "R: " << (static_cast<int>(color[0]));
                    cout << " G: " << (static_cast<int>(color[1]));
                    cout << " B: " << (static_cast<int>(color[2]));
                    cout << endl;
                }
            }
       }


}

void SortingByColor::showImagesMap()
{
    for (auto &x : this->imagesMap) {
        cout << x.first << " ; " << x.second << endl;
    }
}

template<typename K, typename V>
void SortingByColor::invertMap()
{
    cout << "copying... " << endl;
    std::multimap<V, K, greater <double> > multimap;

    for (auto const& pair : this->imagesMap) {
        multimap.insert(std::make_pair(pair.second, pair.first));
    }
    int j = 1;
    for (auto const& pair : multimap) {
       std::cout << j << ") "<<'{' << pair.first << "," << pair.second << '}' << '\n';
       j++;
    }

    this->imagesMap.clear();

    string new_folder;
    int i = 1;

    new_folder = this->path + "\\" + "sort";

    
    if (fs::exists(new_folder))
    {
        std::uintmax_t n = fs::remove_all(new_folder);
        std::cout << "Deleted " << n << " files or directories\n";
    }
    fs::create_directories(new_folder);
    
    cout << "enter to loop: " << endl;
    for (auto const& pair : multimap)
    {
        std::size_t found;
        string path,old_path;
        old_path = pair.second;
        found = old_path.find_last_of("\\");
        if (found != std::string::npos)
        {

            string path(old_path.begin(), old_path.begin() + found +1);
            string newFilename = new_folder + "\\" + "image" + to_string(i);
            this->imagesMap.insert(std::make_pair(newFilename, pair.first));

            std::size_t found;
            found = pair.second.find_last_of(".");
            string extenstion((pair.second.begin() + pair.second.find_last_of(".")), pair.second.end());

            cout << pair.second << "  na:  " << newFilename  + extenstion << endl;
            fs::copy(pair.second, newFilename + extenstion);
        }
        i++;
        cout << "next" << endl;
    }

    //for (auto const& pair : this->imagesMap) {
    //    std::cout << '{' << pair.first << "," << pair.second << '}' << '\n';
   // }


}