#pragma once

#include <vector>
#include <msclr/marshal_cppstd.h>
#include "../maneger.h"
#include "postfix.h"
#include "DialogToch.h"
#include "DialogPerem.h"


namespace CppWinForm1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		bool flag = false;
		maneger* men;
		int tec1 = -1;




		   int tec2 = -1;
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			doSom();
			flag = true;
			men = new maneger();

			/*men->Insert("key", TPolinom("x + y - z"));
			men->Insert("key1", TPolinom("x + y - z"));
			men->Insert("key2", TPolinom("x + y - z"));*/

			setTabel();
		}


		void setTabel() {



			int i = 0;
			int size = men->size();
			int sizeTable = Table1->RowCount;

			for (int i = 0; i < sizeTable; i++) {
				Table1->Rows[i]->Cells[0]->Value = "";
				Table1->Rows[i]->Cells[1]->Value = "";
			}
			
			if (size > sizeTable) {
				for (int i = sizeTable; i <= size; i++) {
					DataGridViewCell^ key0 = gcnew DataGridViewTextBoxCell();
					DataGridViewCell^ polinom0 = gcnew DataGridViewTextBoxCell();

					key0->Value = "";
					polinom0->Value = "";

					DataGridViewRow^ row0 = gcnew DataGridViewRow();
					row0->Cells->AddRange(key0, polinom0);
					Table1->Rows->AddRange(row0);
				}
			}

			maneger::iterator it(*men);
			while (!it.end()) {
				Line temp = (*it);
				Table1->Rows[i]->Cells[0]->Value = gcnew String(temp.key.c_str());
				Table1->Rows[i]->Cells[1]->Value = gcnew String(temp.value.ToString().c_str());

				it++; i++;
			}
	
		}
		
		void doSom() {

			
			
			this->Width = 800;
			this->Height = 400;

			Table1->Width = this->Width - 50;
			Table1->Height = this->Height - 150;

			DataGridViewTextBoxColumn^ colomn0 = gcnew DataGridViewTextBoxColumn();
			colomn0->Name = "key";
			colomn0->HeaderText = "Ключ";
			colomn0->Width = (Table1->Width - 50) * 0.2;

			DataGridViewTextBoxColumn^ colomn1 = gcnew DataGridViewTextBoxColumn();
			colomn1->Name = "polinom";
			colomn1->HeaderText = "Полином";
			colomn1->Width = (Table1->Width - 50) * 0.8;

			Table1->Columns->AddRange(colomn0, colomn1);

			int heigh = Table1->ColumnHeadersHeight;

			///
			for (int i = 0; i <(int)(Table1->Height / heigh) - 2; i++) {
				DataGridViewCell^ key0 = gcnew DataGridViewTextBoxCell();
				DataGridViewCell^ polinom0 = gcnew DataGridViewTextBoxCell();

				key0->Value = "";
				polinom0->Value = "";

				DataGridViewRow^ row0 = gcnew DataGridViewRow();
				row0->Cells->AddRange(key0, polinom0);
				Table1->Rows->AddRange(row0);
			}

		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;





	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ операцииНадОтдельнымиПолиномамиToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ операцииВВыраженияхИзПолиномовToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ вычислениеВТочкеToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ производнаяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ интегралToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сложениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вычитаниеToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ умножениеПолиномовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ делениеПолиномовToolStripMenuItem;





	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;



	private: System::Data::DataSet^ dataSet1;
	private: System::Windows::Forms::DataGridView^ Table1;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->операцииНадОтдельнымиПолиномамиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вычислениеВТочкеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->производнаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->интегралToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->операцииВВыраженияхИзПолиномовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сложениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вычитаниеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->умножениеПолиномовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->делениеПолиномовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackColor = System::Drawing::Color::LimeGreen;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(33, 579);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(238, 81);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Линейная на массиве";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// menuStrip2
			// 
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->операцииНадОтдельнымиПолиномамиToolStripMenuItem,
					this->операцииВВыраженияхИзПолиномовToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip2->Size = System::Drawing::Size(1581, 42);
			this->menuStrip2->TabIndex = 6;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// операцииНадОтдельнымиПолиномамиToolStripMenuItem
			// 
			this->операцииНадОтдельнымиПолиномамиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->вычислениеВТочкеToolStripMenuItem,
					this->производнаяToolStripMenuItem, this->интегралToolStripMenuItem
			});
			this->операцииНадОтдельнымиПолиномамиToolStripMenuItem->Name = L"операцииНадОтдельнымиПолиномамиToolStripMenuItem";
			this->операцииНадОтдельнымиПолиномамиToolStripMenuItem->Size = System::Drawing::Size(487, 36);
			this->операцииНадОтдельнымиПолиномамиToolStripMenuItem->Text = L"Операции над отдельными полиномами";
			// 
			// вычислениеВТочкеToolStripMenuItem
			// 
			this->вычислениеВТочкеToolStripMenuItem->Name = L"вычислениеВТочкеToolStripMenuItem";
			this->вычислениеВТочкеToolStripMenuItem->Size = System::Drawing::Size(374, 44);
			this->вычислениеВТочкеToolStripMenuItem->Text = L"Вычисление в точке";
			this->вычислениеВТочкеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::вычислениеВТочкеToolStripMenuItem_Click);
			// 
			// производнаяToolStripMenuItem
			// 
			this->производнаяToolStripMenuItem->Name = L"производнаяToolStripMenuItem";
			this->производнаяToolStripMenuItem->Size = System::Drawing::Size(374, 44);
			this->производнаяToolStripMenuItem->Text = L"Производная";
			this->производнаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::производнаяToolStripMenuItem_Click);
			// 
			// интегралToolStripMenuItem
			// 
			this->интегралToolStripMenuItem->Name = L"интегралToolStripMenuItem";
			this->интегралToolStripMenuItem->Size = System::Drawing::Size(374, 44);
			this->интегралToolStripMenuItem->Text = L"Интеграл";
			this->интегралToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::интегралToolStripMenuItem_Click);
			// 
			// операцииВВыраженияхИзПолиномовToolStripMenuItem
			// 
			this->операцииВВыраженияхИзПолиномовToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->сложениеToolStripMenuItem,
					this->вычитаниеToolStripMenuItem, this->умножениеПолиномовToolStripMenuItem, this->делениеПолиномовToolStripMenuItem
			});
			this->операцииВВыраженияхИзПолиномовToolStripMenuItem->Name = L"операцииВВыраженияхИзПолиномовToolStripMenuItem";
			this->операцииВВыраженияхИзПолиномовToolStripMenuItem->Size = System::Drawing::Size(478, 36);
			this->операцииВВыраженияхИзПолиномовToolStripMenuItem->Text = L"Операции в выражениях из полиномов";
			// 
			// сложениеToolStripMenuItem
			// 
			this->сложениеToolStripMenuItem->Name = L"сложениеToolStripMenuItem";
			this->сложениеToolStripMenuItem->Size = System::Drawing::Size(412, 44);
			this->сложениеToolStripMenuItem->Text = L"Сложение";
			this->сложениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сложениеToolStripMenuItem_Click);
			// 
			// вычитаниеToolStripMenuItem
			// 
			this->вычитаниеToolStripMenuItem->Name = L"вычитаниеToolStripMenuItem";
			this->вычитаниеToolStripMenuItem->Size = System::Drawing::Size(412, 44);
			this->вычитаниеToolStripMenuItem->Text = L"Вычитание";
			this->вычитаниеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::вычитаниеToolStripMenuItem_Click);
			// 
			// умножениеПолиномовToolStripMenuItem
			// 
			this->умножениеПолиномовToolStripMenuItem->Name = L"умножениеПолиномовToolStripMenuItem";
			this->умножениеПолиномовToolStripMenuItem->Size = System::Drawing::Size(412, 44);
			this->умножениеПолиномовToolStripMenuItem->Text = L"Умножение полиномов";
			this->умножениеПолиномовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::умножениеПолиномовToolStripMenuItem_Click);
			// 
			// делениеПолиномовToolStripMenuItem
			// 
			this->делениеПолиномовToolStripMenuItem->Name = L"делениеПолиномовToolStripMenuItem";
			this->делениеПолиномовToolStripMenuItem->Size = System::Drawing::Size(412, 44);
			this->делениеПолиномовToolStripMenuItem->Text = L"Деление полиномов";
			this->делениеПолиномовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::делениеПолиномовToolStripMenuItem_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackColor = System::Drawing::Color::LimeGreen;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(278, 579);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(238, 81);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Линейная на списке";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(522, 579);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(238, 81);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Упорядоченная на массиве";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button4->BackColor = System::Drawing::Color::LimeGreen;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(766, 579);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(238, 81);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Дерево";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->BackColor = System::Drawing::Color::LimeGreen;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(1011, 579);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(238, 81);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Хэш - 1";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button6->BackColor = System::Drawing::Color::LimeGreen;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(1256, 579);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(238, 81);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Хэш - 2";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// Table1
			// 
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Table1->Location = System::Drawing::Point(32, 59);
			this->Table1->Margin = System::Windows::Forms::Padding(40, 50, 40, 50);
			this->Table1->Name = L"Table1";
			this->Table1->RowHeadersWidth = 51;
			this->Table1->RowTemplate->Height = 24;
			this->Table1->Size = System::Drawing::Size(935, 446);
			this->Table1->TabIndex = 5;
			this->Table1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Table1_CellClick);
			this->Table1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Table1_CellEndEdit);
			this->Table1->CellParsing += gcnew System::Windows::Forms::DataGridViewCellParsingEventHandler(this, &MyForm::Table1_CellParsing);
			this->Table1->RowPrePaint += gcnew System::Windows::Forms::DataGridViewRowPrePaintEventHandler(this, &MyForm::Table1_RowPrePaint);
			this->Table1->UserDeletedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &MyForm::Table1_UserDeletedRow);
			this->Table1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &MyForm::Table1_UserDeletingRow);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::ForestGreen;
			this->ClientSize = System::Drawing::Size(1581, 700);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Table1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip2);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(800, 400);
			this->Name = L"MyForm";
			this->Text = L"Таблица";
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("LinerOnArray");
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("LinearOnList");
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("OrderedOnArray");
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("Tree");
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("HashList");
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		men->ChooseTable("HashChain");
	}


	private: System::Void MyForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (flag) {

			if (this->Width < 800)
				this->Width = 800;
			if (this->Height < 400)
				this->Height = 400;



			Table1->Width = this->Width - 50;
			Table1->Height = this->Height - 150;
			Table1->Columns["key"]->Width = (Table1->Width - 50) * 0.2;
			Table1->Columns["polinom"]->Width = (Table1->Width - 50) * 0.8;

			int heigh = Table1->ColumnHeadersHeight;

			for (int i = Table1->RowCount; i < (int)(Table1->Height / heigh) - 2; i++) {
				DataGridViewCell^ key0 = gcnew DataGridViewTextBoxCell();
				DataGridViewCell^ polinom0 = gcnew DataGridViewTextBoxCell();

				key0->Value = "";
				polinom0->Value = "";

				DataGridViewRow^ row0 = gcnew DataGridViewRow();
				row0->Cells->AddRange(key0, polinom0);
				Table1->Rows->AddRange(row0);
			}
		}
	}

