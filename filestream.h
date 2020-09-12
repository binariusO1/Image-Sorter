#pragma once

#include <list>
#include <string>
#include <iostream>
#include <fstream>							//to save file
#include <filesystem> //C++ 17

/*
namespace fst {

	namespace {
		//resources

	}
}
*/

class filestream
{
	public:
		filestream() {}
		void filename(const  char* name);
		void listFiles(const std::string& foldername);
		bool checkExtension(const std::string& filename);
	protected:

	private:
		std::list<std::string> extenstionList = { "BMP", "JPEG", "JPG", "PNG" };
		std::string path;			//Path of work folder
		std::string folderName;		//Name of work folder



};



