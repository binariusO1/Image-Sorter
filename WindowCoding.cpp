#include "WindowCoding.h"
#include <string>
#include <fstream>
#include <windows.h>

using namespace Hideandextractdatainimages;
using namespace System;

//************************************************************
//		WINDOW FORM ELEMENTS
//************************************************************
void WindowCoding::InitializeComponent(void)
{
	this->components = (gcnew System::ComponentModel::Container());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WindowCoding::typeid));
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
	this->C_Options_GroupBox = (gcnew System::Windows::Forms::GroupBox());
	this->C_Options_ComboBox_format = (gcnew System::Windows::Forms::ComboBox());
	this->C_Options_label_format = (gcnew System::Windows::Forms::Label());
	this->C_button_Process = (gcnew System::Windows::Forms::Button());
	this->C_Options_ComboBox_bits = (gcnew System::Windows::Forms::ComboBox());
	this->C_Options_label_note = (gcnew System::Windows::Forms::Label());
	this->C_Options_label_bits = (gcnew System::Windows::Forms::Label());
	this->C_Hide_groupBox = (gcnew System::Windows::Forms::GroupBox());
	this->C_Hide_label_Heightpx = (gcnew System::Windows::Forms::Label());
	this->C_Hide_label_Widthpx = (gcnew System::Windows::Forms::Label());
	this->C_Hide_label_Height = (gcnew System::Windows::Forms::Label());
	this->C_Hide_label_Width = (gcnew System::Windows::Forms::Label());
	this->C_Hide_listBox = (gcnew System::Windows::Forms::ListBox());
	this->C_Main_groupBox = (gcnew System::Windows::Forms::GroupBox());
	this->C_Main_label_Heightpx = (gcnew System::Windows::Forms::Label());
	this->C_Main_label_Widthpx = (gcnew System::Windows::Forms::Label());
	this->C_Main_label_Height = (gcnew System::Windows::Forms::Label());
	this->C_Main_label_Width = (gcnew System::Windows::Forms::Label());
	this->C_Main_listBox = (gcnew System::Windows::Forms::ListBox());
	this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
	this->D_options_groupBox = (gcnew System::Windows::Forms::GroupBox());
	this->D_options_checkBox = (gcnew System::Windows::Forms::CheckBox());
	this->D_button_Process = (gcnew System::Windows::Forms::Button());
	this->D_options_comboBox_format = (gcnew System::Windows::Forms::ComboBox());
	this->D_options_label_format = (gcnew System::Windows::Forms::Label());
	this->D_options_comboBox_bits = (gcnew System::Windows::Forms::ComboBox());
	this->D_options_label_note = (gcnew System::Windows::Forms::Label());
	this->D_options_label_bits = (gcnew System::Windows::Forms::Label());
	this->D_groupBox = (gcnew System::Windows::Forms::GroupBox());
	this->D_label_Heightpx = (gcnew System::Windows::Forms::Label());
	this->D_label_Widthpx = (gcnew System::Windows::Forms::Label());
	this->D_label_Height = (gcnew System::Windows::Forms::Label());
	this->D_label_Width = (gcnew System::Windows::Forms::Label());
	this->D_listBox = (gcnew System::Windows::Forms::ListBox());
	this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
	this->label_author = (gcnew System::Windows::Forms::Label());
	this->tabControl1->SuspendLayout();
	this->tabPage1->SuspendLayout();
	this->C_Options_GroupBox->SuspendLayout();
	this->C_Hide_groupBox->SuspendLayout();
	this->C_Main_groupBox->SuspendLayout();
	this->tabPage2->SuspendLayout();
	this->D_options_groupBox->SuspendLayout();
	this->D_groupBox->SuspendLayout();
	this->SuspendLayout();
	// 
	// tabControl1
	// 
	this->tabControl1->AllowDrop = true;
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	resources->ApplyResources(this->tabControl1, L"tabControl1");
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
	// 
	// tabPage1
	// 
	this->tabPage1->Controls->Add(this->C_Options_GroupBox);
	this->tabPage1->Controls->Add(this->C_Hide_groupBox);
	this->tabPage1->Controls->Add(this->C_Main_groupBox);
	resources->ApplyResources(this->tabPage1, L"tabPage1");
	this->tabPage1->Name = L"tabPage1";
	this->tabPage1->UseVisualStyleBackColor = true;
	// 
	// C_Options_GroupBox
	// 
	this->C_Options_GroupBox->Controls->Add(this->C_Options_ComboBox_format);
	this->C_Options_GroupBox->Controls->Add(this->C_Options_label_format);
	this->C_Options_GroupBox->Controls->Add(this->C_button_Process);
	this->C_Options_GroupBox->Controls->Add(this->C_Options_ComboBox_bits);
	this->C_Options_GroupBox->Controls->Add(this->C_Options_label_note);
	this->C_Options_GroupBox->Controls->Add(this->C_Options_label_bits);
	resources->ApplyResources(this->C_Options_GroupBox, L"C_Options_GroupBox");
	this->C_Options_GroupBox->Name = L"C_Options_GroupBox";
	this->C_Options_GroupBox->TabStop = false;
	// 
	// C_Options_ComboBox_format
	// 
	this->C_Options_ComboBox_format->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
	this->C_Options_ComboBox_format->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->C_Options_ComboBox_format->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		resources->GetString(L"C_Options_ComboBox_format.Items"),
			resources->GetString(L"C_Options_ComboBox_format.Items1"), resources->GetString(L"C_Options_ComboBox_format.Items2")
	});
	resources->ApplyResources(this->C_Options_ComboBox_format, L"C_Options_ComboBox_format");
	this->C_Options_ComboBox_format->SelectedIndex = 0;
	// 
	// C_Options_label_format
	// 
	resources->ApplyResources(this->C_Options_label_format, L"C_Options_label_format");
	this->C_Options_label_format->Name = L"C_Options_label_format";
	// 
	// C_button_Process
	// 
	resources->ApplyResources(this->C_button_Process, L"C_button_Process");
	this->C_button_Process->Name = L"C_button_Process";
	this->C_button_Process->UseVisualStyleBackColor = true;
	this->C_button_Process->Click += gcnew System::EventHandler(this, &WindowCoding::C_button_Process_Start);
	// 
	// C_Options_ComboBox_bits
	// 
	this->C_Options_ComboBox_bits->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
	this->C_Options_ComboBox_bits->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->C_Options_ComboBox_bits->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		resources->GetString(L"C_Options_ComboBox_bits.Items"),
			resources->GetString(L"C_Options_ComboBox_bits.Items1"), resources->GetString(L"C_Options_ComboBox_bits.Items2")
	});
	resources->ApplyResources(this->C_Options_ComboBox_bits, L"C_Options_ComboBox_bits");
	this->C_Options_ComboBox_bits->SelectedIndex = 0;
	// 
	// C_Options_label_note
	// 
	resources->ApplyResources(this->C_Options_label_note, L"C_Options_label_note");
	this->C_Options_label_note->Name = L"C_Options_label_note";
	// 
	// C_Options_label_bits
	// 
	resources->ApplyResources(this->C_Options_label_bits, L"C_Options_label_bits");
	this->C_Options_label_bits->Name = L"C_Options_label_bits";
	// 
	// C_Hide_groupBox
	// 
	this->C_Hide_groupBox->Controls->Add(this->C_Hide_label_Heightpx);
	this->C_Hide_groupBox->Controls->Add(this->C_Hide_label_Widthpx);
	this->C_Hide_groupBox->Controls->Add(this->C_Hide_label_Height);
	this->C_Hide_groupBox->Controls->Add(this->C_Hide_label_Width);
	this->C_Hide_groupBox->Controls->Add(this->C_Hide_listBox);
	resources->ApplyResources(this->C_Hide_groupBox, L"C_Hide_groupBox");
	this->C_Hide_groupBox->Name = L"C_Hide_groupBox";
	this->C_Hide_groupBox->TabStop = false;
	// 
	// C_Hide_label_Heightpx
	// 
	resources->ApplyResources(this->C_Hide_label_Heightpx, L"C_Hide_label_Heightpx");
	this->C_Hide_label_Heightpx->Name = L"C_Hide_label_Heightpx";
	// 
	// C_Hide_label_Widthpx
	// 
	resources->ApplyResources(this->C_Hide_label_Widthpx, L"C_Hide_label_Widthpx");
	this->C_Hide_label_Widthpx->Name = L"C_Hide_label_Widthpx";
	// 
	// C_Hide_label_Height
	// 
	resources->ApplyResources(this->C_Hide_label_Height, L"C_Hide_label_Height");
	this->C_Hide_label_Height->Name = L"C_Hide_label_Height";
	// 
	// C_Hide_label_Width
	// 
	resources->ApplyResources(this->C_Hide_label_Width, L"C_Hide_label_Width");
	this->C_Hide_label_Width->Name = L"C_Hide_label_Width";
	// 
	// C_Hide_listBox
	// 
	this->C_Hide_listBox->AllowDrop = true;
	this->C_Hide_listBox->Cursor = System::Windows::Forms::Cursors::Hand;
	this->C_Hide_listBox->FormattingEnabled = true;
	resources->ApplyResources(this->C_Hide_listBox, L"C_Hide_listBox");
	this->C_Hide_listBox->Name = L"C_Hide_listBox";
	this->C_Hide_listBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
	this->toolTip2->SetToolTip(this->C_Hide_listBox, resources->GetString(L"C_Hide_listBox.ToolTip"));
	this->C_Hide_listBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragDrop_C_listBox_Hide);
	this->C_Hide_listBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragEnter_C_listBox_Hide);
	// 
	// C_Main_groupBox
	// 
	this->C_Main_groupBox->Controls->Add(this->C_Main_label_Heightpx);
	this->C_Main_groupBox->Controls->Add(this->C_Main_label_Widthpx);
	this->C_Main_groupBox->Controls->Add(this->C_Main_label_Height);
	this->C_Main_groupBox->Controls->Add(this->C_Main_label_Width);
	this->C_Main_groupBox->Controls->Add(this->C_Main_listBox);
	resources->ApplyResources(this->C_Main_groupBox, L"C_Main_groupBox");
	this->C_Main_groupBox->Name = L"C_Main_groupBox";
	this->C_Main_groupBox->TabStop = false;
	// 
	// C_Main_label_Heightpx
	// 
	resources->ApplyResources(this->C_Main_label_Heightpx, L"C_Main_label_Heightpx");
	this->C_Main_label_Heightpx->Name = L"C_Main_label_Heightpx";
	// 
	// C_Main_label_Widthpx
	// 
	resources->ApplyResources(this->C_Main_label_Widthpx, L"C_Main_label_Widthpx");
	this->C_Main_label_Widthpx->Name = L"C_Main_label_Widthpx";
	// 
	// C_Main_label_Height
	// 
	resources->ApplyResources(this->C_Main_label_Height, L"C_Main_label_Height");
	this->C_Main_label_Height->Name = L"C_Main_label_Height";
	// 
	// C_Main_label_Width
	// 
	resources->ApplyResources(this->C_Main_label_Width, L"C_Main_label_Width");
	this->C_Main_label_Width->Name = L"C_Main_label_Width";
	// 
	// C_Main_listBox
	// 
	this->C_Main_listBox->AllowDrop = true;
	this->C_Main_listBox->Cursor = System::Windows::Forms::Cursors::Hand;
	this->C_Main_listBox->FormattingEnabled = true;
	resources->ApplyResources(this->C_Main_listBox, L"C_Main_listBox");
	this->C_Main_listBox->Name = L"C_Main_listBox";
	this->C_Main_listBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
	this->toolTip1->SetToolTip(this->C_Main_listBox, resources->GetString(L"C_Main_listBox.ToolTip"));
	this->C_Main_listBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragDrop_C_listBox_Main);
	this->C_Main_listBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragEnter_C_listBox_Main);
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->D_options_groupBox);
	this->tabPage2->Controls->Add(this->D_groupBox);
	resources->ApplyResources(this->tabPage2, L"tabPage2");
	this->tabPage2->Name = L"tabPage2";
	this->tabPage2->UseVisualStyleBackColor = true;
	// 
	// D_options_groupBox
	// 
	this->D_options_groupBox->Controls->Add(this->D_options_checkBox);
	this->D_options_groupBox->Controls->Add(this->D_button_Process);
	this->D_options_groupBox->Controls->Add(this->D_options_comboBox_format);
	this->D_options_groupBox->Controls->Add(this->D_options_label_format);
	this->D_options_groupBox->Controls->Add(this->D_options_comboBox_bits);
	this->D_options_groupBox->Controls->Add(this->D_options_label_note);
	this->D_options_groupBox->Controls->Add(this->D_options_label_bits);
	resources->ApplyResources(this->D_options_groupBox, L"D_options_groupBox");
	this->D_options_groupBox->Name = L"D_options_groupBox";
	this->D_options_groupBox->TabStop = false;
	// 
	// D_options_checkBox
	// 
	resources->ApplyResources(this->D_options_checkBox, L"D_options_checkBox");
	this->D_options_checkBox->Name = L"D_options_checkBox";
	this->D_options_checkBox->UseVisualStyleBackColor = true;
	this->D_options_checkBox->CheckedChanged += gcnew System::EventHandler(this, &WindowCoding::D_options_checkedChanged);
	// 
	// D_button_Process
	// 
	resources->ApplyResources(this->D_button_Process, L"D_button_Process");
	this->D_button_Process->Name = L"D_button_Process";
	this->D_button_Process->Click += gcnew System::EventHandler(this, &WindowCoding::D_button_Process_Start);
	// 
	// D_options_comboBox_format
	// 
	this->D_options_comboBox_format->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
	this->D_options_comboBox_format->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->D_options_comboBox_format->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
		resources->GetString(L"D_options_comboBox_format.Items"),
			resources->GetString(L"D_options_comboBox_format.Items1"), resources->GetString(L"D_options_comboBox_format.Items2")
	});
	resources->ApplyResources(this->D_options_comboBox_format, L"D_options_comboBox_format");
	this->D_options_comboBox_format->Name = L"D_options_comboBox_format";
	this->D_options_comboBox_format->SelectedIndex = 0;
	// 
	// D_options_label_format
	// 
	resources->ApplyResources(this->D_options_label_format, L"D_options_label_format");
	this->D_options_label_format->Name = L"D_options_label_format";
	// 
	// D_options_comboBox_bits
	// 
	this->D_options_comboBox_bits->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
	this->D_options_comboBox_bits->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->D_options_comboBox_bits->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
		resources->GetString(L"D_options_comboBox_bits.Items"),
			resources->GetString(L"D_options_comboBox_bits.Items1"), resources->GetString(L"D_options_comboBox_bits.Items2"), resources->GetString(L"D_options_comboBox_bits.Items3")
	});
	resources->ApplyResources(this->D_options_comboBox_bits, L"D_options_comboBox_bits");
	this->D_options_comboBox_bits->Name = L"D_options_comboBox_bits";
	this->D_options_comboBox_bits->SelectedIndex = 0;
	// 
	// D_options_label_note
	// 
	resources->ApplyResources(this->D_options_label_note, L"D_options_label_note");
	this->D_options_label_note->Name = L"D_options_label_note";
	// 
	// D_options_label_bits
	// 
	resources->ApplyResources(this->D_options_label_bits, L"D_options_label_bits");
	this->D_options_label_bits->Name = L"D_options_label_bits";
	// 
	// D_groupBox
	// 
	this->D_groupBox->Controls->Add(this->D_label_Heightpx);
	this->D_groupBox->Controls->Add(this->D_label_Widthpx);
	this->D_groupBox->Controls->Add(this->D_label_Height);
	this->D_groupBox->Controls->Add(this->D_label_Width);
	this->D_groupBox->Controls->Add(this->D_listBox);
	resources->ApplyResources(this->D_groupBox, L"D_groupBox");
	this->D_groupBox->Name = L"D_groupBox";
	this->D_groupBox->TabStop = false;
	// 
	// D_label_Heightpx
	// 
	resources->ApplyResources(this->D_label_Heightpx, L"D_label_Heightpx");
	this->D_label_Heightpx->Name = L"D_label_Heightpx";
	// 
	// D_label_Widthpx
	// 
	resources->ApplyResources(this->D_label_Widthpx, L"D_label_Widthpx");
	this->D_label_Widthpx->Name = L"D_label_Widthpx";
	// 
	// D_label_Height
	// 
	resources->ApplyResources(this->D_label_Height, L"D_label_Height");
	this->D_label_Height->Name = L"D_label_Height";
	// 
	// D_label_Width
	// 
	resources->ApplyResources(this->D_label_Width, L"D_label_Width");
	this->D_label_Width->Name = L"D_label_Width";
	// 
	// D_listBox
	// 
	this->D_listBox->AllowDrop = true;
	this->D_listBox->Cursor = System::Windows::Forms::Cursors::Hand;
	this->D_listBox->FormattingEnabled = true;
	resources->ApplyResources(this->D_listBox, L"D_listBox");
	this->D_listBox->Name = L"D_listBox";
	this->D_listBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
	this->toolTip3->SetToolTip(this->D_listBox, resources->GetString(L"D_listBox.ToolTip"));
	this->D_listBox->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragDrop_D_listBox);
	this->D_listBox->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &WindowCoding::listBox1_DragEnter_D_listBox);
	// 
	// label_author
	// 
	resources->ApplyResources(this->label_author, L"label_author");
	this->label_author->Name = L"label_author";
	// 
	// WindowCoding
	// 
	this->AllowDrop = true;
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
	this->CausesValidation = false;
	resources->ApplyResources(this, L"$this");
	this->Controls->Add(this->label_author);
	this->Controls->Add(this->tabControl1);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MaximizeBox = false;
	this->Name = L"WindowCoding";
	this->ShowIcon = false;
	this->tabControl1->ResumeLayout(false);
	this->tabPage1->ResumeLayout(false);
	this->C_Options_GroupBox->ResumeLayout(false);
	this->C_Options_GroupBox->PerformLayout();
	this->C_Hide_groupBox->ResumeLayout(false);
	this->C_Hide_groupBox->PerformLayout();
	this->C_Main_groupBox->ResumeLayout(false);
	this->C_Main_groupBox->PerformLayout();
	this->tabPage2->ResumeLayout(false);
	this->D_options_groupBox->ResumeLayout(false);
	this->D_options_groupBox->PerformLayout();
	this->D_groupBox->ResumeLayout(false);
	this->D_groupBox->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();
}

