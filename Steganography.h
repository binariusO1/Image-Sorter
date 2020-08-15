#pragma once

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>				//for fastNlMeansDenoising (using with release mode (faster))
#include <fstream>							//to save file

using namespace std;
//using namespace cv;

class Steganography
{
public:
	Steganography(){
		bit = 4;
		format = 0;
	}
	~Steganography() = default;
	//b - steganography last significants bits, f - output format
	bool Coding(const std::string* nameMain, const std::string* nameHide, int b, int f);
	//b - steganography last significants bits, f - output format
	bool Decoding(const std::string * nameDecoding, int b, int f, bool d);
	bool CompareSizeOut(const std::string* nameMain, const std::string* nameHide);
	int GetImageRows(const std::string* image);
	int GetImageCols(const std::string* image); 

protected:
	void ReadChanels(cv::Mat& temp, const cv::Mat& decoding);
	bool CheckIfEmpty(const cv::Mat& image);
	bool CheckIfEmpty(const cv::Mat& main, const cv::Mat& hide);
	bool CompareSize(const cv::Mat& main, const cv::Mat& hide);

private:
	std::string imageNameMain;
	std::string imageNameHide;
	std::string imageNameDecoding;

	cv::Mat imageMain;
	cv::Mat imageHide;
	cv::Mat imageDecoding;

	void MixChanels(cv::Mat& temp, const cv::Mat& main, const cv::Mat& hide);
	int cutRGB( int value1);
	int cutRGB( int value1, int value2);
	void Denoising(cv::Mat& image);

	void SaveFile(cv::Mat& image);
	void SaveFileDecoding(const cv::Mat& image);

	int bit;
	int format;
	bool denoising;
};