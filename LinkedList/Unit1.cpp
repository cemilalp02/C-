//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"


class Node {
public:
	int value;
	Node* next;
};

class LinkedList {
private:
	Node* head;
	int nodeCount;

public:
	LinkedList() : head(nullptr), nodeCount(0) {}

	int getCount() const { return nodeCount; }

	void insertAtEnd(int val) {
		if (nodeCount >= 55) {
			ShowMessage("Maximum of 55 nodes can be added!");
			return;
		}
		Node* newNode = new Node();
		newNode->value = val;
		newNode->next = nullptr;
		if (!head) {
			head = newNode;
		} else {
			Node* temp = head;
			while (temp->next) temp = temp->next;
			temp->next = newNode;
		}
		nodeCount++;
	}

	void insertAtFront(int val) {
		if (nodeCount >= 55) {
			ShowMessage("Maximum of 55 nodes can be added!");
			return;
		}
		Node* newNode = new Node();
		newNode->value = val;
		newNode->next = head;
		head = newNode;
		nodeCount++;
	}

	void clear() {
		Node* temp;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
		nodeCount = 0;
	}

	Node* getHead() const { return head; }
};

	int initialValues[5];
		void shuffleInitialValues() {
	for (int i = 4; i > 0; i--) {
		int j = rand() % (i + 1);
		std::swap(initialValues[i], initialValues[j]);
	}
}
LinkedList list;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
 srand(time(0));
    for (int i = 0; i < 5; i++) {
        initialValues[i] = rand() % 100;
	}
	PaintBox1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CreateLinkedListClick(TObject *Sender)
{
list.clear();
int indices[5] = { 0, 1, 2, 3, 4 };

for (int i = 4; i > 0; i--) {
		int j = rand() % (i + 1);
		std::swap(indices[i], indices[j]);
}

	for (int i = 0; i < 5; i++) {
		list.insertAtEnd(initialValues[indices[i]]);
	}

	PaintBox1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect)

{
 float x = 10, y = 20;
    TRectF rect;
    for (int i = 0; i < 5; i++) {
        rect = TRectF(x, y, x + 50, y + 30);
		Canvas->Fill->Color = claWhite;
        Canvas->FillRect(rect, 0, 0, AllCorners, 1);
        Canvas->Stroke->Color = claBlack;
        Canvas->DrawRect(rect, 0, 0, AllCorners, 1);
        Canvas->Fill->Color = claBlack;
        Canvas->FillText(rect, IntToStr(initialValues[i]), false, 1.0f, TFillTextFlags(), TTextAlign::Center, TTextAlign::Center);

        x += 70;
		if (x + 50 > PaintBox1->Width) {
			x = 10;
            y += 50;
        }
    }

	Node* temp = list.getHead();
	x = 10;
	y += 60;
	while (temp) {
        rect = TRectF(x, y, x + 50, y + 30);
        Canvas->Fill->Color = claLightgray;
        Canvas->FillRect(rect, 0, 0, AllCorners, 1);
        Canvas->Stroke->Color = claBlack;
        Canvas->DrawRect(rect, 0, 0, AllCorners, 1);
		Canvas->Fill->Color = claBlack;
        Canvas->FillText(rect, IntToStr(temp->value), false, 1.0f, TFillTextFlags(), TTextAlign::Center, TTextAlign::Center);

        if (temp->next) {
            Canvas->DrawLine(PointF(x + 50, y + 15), PointF(x + 70, y + 15), 1);
        }

        x += 70;
		if (x + 50 > PaintBox1->Width) {
            x = 10;
            y += 50;
        }

        temp = temp->next;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddToHeadClick(TObject *Sender)
{
	if (EditValue->Text != "") {
        try {
			int val = StrToInt(EditValue->Text);
			list.insertAtFront(val);
			PaintBox1->Repaint();
		}
		catch (...) {
			ShowMessage("Please enter a valid number!");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddToEndClick(TObject *Sender)
{
   if (EditValue->Text != "") {
		try {
			int val = StrToInt(EditValue->Text);
			list.insertAtEnd(val);
			PaintBox1->Repaint();
		}
		catch (...) {
			ShowMessage("Please enter a valid number!");
		}
	}
}
//---------------------------------------------------------------------------
