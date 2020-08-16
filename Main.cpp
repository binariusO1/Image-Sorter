/*
2020-05-26 binariusO1
Programing challenge
Hide and extract data in images
*/

#include "WindowCoding.h"
#include "Steganography.h"
#include "SortingByColor.h"

using namespace Hideandextractdatainimages;

int app_WindowCoding(Steganography& obj)
{ 
	Application::EnableVisualStyles();  
	Application::SetCompatibleTextRenderingDefault(false);
	Hideandextractdatainimages::WindowCoding form(obj);
	Application::Run(% form);
	return 0;
}
#include <iostream>
using namespace std;
[STAThread]
int main()
{
	//Steganography stegObj;
	//app_WindowCoding(stegObj);

	string folderName = "images";
	SortingByColor obj(folderName);
	//obj.showFileName(true);
	obj.sortByBiggestColor(0,128,255,30,false);
	obj.showImagesMap();
	//obj.showFileNameRGB();
	

}