private: System::Void Table1_UserDeletedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
	setTabel();
	int a = men->size();
}
private: System::Void Table1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e) {
	int del = e->Row->Index;
	string s = msclr::interop::marshal_as<std::string>(Table1->Rows[del]->Cells[0]->Value->ToString());
	men->Delete(s);
}
private: System::Void Table1_CellParsing(System::Object^ sender, System::Windows::Forms::DataGridViewCellParsingEventArgs^ e) {
	/*int h = e->RowIndex;
	int w = e->ColumnIndex;
	if (w == 0) {
		if (value != nullptr) {
			string key = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[0]->Value->ToString());
			men->Insert(key, *value);
			delete value;
			value = nullptr;
			setTabel();
			this->Text = gcnew String(key.c_str());
		}
		else {
			key = new string(msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[0]->Value->ToString()));
		}

	}
	if (w == 1) {
		if (key != nullptr) {
			string value = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[1]->Value->ToString());
			men->Insert(*key, value);
			delete key;
			key = nullptr;
			setTabel();
		}
		else {
			value = new string(msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[1]->Value->ToString()));
		}
	}*/
	
}
private: System::Void Table1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int h = e->RowIndex;
	int w = e->ColumnIndex;
	if (w == 0) {
		if (Table1->Rows[h]->Cells[1]->Value->ToString() != "") {
			string key = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[0]->Value->ToString());
			string value = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[1]->Value->ToString());
			men->Insert(key, value);
			setTabel();
		}

	}
	if (w == 1) {
		if (Table1->Rows[h]->Cells[0]->Value->ToString() != "") {
			string value = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[1]->Value->ToString());
			string key = msclr::interop::marshal_as<std::string>(Table1->Rows[h]->Cells[0]->Value->ToString());
			men->Insert(key, value);
			setTabel();
		}
	}
}
	  
	   
private: System::Void Table1_RowPrePaint(System::Object^ sender, System::Windows::Forms::DataGridViewRowPrePaintEventArgs^ e) {
	DataGridViewRow^ row = Table1->Rows[e->RowIndex];

	// Проверяем условие для определенной строки (например, возраст > 30)
	if (e->RowIndex == tec1)
	{
		row->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(121,245,138); // Задаем желтый цвет фона для строки
	}
	else if (e->RowIndex == tec2)
	{
		row->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(224, 242, 62); // Задаем желтый цвет фона для строки
	}
	else {
		row->DefaultCellStyle->BackColor = System::Drawing::Color::White;
	}
}
private: System::Void Table1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int t = e->RowIndex;
	tec2 = tec1;
	tec1 = t;
}
private: System::Void сложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());

	string value2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[1]->Value->ToString());
	string key2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[0]->Value->ToString());

	TPolinom* pol1 = men->Find(key1);
	TPolinom* pol2 = men->Find(key2);
	if (pol1 != nullptr && pol2 != nullptr) {
		men->Insert(key1 + " + " + key2, *pol1 + *pol2);
		setTabel();
	}
}
	   

