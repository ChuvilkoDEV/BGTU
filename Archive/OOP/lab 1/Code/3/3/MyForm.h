#pragma once

namespace My3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ asd;
	protected:

	protected:

	private: System::Windows::Forms::ImageList^ imageList1;






















	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button4;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->asd = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// asd
			// 
			this->asd->AutoSize = true;
			this->asd->Location = System::Drawing::Point(12, 9);
			this->asd->Name = L"asd";
			this->asd->Size = System::Drawing::Size(88, 17);
			this->asd->TabIndex = 0;
			this->asd->Text = L"Устройства:";
			this->asd->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(213, 496);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 31);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Ок";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(312, 496);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 31);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(409, 496);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 31);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Применить";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				47)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53)));
			this->tableLayoutPanel1->Controls->Add(this->label4, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(15, 39);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 31)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 69)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(473, 100);
			this->tableLayoutPanel1->TabIndex = 11;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 17);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(225, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Тип";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"HID-совместимая мышь";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(225, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Мыши и иные устройства";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(147, 17);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Свойства устройства";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 198);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 17);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Изготовитель:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 231);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(92, 17);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Размещение";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(18, 266);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(83, 17);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Состояние:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(155, 266);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(226, 17);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Устройство работает нормально";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(155, 231);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(157, 17);
			this->label10->TabIndex = 20;
			this->label10->Text = L"USB-устройство ввода";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(155, 198);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(65, 17);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Microsoft";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(369, 415);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(97, 31);
			this->button4->TabIndex = 22;
			this->button4->Text = L"Свойства";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(523, 539);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->asd);
			this->Name = L"MyForm";
			this->Text = L"Параметры указателя";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
