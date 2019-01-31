#include <iostream>
#include <cstdlib>
//INTMAX = 2147483647
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
int NumberToInt(Number);

class Node {
private:
	short int number;
	Node* ptr;
public:
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
	friend int NumberToInt(Number);
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
	bool operator>=(const Number& );
	bool operator>=(int);
	bool operator>=(char *);
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
	friend int NumberToInt(Number);
	int Length();
private:
	Node* Head = NULL;
	int biggerthan0 = 1;
	void Reverse(int);
	void Free(Node*);
};


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
void Check(Node* input) {
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
std::istream &operator>>(std::istream &a, Number &b){
	b.Free();
	b.Head = MallocNode();
	Node* ptr = b.Head;
	int length = 0;
    char InputChar;
	InputChar = a.get();
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
	if(b.biggerthan0 == 2){
		a << "INF" ;
		return a;
	}
	if(b.biggerthan0 == 0){
		a << "-";
	}if(b.Head->ptr == NULL){
		a << b.Head->number;
	}else{
		Node *ptr;
		ptr = b.Head;
		int length = FindLength(ptr);
		b.Reverse(length);
		while(ptr != NULL){
			a << ptr->number;
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
bool Number::operator!=(const Number& b){
	return !(*this == b);
};
bool Number::operator!=(int b){
	return !(*this == b);
};
bool Number::operator!=(char b[]){
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
Number Number::operator+(const Number& b) {
	Number result, temp;
	temp = b;
	if(this->biggerthan0 == 2 || b.biggerthan0 == 2){
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	if (*this > 0 && temp > 0) {
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
	else if (*this > 0 && temp < 0) {
		temp.biggerthan0 = 1;
		result = *this - temp;
		temp.biggerthan0 = 0;

	}
	else if (*this < 0 && temp > 0) {
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
	if(this->biggerthan0 == 2 || b.biggerthan0 == 2){
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	if (*this > 0 && temp > 0) {
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
	else if (*this > 0 && temp < 0) {
		temp.biggerthan0 = 1;
		result = *this + temp;
		temp.biggerthan0 = 0;
	}
	else if (*this < 0 && temp > 0) {
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
	Number temp,result;
	temp = b;
	if(temp == 0 || *this == 0){
		result.Head = MallocNode();
		result.Head->number = 0;
		result.Head->ptr = NULL;
		return result;
	}
	if(this->biggerthan0 == 2 || b.biggerthan0 == 2){
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	Node *A = this->Head;
	Node *B = b.Head;
	result.Head = MallocNode();
	Node *C = result.Head;
	Node *tempI, *tempAJ, *tempBI, *tempIJ;
	int ALength, BLength;
	ALength = FindLength(A);
	BLength = FindLength(B);
	CreateNode(C, ALength + BLength);
	tempI = C;
	tempBI = B;
	for (int i = 0; i <= BLength; i++) {
		tempIJ = tempI;
		tempAJ = A;
		for (int j = 0; j <= ALength; j++) {
			tempIJ->number += tempAJ->number * tempBI->number;
		//	AddtoNode(C, i + j, ReadNode(A, j) * ReadNode(B, i));
			tempIJ = tempIJ->ptr;
			tempAJ = tempAJ->ptr;
		}
		tempBI = tempBI->ptr;
		tempI = tempI->ptr;
	}
	Check(C);
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
	Number temp;
	Number D;
	Number result;
	temp = b;
	if(temp == 0){
		result.Head = NULL;
		result.biggerthan0 = 2;
		return result;
	}
	result.Head = MallocNode();
	Node *A = this->Head;
	Node *B = b.Head;
	Node *C = result.Head;
	int flag = 1;
	int ThisPositive = 1;
	if (*this < 0) {
		ThisPositive = 0;
		this->biggerthan0 = 1;
	}
	if (*this > b) {
		while (flag) {
			D.Head = MallocNode();
			D = result * temp;
			if (D < 0){
				D.biggerthan0 = 1;
			}
			if (*this < D) {
				AddtoNode(C, 0, -1);
				Check(C);
				flag = 0;
			}
			else {
				AddtoNode(C, 0, 1);
				Check(C);
			}
			D.Free();
		}
		Check0(C);
		if (this->biggerthan0 + temp.biggerthan0 == 1) {//here
			result.biggerthan0 = 0;
		}
	}
	if (ThisPositive == 0) {
		this->biggerthan0 = 0;
	}
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
Number Number::operator%(const Number& b){
	Number temp;
	Number D;
	Number result;
	result.Head = MallocNode();
	temp = b;
	int flag = 1;
	Node *A = this->Head;
	Node *B = b.Head;
	Node* C = result.Head;
	int ThisPositive = 1;
	if (*this < 0) {
		ThisPositive = 0;
		this->biggerthan0 = 1;
	}
	if (*this > b) {
		while (flag) {
			D.Head = MallocNode();
			D = result * temp;
			if (D < 0) {
				D.biggerthan0 = 1;
			}
			if (*this < D) {
				if(temp > 0){
					D -= temp;
				}else {
					D += temp;
				}
				result = *this - D;
				if (ThisPositive == 0) {
					this->biggerthan0 = 0;
				}
				flag = 0;
			}
			else {
				AddtoNode(C, 0, 1);
				Check(C);
			}
			D.Free();
		}
	}
	return result;
};
Number Number::operator%(int b){
	Number temp;
	temp = b;
	return *this % temp ;
};
Number Number::operator%(char b[]){
	Number temp;
	temp = b;
	return *this % temp;
};
void Number::operator%=(const Number& b){
	*this = *this % b;
};
void Number::operator%=(int b){
	Number temp;
	temp = b;
	*this = *this % temp;
};
void Number::operator%=(char b[]){
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
	if (input != NULL) {
		Node* temp = input->ptr;
		free(input);
		Free(temp);
	}
};
int NumberToInt(Number b){
	if(b > "2147483647" || b < "-2147483647"){
		return 0;
	}
	Node* ptr = b.Head;
	int result = 0;
	int MulBy10 = 1;
	result += ptr->number;
	ptr = ptr->ptr;
	while (ptr != NULL){
		result += ptr->number * 10 * MulBy10;
		MulBy10 *= 10;
		ptr = ptr->ptr;
	}
	if(b < 0){
		result *= -1;
	}
	return result;
};
int Number::Length(){
	return FindLength(Head);
}