private: System::Void вычитаниеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());

	string value2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[1]->Value->ToString());
	string key2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[0]->Value->ToString());

	TPolinom* pol1 = men->Find(key1);
	TPolinom* pol2 = men->Find(key2);
	if (pol1 != nullptr && pol2 != nullptr) {
		men->Insert(key1 + " - " + key2, *pol1 - *pol2);
		setTabel();
	}
}
private: System::Void умножениеПолиномовToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());

	string value2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[1]->Value->ToString());
	string key2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[0]->Value->ToString());

	TPolinom* pol1 = men->Find(key1);
	TPolinom* pol2 = men->Find(key2);
	if (pol1 != nullptr && pol2 != nullptr) {
		men->Insert(key1 + " * " + key2, *pol1 * *pol2);
		setTabel();
	}
}
private: System::Void делениеПолиномовToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());

	string value2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[1]->Value->ToString());
	string key2 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec2]->Cells[0]->Value->ToString());

	TPolinom* pol1 = men->Find(key1);
	TPolinom* pol2 = men->Find(key2);
	if (pol1 != nullptr && pol2 != nullptr) {
		men->Insert(key1 + " / " + key2, *pol1 / *pol2);
		setTabel();
	}
}
private: System::Void производнаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CppWinDialogPeremForm::DialogPeremForm^ form = gcnew CppWinDialogPeremForm::DialogPeremForm("Производная по:");
	form->ShowDialog();
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());
	TPolinom* pol1 = men->Find(key1);
	if (pol1 != nullptr) {
		men->Insert(key1 + "_der",pol1->derivative(form->c));
	}
	setTabel();
}
private: System::Void toolStripTextBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void вычислениеВТочкеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CppWinDialogTochForm::DialogTochForm^ form = gcnew CppWinDialogTochForm::DialogTochForm();
	form->ShowDialog();
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());
	TPolinom* pol1 = men->Find(key1);
	if (pol1 != nullptr) {
		postfix::calculator a((*pol1).ToPostfix());
		auto var = a.GetVar();
		for (auto& a : var) {
			if (a.first == "x" || a.first == "X")
				a.second = form->x;
			if (a.first == "y" || a.first == "Y")
				a.second = form->y;
			if (a.first == "z" || a.first == "Z")
				a.second = form->z;		
		}
		a.SetVar(var);
		String^ s = gcnew String(to_string((int)a.Ansver()).c_str());

		MessageBox::Show(s, L"Результат:", MessageBoxButtons::OK);
			
	}
	


}
private: System::Void интегралToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	CppWinDialogPeremForm::DialogPeremForm^ form = gcnew CppWinDialogPeremForm::DialogPeremForm("   Интеграл по:");
	form->ShowDialog();
	string value1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[1]->Value->ToString());
	string key1 = msclr::interop::marshal_as<std::string>(Table1->Rows[tec1]->Cells[0]->Value->ToString());
	TPolinom* pol1 = men->Find(key1);
	if (pol1 != nullptr) {
		men->Insert(key1 + "_ins", pol1->Integral(form->c));
	}
	setTabel();
}
};
}
