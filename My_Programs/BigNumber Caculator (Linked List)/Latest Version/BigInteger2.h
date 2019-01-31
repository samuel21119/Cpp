//Big Interger
#include <iostream>
#include <cstdlib>
#include <cstring>

class Node;
class Input;
class BigInt;
void FreeNode(Node*);
int BigIntToInt(BigInt);
Node* MallocNode();

class Node {
private:
    unsigned int number; // MAX : 9999
    Node* ptr;
    friend BigInt;
    friend Node* MallocNode();
    friend void Free(Node*);
    friend std::istream &operator>>(std::istream &, BigInt &);
    friend std::ostream &operator<<(std::ostream &, BigInt);
    friend int BigIntToInt(BigInt);
    friend void FreeNode(Node *);

};

class BigInt {
public:
    void Free();
    void operator=(const BigInt&);
    void operator=(int);
    void operator=(char *);
    bool operator==(const BigInt&);
    bool operator==(int);
    bool operator==(char *);
    bool operator<(const BigInt&);
    bool operator<(int);
    bool operator<(char *);
    bool operator>(const BigInt&);
    bool operator>(int);
    bool operator>(char *);
    bool operator>=(const BigInt&);
    bool operator>=(int);
    bool operator>=(char *);
    bool operator<=(const BigInt&);
    bool operator<=(int);
    bool operator<=(char *);
    bool operator!=(const BigInt&);
    bool operator!=(int);
    bool operator!=(char *);
    friend std::istream &operator>>(std::istream &, BigInt &);
    friend std::ostream &operator<<(std::ostream &, BigInt);
    BigInt operator+(const BigInt&);
    BigInt operator+(int);
    BigInt operator+(char *);
    BigInt operator-(const BigInt&);
    BigInt operator-(int);
    BigInt operator-(char *);
    BigInt operator*(const BigInt&);
    BigInt operator*(int);
    BigInt operator*(char *);
    BigInt operator/(const BigInt&);
    BigInt operator/(int);
    BigInt operator/(char *);
    void operator+=(const BigInt&);
    void operator+=(int);
    void operator+=(char *);
    void operator-=(const BigInt&);
    void operator-=(int);
    void operator-=(char *);
    void operator*=(const BigInt&);
    void operator*=(int);
    void operator*=(char *);
    void operator/=(const BigInt&);
    void operator/=(int);
    void operator/=(char *);
    friend int BigIntToInt(BigInt);
private:
    Node* Head = NULL;
    char biggerthan0 = 1;
    // biggerthan0 == 0 -> <0
    // biggerthan0 == 1 -> >= 0
    // biggerthan0 == 2 -> Unlumited
    void Reverse();
    void Reverse(int);
    friend void FreeNode(Node *);
};

Node* MallocNode() {
    Node* result;
    result = (Node*)malloc(sizeof(Node));
    result->number = 0;
    result->ptr = NULL;
    return result;
}
void BigInt::Free() {
    FreeNode(Head);
}
void FreeNode(Node* input) {
    if(input != NULL) {
        Node* temp;
        temp = input->ptr;
        free(input);
        FreeNode(temp);
    }
}

void BigInt::operator=(const BigInt& input) {
    FreeNode(this->Head);
    this->Head = input.Head;
    this->biggerthan0 = input.biggerthan0;
}

void BigInt::operator=(int input) {
    Node* ptr;
    int int_temp;
    FreeNode(this->Head);
    this->Head = MallocNode();
    ptr = this->Head;
    if (input < 0) {
        input = -input;
        this->biggerthan0 = 0;
    }
    ptr->number += input;
    while(ptr->number >= 10000) {
        int_temp = ptr->number / 10000;
        ptr->number %= 10000;
        ptr->ptr = MallocNode();
        ptr->ptr->number = int_temp;
        ptr = ptr->ptr;
    }
}

void BigInt::operator=(char input[]) {
    unsigned int length, repeat, temp, MulBy10;
    char ElementAdd1;
    FreeNode(this->Head);
    this->Head = MallocNode();
    Node* ptr = this->Head;
    length = strlen(input);
    if (input[0] == '-') {
        length -= 1;
        this->biggerthan0 = 0;
        ElementAdd1 = 0;
    }else {
        ElementAdd1 = -1;
    }
    repeat = length / 4;
    if (length % 4 != 0) {
        repeat += 1;
    }
    for (int i = 0; i < repeat; i++) {
        MulBy10 = 1;
        temp = 0;
        if (i != repeat - 1) {
            for (int j = 0; j < 4; j++, MulBy10 *= 10) {
                temp += MulBy10 * (input[(int)length + ElementAdd1 - i * 4 - j] - 48);
            }
            ptr->number = temp;
            ptr->ptr = MallocNode();
            ptr = ptr->ptr;
        }else {
            for (int j = 0; (int)length + ElementAdd1 - i * 4 - j >= ElementAdd1 + 1; j++, MulBy10 *= 10) {
                temp += MulBy10 * (input[(int)length + ElementAdd1 - i * 4 - j] - 48);
            }
            ptr->number = temp;

        }
    }
}

std::istream &operator>>(std::istream &istreamInput, BigInt &BigIntOutput) {
    char CharInput;
    int length = 0;
    BigIntOutput.Free();
    BigIntOutput.Head = MallocNode();
    BigInt output;
    Node* ptr = BigIntOutput.Head;
    Node* tempNode, tempNodeHead;
    unsigned int length = 0;
    //吃掉其他的字元
    CharInput = istreamInput.get();
    while (!((CharInput >= '0' && CharInput <= '9') || CharInput == '-')) {
        CharInput = istreamInput.get();
    }
    tempNode = Head = MallocNode();
    while(CharInput != ' ' || CharInput != '\n') {
        if (CharInput == '-') {
            output.biggerthan0 = 0;
        }else {
            tempNode->number = CharInput - (int)'0';
            tempNode->ptr = tempNode;
            tempNode = MallocNode();
            length++;
        }
        CharInput = istreamInput.get();
    }
    tempNodeHead = tempNode->ptr;
    free(tempNode);
    for (int i = 0;i < length; i++) {
        if (i % 4 < 3)
    }
}
