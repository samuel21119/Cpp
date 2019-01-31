#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct number {//�w�q�`�I���c
	int num;
	int biggerthan0;
	number* ptr;
}n;
//�ŧi���
n* MALLOC();
void CreateNode(n*, int);
int ReadeNode(n*, int);
void WriteNode(n*, int, int);
void AddNodeNum(n*, int, int);
n* ReturnAddr(n*, int);
void Reverse(n*, int);
void Scan(n*);
int FindLength(n*);
void Add(n*, n*, n*);
void Minus(n*, n*, n*);
void Multiply(n*, n*, n*);
void Divide(n*, n*, n*);
void FREE(n*);
void Check(n*);
void Check0(n*);
void Print(n*);
int IfBBiggerA(n*, n*);

int main() {
	n *A, *B, *C;
	char var;
	A = MALLOC();//�t�m�O����
	B = MALLOC();
	C = MALLOC();
	Scan(A);//��J�Ʀr
	Scan(B);
	printf("Please enter \"+\" or \"-\" or \"*\" or \"/\"> ");
	scanf("%c", &var);
	switch (var) {
	case '+':
		Add(A, B, C);
		break;
	case '-':
		Minus(A, B, C);
		break;
	case '*':
		Multiply(A, B, C);
		break;
	case '/':
		Divide(A, B, C);
	default:
		break;
	};
	Print(C);
	printf("\n");
	system("pause");
	FREE(A);
	FREE(B);
	FREE(C);
	return 0;
}


