#include <iostream>
#include <cstdlib>
#define INTMAX  2147483647
//declare classes, functions
class Node;
class Number;
Node* MallocNode();
void CreateNode(Node*, int);
int ReadNode(Node*, int);
void WriteNode(Node*, int, int);
void AddtoNode(Node*, int, int);
Node* ReturnAddr(Node*, int);
int FindLength(Node*);
void Check(Node*);
void Check0(Node*);
Number sqrt(Number);


class Node {
private:
	char number;
	Node* ptr;
	friend Node* MallocNode();
	friend void CreateNode(Node*, int);
	friend int ReadNode(Node*, int);
	friend void WriteNode(Node*, int, int);
	friend void AddtoNode(Node*, int, int);
	friend Node* ReturnAddr(Node*, int);
	friend int FindLength(Node*);
	friend void Check(Node*);
	friend void Check0(Node*);
	friend Number;
	friend std::istream &operator>>(std::istream &, Number &);
	friend std::ostream &operator<<(std::ostream &, Number);
	friend Number sqrt(Number);
};

class Number {
public:
	void Free();
	bool operator<(const Number&);
	bool operator<(int);
	bool operator<(char *);
	bool operator>(const Number&);
	bool operator>(int);
	bool operator>(char *);
	friend std::istream &operator>>(std::istream &, Number &);
	friend std::ostream &operator<<(std::ostream &, Number);
	void operator=(const Number&);
	void operator=(int);
	void operator=(char *);
	bool operator==(const Number&);
	bool operator==(int);
	bool operator==(char *);
	bool operator!=(const Number&);
	bool operator!=(int);
	bool operator!=(char *);
	bool operator<=(const Number&);
	bool operator<=(int);
	bool operator<=(char *);
	bool operator>=(const Number&);
	bool operator>=(int);
	bool operator>=(char *);
	bool operator&&(const Number&);
	bool operator&&(int);
	bool operator&&(char *);
	bool operator||(const Number&);
	bool operator||(int);
	bool operator||(char *);
	Number operator+(const Number&);
	Number operator+(int);
	Number operator+(char *);
	void operator+=(const Number&);
	void operator+=(int);
	void operator+=(char *);
	Number operator++(int);//(*this)++
	Number& operator++();// ++(*this)
	Number operator-(const Number&);
	Number operator-(int);
	Number operator-(char *);
	void operator-=(const Number&);
	void operator-=(int);
	void operator-=(char *);
	Number operator--(int);
	Number& operator--();
	Number operator*(const Number&);
	Number operator*(int);
	Number operator*(char *);
	void operator*=(const Number&);
	void operator*=(int);
	void operator*=(char *);
	Number operator/(const Number&);
	Number operator/(int);
	Number operator/(char *);
	void operator/=(const Number&);
	void operator/=(int);
	void operator/=(char *);
	Number operator%(const Number&);
	Number operator%(int);
	Number operator%(char *);
	void operator%=(const Number&);
	void operator%=(int);
	void operator%=(char *);
	int Length();
	friend Number sqrt(Number);
	operator char();
	operator int();
	operator long long int();
	operator double();
	operator float();
private:
	Node* Head = NULL;
	char biggerthan0 = 1;
	// biggerthan0 == 0 -> <0
	// biggerthan0 == 1 -> >= 0
	// biggerthan0 == 2 -> Unlumited
	void Reverse(int);
	void Free(Node*);
};



//Func about Node
Node* ReturnAddr(Node* input, int element) {
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	return input;
};
int FindLength(Node* input) {
	int count = 0;
	while (input->ptr != NULL) {
		count++;
		input = input->ptr;
	}
	return count;
};
void Check(Node* input) {//check if there's a number that is bigger than 9
	int length = FindLength(input);
	int temp;
	for (int i = 0; i <= length; i++) {
		temp = ReadNode(input, 0);
		if (temp >= 10) {
			if (i == length) {
				CreateNode(ReturnAddr(input, 0), 1);
			}
			WriteNode(input, 0, temp % 10);
			AddtoNode(input, 1, temp / 10);
		}
		input = input->ptr;
	}
};
void Check0(Node* input) {
	Node* tempN;
	int MaxLength = FindLength(input);
	for (int i = MaxLength; i > 0; i--) {
		if (ReadNode(input, i) == 0) {
			tempN = ReturnAddr(input, i - 1);
			free(tempN->ptr);
			tempN->ptr = NULL;
		}
		else if (ReadNode(input, i) != 0) {
			break;
		}
	}
};
Node* MallocNode() {
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->number = 0;
	ptr->ptr = NULL;
	return ptr;
};
void CreateNode(Node* input, int quantity) {
	for (int i = 0; i < quantity; i++) {
		input->ptr = MallocNode();
		input = input->ptr;
	}
};
int ReadNode(Node* input, int element) {
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	return (int)(input->number);
};
void WriteNode(Node* input, int element, int value) {
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	input->number = value;
};
void AddtoNode(Node* input, int element, int value) {
	for (int i = 0; i < element; i++) {
		input = input->ptr;
	}
	input->number += value;
};



