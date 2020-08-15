#pragma once

#include <msclr\marshal_cppstd.h>	//To convert String^ to string
#include "Steganography.h"
#include <string>
namespace Hideandextractdatainimages 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Drag & Drop
	using namespace System::Collections::Generic;
	//Path::GetFileName(file);
	using namespace System::IO;

	public ref class WindowCoding : public System::Windows::Forms::Form
	{
		public:
			WindowCoding(Steganography & obj) {
				InitializeComponent();
				this->check_ext_C_Main = -1;
				this->check_ext_C_Hide = -1;
				this->check_ext_D = -1;
				this->check_size = false;
				this->Denoising = false;
				sptr = &obj;
			}
		protected:
			~WindowCoding(){
				if (components){
					delete components;
				}
			}

//************************************************************
//		WINDOW FORM ELEMENTS
//************************************************************
	//-------------------------------------------------
	//		OTHER
	//-------------------------------------------------
	private: 
			System::Windows::Forms::TabControl^ tabControl1;
			System::Windows::Forms::TabPage^ tabPage1;
			System::Windows::Forms::TabPage^ tabPage2;
			System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label_author;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::ToolTip^ toolTip4;
	//-------------------------------------------------
	//		C
	//-------------------------------------------------
	private: System::Windows::Forms::ListBox^ C_Main_listBox;
	private: System::Windows::Forms::GroupBox^ C_Main_groupBox;
	private: System::Windows::Forms::Label^ C_Main_label_Height;
	private: System::Windows::Forms::Label^ C_Main_label_Width;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ C_button_Process;
	private: System::Windows::Forms::GroupBox^ C_Hide_groupBox;
	private: System::Windows::Forms::Label^ C_Hide_label_Height;
	private: System::Windows::Forms::Label^ C_Hide_label_Width;
	private: System::Windows::Forms::ListBox^ C_Hide_listBox;
	private: System::Windows::Forms::Label^ C_Options_label_bits;
	private: System::Windows::Forms::ComboBox^ C_Options_ComboBox_bits;
	private: System::Windows::Forms::Label^ C_Options_label_note;
	private: System::Windows::Forms::GroupBox^ C_Options_GroupBox;
	private: System::Windows::Forms::ComboBox^ C_Options_ComboBox_format;
	private: System::Windows::Forms::Label^ C_Options_label_format;
	private: System::Windows::Forms::Label^ C_Hide_label_Heightpx;
	private: System::Windows::Forms::Label^ C_Hide_label_Widthpx;
	private: System::Windows::Forms::Label^ C_Main_label_Heightpx;
	private: System::Windows::Forms::Label^ C_Main_label_Widthpx;
	//-------------------------------------------------
	//		D
	//-------------------------------------------------
	private: System::Windows::Forms::Button^ D_button_Process;
	private: System::Windows::Forms::GroupBox^ D_groupBox;
	private: System::Windows::Forms::Label^ D_label_Height;
	private: System::Windows::Forms::Label^ D_label_Width;
	private: System::Windows::Forms::GroupBox^ D_options_groupBox;
	private: System::Windows::Forms::ComboBox^ D_options_comboBox_format;
	private: System::Windows::Forms::Label^ D_options_label_format;
	private: System::Windows::Forms::ComboBox^ D_options_comboBox_bits;
	private: System::Windows::Forms::Label^ D_options_label_note;
	private: System::Windows::Forms::Label^ D_options_label_bits;
	private: System::Windows::Forms::Label^ D_label_Heightpx;
	private: System::Windows::Forms::Label^ D_label_Widthpx;
	private: System::Windows::Forms::CheckBox^ D_options_checkBox;
	private: System::Windows::Forms::ListBox^ D_listBox;

#pragma region Windows Form Designer generated code
	private:
		void InitializeComponent(void);

//************************************************************
//		DRAG & DROP EVENTS
//************************************************************
	private:
		System::Void listBox1_DragDrop_C_listBox_Main(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void listBox1_DragEnter_C_listBox_Main(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void listBox1_DragDrop_C_listBox_Hide(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void listBox1_DragEnter_C_listBox_Hide(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void listBox1_DragDrop_D_listBox(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void listBox1_DragEnter_D_listBox(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
		System::Void C_button_Process_Start(System::Object^ sender, System::EventArgs^ e);
		System::Void D_button_Process_Start(System::Object^ sender, System::EventArgs^ e);
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void D_options_checkedChanged(System::Object^ sender, System::EventArgs^ e);

		int checkFile(std::string path);

//************************************************************
//		CLASS COMPONENTS
//************************************************************
	private:
		int check_ext_C_Main;
		int check_ext_C_Hide;
		int check_ext_D;
		bool check_size;
		bool Denoising;
		Steganography* sptr;
		std::string* fileNameMain;
		std::string* fileNameHide;
		std::string* fileNameDecoding;
		std::string* extensionDecoding;

#pragma endregion


};
}
