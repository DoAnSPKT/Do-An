#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
//dinh nghia cau truc stack

typedef struct Node
{
	char a;
	Node *Next;
};
typedef struct
{
	Node *top;
}Stack;

void KhoiTao(Stack &S);
int Toantu(char s);
void xuly(char *s);
void ThemCach(char *s);
int Priroty(char s);
int IsEmpty(Stack &S);
void Push(Stack &S, char c);
char Top(Stack S);//lay o dau ngan stack
void Pop(Stack &S, char &c);
void Postfix(Stack &S, char *s);

//khoi tao stack
void KhoiTao(Stack &S)
{
	Node *Newnode = new Node;
	Newnode->a = '(';
	Newnode->Next = NULL;
	S.top = Newnode;//khoi tao stack
	return;
}
//kiem tra la toan tu hay khong
int Toantu(char s)
{
	if (s == '+' || s == '-' || s == '*' || s == '/' || s == '%' || s == '^' || s == '(' || s == ')')
		return 1;
	return 0;
}
//xu ly bieu thuc nhap vao
void xuly(char *s)
{
	int j = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] != ' ')//
			s[j++] = s[i];
	}
	s[j] = '\0';
	return;
}
//Them dau cach
void ThemCach(char *s)
{
	int j = 0;
	char *b = new char[256];
	for (int i = 0; s[i] != '\0'; ++i)
		if (Toantu(s[i]))
		{
			b[j++] = ' ';
			b[j++] = s[i];
			b[j++] = ' ';
		}
		else
			b[j++] = s[i];
	b[j] = '\0';
	strcpy(s, b);
	strupr(s);
	delete[] b;
	b = NULL;
	return;
}
//xet do uu tien
int Priroty(char s)
{
	if (s == '^')
		return 3;
	else
		if (s == '*' || s == '/' || s == '%')
			return 2;
		else
			if (s == '+' || s == '-')
				return 1;
			else
				return 0;
}
//kiem tra stack rong hay khong
int IsEmpty(Stack &S)
{
	if (S.top == NULL)//stack rong
		return 1;
	return 0;
}
//ham dat vao stack
void Push(Stack &S, char c)
{
	Node *Newnode = new Node;
	if (Newnode != NULL)//Neu  cap phat duoc
	{
		Newnode->a = c;
		Newnode->Next = NULL;
	}
	if (IsEmpty(S))
		S.top = Newnode;
	else
	{
		Newnode->Next = S.top;
		S.top = Newnode;
	}
	return;
}
//lay phan tu dau tien o stack
char Top(Stack S)
{
	return S.top->a;
}
//lay ra khoi ham stack
void Pop(Stack &S, char &c)
{
	Node *p = NULL;
	if (!IsEmpty(S))
	{
		p = S.top;
		c = p->a;
		S.top = p->Next;
		delete p;
	}
	return;
}
//xu ly hau to
void Postfix(Stack &S, char *s)
{
	//doc stack
	char c;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0'&& s[i] <= '9')
			cout << s[i];
		else
			if (s[i] == ' ')
				cout << "";
			else
				if (s[i] == '(')
					Push(S, s[i]);//dua vao stack
				else
					if (s[i] == ')')//lay ra cho den khi gap dau ")"
					{
						Pop(S, c);
						while (c != '(')
						{
							cout << c << " ";
							Pop(S, c);//lay ra khoi stack
						}
					}
					else
						if (Toantu(s[i]))//la toan hang
						{
							while (Priroty(s[i]) < Priroty(Top(S)))//do uu tien cua toan tu dinh stack lon hon.
							{
								Pop(S, c);//lay ra o dinh stack
								cout << c << "";
							}
							Push(S, s[i]);//dat toan tu hien tai vao stack
						}
	}
	while (S.top >= 0)//lay nhung gi con lai trong stack
	{
		Pop(S, c);
		if (c != '(')
			cout << c << " ";
	}
	return;
}

int main()
{
	char s[256];
	Stack S;
	KhoiTao(S);
	cout << "Nhap vao bieu thuc trung to:";
	cin.getline(s, 256);
	xuly(s);
	ThemCach(s);
	cout << "Bieu thuc trung to sau khi xu ly:" << s << endl;
	cout << "Bieu thuc hau to:";
	Postfix(S, s);
	cout << endl;
	return 0;
}