//Func about Number
Number sqrt(Number input) {
	int Length, count;
	Node *NodeTemp;
	Number result, temp, temp2, temp3, number2;
	result = 0;
	number2 = 2;
	Length = input.Length();
	if (Length == 0) {
		result = 1;
		for (; result < 4; ++result) {
			temp = result * result;
			if (temp == input) {
				return result;
			}
			if (temp > input) {
				result = -1;
				return result;
			}
		}
	}
	if (Length == 1) {
		result = 3;
		for (; result < 10; ++result) {
			temp = result * result;
			if (temp == input) {
				return result;
			}
			if (temp > input) {
				result = -1;
				return result;
			}
		}
	}
	//Length > 1
	if (Length % 2 == 1) {//4 6 8...
		temp.Head = ReturnAddr(input.Head, Length - 1);
		for (int i = 1; i <= Length/2 + 1; i++) {
			for (count = 0; count <= 10; count++) {
				temp3 = result * number2;
				temp3 = temp3 + count;
				temp3 = temp3 * count;
				if (i > 1) {
					if (temp3 == temp2) {
						break;
					}
					if (temp3 > temp2) {
						count -= 1;
						break;
					}
				}
				else {
					if (temp3 == temp) {
						break;
					}
					if (temp3 > temp) {
						count -= 1;
						break;
					}
				}
			}
			temp3 = result * number2;
			temp3 = temp3 + count;
			temp3 = temp3 * count;
			if (i < Length/2 + 1) {
				if (i > 1) {
					temp2 -= temp3;
				}
				else {
					temp2 = temp - temp3;
				}
				if (i == 1 && temp2 == 0) {
					temp2.Head->number = ReadNode(input.Head, Length - i*2);
					NodeTemp = temp2.Head;
					temp2.Head = MallocNode();
					temp2.Head->ptr = NodeTemp;
					temp2.Head->number = ReadNode(input.Head, Length - i*2 - 1);
				}
				else {
					NodeTemp = temp2.Head;
					temp2.Head = MallocNode();
					temp2.Head->ptr = NodeTemp;
					temp2.Head->number = ReadNode(input.Head, Length - i*2);
					NodeTemp = temp2.Head;
					temp2.Head = MallocNode();
					temp2.Head->ptr = NodeTemp;
					temp2.Head->number = ReadNode(input.Head, Length - i*2 - 1);
				}
				if (!(i == 1 && temp2 == 0)) {
					result.Head->number = count;
					NodeTemp = result.Head;
					result.Head = MallocNode();
					result.Head->ptr = NodeTemp;
				}
				else if (i == 1 && temp2 > 0) {
					result.Head->number = count;
				}
			}
			else {
				result.Head->number = count;
				if (temp3 < temp2) {
					result = -1;
					return result;
				}
				temp3.Free();
				temp2.Free();
			}
		}
	}
	else {//3 5 7...
		int count2;
		result = 0;
		count2 = ReadNode(input.Head, Length);
		for (count = 0; count <= 4; count++) {
			temp = count * count;
			if (temp > count2) {
				count -= 1;
				break;
			}
			if (temp == count2) {
				break;
			}
		}
		if (count > 0) {
			result.Head->number = count;
			NodeTemp = result.Head;
			result.Head = MallocNode();
			result.Head->ptr = NodeTemp;
		}
		temp = count2 - count * count;
		if (temp > 0) {
			NodeTemp = temp.Head;
			temp.Head = MallocNode();
			temp.Head->ptr = NodeTemp;
		}
		temp.Head->number = ReadNode(input.Head, Length - 1);
		NodeTemp = temp.Head;
		temp.Head = MallocNode();
		temp.Head->ptr = NodeTemp;
		temp.Head->number = ReadNode(input.Head, Length - 2);
		for (int i = 1; i <= Length/2; i++) {
			Check0(temp.Head);
			for (count = 0; count <= 10; count++) {
				temp3 = result * number2;
				temp3 = temp3 + count;
				temp3 = temp3 * count;
				if (temp3 == temp) {
					break;
				}
				if (temp3 > temp) {
					count -= 1;
					break;
				}
			}
			temp3 = result * number2;
			temp3 = temp3 + count;
			temp3 = temp3 * count;
			if (i < Length/2) {
				result.Head->number = count;
				NodeTemp = result.Head;
				result.Head = MallocNode();
				result.Head->ptr = NodeTemp;

				temp -= temp3;
				if (temp > 0) {
					NodeTemp = temp.Head;
					temp.Head = MallocNode();
					temp.Head->ptr = NodeTemp;
				}
				temp.Head->number = ReadNode(input.Head, Length - i*2 - 1);
				NodeTemp = temp.Head;
				temp.Head = MallocNode();
				temp.Head->ptr = NodeTemp;
				temp.Head->number = ReadNode(input.Head, Length - i*2 - 2);
			}
			else {
				result.Head->number = count;
				if (temp3 < temp) {
					result = -1;
				}
			}
		}
		temp.Free();
		temp3.Free();
		number2.Free();
	}
	return result;
}
void Number::Free() {
	Free(Head);
};
bool Number::operator<(const Number& input) {
	Number temp;
	temp = input;
	Node* A = this->Head;
	Node* B = input.Head;
	if (A->ptr == NULL && B->ptr == NULL && A->number == 0 && B->number == 0) {
		this->biggerthan0 = 1;
		temp.biggerthan0 = 1;
		return 0;
	}
	if (this->biggerthan0 == 1 && input.biggerthan0 == 0) {
		return 0;
	}
	if (this->biggerthan0 == 0 && input.biggerthan0 == 1) {
		return 1;
	}
	int positive = 1;
	if (this->biggerthan0 == 0 && input.biggerthan0 == 0) {
		positive = 0;
	}
	int a = FindLength(A);
	int b = FindLength(B);
	if (a < b) {
		if (positive == 1)
			return 1;
		else
			return 0;
	}
	if (a > b) {
		if (positive == 1)
			return 0;
		else
			return 1;
	}
	for (int i = a; i >= 0; i--) {
		a = ReadNode(A, i);
		b = ReadNode(B, i);
		if (a < b) {
			if (positive == 1)
				return 1;
			else
				return 0;
		}
		if (a > b) {
			if (positive == 1)
				return 0;
			else
				return 1;
		}
	}
	return 0;
};
bool Number::operator<(int input) {
	Number temp;
	temp = input;
	return *this < temp;
};
bool Number::operator<(char input[]) {
	Number temp;
	temp = input;
	return *this < temp;
};
bool Number::operator>(const Number& input) {
	Number temp;
	temp = input;
	return temp < *this;
};
bool Number::operator>(int input) {
	Number temp;
	temp = input;
	return temp < *this;
};
bool Number::operator>(char input[]) {
	Number temp;
	temp = input;
	return temp < *this;
};
std::istream &operator>>(std::istream &a, Number &b) {
	b.Free();
	b.Head = MallocNode();
	Node* ptr = b.Head;
	int length = 0;
	char InputChar;
	InputChar = a.get();
	if (InputChar == '\n' || InputChar == ' ') {
		InputChar = a.get();
	}
	while (InputChar != '\n' && InputChar != ' ') {
		if (InputChar == '-') {
			b.biggerthan0 = 0;
			InputChar = a.get();
		}
		ptr->number = InputChar - '0';
		InputChar = a.get();
		if (InputChar != '\n' && InputChar != ' ') {
			CreateNode(ptr, 1);
			ptr = ptr->ptr;
			length++;
		}
	}
	b.Reverse(length);
	return a;
};
std::ostream &operator<<(std::ostream &a, Number b) {
	if (b.biggerthan0 == 2) {
		a << "inf";
		return a;
	}
	if (b.biggerthan0 == 0) {
		a << "-";
	}
	if (b.Head->ptr == NULL) {
		a << (int)(b.Head->number);
	}
	else {
		Node *ptr;
		ptr = b.Head;
		int length = FindLength(ptr);
		b.Reverse(length);
		while (ptr != NULL) {
			a << (int)(ptr->number);
			ptr = ptr->ptr;
		}
		b.Reverse(length);
	}
	return a;
};

