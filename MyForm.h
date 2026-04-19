#pragma once

#include "CEmployee.h"
#include "CManagerEmployee.h"
#include "CSalesmanEmployee.h"
#include "CEngineerEmployee.h"
#include "CSpecialistEmployee.h"
#include "EmployeeUtils.h"

#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <sstream>
#include <iostream>
namespace ooplab7prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;
	using namespace std;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			employee = new CEmployee*[10];
			for (int i = 0; i < 10; i++) employee[i] = nullptr;
		}

	protected:
		~MyForm()				
		{
			if (employee)
			{
				for (int i = 0; i < 10; i++)
				{
					if (employee[i] != nullptr)
					{
						delete employee[i];
						employee[i] = nullptr;
					}
				}
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
	private: System::Windows::Forms::Button^ buttonShowAll;
	private: System::Windows::Forms::Button^ buttonCalculateTotal;
	private: System::Windows::Forms::Button^ buttonStatistics;

	private: System::Windows::Forms::Label^ labelNameOfWorker;
	private: System::Windows::Forms::ComboBox^ comboBoxSelectEmployee;
	private: System::Windows::Forms::TextBox^ textBoxNameOfWorker;
	private: System::Windows::Forms::TextBox^ textBoxHourRate;
	private: System::Windows::Forms::TextBox^ textBoxGetNumberOfItem;
	private: System::Windows::Forms::TextBox^ textBoxWorkedHours;

	private: System::Windows::Forms::Label^ labelHoursRate;
	private: System::Windows::Forms::Label^ labelSelectEmployee;
	private: System::Windows::Forms::Label^ labelGetNumberOfItem;
	private: System::Windows::Forms::Label^ labelWorkedHours;
	private: System::Windows::Forms::Label^ labelSpecialistBonus;
	private: System::Windows::Forms::TextBox^ textBoxSpecialistBonus;

	private: System::Windows::Forms::SaveFileDialog^ saveFileTxt;
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::RichTextBox^ richTextBoxResults;

	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;

	private:
		double salary = 0.0;
		double h_rate = 0.0;
		int num_of_item = 0;
		int choice = 0;
		CEmployee** employee = nullptr;
		int employeeCount = 0;
		String^ lastResultText = "";

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->buttonGetResult = (gcnew System::Windows::Forms::Button());
			this->buttonClearResults = (gcnew System::Windows::Forms::Button());
			this->buttonShowAll = (gcnew System::Windows::Forms::Button());
			this->buttonCalculateTotal = (gcnew System::Windows::Forms::Button());
			this->buttonStatistics = (gcnew System::Windows::Forms::Button());
			this->labelNameOfWorker = (gcnew System::Windows::Forms::Label());
			this->comboBoxSelectEmployee = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxNameOfWorker = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRate = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGetNumberOfItem = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWorkedHours = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSpecialistBonus = (gcnew System::Windows::Forms::TextBox());
			this->labelHoursRate = (gcnew System::Windows::Forms::Label());
			this->labelSelectEmployee = (gcnew System::Windows::Forms::Label());
			this->labelGetNumberOfItem = (gcnew System::Windows::Forms::Label());
			this->labelWorkedHours = (gcnew System::Windows::Forms::Label());
			this->labelSpecialistBonus = (gcnew System::Windows::Forms::Label());
			this->richTextBoxResults = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileTxt = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonGetResult
			// 
			this->buttonGetResult->Location = System::Drawing::Point(30, 310);
			this->buttonGetResult->Name = L"buttonGetResult";
			this->buttonGetResult->Size = System::Drawing::Size(140, 35);
			this->buttonGetResult->TabIndex = 13;
			this->buttonGetResult->Text = L"Add Employee";
			this->buttonGetResult->UseVisualStyleBackColor = true;
			this->buttonGetResult->Click += gcnew System::EventHandler(this, &MyForm::buttonGetResult_Click);
			// 
			// buttonClearResults
			// 
			this->buttonClearResults->Location = System::Drawing::Point(30, 390);
			this->buttonClearResults->Name = L"buttonClearResults";
			this->buttonClearResults->Size = System::Drawing::Size(290, 35);
			this->buttonClearResults->TabIndex = 17;
			this->buttonClearResults->Text = L"Clear Results";
			this->buttonClearResults->UseVisualStyleBackColor = true;
			this->buttonClearResults->Click += gcnew System::EventHandler(this, &MyForm::buttonClearResults_Click);
			// 
			// buttonShowAll
			// 
			this->buttonShowAll->Location = System::Drawing::Point(180, 310);
			this->buttonShowAll->Name = L"buttonShowAll";
			this->buttonShowAll->Size = System::Drawing::Size(140, 35);
			this->buttonShowAll->TabIndex = 14;
			this->buttonShowAll->Text = L"Show All";
			this->buttonShowAll->UseVisualStyleBackColor = true;
			this->buttonShowAll->Click += gcnew System::EventHandler(this, &MyForm::buttonShowAll_Click);
			// 
			// buttonCalculateTotal
			// 
			this->buttonCalculateTotal->Location = System::Drawing::Point(30, 350);
			this->buttonCalculateTotal->Name = L"buttonCalculateTotal";
			this->buttonCalculateTotal->Size = System::Drawing::Size(140, 35);
			this->buttonCalculateTotal->TabIndex = 15;
			this->buttonCalculateTotal->Text = L"Calculate Total";
			this->buttonCalculateTotal->UseVisualStyleBackColor = true;
			this->buttonCalculateTotal->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculateTotal_Click);
			// 
			// buttonStatistics
			// 
			this->buttonStatistics->Location = System::Drawing::Point(180, 350);
			this->buttonStatistics->Name = L"buttonStatistics";
			this->buttonStatistics->Size = System::Drawing::Size(140, 35);
			this->buttonStatistics->TabIndex = 16;
			this->buttonStatistics->Text = L"Statistics";
			this->buttonStatistics->UseVisualStyleBackColor = true;
			this->buttonStatistics->Click += gcnew System::EventHandler(this, &MyForm::buttonStatistics_Click);
			// 
			// labelNameOfWorker
			// 
			this->labelNameOfWorker->AutoSize = true;
			this->labelNameOfWorker->Location = System::Drawing::Point(30, 100);
			this->labelNameOfWorker->Name = L"labelNameOfWorker";
			this->labelNameOfWorker->Size = System::Drawing::Size(56, 19);
			this->labelNameOfWorker->TabIndex = 2;
			this->labelNameOfWorker->Text = L"Name:";
			// 
			// comboBoxSelectEmployee
			// 
			this->comboBoxSelectEmployee->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSelectEmployee->FormattingEnabled = true;
			this->comboBoxSelectEmployee->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Manager", L"Salesman", L"Engineer",
					L"Specialist"
			});
			this->comboBoxSelectEmployee->Location = System::Drawing::Point(180, 40);
			this->comboBoxSelectEmployee->Name = L"comboBoxSelectEmployee";
			this->comboBoxSelectEmployee->Size = System::Drawing::Size(150, 26);
			this->comboBoxSelectEmployee->TabIndex = 7;
			this->comboBoxSelectEmployee->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxSelectEmployee_SelectedIndexChanged);
			// 
			// textBoxNameOfWorker
			// 
			this->textBoxNameOfWorker->Location = System::Drawing::Point(180, 100);
			this->textBoxNameOfWorker->Name = L"textBoxNameOfWorker";
			this->textBoxNameOfWorker->Size = System::Drawing::Size(150, 26);
			this->textBoxNameOfWorker->TabIndex = 8;
			// 
			// textBoxHourRate
			// 
			this->textBoxHourRate->Location = System::Drawing::Point(180, 140);
			this->textBoxHourRate->Name = L"textBoxHourRate";
			this->textBoxHourRate->Size = System::Drawing::Size(150, 26);
			this->textBoxHourRate->TabIndex = 9;
			// 
			// textBoxGetNumberOfItem
			// 
			this->textBoxGetNumberOfItem->Location = System::Drawing::Point(180, 180);
			this->textBoxGetNumberOfItem->Name = L"textBoxGetNumberOfItem";
			this->textBoxGetNumberOfItem->Size = System::Drawing::Size(150, 26);
			this->textBoxGetNumberOfItem->TabIndex = 10;
			// 
			// textBoxWorkedHours
			// 
			this->textBoxWorkedHours->Location = System::Drawing::Point(180, 220);
			this->textBoxWorkedHours->Name = L"textBoxWorkedHours";
			this->textBoxWorkedHours->Size = System::Drawing::Size(150, 26);
			this->textBoxWorkedHours->TabIndex = 11;
			this->textBoxWorkedHours->Text = L"40";
			// 
			// textBoxSpecialistBonus
			// 
			this->textBoxSpecialistBonus->Location = System::Drawing::Point(180, 260);
			this->textBoxSpecialistBonus->Name = L"textBoxSpecialistBonus";
			this->textBoxSpecialistBonus->Size = System::Drawing::Size(150, 26);
			this->textBoxSpecialistBonus->TabIndex = 12;
			this->textBoxSpecialistBonus->Visible = false;
			// 
			// labelHoursRate
			// 
			this->labelHoursRate->AutoSize = true;
			this->labelHoursRate->Location = System::Drawing::Point(30, 140);
			this->labelHoursRate->Name = L"labelHoursRate";
			this->labelHoursRate->Size = System::Drawing::Size(87, 19);
			this->labelHoursRate->TabIndex = 3;
			this->labelHoursRate->Text = L"Hour Rate:";
			// 
			// labelSelectEmployee
			// 
			this->labelSelectEmployee->AutoSize = true;
			this->labelSelectEmployee->Location = System::Drawing::Point(12, 43);
			this->labelSelectEmployee->Name = L"labelSelectEmployee";
			this->labelSelectEmployee->Size = System::Drawing::Size(176, 19);
			this->labelSelectEmployee->TabIndex = 1;
			this->labelSelectEmployee->Text = L"Select Employee Type:";
			// 
			// labelGetNumberOfItem
			// 
			this->labelGetNumberOfItem->AutoSize = true;
			this->labelGetNumberOfItem->Location = System::Drawing::Point(30, 180);
			this->labelGetNumberOfItem->Name = L"labelGetNumberOfItem";
			this->labelGetNumberOfItem->Size = System::Drawing::Size(101, 19);
			this->labelGetNumberOfItem->TabIndex = 4;
			this->labelGetNumberOfItem->Text = L"Count/Items:";
			// 
			// labelWorkedHours
			// 
			this->labelWorkedHours->AutoSize = true;
			this->labelWorkedHours->Location = System::Drawing::Point(30, 220);
			this->labelWorkedHours->Name = L"labelWorkedHours";
			this->labelWorkedHours->Size = System::Drawing::Size(120, 19);
			this->labelWorkedHours->TabIndex = 5;
			this->labelWorkedHours->Text = L"Worked Hours:";
			// 
			// labelSpecialistBonus
			// 
			this->labelSpecialistBonus->AutoSize = true;
			this->labelSpecialistBonus->Location = System::Drawing::Point(30, 260);
			this->labelSpecialistBonus->Name = L"labelSpecialistBonus";
			this->labelSpecialistBonus->Size = System::Drawing::Size(135, 19);
			this->labelSpecialistBonus->TabIndex = 6;
			this->labelSpecialistBonus->Text = L"Specialist Bonus:";
			this->labelSpecialistBonus->Visible = false;
			// 
			// richTextBoxResults
			// 
			this->richTextBoxResults->Location = System::Drawing::Point(30, 440);
			this->richTextBoxResults->Name = L"richTextBoxResults";
			this->richTextBoxResults->ReadOnly = true;
			this->richTextBoxResults->Size = System::Drawing::Size(840, 280);
			this->richTextBoxResults->TabIndex = 18;
			this->richTextBoxResults->Text = L"";
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(900, 28);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(123, 26);
			this->saveToolStripMenuItem->Text = L"&Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(123, 26);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"&Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(133, 26);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 750);
			this->Controls->Add(this->menuStrip);
			this->Controls->Add(this->labelSelectEmployee);
			this->Controls->Add(this->comboBoxSelectEmployee);
			this->Controls->Add(this->labelNameOfWorker);
			this->Controls->Add(this->textBoxNameOfWorker);
			this->Controls->Add(this->labelHoursRate);
			this->Controls->Add(this->textBoxHourRate);
			this->Controls->Add(this->labelGetNumberOfItem);
			this->Controls->Add(this->textBoxGetNumberOfItem);
			this->Controls->Add(this->labelWorkedHours);
			this->Controls->Add(this->textBoxWorkedHours);
			this->Controls->Add(this->labelSpecialistBonus);
			this->Controls->Add(this->textBoxSpecialistBonus);
			this->Controls->Add(this->buttonGetResult);
			this->Controls->Add(this->buttonShowAll);
			this->Controls->Add(this->buttonCalculateTotal);
			this->Controls->Add(this->buttonStatistics);
			this->Controls->Add(this->buttonClearResults);
			this->Controls->Add(this->richTextBoxResults);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F));
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"Lab 8";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void comboBoxSelectEmployee_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int index = comboBoxSelectEmployee->SelectedIndex;

		labelSpecialistBonus->Visible = (index == 3);
		textBoxSpecialistBonus->Visible = (index == 3);

		switch (index) {
			case 0: // Manager
				labelGetNumberOfItem->Text = L"Number of Workers:";
				break;
			case 1: // Salesman
				labelGetNumberOfItem->Text = L"Products Sold:";
				break;
			case 2: // Engineer
				labelGetNumberOfItem->Text = L"Fixed Details:";
				break;
			case 3: // Specialist
				labelGetNumberOfItem->Text = L"Count/Items:";
				break;
		}
	}

	private: System::Void buttonGetResult_Click(System::Object^ sender, System::EventArgs^ e) {
		if (employeeCount >= 10) {
			richTextBoxResults->Text = "Error: Maximum 10 employees allowed!";
			MessageBox::Show("Maximum capacity reached!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		string name;
		if (String::IsNullOrWhiteSpace(textBoxNameOfWorker->Text)) {
			richTextBoxResults->Text = "Error: You didn't enter a name!";
			MessageBox::Show("You didn't enter a name!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		name = marshal_as<string>(textBoxNameOfWorker->Text);

		if (String::IsNullOrWhiteSpace(textBoxHourRate->Text)) {
			richTextBoxResults->Text = "Error: You didn't enter an hour rate!";
			MessageBox::Show("You didn't enter an hour rate!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		double rate = 0;
		if (!String::IsNullOrWhiteSpace(textBoxHourRate->Text)) {
			rate = Convert::ToDouble(textBoxHourRate->Text);
		}
		else {
			richTextBoxResults->Text = "Error: Invalid hour rate format!";
			MessageBox::Show("Invalid hour rate!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		choice = comboBoxSelectEmployee->SelectedIndex;
		if (choice < 0 || choice > 3) {
			richTextBoxResults->Text = "Error: Please select an employee type!";
			MessageBox::Show("Please select an employee type!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			richTextBoxResults->Text = "Error: You didn't enter required data!";
			MessageBox::Show("Please enter all required fields!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int items = 0;
		if (!String::IsNullOrWhiteSpace(textBoxGetNumberOfItem->Text)) {
			items = Convert::ToInt32(textBoxGetNumberOfItem->Text);
		}
		else {
			richTextBoxResults->Text = "Error: Invalid number format!";
			MessageBox::Show("Invalid input!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		lastResultText = "";

		if (choice == 0) {
			// Manager
			employee[employeeCount] = new CManagerEmployee(name, rate, items);
			lastResultText = "Manager added!\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Hour Rate: $" + rate.ToString() + "/hour\n";
			lastResultText += "Workers Managed: " + items + "\n";
		}
		else if (choice == 1) {
			// Salesman
			employee[employeeCount] = new CSalesmanEmployee(name, rate, items);
			lastResultText = "Salesman added!\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Hour Rate: $" + rate.ToString() + "/hour\n";
			lastResultText += "Products Sold: " + items + "\n";
		}
		else if (choice == 2) {
			// Engineer
			employee[employeeCount] = new CEngineerEmployee(name, rate, items);
			lastResultText = "Engineer added!\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Hour Rate: $" + rate.ToString() + "/hour\n";
			lastResultText += "Fixed Details: " + items + "\n";
		}
		else if (choice == 3) {
			// Specialist
			if (String::IsNullOrWhiteSpace(textBoxSpecialistBonus->Text)) {
				richTextBoxResults->Text = "Error: You didn't enter specialist bonus!";
				MessageBox::Show("Please enter specialist bonus!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			double bonus = 0;
			if (!String::IsNullOrWhiteSpace(textBoxSpecialistBonus->Text)) {
				bonus = Convert::ToDouble(textBoxSpecialistBonus->Text);
			}
			else {
				richTextBoxResults->Text = "Error: Invalid bonus format!";
				MessageBox::Show("Invalid bonus!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			employee[employeeCount] = new CSpecialistEmployee(name, rate, items, items / 2, bonus);
			lastResultText = "Specialist added\n";
			lastResultText += "Name: " + textBoxNameOfWorker->Text + "\n";
			lastResultText += "Hour Rate: $" + rate.ToString() + "/hour\n";
			lastResultText += "Workers: " + items + " | Sales: " + (items / 2) + "\n";
			lastResultText += "Specialist Bonus: $" + bonus.ToString() + "\n";
		}

		lastResultText += "\nTotal Employees: " + (++employeeCount) + "/10\n";
		richTextBoxResults->Text = lastResultText;
	}

	private: System::Void buttonShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
		DisplayAllEmployeesInfo(employee, employeeCount);
		
		string output = "";
		ostringstream oss;
		
		for (int i = 0; i < employeeCount; i++) {
			if (employee[i] != nullptr) {
				cout.flush();
			}
		}

		String^ msg = "All employees information displayed in console window\n";
		msg += "Total employees in system: " + employeeCount + "\n\n";
		richTextBoxResults->Text = msg;
	}

	private: System::Void buttonCalculateTotal_Click(System::Object^ sender, System::EventArgs^ e) {
		if (employeeCount == 0) {
			richTextBoxResults->Text = "Error: No employees added!";
			return;
		}

		if (String::IsNullOrWhiteSpace(textBoxWorkedHours->Text)) {
			richTextBoxResults->Text = "Error: Please enter worked hours!";
			MessageBox::Show("Please enter worked hours!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		double hours = 0;
		if (!String::IsNullOrWhiteSpace(textBoxWorkedHours->Text)) {
			hours = Convert::ToDouble(textBoxWorkedHours->Text);
		}
		else {
			richTextBoxResults->Text = "Error: Invalid hours format!";
			MessageBox::Show("Invalid hours!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		double total = CalculateTotalSalary(employee, employeeCount, hours);

		String^ result = "Salary calculation\n";
		result += "Working Hours: " + hours + "\n";
		result += "Total Employees: " + employeeCount + "\n\n";
		result += "Breakdown:\n";

		for (int i = 0; i < employeeCount; i++) {
			if (employee[i] != nullptr) {
				double salary = employee[i]->CalculateSalaryForHours(hours);
				result += "  Employee " + (i + 1) + ": $" + salary.ToString("F2") + "\n";
			}
		}

		result += "\nTotal salary: $" + total.ToString("F2") + "\n";
		richTextBoxResults->Text = result;
	}

	private: System::Void buttonStatistics_Click(System::Object^ sender, System::EventArgs^ e) {
		if (employeeCount == 0) {
			richTextBoxResults->Text = "Error: No employees added!";
			return;
		}

		CountEmployeesByType(employee, employeeCount);

		int managers = 0, salesmen = 0, engineers = 0, specialists = 0;

		for (int i = 0; i < employeeCount; i++) {
			if (employee[i] != nullptr) {
				if (dynamic_cast<CSpecialistEmployee*>(employee[i]) != nullptr)
					specialists++;
				else if (dynamic_cast<CManagerEmployee*>(employee[i]) != nullptr)
					managers++;
				else if (dynamic_cast<CSalesmanEmployee*>(employee[i]) != nullptr)
					salesmen++;
				else if (dynamic_cast<CEngineerEmployee*>(employee[i]) != nullptr)
					engineers++;
			}
		}

		String^ stats = "Employee statistic\n";
		stats += "Total Employees: " + employeeCount + "/10\n\n";
		stats += "  Managers: " + managers + "\n";
		stats += "  Salesmen: " + salesmen + "\n";
		stats += "  Engineers: " + engineers + "\n";
		stats += "  Specialists: " + specialists + "\n";

		richTextBoxResults->Text = stats;
	}

	private: System::Void buttonClearResults_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBoxResults->Clear();
		textBoxNameOfWorker->Clear();
		textBoxHourRate->Clear();
		textBoxGetNumberOfItem->Clear();
		textBoxSpecialistBonus->Clear();
		comboBoxSelectEmployee->SelectedIndex = 0;
	}

	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileTxt->FileName = "EmployeeData.txt";
		if (saveFileTxt->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamWriter^ writer = gcnew StreamWriter(saveFileTxt->FileName);
			writer->WriteLine("Employee data");
			writer->WriteLine("Total Employees: " + employeeCount);
			writer->WriteLine("");
			
			for (int i = 0; i < employeeCount; i++) {
				if (employee[i] != nullptr) {
					writer->WriteLine("Employee #" + (i + 1));
					writer->WriteLine("Name: " + gcnew String(employee[i]->GetName().c_str()));
					writer->WriteLine("Hour Rate: $" + employee[i]->GetHourRate());
					writer->WriteLine("Salary (40 hrs): $" + employee[i]->CalculateSalaryForHours(40));
					writer->WriteLine("");
				}
			}

			writer->Close();
			MessageBox::Show("Data saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//String^ about = "Lab 8\n\n";
		//about += "This application demonstrates:\n";
		//about += "1. POLYMORPHISM:\n";
		//about += "   - Abstract base class (CEmployee) with pure virtual functions\n";
		//about += "   - Virtual destructor for proper cleanup\n";
		//about += "   - Polymorphic function calls through base class pointers\n\n";
		//about += "2. DYNAMIC_CAST:\n";
		//about += "   - Safe type conversion at runtime\n";
		//about += "   - Type checking before operations\n\n";
		//about += "3. MULTIPLE INHERITANCE:\n";
		//about += "   - CSpecialistEmployee inherits from CManagerEmployee and CSalesmanEmployee\n";
		//about += "   - VIRTUAL INHERITANCE to solve diamond problem\n";
		//about += "   - EXPLICIT ACCESS using scope resolution (::)\n";
		//about += "   - FUNCTION OVERRIDING for ambiguity resolution\n\n";
		//about += "Employee Types:\n";
		//about += "• Manager: $31/hour + $13 per worker\n";
		//about += "• Salesman: $25/hour + $50 per sale\n";
		//about += "• Engineer: $35/hour + $20 per detail fixed\n";
		//about += "• Specialist: Combined manager + salesman roles\n";

		//MessageBox::Show(about, "About Lab 8", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
}