/*
#include <iostream>
using namespace std;
*/

//************************************************************
//		DRAG & DROP EVENTS
//************************************************************

	//-------------------------------------------------
	//		C_Main
	//-------------------------------------------------
System::Void WindowCoding::listBox1_DragDrop_C_listBox_Main(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	this->C_Main_listBox->Items->Clear();
	cli::array<String^>^ files = (cli::array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	for each (String ^ file in files) {
		if (files->Length == 1) {
			std::string s_file = msclr::interop::marshal_as<std::string>(file);
			this->check_ext_C_Main = checkFile(s_file);

			String^ filename = Path::GetFileName(file);
			this->C_Main_listBox->Items->Add(filename);

			this->fileNameMain = new std::string(msclr::interop::marshal_as<std::string>(filename));
		}
	}
	if (this->check_ext_C_Hide > 0 && (sptr->CompareSizeOut((this->fileNameMain), (this->fileNameHide))) != 0)
		this->C_button_Process->Enabled = true;

	std::string strR = to_string(sptr->GetImageRows(this->fileNameMain));
	std::string strC = to_string(sptr->GetImageCols(this->fileNameMain));
	String^ rows = gcnew String(strR.c_str());
	String^ cols = gcnew String(strC.c_str());
	this->C_Main_label_Widthpx->Text = rows + L" px";
	this->C_Main_label_Heightpx->Text = cols + L" px";
}
System::Void WindowCoding::listBox1_DragEnter_C_listBox_Main(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop, false) == true) {
		e->Effect = DragDropEffects::All;
	}
}

