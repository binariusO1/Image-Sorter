#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>				//for fastNlMeansDenoising (using with release mode (faster))
#include <fstream>							//to save file
#include "Steganography.h"					//for inherit
#include <map>
#include <filesystem> //C++ 17
//
// KISS, DRY, YAGNI, TDA
// SOLID

using namespace std;
//using namespace cv;
struct color
{
	int R;
	int G;
	int B;
};

class SortingByColor : protected Steganography
{
public:
	SortingByColor(const string& folder)
	{
		this->folderName = folder;
		listFiles(folder);

	}
	~SortingByColor() = default;

public:
	void showFileName(const bool& state);

	void sortByClosestColor(const string& folder);

	void sortByBiggestColor(const int& mul, const double& per, const int& ra, const bool& showNames, const color& c1, const color& c2 = { 256,256,256 }, const color& c3 = { 256,256,256 }, const color& c4 = { 256,256,256 }, const color& c5 = { 256,256,256 });

	void showImagesMap();

	//noo
	void showFileNameRGB();

protected:
	list<string> extenstionList = { "BMP", "JPEG", "JPG", "PNG" };

	bool checkExtension(const string& filename);
private:
	map<string, double> imagesMap;
	multimap<double, string> multimap;
	int R;
	int G;
	int B;
	int RANGE;
	int MULTIPLE;
	double PERCENT;
	bool isshowFileName = false;
	string path,folderName;
	color col[5];

	void listFiles(const string& folder);
	template<typename K, typename V>
	void invertMap();
	void sortingByBiggest();
	void showFileNameP(const string& filename);

	//
	//
	void getMapRGB(const string& name);

	//unique_ptr<Image> uni = make_unique<Image>();
};



