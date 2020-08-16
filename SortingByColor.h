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

class SortingByColor : protected Steganography
{
public:
	SortingByColor(const string& folder)
	{
		listFiles(folder);

	}
	~SortingByColor() = default;

public:
	void showFileName(const bool& state);
	//show files in 'name' folder
	void sortByClosestColor(const string& folder);
	//show files in 'name' folder
	void sortByBiggestColor( const int& r, const  int& g, const int& b, const int& ra,const bool&showNames);

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
	bool isshowFileName = false;
	string path;


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

