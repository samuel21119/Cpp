#include <iostream>
#include <cstdlib>
class Node {
public:
	char number;
	Node* ptr;
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

class Number {
public:
	void Free() {
		Free(Head);
	};

	int operator<(const Number& input) {
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
	int operator<(int input) {
		Number temp;
		temp = input;
		return *this < temp;
	};
	int operator<(char input[]) {
		Number temp;
		temp = input;
		return *this < temp;
	};
	int operator>(const Number& input) {
		Number temp;
		temp = input;
		return temp < *this;
	};
	int operator>(int input) {
		Number temp;
		temp = input;
		return temp < *this;
	};
	int operator>(char input[]) {
		Number temp;
		temp = input;
		return temp < *this;
	};

	friend std::istream &operator>>(std::istream &a, Number &b); //Scan
	friend std::ostream &operator<<(std::ostream &a, Number b); //Print

	void operator=(const Number& b) {
		Free(this->Head);
		this->Head = b.Head;
		this->biggerthan0 = b.biggerthan0;
	};

	void operator=(int b) {
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

	void operator=(char b[]) {
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
	int operator==(const Number& b) {
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
	int operator==(int b) {
		Number temp;
		temp = b;
		return *this == temp;
	};
	int operator==(char b[]) {
		Number temp;
		temp = b;
		return *this == temp;
	};
	int operator!=(const Number& b){
		return !(*this == b);
	};
	int operator!=(int b){
		return !(*this == b);
	};
	int operator!=(char b[]){
		return !(*this == b);
	};
	int operator<=(const Number& b) {
		return !(*this > b);
	};
	int operator<=(int b) {
		Number temp;
		temp = b;
		return !(*this > temp);
	};
	int operator<=(char b[]) {
		Number temp;
		temp = b;
		return !(*this > temp);
	};
	int operator>=(const Number& b) {
		return !(*this < b);
	};
	int operator>=(int b) {
		Number temp;
		temp = b;
		return !(*this < temp);
	};
	int operator>=(char b[]) {
		Number temp;
		temp = b;
		return !(*this < temp);
	};

	Number operator+(const Number& b) {
		Number result, temp;
		temp = b;
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
	Number operator+(int b) {
		Number A;
		A = b;
		return *this + A;
	};
	Number operator+(char b[]) {
		Number A;
		A = b;
		return *this + A;
	};
	void operator+=(const Number& b) {
		*this = *this + b;
	};
	void operator+=(int b) {
		*this = *this + b;
	};
	void operator+=(char b[]) {
		*this = *this + b;
	};
	Number operator++(int) { //(*this)++
		Number temp;
		temp = *this + 0;
		*this += 1;
		return temp;
	};
	Number & operator++() {// ++(*this)
		*this += 1;
		return *this;
	};

	Number operator-(const Number& b) {
		Number result, temp;
		temp = b;
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
	Number operator-(int b) {
		Number A;
		A = b;
		return *this - A;
	};
	Number operator-(char b[]) {
		Number A;
		A = b;
		return *this - A;
	};
	void operator-=(const Number& b) {
		*this = *this - b;
	};
	void operator-=(int b) {
		*this = *this - b;
	};
	void operator-=(char b[]) {
		*this = *this - b;
	};
	Number operator--(int) {
		Number temp;
		temp = *this - 0;
		*this -= 1;
		return temp;
	};
	Number & operator--() {
		*this -= 1;
		return *this;
	};

	Number operator*(const Number& b) {
		Number temp;
		temp = b;
		Node *A = this->Head;
		Node *B = b.Head;
		Number result;
		result.Head = MallocNode();
		Node* C = result.Head;
		int ALength, BLength;
		ALength = FindLength(A);
		BLength = FindLength(B);
		CreateNode(C, ALength + BLength);
		for (int i = 0; i <= BLength; i++) {
			for (int j = 0; j <= ALength; j++) {
				AddtoNode(C, i + j, ReadNode(A, j)*ReadNode(B, i));
			}
		}
		Check(C);
		if (*this < 0 && !(temp < 0) || !(*this < 0) && temp < 0) {
			result.biggerthan0 = 0;
		}
		return result;
	};
	Number operator*(int b) {
		Number A;
		A = b;
		return *this * A;
	};
	Number operator*(char b[]) {
		Number A;
		A = b;
		return *this * A;
	};
	void operator*=(const Number& b) {
		*this = *this * b;
	};
	void operator*=(int b) {
		*this = *this * b;
	};
	void operator*=(char b) {
		*this = *this * b;
	};

	Number operator/(const Number& b) {
		Number temp;
		Number D;
		Number result;
		result.Head = MallocNode();
		temp = b;
		Node *A = this->Head;
		Node *B = b.Head;
		Node* C = result.Head;
		int flag = 1;
		int ThisPositive = 1;
		if (*this < 0) {
			ThisPositive = 0;
			this->biggerthan0 = 1;
		}
		if (*this > b) {
			while (flag) {
				D.Head = MallocNode();
				D = result * b;
				if (D < 0) {
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
	Number operator/(int b) {
		Number A;
		A = b;
		return *this / A;
	};
	Number operator/(char b[]) {
		Number A;
		A = b;
		return *this / A;
	};
	void operator/=(const Number& b) {
		*this = *this / b;
	};
	void operator/=(int b) {
		*this = *this / b;
	};
	void operator/=(char b[]) {
		*this = *this / b;
	};

	Number operator%(const Number& b){
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
				D = result * b;
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
	Number operator%(int b){
		Number temp;
		temp = b;
		return *this % temp ;
	};
	Number operator%(char b[]){
		Number temp;
		temp = b;
		return *this % temp;
	};
	void operator%=(const Number& b){
		*this = *this % b;
	};
	void operator%=(int b){
		Number temp;
		temp = b;
		*this = *this % temp;
	};
	void operator%=(char b[]){
		Number temp;
		temp = b;
		*this = *this % temp;
	};
private:

	Node* Head = NULL;
	int biggerthan0 = 1;
	void Reverse(int length) {
		int j = 0;
		char temp;
		Node *input = Head;
		for (int i = length; i > length / 2; i--, j++) {
			temp = ReadNode(input, i);
			WriteNode(input, i, ReadNode(input, j));
			WriteNode(input, j, temp);
		}
	};

	void Free(Node* input) {
		if (input != NULL) {
			Node* temp = input->ptr;
			free(input);
			Free(temp);
		}
	}
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
    if(b == 0){
		a << "0";
	}else{
		Node *ptr;
		ptr = b.Head;
		int length;
		length = FindLength(ptr);
		if (b < 0) {
			a << "-";
		}
		for (int i = length; i >= 0; i--) {
			a << (char)(ReadNode(ptr, i) + '0');
		}
	}
    return a;
};
