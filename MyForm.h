#pragma once

#include "CEmployee.h"
#include "CManagerEmployee.h"
#include "CSalesmanEmployee.h"
#include "CEngineerEmployee.h"
#include "EmployeeUtils.h"

#include <msclr/marshal_cppstd.h>
#include <fstream>

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
			employee = new CEmployee*[10];
			for (int i = 0; i < 10; i++) employee[i] = nullptr;
		}

	protected:

		~MyForm()
		{
			if (employee)
			{

				delete[] employee;
				employee = nullptr;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonGetResult;
	private: System::Windows::Forms::Button^ buttonClearResults;
	protected:

	private: System::Windows::Forms::Label^ labelNameOfWorker;
	private: System::Windows::Forms::ComboBox^ comboBoxSelectEmployee;
	protected:

	private: System::Windows::Forms::TextBox^ textBoxNameOfWorker;
	private: System::Windows::Forms::TextBox^ textBoxHourRate;

	private: System::Windows::Forms::TextBox^ textBoxGetNumberOfItem;
	private: System::Windows::Forms::Label^ labelHoursRate;

	private: System::Windows::Forms::Label^ labelSelectEmployee;
	private: System::Windows::Forms::Label^ labelGetNumberOfItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileTxt;
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::RichTextBox^ richTextBoxResults;

	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;

	private:
		double salary = 0.0;
		double h_rate = 0.0;
		int num_of_item = 0;
		int choise = 0;
		CEmployee** employee = nullptr;
		int employeeCount = 0;
		String^ lastResultText = "";

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonGetResult = (gcnew System::Windows::Forms::Button());
			this->buttonClearResults = (gcnew System::Windows::Forms::Button());
			this->labelNameOfWorker = (gcnew System::Windows::Forms::Label());
			this->comboBoxSelectEmployee = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxNameOfWorker = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRate = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGetNumberOfItem = (gcnew System::Windows::Forms::TextBox());
			this->labelHoursRate = (gcnew System::Windows::Forms::Label());
			this->labelSelectEmployee = (gcnew System::Windows::Forms::Label());
			this->labelGetNumberOfItem = (gcnew System::Windows::Forms::Label());
			this->saveFileTxt = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBoxResults = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonGetResult
			// 
			this->buttonGetResult->Location = System::Drawing::Point(12, 345);
			this->buttonGetResult->Name = L"buttonGetResult";
			this->buttonGetResult->Size = System::Drawing::Size(120, 50);
			this->buttonGetResult->TabIndex = 0;
			this->buttonGetResult->Text = L"Calculate Result";
			this->buttonGetResult->UseVisualStyleBackColor = true;
			this->buttonGetResult->Click += gcnew System::EventHandler(this, &MyForm::buttonGetResult_Click);
			// 
			// buttonClearResults
			// 
			this->buttonClearResults->Location = System::Drawing::Point(147, 345);
			this->buttonClearResults->Name = L"buttonClearResults";
			this->buttonClearResults->Size = System::Drawing::Size(120, 50);
			this->buttonClearResults->TabIndex = 15;
			this->buttonClearResults->Text = L"Clear Results";
			this->buttonClearResults->UseVisualStyleBackColor = true;
			this->buttonClearResults->Click += gcnew System::EventHandler(this, &MyForm::buttonClearResults_Click);
			// 
			// labelNameOfWorker
			// 
			this->labelNameOfWorker->AutoSize = true;
			this->labelNameOfWorker->Location = System::Drawing::Point(60, 113);
			this->labelNameOfWorker->Name = L"labelNameOfWorker";
			this->labelNameOfWorker->Size = System::Drawing::Size(44, 16);
			this->labelNameOfWorker->TabIndex = 1;
			this->labelNameOfWorker->Text = L"Name";
			// 
			// comboBoxSelectEmployee
			// 
			this->comboBoxSelectEmployee->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSelectEmployee->FormattingEnabled = true;
			this->comboBoxSelectEmployee->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Manager", L"Salesman", L"Engineer" });
			this->comboBoxSelectEmployee->Location = System::Drawing::Point(63, 58);
			this->comboBoxSelectEmployee->Name = L"comboBoxSelectEmployee";
			this->comboBoxSelectEmployee->Size = System::Drawing::Size(150, 24);
			this->comboBoxSelectEmployee->TabIndex = 4;
			this->comboBoxSelectEmployee->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxSelectEmployee_SelectedIndexChanged);
			// 
			// textBoxNameOfWorker
			// 
			this->textBoxNameOfWorker->Location = System::Drawing::Point(63, 132);
			this->textBoxNameOfWorker->Name = L"textBoxNameOfWorker";
			this->textBoxNameOfWorker->Size = System::Drawing::Size(150, 22);
			this->textBoxNameOfWorker->TabIndex = 5;
			// 
			// textBoxHourRate
			// 
			this->textBoxHourRate->Location = System::Drawing::Point(63, 192);
			this->textBoxHourRate->Name = L"textBoxHourRate";
			this->textBoxHourRate->Size = System::Drawing::Size(150, 22);
			this->textBoxHourRate->TabIndex = 6;
			// 
			// textBoxGetNumberOfItem
			// 
			this->textBoxGetNumberOfItem->Location = System::Drawing::Point(63, 259);
			this->textBoxGetNumberOfItem->Name = L"textBoxGetNumberOfItem";
			this->textBoxGetNumberOfItem->Size = System::Drawing::Size(150, 22);
			this->textBoxGetNumberOfItem->TabIndex = 9;
			// 
			// labelHoursRate
			// 
			this->labelHoursRate->AutoSize = true;
			this->labelHoursRate->Location = System::Drawing::Point(60, 173);
		 this->labelHoursRate->Name = L"labelHoursRate";
			this->labelHoursRate->Size = System::Drawing::Size(69, 16);
			this->labelHoursRate->TabIndex = 10;
			this->labelHoursRate->Text = L"Hours rate";
			// 
			// labelSelectEmployee
			// 
			this->labelSelectEmployee->AutoSize = true;
			this->labelSelectEmployee->Location = System::Drawing::Point(60, 39);
			this->labelSelectEmployee->Name = L"labelSelectEmployee";
			this->labelSelectEmployee->Size = System::Drawing::Size(110, 16);
			this->labelSelectEmployee->TabIndex = 12;
			this->labelSelectEmployee->Text = L"Select Employee";
			// 
			// labelGetNumberOfItem
			// 
			this->labelGetNumberOfItem->AutoSize = true;
			this->labelGetNumberOfItem->Location = System::Drawing::Point(60, 231);
			this->labelGetNumberOfItem->Name = L"labelGetNumberOfItem";
			this->labelGetNumberOfItem->Size = System::Drawing::Size(0, 16);
			this->labelGetNumberOfItem->TabIndex = 13;
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(660, 28);
			this->menuStrip->TabIndex = 14;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(173, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(173, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// richTextBoxResults
			// 
			this->richTextBoxResults->Location = System::Drawing::Point(290, 55);
			this->richTextBoxResults->Name = L"richTextBoxResults";
			this->richTextBoxResults->Size = System::Drawing::Size(350, 340);
			this->richTextBoxResults->TabIndex = 14;
			this->richTextBoxResults->Text = L"Results will be displayed here...";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 420);
			this->Controls->Add(this->richTextBoxResults);
			this->Controls->Add(this->buttonClearResults);
			this->Controls->Add(this->comboBoxSelectEmployee);
			this->Controls->Add(this->labelSelectEmployee);
			this->Controls->Add(this->labelGetNumberOfItem);
			this->Controls->Add(this->labelHoursRate);
			this->Controls->Add(this->textBoxGetNumberOfItem);
			this->Controls->Add(this->textBoxHourRate);
			this->Controls->Add(this->textBoxNameOfWorker);
			this->Controls->Add(this->labelNameOfWorker);
			this->Controls->Add(this->buttonGetResult);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Employee Management System";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void buttonGetResult_Click(System::Object^ sender, System::EventArgs^ e) {
	string name;
	lastResultText = "";

	if (!String::IsNullOrWhiteSpace(textBoxNameOfWorker->Text)) {
		name = msclr::interop::marshal_as<std::string>(textBoxNameOfWorker->Text);
	}
	else {
		richTextBoxResults->Text = "Error: You didn't enter a name!";
		MessageBox::Show("You didn't enter a name!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	if (!String::IsNullOrWhiteSpace(textBoxHourRate->Text)) {
		if (!double::TryParse(textBoxHourRate->Text, h_rate)) {
			richTextBoxResults->Text = "Error: Invalid hour rate format!";
			MessageBox::Show("Invalid hour rate format!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
	}
	else {
		richTextBoxResults->Text = "Error: You didn't enter an hours rate!";
		MessageBox::Show("You didn't enter an hours rate!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	choise = comboBoxSelectEmployee->SelectedIndex;

	lastResultText = "Employee Calculate Results\n\n";
	lastResultText += "Employee Type: ";

	if (choise == 0) {
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			if (!int::TryParse(textBoxGetNumberOfItem->Text, num_of_item)) {
				richTextBoxResults->Text = "Error: Invalid number of workers!";
				MessageBox::Show("Invalid input!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			CManagerEmployee manager(name, h_rate, num_of_item);
			salary = manager.CalculateSalaryForHours(h_rate);
			int productivityScore = manager.GetProductivityScore();

			lastResultText += "Manager\n";
			lastResultText += "\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Base Hour Rate: $" + h_rate.ToString() + "/hour\n";
			lastResultText += "Number of Workers: " + num_of_item + "\n";
			lastResultText += "\n";
			lastResultText += "Productivity:\n";
			lastResultText += "Productivity Score: " + productivityScore + "/100\n";
			lastResultText += "Performance Level: ";
			
			if (productivityScore >= 80) lastResultText += "Excellent\n";
			else if (productivityScore >= 60) lastResultText += "good\n";
			else if (productivityScore >= 40) lastResultText += "not bad\n";
			else lastResultText += "bad\n";
			
			lastResultText += "\n";
			lastResultText += "Calculated Salary: $" + salary.ToString() + "\n";
			lastResultText += "\n";
			lastResultText += "Total Employees in System: " + (++employeeCount) + "\n";

			richTextBoxResults->Text = lastResultText;
		}
		else {
			richTextBoxResults->Text = "Error: You didn't enter a number of workers!";
			MessageBox::Show("You didn't enter a number of workers!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else if (choise == 1) {
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			if (!int::TryParse(textBoxGetNumberOfItem->Text, num_of_item)) {
				richTextBoxResults->Text = "Error: Invalid number of products!";
				MessageBox::Show("Invalid input!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			CSalesmanEmployee salesman(name, h_rate, num_of_item);
			salary = salesman.CalculateSalaryForHours(h_rate);
			int productivityScore = salesman.GetProductivityScore();

			lastResultText += "Salesman\n";
			lastResultText += "\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Base Hour Rate: $" + h_rate.ToString() + "/hour\n";
			lastResultText += "Number of Products: " + num_of_item + "\n";
			lastResultText += "\n";
			lastResultText += "Productivity:\n";
			lastResultText += "Productivity Score: " + productivityScore + "/100\n";
			lastResultText += "Performance Level: ";
			
			if (productivityScore >= 80) lastResultText += "excellent\n";
			else if (productivityScore >= 60) lastResultText += "good\n";
			else if (productivityScore >= 40) lastResultText += "not bad\n";
			else lastResultText += "bad\n";
			
			lastResultText += "\n";
			lastResultText += "Calculated Salary: $" + salary.ToString() + "\n";
			lastResultText += "\n";
			lastResultText += "Total Employees in System: " + (++employeeCount) + "\n";

			richTextBoxResults->Text = lastResultText;
		}
		else {
			richTextBoxResults->Text = "Error: You didn't enter a number of sold items!";
			MessageBox::Show("You didn't enter a number of sold items!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else if (choise == 2) {
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			if (!int::TryParse(textBoxGetNumberOfItem->Text, num_of_item)) {
				richTextBoxResults->Text = "Error: Invalid number of details!";
				MessageBox::Show("Invalid input!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			CEngineerEmployee engineer(name, h_rate, num_of_item);
			salary = engineer.CalculateSalaryForHours(h_rate);
			int productivityScore = engineer.GetProductivityScore();

			lastResultText += "Enginner\n";
			lastResultText += "\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Base Hour Rate: $" + h_rate.ToString() + "/hour\n";
			lastResultText += "Number of Details: " + num_of_item + "\n";
			lastResultText += "\n";
			lastResultText += "Productivity:\n";
			lastResultText += "Productivity Score: " + productivityScore + "/100\n";
			lastResultText += "Performance Level: ";
			
			if (productivityScore >= 80) lastResultText += "excellent\n";
			else if (productivityScore >= 60) lastResultText += "good\n";
			else if (productivityScore >= 40) lastResultText += "not bad\n";
			else lastResultText += "bad\n";
			
			lastResultText += "\n";
			lastResultText += "Calculated Salary: $" + salary.ToString() + "\n";
			lastResultText += "\n";
			lastResultText += "Total Employees in System: " + (++employeeCount) + "\n";

			richTextBoxResults->Text = lastResultText;
		}
		else {
			richTextBoxResults->Text = "Error: You didn't enter a number of created details!";
			MessageBox::Show("You didn't enter a number of created details!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	else {
		richTextBoxResults->Text = "Error: Please select an employee type!";
		MessageBox::Show("Please select an employee type!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

private: System::Void comboBoxSelectEmployee_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int choice = comboBoxSelectEmployee->SelectedIndex;
	switch (choice)
	{
	case 0:
		labelGetNumberOfItem->Text = "Enter number of workers";
		break;
	case 1:
		labelGetNumberOfItem->Text = "Enter number of sold products";
		break;
	case 2:
		labelGetNumberOfItem->Text = "Enter number of created details";
		break;
	default:
		break;
	}
}

private: System::Void buttonClearResults_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBoxResults->Text = "Results will be displayed here...";
	textBoxNameOfWorker->Text = "";
	textBoxHourRate->Text = "";
	textBoxGetNumberOfItem->Text = "";
	comboBoxSelectEmployee->SelectedIndex = -1;
	employeeCount = 0;
	lastResultText = "";
}

private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(lastResultText)) {
		MessageBox::Show("No results to save! Please calculate results first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	SaveFileDialog^ path = gcnew SaveFileDialog();
	path->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	path->DefaultExt = "txt";
	path->FileName = "EmployeeResults";
	
	if (path->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		msclr::interop::marshal_context context;
		std::string file_path = context.marshal_as<std::string>(path->FileName);
		ofstream out_file(file_path);

		if (out_file.is_open()) {
			out_file << "Employee system:" << std::endl;
			out_file << context.marshal_as<std::string>(lastResultText) << std::endl;
			out_file << "System Status: Successfully Processed" << std::endl;
			out_file << "Total Employees Created: " << employeeCount << std::endl;

			out_file.close();
			MessageBox::Show("Results saved successfully to:\n" + path->FileName, "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
		else {
			MessageBox::Show("Error opening file for writing!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: System::Void textBoxHours_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
};
}