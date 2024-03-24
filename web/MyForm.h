#pragma once



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


	public:
		MyForm(void)
		{
			InitializeComponent();
			doSom();
		}
		
		void doSom() {
			DataGridViewTextBoxColumn^ colomn0 = gcnew DataGridViewTextBoxColumn();
			colomn0->Name = "key";
			colomn0->HeaderText = "����";
			colomn0->Width = 200;

			DataGridViewTextBoxColumn^ colomn1 = gcnew DataGridViewTextBoxColumn();
			colomn1->Name = "polinom";
			colomn1->HeaderText = "�������";
			colomn1->Width = 649;

			Table1->Columns->AddRange(colomn0, colomn1);
			///
			DataGridViewCell^ key0 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom0 = gcnew DataGridViewTextBoxCell();

			key0->Value = "";
			polinom0->Value = "";
		
			DataGridViewRow^ row0 = gcnew DataGridViewRow();
			row0->Cells->AddRange(key0, polinom0);
			Table1->Rows->AddRange(row0);
			///
			DataGridViewCell^ key1 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom1 = gcnew DataGridViewTextBoxCell();

			key1->Value = "";
			polinom1->Value = "";

			DataGridViewRow^ row1 = gcnew DataGridViewRow();
			row1->Cells->AddRange(key1, polinom1);
			Table1->Rows->AddRange(row1);
			///
			DataGridViewCell^ key2 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom2 = gcnew DataGridViewTextBoxCell();

			key2->Value = "";
			polinom2->Value = "";

			DataGridViewRow^ row2 = gcnew DataGridViewRow();
			row2->Cells->AddRange(key2, polinom2);
			Table1->Rows->AddRange(row2);
			///
			DataGridViewCell^ key3 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom3 = gcnew DataGridViewTextBoxCell();

			key3->Value = "";
			polinom3->Value = "";

			DataGridViewRow^ row3 = gcnew DataGridViewRow();
			row3->Cells->AddRange(key3, polinom3);
			Table1->Rows->AddRange(row3);
			///
			DataGridViewCell^ key4 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom4 = gcnew DataGridViewTextBoxCell();

			key4->Value = "";
			polinom4->Value = "";

			DataGridViewRow^ row4 = gcnew DataGridViewRow();
			row4->Cells->AddRange(key4, polinom4);
			Table1->Rows->AddRange(row4);
			///
			DataGridViewCell^ key5 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom5 = gcnew DataGridViewTextBoxCell();

			key5->Value = "";
			polinom5->Value = "";

			DataGridViewRow^ row5 = gcnew DataGridViewRow();
			row5->Cells->AddRange(key5, polinom5);
			Table1->Rows->AddRange(row5);
			///
			DataGridViewCell^ key6 = gcnew DataGridViewTextBoxCell();
			DataGridViewCell^ polinom6 = gcnew DataGridViewTextBoxCell();

			key6->Value = "";
			polinom6->Value = "";

			DataGridViewRow^ row6 = gcnew DataGridViewRow();
			row6->Cells->AddRange(key6, polinom6);
			Table1->Rows->AddRange(row6);
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
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������������������ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������������ToolStripMenuItem;
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
			this->�������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->button1->BackColor = System::Drawing::Color::LimeGreen;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(14, 324);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�������� �� �������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�������������������������������ToolStripMenuItem,
					this->������������������������������ToolStripMenuItem, this->��������������������ToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1229, 28);
			this->menuStrip2->TabIndex = 6;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// �������������������������������ToolStripMenuItem
			// 
			this->�������������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->����������������ToolStripMenuItem,
					this->��������������������ToolStripMenuItem, this->�����������ToolStripMenuItem, this->��������ToolStripMenuItem
			});
			this->�������������������������������ToolStripMenuItem->Name = L"�������������������������������ToolStripMenuItem";
			this->�������������������������������ToolStripMenuItem->Size = System::Drawing::Size(311, 24);
			this->�������������������������������ToolStripMenuItem->Text = L"�������� ��� ���������� ����������";
			this->�������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������������������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(268, 26);
			this->����������������ToolStripMenuItem->Text = L"���������� � �����";
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(268, 26);
			this->��������������������ToolStripMenuItem->Text = L"��������� �� ���������";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(268, 26);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(268, 26);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ������������������������������ToolStripMenuItem
			// 
			this->������������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->��������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->��������������������ToolStripMenuItem1, this->������������������ToolStripMenuItem, this->����������������ToolStripMenuItem,
					this->������������������������������ToolStripMenuItem
			});
			this->������������������������������ToolStripMenuItem->Name = L"������������������������������ToolStripMenuItem";
			this->������������������������������ToolStripMenuItem->Size = System::Drawing::Size(304, 24);
			this->������������������������������ToolStripMenuItem->Text = L"�������� � ���������� �� ���������";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(351, 26);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(351, 26);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// ��������������������ToolStripMenuItem1
			// 
			this->��������������������ToolStripMenuItem1->Name = L"��������������������ToolStripMenuItem1";
			this->��������������������ToolStripMenuItem1->Size = System::Drawing::Size(351, 26);
			this->��������������������ToolStripMenuItem1->Text = L"��������� �� ���������";
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(351, 26);
			this->������������������ToolStripMenuItem->Text = L"��������� ���������";
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(351, 26);
			this->����������������ToolStripMenuItem->Text = L"������� ���������";
			// 
			// ������������������������������ToolStripMenuItem
			// 
			this->������������������������������ToolStripMenuItem->Name = L"������������������������������ToolStripMenuItem";
			this->������������������������������ToolStripMenuItem->Size = System::Drawing::Size(351, 26);
			this->������������������������������ToolStripMenuItem->Text = L"������������� ����������� �����";
			this->������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������������������������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->������������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem, this->�����ToolStripMenuItem, this->���������������������������ToolStripMenuItem
			});
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(205, 24);
			this->��������������������ToolStripMenuItem->Text = L"�������� ��� ���������";
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->������������������ToolStripMenuItem->Text = L"���������� ��������";
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->����������������ToolStripMenuItem->Text = L"�������� ��������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->�����ToolStripMenuItem->Text = L"�����";
			// 
			// ���������������������������ToolStripMenuItem
			// 
			this->���������������������������ToolStripMenuItem->Name = L"���������������������������ToolStripMenuItem";
			this->���������������������������ToolStripMenuItem->Size = System::Drawing::Size(335, 26);
			this->���������������������������ToolStripMenuItem->Text = L"����� �������� ������� �� �����";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LimeGreen;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(177, 324);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 52);
			this->button2->TabIndex = 7;
			this->button2->Text = L"�������� �� ������";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(340, 324);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 52);
			this->button3->TabIndex = 8;
			this->button3->Text = L"������������� �� �������";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LimeGreen;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(503, 324);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(159, 52);
			this->button4->TabIndex = 9;
			this->button4->Text = L"������";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LimeGreen;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(666, 324);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(159, 52);
			this->button5->TabIndex = 10;
			this->button5->Text = L"��� - 1";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LimeGreen;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(829, 324);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(159, 52);
			this->button6->TabIndex = 11;
			this->button6->Text = L"��� - 2";
			this->button6->UseVisualStyleBackColor = false;
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
			this->Table1->Location = System::Drawing::Point(12, 42);
			this->Table1->Name = L"Table1";
			this->Table1->RowHeadersWidth = 51;
			this->Table1->RowTemplate->Height = 24;
			this->Table1->Size = System::Drawing::Size(1205, 268);
			this->Table1->TabIndex = 5;
			this->Table1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::ForestGreen;
			this->ClientSize = System::Drawing::Size(1229, 398);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->Table1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"MyForm";
			this->Text = L"�������";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	
	

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void �������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void ������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