n* MALLOC() {//�t�m�O����禡(�]���l��)
	n* ptr = (n*)malloc(sizeof(n));
	ptr->biggerthan0 = 1;
	ptr->num = 0;
	ptr->ptr = NULL;
	return ptr;
}
void CreateNode(n* input, int quantity) {//�إ߸`�I
	for (int i = 0; i < quantity; i++) {
		input->ptr = (n*)malloc(sizeof(n));
		input = input->ptr;
		input->biggerthan0 = 1;
		input->num = 0;
		input->ptr = NULL;
	}
};
int ReadeNode(n* input, int element) {//Ū���`�I
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	return input->num;
};
void WriteNode(n* input, int element, int value) {//�g�J�`�I
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	input->num = value;
};
void AddNodeNum(n* input, int element, int value) {//�N�Ʀr�[��`�I��num��
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	input->num += value;
};
n* ReturnAddr(n* input, int element) {//�^�ǲ�element���`�I��address
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	return input;
};
void Reverse(n* input, int length) {//�N�@�Ӹ`�I�����Ʀr����
	int j = 0;
	char temp;
	for (int i = length; i > length / 2; i--, j++) {
		temp = ReadeNode(input, i);
		WriteNode(input, i, ReadeNode(input, j));
		WriteNode(input, j, temp);
	}
};
void Scan(n* input) {//��J�Ʀr
	n* input2 = input;
	int length = 0;
	char InputChar;
	printf("Please enter number> ");
	scanf("%c", &InputChar);
	while (InputChar != '\n') {
		input->num = InputChar - '0';
		scanf("%c", &InputChar);
		if (InputChar != '\n') {
			CreateNode(input, 1);
			input = input->ptr;
			length++;
		}
	}
	Reverse(input2, length);
};
int FindLength(n* input) {
	int count = 0;
	while (input->ptr != NULL) {
		count++;
		input = input->ptr;
	}
	return count;
}
void Add(n* A, n* B, n* C) {//�NA+B���Ȧs��C (�YC=A+B)
	int ALength = FindLength(A);
	int BLength = FindLength(B);
	int MaxLength, tempA, tempB;
	if (BLength > ALength) {
		MaxLength = BLength;
	}
	else {
		MaxLength = ALength;
	}
	CreateNode(C, MaxLength);
	for (int i = 0; i <= MaxLength; i++) {
		if (i > ALength) {
			tempA = 0;
		}
		else {
			tempA = ReadeNode(A, i);
		}
		if (i > BLength) {
			tempB = 0;
		}
		else {
			tempB = ReadeNode(B, i);
		}
		AddNodeNum(C, i, tempA + tempB);
	}
	Check(C);
};
void Minus(n* A, n* B, n* C) {//�NA-B���Ȧs��C (�YC=A-B)�A�YC<0�A�hC����0�`�I�� "biggerthan0"��0�A�Ϥ��h��1
	int ALength = FindLength(A);
	int BLength = FindLength(B);
	int MaxLength, temp, tempA, tempB;
	n* tempN;
	if (BLength > ALength) {
		MaxLength = BLength;
	}
	else {
		MaxLength = ALength;
	}
	CreateNode(C, MaxLength);
	if (IfBBiggerA(A, B)) {
		tempN = B;
		B = A;
		A = tempN;
		C->biggerthan0 = 0;
		temp = ALength;
		ALength = BLength;
		BLength = temp;
	}
	for (int i = 0; i <= MaxLength; i++) {
		if (i > ALength) {
			tempA = 0;
		}
		else {
			tempA = ReadeNode(A, i);
		}
		if (i > BLength) {
			tempB = 0;
		}
		else {
			tempB = ReadeNode(B, i);
		}
		AddNodeNum(C, i, tempA - tempB);
	}
	for (int i = 0; i < MaxLength; i++) {
		temp = ReadeNode(C, i);
		if (temp < 0) {
			WriteNode(C, i, temp + 10);
			AddNodeNum(C, i+1,-1);
		}
	}
	Check0(C);
};
void Multiply(n* A, n* B, n* C) {//C=A*B
	int ALength, BLength;
	ALength = FindLength(A);
	BLength = FindLength(B);
	CreateNode(C, ALength + BLength);
	for (int i = 0; i <= BLength; i++) {
		for (int j = 0; j <= ALength; j++) {
			AddNodeNum(C, i + j, ReadeNode(A, j)*ReadeNode(B, i));
		}
	}
	Check(C);
};
void Divide(n* A, n* B, n* C) {//  C=A/B (C��int�A�ҥH�o�쪺�Ӥ��|���p���I�A�p3/2=1
	int flag = 1;
	n* D;
	if (!(IfBBiggerA(A, B))) {
		while (flag) {
			D = MALLOC();
			Multiply(B, C, D);
			if (IfBBiggerA(A, D)) {
				AddNodeNum(C, 0, -1);
				Check(C);
				flag = 0;
			}
			else {
				AddNodeNum(C, 0, 1);
				Check(C);
			}
			FREE(D);
		}
		Check0(C);
	}
}
int IfBBiggerA(n* A, n* B) {//�P�_B�O�_�j��A
	if (FindLength(A) < FindLength(B))
		return 1;
	if (FindLength(A) > FindLength(B))
		return 0;
	for (int i = FindLength(A); i >= 0; i--) {
		if (ReadeNode(A, i) < ReadeNode(B, i))
			return 1;
		if (ReadeNode(A, i) > ReadeNode(B, i))
			return 0;
	}
	return 0;
};
void Check(n* input) {//�ˬdinput�̩Ҧ����ȡA�Y��>=10���ȡA�h�i��A�Y<0�A�h�ɦ�
	int length = FindLength(input);
	int temp;
	for (int i = 0; i <= length; i++) {
		temp = ReadeNode(input, i);
		if (temp >= 10) {
			if (i == length) {
				CreateNode(ReturnAddr(input, i), 1);
			}
			WriteNode(input, i, temp % 10);
			AddNodeNum(input, i + 1, temp / 10);
		}
	}
}
void FREE(n* input) {//����input�̩Ҧ��`�I���O����
	for (int length = FindLength(input); length >= 0; length--) {
		free(ReturnAddr(input, length));
	}
}
void Check0(n* input) {//�ˬd�A�@��Ʀr�̫e���O�_���h�l��0�A�p�G���A�h�R�� (�Ҧp: 001234 -> 1234)
	n* tempN;
	int MaxLength = FindLength(input);
	for (int i = MaxLength; i > 0; i--) {
		if (ReadeNode(input, i) == 0) {
			tempN = ReturnAddr(input, i - 1);
			free(tempN->ptr);
			tempN->ptr = NULL;
		}else if (ReadeNode(input, i) != 0) {
			break;
		}
	}
}
void Print(n* input){//�C�L�Ʀr
	int length;
	length = FindLength(input);
	if (!(input->biggerthan0)) {
		printf("-");
	}
	for (int i = length; i >= 0; i--) {
		printf("%d", ReadeNode(input, i));
	}
};