//-------------------------------------------------
//		C_Hide
//-------------------------------------------------
System::Void WindowCoding::listBox1_DragDrop_C_listBox_Hide(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	this->C_Hide_listBox->Items->Clear();
	cli::array<String^>^ files = (cli::array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	for each (String ^ file in files) {
		if (files->Length == 1) {
			std::string s_file = msclr::interop::marshal_as<std::string>(file);
			this->check_ext_C_Hide = checkFile(s_file);

			String^ filename = Path::GetFileName(file);
			this->C_Hide_listBox->Items->Add(filename);

			this->fileNameHide = new std::string(msclr::interop::marshal_as<std::string>(filename));
		}
	}
	if (this->check_ext_C_Main > 0 && (sptr->CompareSizeOut((this->fileNameMain), (this->fileNameHide))) != 0) {
		this->C_button_Process->Enabled = true;
	}
	else
		this->C_button_Process->Enabled = false;
	std::string strR = to_string(sptr->GetImageRows(this->fileNameHide));
	std::string strC = to_string(sptr->GetImageCols(this->fileNameHide));
	String^ rows = gcnew String(strR.c_str());
	String^ cols = gcnew String(strC.c_str());
	this->C_Hide_label_Widthpx->Text = rows + L" px";
	this->C_Hide_label_Heightpx->Text = cols + L" px";
}
System::Void WindowCoding::listBox1_DragEnter_C_listBox_Hide(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop, false) == true) {
		e->Effect = DragDropEffects::All;
	}
}