void Number::operator=(const Number& b) {
	Free(this->Head);
	this->Head = b.Head;
	this->biggerthan0 = b.biggerthan0;
};
void Number::operator=(int b) {
	Free(this->Head);
	this->Head = MallocNode();
	Node* ptr = this->Head;
	if (b < 0) {
		this->biggerthan0 = 0;
		b = -b;
	}
	while (b > 0) {
		ptr->number = b % 10;
		b /= 10;
		if (b > 0) {
			CreateNode(ptr, 1);
			ptr = ptr->ptr;
		}
	}
};
void Number::operator=(char b[]) {
	size_t length = strlen(b);
	Free(this->Head);
	this->Head = MallocNode();
	Node* ptr = this->Head;
	while (length > 0) {
		WriteNode(ptr, 0, b[length - 1] - '0');
		length--;
		if (length > 0 && b[length - 1] != '-') {
			CreateNode(ptr, 1);
			ptr = ptr->ptr;
		}
		if (b[length - 1] == '-') {
			this->biggerthan0 = 0;
			break;
		}
	}
};
bool Number::operator==(const Number& b) {
	Number temp;
	temp = b;
	Node* A, *B;
	A = this->Head;
	B = temp.Head;
	unsigned int lengthA, lengthB;
	lengthA = FindLength(A);
	lengthB = FindLength(B);
	if (lengthA != lengthB)
		return 0;
	if (*this > temp || temp > *this) {
		return 0;
	}
	for (unsigned int i = 0; i <= lengthA; i++) {
		if (A->number != B->number) {
			return 0;
		}
		A = A->ptr;
		B = B->ptr;
	}
	return 1;
};
bool Number::operator==(int b) {
	Number temp;
	temp = b;
	return *this == temp;
};
bool Number::operator==(char b[]) {
	Number temp;
	temp = b;
	return *this == temp;
};
bool Number::operator!=(const Number& b) {
	return !(*this == b);
};
bool Number::operator!=(int b) {
	return !(*this == b);
};
bool Number::operator!=(char b[]) {
	return !(*this == b);
};
bool Number::operator<=(const Number& b) {
	return !(*this > b);
};
bool Number::operator<=(int b) {
	Number temp;
	temp = b;
	return !(*this > temp);
};
bool Number::operator<=(char b[]) {
	Number temp;
	temp = b;
	return !(*this > temp);
};
bool Number::operator>=(const Number& b) {
	return !(*this < b);
};
bool Number::operator>=(int b) {
	Number temp;
	temp = b;
	return !(*this < temp);
};
bool Number::operator>=(char b[]) {
	Number temp;
	temp = b;
	return !(*this < temp);
};
bool Number::operator&&(const Number& b) {
	Number temp;
	temp = b;
	if (*this != 0 && temp != 0) {
		return true;
	}
	return false;
};
bool Number::operator&&(int b) {
	Number temp;
	temp = b;
	return *this && temp;
};
bool Number::operator&&(char b[]) {
	Number temp;
	temp = b;
	return *this && temp;
};
bool Number::operator||(const Number& b) {
	Number temp;
	temp = b;
	if (*this != 0 || temp != 0) {
		return true;
	}
	return false;
};
bool Number::operator||(int b) {
	Number temp;
	temp = b;
	return *this && temp;
};
bool Number::operator||(char b[]) {
	Number temp;
	temp = b;
	return *this && temp;
};
Number Number::operator+(const Number& b) {
	Number result, temp;
	temp = b;
	if (this->biggerthan0 == 2 || b.biggerthan0 == 2) {
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	if (*this >= 0 && temp >= 0) {
		Node *A = this->Head;
		Node *B = b.Head;
		result.Head = MallocNode();
		Node* C = result.Head;
		Node* temp = C;
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
				tempA = ReadNode(A, i);
			}
			if (i > BLength) {
				tempB = 0;
			}
			else {
				tempB = ReadNode(B, i);
			}
			WriteNode(temp, 0, tempA + tempB);
			temp = temp->ptr;
		}
		Check(C);
	}
	else if (*this >= 0 && temp < 0) {
		temp.biggerthan0 = 1;
		result = *this - temp;
		temp.biggerthan0 = 0;

	}
	else if (*this < 0 && temp >= 0) {
		this->biggerthan0 = 1;
		result = temp - *this;
		this->biggerthan0 = 0;
	}
	else if (*this < 0 && temp < 0) {
		this->biggerthan0 = 1;
		temp.biggerthan0 = 1;
		result = *this + temp;
		result.biggerthan0 = 0;
	}
	return result;
};
Number Number::operator+(int b) {
	Number A;
	A = b;
	return *this + A;
};
Number Number::operator+(char b[]) {
	Number A;
	A = b;
	return *this + A;
};
void Number::operator+=(const Number& b) {
	*this = *this + b;
};
void Number::operator+=(int b) {
	*this = *this + b;
};
void Number::operator+=(char b[]) {
	*this = *this + b;
};
Number Number::operator++(int) {
	Number temp;
	temp = *this + 0;
	*this += 1;
	return temp;
};
Number& Number::operator++() {
	*this += 1;
	return *this;
};
Number Number::operator-(const Number& b) {
	Number result, temp;
	temp = b;
	if (this->biggerthan0 == 2 || b.biggerthan0 == 2) {
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	if (*this >= 0 && temp >= 0) {
		Node *A = this->Head;
		Node *B = b.Head;
		result.Head = MallocNode();
		Node* C = result.Head;
		int ALength = FindLength(A);
		int BLength = FindLength(B);
		int MaxLength, temp, tempA, tempB;
		Node* tempN;
		if (BLength > ALength) {
			MaxLength = BLength;
		}
		else {
			MaxLength = ALength;
		}
		CreateNode(C, MaxLength);
		if (*this < b) {
			tempN = B;
			B = A;
			A = tempN;
			result.biggerthan0 = 0;
			temp = ALength;
			ALength = BLength;
			BLength = temp;
		}
		for (int i = 0; i <= MaxLength; i++) {
			if (i > ALength) {
				tempA = 0;
			}
			else {
				tempA = ReadNode(A, i);
			}
			if (i > BLength) {
				tempB = 0;
			}
			else {
				tempB = ReadNode(B, i);
			}
			AddtoNode(C, i, tempA - tempB);
		}
		for (int i = 0; i < MaxLength; i++) {
			temp = ReadNode(C, i);
			if (temp < 0) {
				WriteNode(C, i, temp + 10);
				AddtoNode(C, i + 1, -1);
			}
		}
		Check0(C);
	}
	else if (*this >= 0 && temp < 0) {
		temp.biggerthan0 = 1;
		result = *this + temp;
		temp.biggerthan0 = 0;
	}
	else if (*this < 0 && temp >= 0) {
		temp.biggerthan0 = 0;
		result = *this + temp;
		temp.biggerthan0 = 1;
	}
	else if (*this < 0 && temp < 0) {
		temp.biggerthan0 = 1;
		result = temp + *this;
		temp.biggerthan0 = 0;
	}
	return result;
};
Number Number::operator-(int b) {
	Number A;
	A = b;
	return *this - A;
};
Number Number::operator-(char b[]) {
	Number A;
	A = b;
	return *this - A;
};
void Number::operator-=(const Number& b) {
	*this = *this - b;
};
void Number::operator-=(int b) {
	*this = *this - b;
};
void Number::operator-=(char b[]) {
	*this = *this - b;
};
Number Number::operator--(int) {
	Number temp;
	temp = *this - 0;
	*this -= 1;
	return temp;
};
Number& Number::operator--() {
	*this -= 1;
	return *this;
};
Number Number::operator*(const Number& b) {
	Number temp, result;
	temp = b;
	if (temp == 0 || *this == 0) {
		result.Head = MallocNode();
		result.Head->number = 0;
		result.Head->ptr = NULL;
		return result;
	}
	if (this->biggerthan0 == 2 || b.biggerthan0 == 2) {
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	Node *A = this->Head;
	Node *B = b.Head;
	result.Head = MallocNode();
	Node *C = result.Head;
	Node *tempI, *tempAJ, *tempBI, *tempIJ;
	int ALength, BLength, IntTemp;
	ALength = FindLength(A);
	BLength = FindLength(B);
	CreateNode(C, ALength + BLength);
	tempI = C;
	tempBI = B;
	for (int i = 0; i <= BLength; i++) {
		tempIJ = tempI;
		tempAJ = A;
		for (int j = 0; j <= ALength && tempBI->number > 0; j++) {
			IntTemp = tempAJ->number * tempBI->number;
			if (IntTemp >= 10) {
				if (tempIJ->ptr == NULL) {
					tempIJ->ptr = MallocNode();
				}
				tempIJ->number += IntTemp % 10;
				tempIJ->ptr->number += IntTemp / 10;
			}
			else {
				tempIJ->number += IntTemp;
			}
			if (tempIJ->number >= 10) {
				if (tempIJ->ptr == NULL) {
					tempIJ->ptr = MallocNode();
				}
				tempIJ->ptr->number += tempIJ->number / 10;
				tempIJ->number %= 10;
			}
			tempIJ = tempIJ->ptr;
			tempAJ = tempAJ->ptr;
		}
		tempBI = tempBI->ptr;
		tempI = tempI->ptr;
	}
	if ((*this < 0 && !(temp < 0)) || (!(*this < 0) && temp < 0)) {
		result.biggerthan0 = 0;
	}
	return result;
};
Number Number::operator*(int b) {
	Number temp;
	temp = b;
	return *this * temp;
};
Number Number::operator*(char b[]) {
	Number temp;
	temp = b;
	return *this * temp;
};
void Number::operator*=(const Number& b) {
	Number temp;
	temp = b;
	*this = *this * temp;
};
void Number::operator*=(int b) {
	*this = *this * b;
};
void Number::operator*=(char b[]) {
	*this = *this * b;
};
Number Number::operator/(const Number& b) {
	Number result, temp, temp2, j, A, B;
	Node *NodeTemp;
	int ALength, BLength, Difference;
	A = *this;
	B = b;
	result = 0;
	if (A.biggerthan0 == 2 || B == 0) {
		result.biggerthan0 = 2;
		return result;
	}
	else if (A.biggerthan0 == 0 && B.biggerthan0 == 0) {
		A.biggerthan0 = 1;
		B.biggerthan0 = 1;
	}
	else if ((A.biggerthan0 == 1 && B.biggerthan0 == 0) || (A.biggerthan0 == 0 && B.biggerthan0 == 1)) {
		A.biggerthan0 = 1;
		B.biggerthan0 = 1;
		result.biggerthan0 = 0;
	}
	else if (A < B || A == 0 || B.biggerthan0 == 2) {
		return result;
	}

	ALength = A.Length();
	BLength = B.Length();
	Difference = ALength - BLength;
	temp.Head = ReturnAddr(A.Head, Difference);
	for (int i = 0; i <= Difference; i++) {
		for (j = 1; j <= 10; j++) {
            if (i == 0 && j * B > temp) {
                j = j - 1;
                result.Head->number = j;
                temp2 = temp - j * B;
                break;
            }
			else if (i > 0 && j * B > temp2) {
                j = j - 1;
                result.Head->number = j;
                temp2 = temp2 - j * B;
                break;
            }
		}
		if (i < Difference) {
			if (temp2 > 0) {
				NodeTemp = temp2.Head;
				temp2.Head = MallocNode();
				temp2.Head->ptr = NodeTemp;
			}
			temp2.Head->number = ReadNode(A.Head,Difference - i - 1);
			if (!(i == 0 && j == 0)) {
				NodeTemp = result.Head;
				result.Head = MallocNode();
				result.Head->ptr = NodeTemp;
			}
		}
	}
	temp2.Free();
	j.Free();
	return result;
};
Number Number::operator/(int b) {
	Number A;
	A = b;
	return *this / A;
};
Number Number::operator/(char b[]) {
	Number A;
	A = b;
	return *this / A;
};
void Number::operator/=(const Number& b) {
	*this = *this / b;
};
void Number::operator/=(int b) {
	*this = *this / b;
};
void Number::operator/=(char b[]) {
	*this = *this / b;
};
Number Number::operator%(const Number& b) {
	Number result, temp, temp2, j, A, B;
	Node *NodeTemp;
	int ALength, BLength, Difference;
	A = *this;
	B = b;
	result = 0;
	if (A.biggerthan0 == 2 || B == 0) {
		result.biggerthan0 = 2;
		return result;
	}
	else if (A.biggerthan0 == 0 && B.biggerthan0 == 0) {
		A.biggerthan0 = 1;
		B.biggerthan0 = 1;
		result.biggerthan0 = 0;
	}
	else if (A.biggerthan0 == 1 && B.biggerthan0 == 0) {
		B.biggerthan0 = 1;
	}
	else if (A.biggerthan0 == 0 && B.biggerthan0 == 1) {
		A.biggerthan0 = 1;
		result.biggerthan0 = 0;
	}
	else if (A < B) {
		temp2 = A + 0;
		result.Head = temp2.Head;
		return result;
	}

	ALength = A.Length();
	BLength = B.Length();
	Difference = ALength - BLength;
	temp.Head = ReturnAddr(A.Head, Difference);
	for (int i = 0; i <= Difference; i++) {
		for (j = 1; j <= 10; j++) {
            if (i == 0 && j * B > temp) {
                j = j - 1;
                result.Head->number = j;
                temp2 = temp - j * B;
                break;
            }
			else if (i > 0 && j * B > temp2) {
                j = j - 1;
                result.Head->number = j;
                temp2 = temp2 - j * B;
                break;
            }
		}
		if (i < Difference) {
			if (temp2 > 0) {
				NodeTemp = temp2.Head;
				temp2.Head = MallocNode();
				temp2.Head->ptr = NodeTemp;
			}
			temp2.Head->number = ReadNode(A.Head,Difference - i - 1);
			if (!(i == 0 && j == 0)) {
				NodeTemp = result.Head;
				result.Head = MallocNode();
				result.Head->ptr = NodeTemp;
			}
		}
		else {
			result.Head = temp2.Head;
		}
	}
	temp2.Free();
	j.Free();
	return result;
};
Number Number::operator%(int b) {
	Number temp;
	temp = b;
	return *this % temp;
};
Number Number::operator%(char b[]) {
	Number temp;
	temp = b;
	return *this % temp;
};
void Number::operator%=(const Number& b) {
	*this = *this % b;
};
void Number::operator%=(int b) {
	Number temp;
	temp = b;
	*this = *this % temp;
};
void Number::operator%=(char b[]) {
	Number temp;
	temp = b;
	*this = *this % temp;
};
void Number::Reverse(int length) {
	int j = 0;
	char temp;
	Node *input = Head;
	for (int i = length; i > length / 2; i--, j++) {
		temp = ReadNode(input, i);
		WriteNode(input, i, ReadNode(input, j));
		WriteNode(input, j, temp);
	}
};
void Number::Free(Node* input) {
	Node* temp;
	while (input != NULL) {
		temp = input->ptr;
		free(input);
		input = temp;
	}
};
int Number::Length() {
	return FindLength(Head);
}
Number::operator int() {
	Number b;
	b.Head = Head;
	if (b > INTMAX || b < -INTMAX) {
		return 0;
	}
	Node* ptr = b.Head;
	int result = 0;
	int MulBy10 = 1;
	result += ptr->number;
	ptr = ptr->ptr;
	while (ptr != NULL) {
		result += ptr->number * 10 * MulBy10;
		MulBy10 *= 10;
		ptr = ptr->ptr;
	}
	if (biggerthan0 == 0) {
		result *= -1;
	}
	return result;
}
Number::operator long long int() {
	Number b, LongLongIntMax;
	b.Head = Head;
	LongLongIntMax = "9223372036854775807";

	if (b > LongLongIntMax || b < LongLongIntMax * -1) {
		return 0;
	}
	Node *ptr = Head;
	long long int result, MulBy10;
	MulBy10 = 1;
	result = 0;
	result += ptr->number;
	ptr = ptr->ptr;
	while (ptr != NULL) {
		result += ptr->number * 10 * MulBy10;
		MulBy10 *= 10;
		ptr = ptr->ptr;
	}
	if (biggerthan0 == 0) {
		result *= -1;
	}
	return result;
}
Number::operator char() {
	Number b;
	b.Head = Head;
	int temp;
	temp = b;
	if (b >= 256) {
		return 0;
	}else {
		return temp;
	}
}
Number::operator double() {
	Number b, max;
	b.Head = Head;
	max = 1;
	for (int i = 0; i < 53; i++) {
		max *= 2;
	}
	if (b >= max || b < max * -1) {
		return 0;
	}
	Node *ptr = Head;
	double result, MulBy10;
	MulBy10 = 1;
	result = 0;
	result += ptr->number;
	ptr = ptr->ptr;
	while (ptr != NULL) {
		result += ptr->number * 10 * MulBy10;
		MulBy10 *= 10;
		ptr = ptr->ptr;
	}
	if (biggerthan0 == 0) {
		result *= -1;
	}
	return result;
}
Number::operator float() {
	Number b;
	b.Head = Head;
	int result;
	result = b;
	return (float)b;
}
