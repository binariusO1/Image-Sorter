#include "Steganography.h"

bool Steganography::Coding( const std::string * nameMain, const std::string*nameHide, int b=4, int f=0)
{
	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cout << "coding" << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	this->bit = b;
	this->format = f;

	cv::String SnameMain(*nameMain);
	cv::String SnameHide(*nameHide);

	imageMain = cv::imread(cv::samples::findFile(SnameMain), cv::IMREAD_COLOR);
	imageHide = cv::imread(cv::samples::findFile(SnameHide), cv::IMREAD_COLOR);

	if (!CheckIfEmpty(imageMain, imageHide))
		return 0;

	if (!CompareSize(imageMain, imageHide))
		return 0;

	//NOTE: copy constructor creates only duplicate adress, we need to clone
	cv::Mat* temp = new cv::Mat;
	*temp = imageMain.clone();

	MixChanels(*temp,imageMain, imageHide);

	//quality info
	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cv::Vec3b colorMain = temp->at<cv::Vec3b>(1, 1);
	cout << "(1,1)temp:" << static_cast<int>(colorMain[0]) << endl;
	cv::Vec3b ch2 = imageMain.at<cv::Vec3b>(1, 1);
	cout << "(1,1)main:" << static_cast<int>(ch2[0]) << endl;
	cv::Vec3b ch = imageHide.at<cv::Vec3b>(1, 1);
	cout << "(1,1)hide:" << static_cast<int>(ch[0]) << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	//first bits of blue give us an information about last significations bits
	//(facilitation to decoding)
	cv::Vec3b& color = temp->at<cv::Vec3b>(0, 0);
	cv::Vec3b colorMain2 = imageMain.at<cv::Vec3b>(0, 0);
	int t = this->bit;
	this->bit = 4;
	color[0] = cutRGB(static_cast<int>(colorMain2[0]), (t << 4));
	this->bit = t;

	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cout << "point (0,0): " << static_cast<int>(color[0]) << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	SaveFile(*temp);
	return 1;
}
bool Steganography::Decoding(const std::string * nameDecoding, int b = 4, int f = 0, bool d = false)
{
	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cout << "decoding" << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	this->bit = b;
	this->format = f;
	this->denoising = d;

	cv::String SnameDecoding(*nameDecoding);
	imageDecoding = cv::imread(cv::samples::findFile(SnameDecoding), cv::IMREAD_COLOR);

	if (!CheckIfEmpty(imageDecoding))
		return 0;

	cv::Mat* temp = new cv::Mat;
	*temp = imageDecoding.clone();
	ReadChanels(*temp, imageDecoding);

	//quality info
	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cv::Vec3b colorMain = temp->at<cv::Vec3b>(1, 1);
	cout << "(1,1)temp:" << static_cast<int>(colorMain[0]) << endl;
	cv::Vec3b ch2 = imageDecoding.at<cv::Vec3b>(1, 1);
	cout << "(1,1)decod:" << static_cast<int>(ch2[0]) << endl;
	cv::Vec3b color0 = temp->at<cv::Vec3b>(0, 0);
	cout << "(0,0)temp:" << static_cast<int>(color0[0]) << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	if (this->denoising == true)
		Denoising(*temp);

	SaveFileDecoding(*temp);
	return 1;
}
bool Steganography::CheckIfEmpty(const cv::Mat& image)
{
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	return 1;
}
bool Steganography::CheckIfEmpty(const cv::Mat& main, const cv::Mat& hide)
{
	if (main.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	if (hide.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return 0;
	}
	return 1;
}
bool Steganography::CompareSize(const cv::Mat & main, const cv::Mat& hide)
{
	if (main.rows < hide.rows || main.cols < main.cols){
		cout << "Unable to create by size or throw exception" << endl;
		return 0;
	}
	else {
		return 1;
	}
}
bool Steganography::CompareSizeOut(const std::string* nameMain, const std::string* nameHide)
{
	cv::String SnameMain(*nameMain);
	cv::String SnameHide(*nameHide);
	imageMain = cv::imread(cv::samples::findFile(SnameMain), cv::IMREAD_COLOR);
	imageHide = cv::imread(cv::samples::findFile(SnameHide), cv::IMREAD_COLOR);
	if (!CompareSize(imageMain, imageHide))
		return 0;
	return 1;
}
void Steganography::MixChanels(cv::Mat& temp, const cv::Mat& main, const cv::Mat& hide)
{
	int temp_rows = hide.rows;
	int temp_cols = hide.cols;

	for (int i = 0; i < static_cast<int>(temp_rows); i++)	//y
	{
		for (int j = 0; j < static_cast<int>(temp_cols); j++)	//x
		{
			cv::Vec3b &color = temp.at<cv::Vec3b>(i, j);
			cv::Vec3b colorMain = main.at<cv::Vec3b>(i, j);
			cv::Vec3b colorHide = hide.at<cv::Vec3b>(i, j);
			color[0] = cutRGB(static_cast<int>(colorMain[0]) , static_cast<int>(colorHide[0]));
			color[1] = cutRGB(static_cast<int>(colorMain[1]) , static_cast<int>(colorHide[1]));
			color[2] = cutRGB(static_cast<int>(colorMain[2]) , static_cast<int>(colorHide[2]));
		}
	}
}
int Steganography::cutRGB(int value1, int value2)
{
	int num1[8]{};
	int num2[8]{};

	int t1 = value1;
	int t2 = value2;
	int rval = 0;

	unsigned i = 0,j=1;
	for (i = 0; i < 8; i++){
		num1[i] = t1 % 2;
		t1 = t1 / 2;
	}
	for (i = 0; i < 8; i++){
		num2[i] = t2 % 2;
		t2 = t2 / 2;
	}
	for (i = 8 - this->bit; i < 8; i++,j=j*2){
		rval += num2[i] * j;
	}
	for (i = (this->bit); i < 8; i++, j = j * 2){
		rval += num1[i] * j;
	}
	return rval;
	/*
	explanation:
 	t1 = 231;
	t2 = 193;
	--
	num1[]:
	7	6	5	4	3	2	1	0
	1	1	1	0	0	1	1	1
	num2[]:
	7	6	5	4	3	2	1	0
	1	1	0	0	0	0	0	1
	---
	(1)
	7	6	5	4	3	2	1	0
	124	64	32	16	8	4	2	1
	0	0	0	0	8	4	0	0	= 12
	(2)
	7	6	5	4	3	2	1	0
	124	64	32	16	8	4	2	1
	124	64	32	0	0	4	0	0	= 224 + 12 = 236
	*/
}
int Steganography::cutRGB(int value1)
{
	int num1[8]{};
	int num2[8]{};

	int t1 = value1;

	int rval = 0;
	unsigned i = 0, j = 1;
	for (i = 0; i < 8; i++) {
		num1[i] = t1 % 2;
		t1 = t1 / 2;
	}
	for (i = 0; i < (8-this->bit); i++, j = j * 2) {
		rval += 0;
	}
	for (i = 0; i < this->bit; i++, j = j * 2) {
		rval += num1[i] * j;
	}
	return rval;

	/*
	explanation:
 	t1 = 228;
	this->bit = 4;
	--
	num1[]:
	7	6	5	4	3	2	1	0
	1	1	1	0	0	1	0	0
	num2[]:
	7	6	5	4	3	2	1	0
	.	.	.	.	.	.	.	.	(zeros)
	---
	(1)
	7	6	5	[4]	3	2	1	0
	124	64	32	16	8	4	2	1
	.	.	.	.	0	0	0	0	= 0
	(2)
	7	6	5	4	3	2	1	0
	124	64	32	16	8	4	2	1
	0	64	0	0	0	0	0	0	= 64
	*/
}
void Steganography::ReadChanels(cv::Mat& temp, const cv::Mat& decoding)
{
	int temp_rows = decoding.rows;
	int temp_cols = decoding.cols;

	if (bit == 0) {
		cv::Vec3b color = decoding.at<cv::Vec3b>(0, 0);
		int code = static_cast<int>(color.val[0]);
		cout << "decoding point(0,0): " << code << endl;

		int num1[8]{};
		unsigned i = 0, j = 1;
		for (i; i < 8; i++) {
			num1[i] = code % 2;
			code = code / 2;
		}
		code = 0;
		for (i = 0; i < 3; i++, j = j * 2) {
			code += num1[i] * j;
		}
		
		bit = code;
		cout << "deduced bit: " << bit << endl;
	}

	for (int i = 0; i < static_cast<int>(temp_rows); i++)	//y
	{
		for (int j = 0; j < static_cast<int>(temp_cols); j++)	//x
		{
			cv::Vec3b& color = temp.at<cv::Vec3b>(i, j);
			cv::Vec3b colorDecoding = decoding.at<cv::Vec3b>(i, j);
			color[0] = cutRGB( static_cast<int>(colorDecoding[0]) );
			color[1] = cutRGB( static_cast<int>(colorDecoding[1]) );
			color[2] = cutRGB( static_cast<int>(colorDecoding[2]) );
		}
	}
}
void Steganography::Denoising(cv::Mat& image)
{
	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cout << "start denoising..." << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v

	medianBlur(image, image, 3);
	fastNlMeansDenoising(image, image, 25.0, 7, 21);

	//^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^
	cout << "...denoising end" << endl;
	//v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v-v
}
void Steganography::SaveFile(cv::Mat& image)
{
	std::vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
	compression_params.push_back(100);

	if (format == 1)
		cv::imwrite("output.png", image);
	else if(format == 2)
		cv::imwrite("output.bmp", image);
	else {
		cv::imwrite("output.jpg", image, compression_params);
	}
}
void Steganography::SaveFileDecoding(const cv::Mat& image)
{
	if (format == 1)
		cv::imwrite("output_decoding.png", image);
	else if (format == 2)
		cv::imwrite("output_decoding.bmp", image);
	else
		cv::imwrite("output_decoding.jpg", image);
}
int Steganography::GetImageRows(const std::string* image)
{
	cv::String Sname(*image);
	cv::Mat* temp = new cv::Mat;
	*temp = cv::imread(cv::samples::findFile(Sname), cv::IMREAD_COLOR);
	if (!CheckIfEmpty(*temp))
		return 0;
	return temp->rows;
}
int Steganography::GetImageCols(const std::string* image)
{
	cv::String Sname(*image);
	cv::Mat* temp = new cv::Mat;
	*temp = cv::imread(cv::samples::findFile(Sname), cv::IMREAD_COLOR);
	if (!CheckIfEmpty(*temp))
		return 0;
	return temp->cols;
}

//-------------------------------------------------------------------------------------------------
	//remainings
	//cv::Mat temp(imageMain);
	/*
	cv::Vec3b& colorMain = imageMain.at<cv::Vec3b>(0, 0);
	cv::Vec3b& colorHide = imageHide.at<cv::Vec3b>(0, 0);
	cout << static_cast<int>( colorMain[0])<< " " << static_cast<int>(colorMain[1]) << " " << static_cast<int>(colorMain[2]) << endl;
	cout << static_cast<int>( colorHide[0] )<< " " << static_cast<int>(colorHide[1]) << " " << static_cast<int>(colorHide[2]) << endl;
	*/
	/*
	cout << cutRGB(static_cast<int>(colorMain[0])) << " "
		<< cutRGB(static_cast<int>(colorMain[1])) << " "
		<< cutRGB(static_cast<int>(colorMain[2])) << endl;
	cout << cutRGB(static_cast<int>(colorHide[0])) << " "
		<< cutRGB(static_cast<int>(colorHide[1])) << " "
		<< cutRGB(static_cast<int>(colorHide[2])) << endl;
		*/
		//cout << cutRGB(static_cast<int>(colorMain[0]), static_cast<int>(colorHide[0])) << endl;

	//IMPORTANT: HEIGHT , WIDTH
	/*
	cv::Scalar color = temp.at<uchar>(i, j);
	uchar blue = static_cast<uchar>(color.val[0]);
	uchar red = static_cast<uchar>(color.val[1]);
	uchar green = static_cast<uchar>(color.val[2]);
	cv::Scalar t = imageMain.at<uchar>(i, j);
	temp.at<uchar>(cv::Point(i, j)) = t;
	*/
	//cout << static_cast<unsigned>(blue) << " " << static_cast<unsigned>(red) << " " << static_cast<unsigned>(green) << endl;