System::Void WindowCoding::C_button_Process_Start(System::Object^ sender, System::EventArgs^ e)
{
	try {
		if (this->check_ext_C_Main == -1 || this->check_ext_C_Hide == -1)
			MessageBox::Show("No file", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else if (this->check_ext_C_Main == 0 || this->check_ext_C_Hide == 0)
			MessageBox::Show("File extension must be .jpg, .png or .bmp", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else if ((sptr->CompareSizeOut((this->fileNameMain), (this->fileNameHide))) == 0) {
			MessageBox::Show("Size of main image must be equal or bigger than image to hide", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else {
			String^ temp1 = C_Options_ComboBox_bits->Text;
			std::string t1 = msclr::interop::marshal_as<std::string>(temp1);
			int k = strtol(t1.c_str(), NULL, 10);
			int f = C_Options_ComboBox_format->SelectedIndex;

			sptr->Coding((this->fileNameMain), (this->fileNameHide), k, f);
			MessageBox::Show("output.jpg has been created succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (...)
	{
		MessageBox::Show("unable to load images", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

//-------------------------------------------------
//		D
//-------------------------------------------------
System::Void WindowCoding::listBox1_DragDrop_D_listBox(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	this->D_listBox->Items->Clear();
	cli::array<String^>^ files = (cli::array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
	for each (String ^ file in files) {
		if (files->Length == 1) {
			std::string s_file = msclr::interop::marshal_as<std::string>(file);
			this->check_ext_D = checkFile(s_file);

			String^ filename = Path::GetFileName(file);
			this->D_listBox->Items->Add(filename);

			this->fileNameDecoding = new std::string(msclr::interop::marshal_as<std::string>(filename));
		}
	}
	if (this->check_ext_D > 0) {
		this->D_button_Process->Enabled = true;
	}
	else
		this->D_button_Process->Enabled = false;

	if (this->D_options_checkBox->Enabled == false && (*extensionDecoding == "gpj." || *extensionDecoding == "gepj"))
		this->D_options_checkBox->Enabled = true;
	else
		this->D_options_checkBox->Enabled = false;

	std::string strR = to_string(sptr->GetImageRows(this->fileNameDecoding));
	std::string strC = to_string(sptr->GetImageCols(this->fileNameDecoding));
	String^ rows = gcnew String(strR.c_str());
	String^ cols = gcnew String(strC.c_str());
	this->D_label_Widthpx->Text = rows + L" px";
	this->D_label_Heightpx->Text = cols + L" px";
}
System::Void WindowCoding::listBox1_DragEnter_D_listBox(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop, false) == true) {
		e->Effect = DragDropEffects::All;
	}
}

System::Void WindowCoding::D_options_checkedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->D_options_checkBox->Checked == true)
		this->Denoising = true;
	else
		this->Denoising = false;
}

System::Void WindowCoding::D_button_Process_Start(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::Cursor::Current = System::Windows::Forms::Cursors::WaitCursor;
	try {
		if (this->check_ext_D == -1)
			MessageBox::Show("No file", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else if (this->check_ext_D == 0)
			MessageBox::Show("File extension should be .jpg, .png or .bmp", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		else {
			String^ temp1 = D_options_comboBox_bits->Text;
			std::string t1 = msclr::interop::marshal_as<std::string>(temp1);
			if (t1 == "auto")
				t1 = "0";
			int k = strtol(t1.c_str(), NULL, 10);
			int f = D_options_comboBox_format->SelectedIndex;

			sptr->Decoding((this->fileNameDecoding), k, f, this->Denoising);
			MessageBox::Show("output_decoding.jpg has been created succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (...)
	{
		MessageBox::Show("unable to load image", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	System::Windows::Forms::Cursor::Current = System::Windows::Forms::Cursors::Default;
}

//-------------------------------------------------
//		OTHER
//-------------------------------------------------
int WindowCoding::checkFile(std::string path)
{
	std::fstream file;
	std::string extension;
	for (size_t i = path.size() - 1; i >= path.size() - 4; i--)
	{
		extension += path[i];
	}
	this->extensionDecoding = new std::string(extension);
	file.open(path, std::ios::in);
	if (file.good() == false)
	{
		file.close();
		return -1;
	}
	else if (extension == "gpj." || extension == "gnp." || extension == "pmb." || extension == "gepj")
	{
		extension.clear();
		file.close();
		return 1;
	}
	else
	{
		extension.clear();
		file.close();
		return 0;
	}
}

System::Void WindowCoding::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
}

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	this->comboBox1->SelectedIndex = 0;
*/