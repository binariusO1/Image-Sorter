#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>				//for fastNlMeansDenoising (using with release mode (faster))
#include <fstream>							//to save file
#include "Steganography.h"					//for inherit
#include <list>
//
// KISS, DRY, YAGNI, TDA
// SOLID

using namespace std;
using namespace cv;

class SortingByColor : protected Steganography
{
public:
	SortingByColor()
	{
		
	}
	~SortingByColor() = default;

	//show files in 'name' folder
	void listFiles(const string & folder);
protected:
	list<string> extenstionList = { "BMP", "JPEG", "JPG", "PNG" };
	
	bool checkExtension(const string& filename);
private:
	list<string> imagesList;

};

