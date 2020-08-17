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
	while (true)
	{
		//Steganography stegObj;
//app_WindowCoding(stegObj);
		string folderName;
		//cin >> folderName;
		folderName = "images";
		if (!folderName.empty())
			folderName = "\\" + folderName;
		SortingByColor obj(folderName);
		//obj.showFileName(true);

		color color[5] = { 256,256,256 };
		int num = 1;
		cout << "number of colors: " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++)
		{
			cout << "color" << i + 1 << ":" << endl;
			cin >> color[i].R >> color[i].G >> color[i].B;
		}
		cout << "Range (0-255): " << endl;
		int range = 0;
		cin >> range;
		//1 kolor range ~30, 2 kolory range 10-15
		cout << "Percent good (0-100) [optimum 0.1]: " << endl;
		double per = 0;
		cin >> per;
		cout << "Multiple (lower-faster | 0 - most accurate and slowest) [optimum 1 000 000]: " << endl;
		int mul = 0;
		cin >> mul;
		obj.sortByBiggestColor(mul,per,range, true, color[0], color[1], color[2], color[3]);
		//obj.showImagesMap();
		//obj.showFileNameRGB();
	}

	

}
