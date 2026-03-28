#pragma once

#include "CEmployee.h"
#include "CManagerEmployee.h"
#include "CSalemanEmployee.h"
#include "CIngineerEmployee.h"


#include <msclr/marshal_cppstd.h>

namespace ooplab7prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace msclr::interop;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonGetResult;
	protected:

	private: System::Windows::Forms::Label^ labelNameOfWorker;
	private: System::Windows::Forms::ComboBox^ comboBoxSelectEmployee;
	protected:




	private: System::Windows::Forms::TextBox^ textBoxNameOfWorker;
	private: System::Windows::Forms::TextBox^ textBoxHourRate;


	private: System::Windows::Forms::TextBox^ textBoxHours;
	private: System::Windows::Forms::TextBox^ textBoxGetNumberOfItem;



	private: System::Windows::Forms::Label^ labelHoursRate;
	private: System::Windows::Forms::Label^ labelHours;
	private: System::Windows::Forms::Label^ labelSelectEmployee;
	private: System::Windows::Forms::Label^ labelGetNumberOfItem;



	private:
		

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonGetResult = (gcnew System::Windows::Forms::Button());
			this->labelNameOfWorker = (gcnew System::Windows::Forms::Label());
			this->comboBoxSelectEmployee = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxNameOfWorker = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRate = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHours = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGetNumberOfItem = (gcnew System::Windows::Forms::TextBox());
			this->labelHoursRate = (gcnew System::Windows::Forms::Label());
			this->labelHours = (gcnew System::Windows::Forms::Label());
			this->labelSelectEmployee = (gcnew System::Windows::Forms::Label());
			this->labelGetNumberOfItem = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonGetResult
			// 
			this->buttonGetResult->Location = System::Drawing::Point(277, 367);
			this->buttonGetResult->Name = L"buttonGetResult";
			this->buttonGetResult->Size = System::Drawing::Size(90, 55);
			this->buttonGetResult->TabIndex = 0;
			this->buttonGetResult->Text = L"Calculate Result";
			this->buttonGetResult->UseVisualStyleBackColor = true;
			this->buttonGetResult->Click += gcnew System::EventHandler(this, &MyForm::buttonGetResult_Click);
			// 
			// labelNameOfWorker
			// 
			this->labelNameOfWorker->AutoSize = true;
			this->labelNameOfWorker->Location = System::Drawing::Point(81, 179);
			this->labelNameOfWorker->Name = L"labelNameOfWorker";
			this->labelNameOfWorker->Size = System::Drawing::Size(44, 16);
			this->labelNameOfWorker->TabIndex = 1;
			this->labelNameOfWorker->Text = L"Name";
			// 
			// comboBoxSelectEmployee
			// 
			this->comboBoxSelectEmployee->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSelectEmployee->FormattingEnabled = true;
			this->comboBoxSelectEmployee->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Manager", L"Saleman", L"Engineer" });
			this->comboBoxSelectEmployee->Location = System::Drawing::Point(260, 115);
			this->comboBoxSelectEmployee->Name = L"comboBoxSelectEmployee";
			this->comboBoxSelectEmployee->Size = System::Drawing::Size(121, 24);
			this->comboBoxSelectEmployee->TabIndex = 4;
			this->comboBoxSelectEmployee->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxSelectEmployee_SelectedIndexChanged);
			// 
			// textBoxNameOfWorker
			// 
			this->textBoxNameOfWorker->Location = System::Drawing::Point(84, 209);
			this->textBoxNameOfWorker->Name = L"textBoxNameOfWorker";
			this->textBoxNameOfWorker->Size = System::Drawing::Size(100, 22);
			this->textBoxNameOfWorker->TabIndex = 5;
			// 
			// textBoxHourRate
			// 
			this->textBoxHourRate->Location = System::Drawing::Point(268, 209);
			this->textBoxHourRate->Name = L"textBoxHourRate";
			this->textBoxHourRate->Size = System::Drawing::Size(100, 22);
			this->textBoxHourRate->TabIndex = 6;
			// 
			// textBoxHours
			// 
			this->textBoxHours->Location = System::Drawing::Point(439, 209);
			this->textBoxHours->Name = L"textBoxHours";
			this->textBoxHours->Size = System::Drawing::Size(100, 22);
			this->textBoxHours->TabIndex = 7;
			// 
			// textBoxGetNumberOfItem
			// 
			this->textBoxGetNumberOfItem->Location = System::Drawing::Point(84, 304);
			this->textBoxGetNumberOfItem->Name = L"textBoxGetNumberOfItem";
			this->textBoxGetNumberOfItem->Size = System::Drawing::Size(100, 22);
			this->textBoxGetNumberOfItem->TabIndex = 9;
			// 
			// labelHoursRate
			// 
			this->labelHoursRate->AutoSize = true;
			this->labelHoursRate->Location = System::Drawing::Point(265, 179);
			this->labelHoursRate->Name = L"labelHoursRate";
			this->labelHoursRate->Size = System::Drawing::Size(69, 16);
			this->labelHoursRate->TabIndex = 10;
			this->labelHoursRate->Text = L"Hours rate";
			// 
			// labelHours
			// 
			this->labelHours->AutoSize = true;
			this->labelHours->Location = System::Drawing::Point(436, 179);
			this->labelHours->Name = L"labelHours";
			this->labelHours->Size = System::Drawing::Size(43, 16);
			this->labelHours->TabIndex = 11;
			this->labelHours->Text = L"Hours";
			// 
			// labelSelectEmployee
			// 
			this->labelSelectEmployee->AutoSize = true;
			this->labelSelectEmployee->Location = System::Drawing::Point(257, 77);
			this->labelSelectEmployee->Name = L"labelSelectEmployee";
			this->labelSelectEmployee->Size = System::Drawing::Size(110, 16);
			this->labelSelectEmployee->TabIndex = 12;
			this->labelSelectEmployee->Text = L"Select Employee";
			// 
			// labelGetNumberOfItem
			// 
			this->labelGetNumberOfItem->AutoSize = true;
			this->labelGetNumberOfItem->Location = System::Drawing::Point(81, 275);
			this->labelGetNumberOfItem->Name = L"labelGetNumberOfItem";
			this->labelGetNumberOfItem->Size = System::Drawing::Size(0, 16);
			this->labelGetNumberOfItem->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 523);
			this->Controls->Add(this->labelGetNumberOfItem);
			this->Controls->Add(this->labelSelectEmployee);
			this->Controls->Add(this->labelHours);
			this->Controls->Add(this->labelHoursRate);
			this->Controls->Add(this->textBoxGetNumberOfItem);
			this->Controls->Add(this->textBoxHours);
			this->Controls->Add(this->textBoxHourRate);
			this->Controls->Add(this->textBoxNameOfWorker);
			this->Controls->Add(this->comboBoxSelectEmployee);
			this->Controls->Add(this->labelNameOfWorker);
			this->Controls->Add(this->buttonGetResult);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void buttonGetResult_Click(System::Object^ sender, System::EventArgs^ e) {
	string name;
	double h_rate = 0.0;
	double hours = 0.0;
	double num_of_item = 0.0;
	double salary = 0.0;

	if (!String::IsNullOrWhiteSpace(textBoxNameOfWorker->Text)) {
	name = marshal_as<string>(textBoxNameOfWorker->Text);
	}
	else {
		MessageBox::Show("You didnt enter a name!","Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	if (!String::IsNullOrWhiteSpace(textBoxHourRate->Text)) {
		h_rate = Convert::ToDouble(textBoxHourRate->Text);
	}
	else {
		MessageBox::Show("You didnt enter a hours rate!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	if (!String::IsNullOrWhiteSpace(textBoxHours->Text)) {
		hours = Convert::ToDouble(textBoxHours->Text); name = marshal_as<string>(textBoxNameOfWorker->Text);
	}
	else {
		MessageBox::Show("You didnt enter a hours!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	int choise = comboBoxSelectEmployee->SelectedIndex;
	

	if (choise == 0) {
		
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			num_of_item = Convert::ToInt32(textBoxGetNumberOfItem->Text);
		CManagerEmployee manager(name, h_rate, num_of_item);
		salary = manager.CalculateSalaryForHours(hours);
		MessageBox::Show("You selected Manager!\n You have " + num_of_item + " employeers;\nYour salary is: " + salary , "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else {
			MessageBox::Show("You didnt enter a number of workers!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else if (choise == 1) {
		
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			num_of_item = Convert::ToInt32(textBoxGetNumberOfItem->Text);
			CSalesmanEmployee saleman(name, h_rate, num_of_item);
			salary = saleman.CalculateSalaryForHours(hours);
			MessageBox::Show("You selected SaleMan!\n You saled " + num_of_item + " products;\nYour salary is: " + salary, "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else {
			MessageBox::Show("You didnt enter a number of saled items!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else if (choise == 2) {
		labelGetNumberOfItem->Text = "Enter number of created details";
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			num_of_item = Convert::ToInt32(textBoxGetNumberOfItem->Text);
			CSalesmanEmployee saleman(name, h_rate, num_of_item);
			salary = saleman.CalculateSalaryForHours(hours);
			MessageBox::Show("You selected Engineer!\n You created " + num_of_item + " details;\nYour salary is: " + salary, "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else {
			MessageBox::Show("You didnt enter a number of created details!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}
private: System::Void comboBoxSelectEmployee_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int choise = comboBoxSelectEmployee->SelectedIndex;
	switch (choise)
	{
	case 0:
		labelGetNumberOfItem->Text = "Enter number of workers";
		break;
	case 1:
		labelGetNumberOfItem->Text = "Enter number of saled products";
		break;
	case 2:
		labelGetNumberOfItem->Text = "Enter number of created details";
		break;
	default:
		break;
	}
}
};
}
