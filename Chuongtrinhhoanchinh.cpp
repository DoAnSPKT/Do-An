#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


#define MAX 200
struct Stack // Khai báo Struct
{
	float DATA[MAX];
	int TOP;
};
void init(Stack *S)  // Hàm khởi tạo 
{
	S->TOP = -1;
}
int isEmpty(Stack *S) // Hàm kiểm tra liệu Stack co rỗng hay là ko 
{
	if (S->TOP == -1)
		return 1;

	return 0;
}
void Push(struct Stack* S, float item) // Hàm thêm giá trị vào Stack
{
	if (S->TOP == (MAX - 1))
	{
		printf("\nStack is full");
	}
	else
	{
		++S->TOP; 
		S->DATA[S->TOP] = item;
	}
}
int top(Stack *S)  // Hàm trả về giá trị top
{
	return (S->DATA[S->TOP]);
}

float Pop(struct Stack* S) // Hàm pop lấy ra giá trị đầu của Stack
{
	float ret = -1;
	if (S->TOP == -1)
		printf("\nStack is empty");
	else
	{
		ret = S->DATA[S->TOP];
		--S->TOP;
	}
	return ret;
}
int Xetuutien(char x) // Hàm xét độ ưu tiên 
{
	if (x == '(') 
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;

	return 3;
}


void InfixtoPostfix(char infix[], char postfix[])
{
	Stack S; //khai báo stack S
	char x, token;
	int i = 0, j = 0;    
	init(&S); // Khởi tạo 1 stack rỗng
	for (i = 0; infix[i] != '\0'; i++)   // vòng lặp chạy từ vị trí đầu tới cuối của biểu thức trung tố
	{                           
		token = infix[i];       // cho biến token bằng với chuỗi char của trung tố (Lúc này tùy thuộc vào biến i )
		if (isalnum(token))    //Kiểm tra biến Token có phải là số ko        
			postfix[j++] = token;   //Nếu có cho giá trị của postfix[j++] = với giá trị số của token
		else
			if (token == '(') //Nếu token là ký tự '('
				Push(&S, '(');  // Thêm ký tự '(' vào stack S
			else
				if (token == ')') // Nếu token là ký tự
					while ((x = Pop(&S)) != '(') // Vòng lặp nếu biến x khác với Pop(&S) != '(' thì dừng
						postfix[j++] = x; // Nếu vẫn trong vòng lặp ta cho giá trị của postfix[j++]= x
				else                // Nếu ko phải là ký tư ngoặc thì 
				{
					while (Xetuutien(token) <= Xetuutien(top(&S)) && !isEmpty(&S))  // Xét ưu tiên. Nếu token hiện tại có giá trị bé hơn so với phần tử vị trí top của stack S và Stack S ko rỗng
					{
						x = Pop(&S); //Lấy giá trị đầu của stack
						postfix[j++] = x; //Giá trị của post fix = với giá trị vừa lấy ra từ stack
					}
					Push(&S, token); // Thêm token hiện tại vào stack S
				}
	}

	while (!isEmpty(&S)) //Nếu Stack Empty thì thoát ra ngoài 
	{
		x = Pop(&S); // lấy ra phần tử đầu
		postfix[j++] = x; 
	}

	postfix[j] = '\0';
}
float Evaluate(char *Postfix) //Thực hiện công việc tính toán bằng hậu tố
{
	struct Stack S; 
	char *p;
	float op1, op2, result;   
	S.TOP = -1; // cho stack trở về rỗng
	p = &Postfix[0]; // cho giá trị con trỏ p = với giá trị hậu tố ban đầu 
	while (*p != '\0')  // cho p chạy tới cuối mảng thì dừng lại
	{
		while (*p == ' ' || *p == '\t')  //nếu ko gặp khoảng trắng hay 
		{
			p++; //con trỏ đi tới vị trí tiếp theo trong chuỗi(Array)
		}
		if (isdigit(*p)) // dùng để phân biệt chữ số với toán tử 
		{
			int num = 0;
			while (isdigit(*p))  //vòng lặp chạy tới khi gặp toán tử (- , + , * , /) thì thoát ra ngoài 
			{
				num = num * 10 + *p - 48; // biến char thành số có thể dùng để tính toán đc 
				*p++; // con trỏ đi tới vị trí tiếp theo trong chuỗi (Array) nhưng trả về giá trị cũ 
			}
			Push(&S, num); // Lấy chữ số ra và bỏ vào Stack	
		}	
		else
		{
			op1 = Pop(&S); // Lấy ký tự đầu và bỏ vào biến op1
			op2 = Pop(&S); // Lấy ký tự đầu và bỏ vào biến op2
			switch (*p)  // Lệnh switch case để thực hiện công việc tính toán
			{
			case '+':
				result = op2 + op1; // Thực hiện phép cộng
				break;
			case '-':
				result = op2 - op1; // Thực hiện phép trừ
				break;
			case '/':
				result = op2 / op1; // Thực hiện phép chia
				break;
			case '*':
				result = op2 * op1; // Thực hiện phép nhân
				break;
			default:
				printf("\nKo Hop Le"); // Nếu toán tử nhập vào ko hợp lệ 
				return 0;
			}
			Push(&S, result); // Sau khi thực hiên xong thì bỏ kết quả vào Stack (1)
		}
		p++; // Cho con trỏ p di chuyển tới vị trí tiếp theo trong mảng
	}
	result = Pop(&S); // Từ (1) Kết quả bằng với kết quả mà ta lấy ra từ Stack 
	return result; // Trả về kết quả
}





int main()
{
	char A[MAX], B[MAX];
	printf("Trung To : ");
	gets_s(A); // nhập biểu thức trung tố
	InfixtoPostfix(A, B); // Biến đổi

	printf("Hau To: %s\n", B); // Xuất ra kết quả
	printf("Ket Qua la %f\n", Evaluate(&B[0]));  // Xuất ra kết quả từ việc tính toán hậu tố 

	

	return 0;
}