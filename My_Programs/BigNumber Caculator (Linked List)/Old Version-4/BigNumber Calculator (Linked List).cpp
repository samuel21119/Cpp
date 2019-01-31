#include <iostream>
#include <cstdlib>
class BigerNumber{
private:
    typedef struct number {
    	int num;
    	int biggerthan0;
    	number* ptr;
    }n;
    n *A, *B, *C;
    n* MALLOC(){
        n* ptr = (n*)malloc(sizeof(n));
    	ptr->biggerthan0 = 1;
    	ptr->num = 0;
    	ptr->ptr = NULL;
    	return ptr;
    };
    void CreateNode(n* input, int quantity) {//建立節點
    	for (int i = 0; i < quantity; i++) {
    		input->ptr = (n*)malloc(sizeof(n));
    		input = input->ptr;
    		input->biggerthan0 = 1;
    		input->num = 0;
    		input->ptr = NULL;
    	}
    };
    int ReadeNode(n* input, int element) {//讀取節點
    	for (int i = 0; i < element; i++) {
    		input = input->ptr;
    	}
    	return input->num;
    };
    void WriteNode(n* input, int element, int value) {//寫入節點
    	for (int i = 0; i < element; i++) {
    		input = input->ptr;
    	}
    	input->num = value;
    };
    void WriteNode(n* input, int element, int value,char operater) {//將數字加到節點的num裡
    	for (int i = 0; i < element; i++) {
    		input = input->ptr;
    	}
    	input->num += value;
    };
    n* ReturnAddr(n* input, int element) {//回傳第element號節點的address
    	for (int i = 0; i < element; i++) {
    		input = input->ptr;
    	}
    	return input;
    };
    void Reverse(n* input, int length) {//將一個節點內的數字反轉
    	int j = 0;
    	char temp;
    	for (int i = length; i > length / 2; i--, j++) {
    		temp = ReadeNode(input, i);
    		WriteNode(input, i, ReadeNode(input, j));
    		WriteNode(input, j, temp);
    	}
    };
    int FindLength(n* input) {
    	int count = 0;
    	while (input->ptr != NULL) {
    		count++;
    		input = input->ptr;
    	}
    	return count;
    };
    void Add(n* A, n* B, n* C) {//將A+B的值存到C (即C=A+B)
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
    		WriteNode(C, i, tempA + tempB);
    	}
    	Check(C);
    };
    void Minus(n* A, n* B, n* C) {//將A-B的值存到C (即C=A-B)，若C<0，則C的第0節點的 "biggerthan0"為0，反之則為1
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
    		WriteNode(C, i, tempA - tempB,'+');
    	}
    	for (int i = 0; i < MaxLength; i++) {
    		temp = ReadeNode(C, i);
    		if (temp < 0) {
    			WriteNode(C, i, temp + 10);
    			WriteNode(C, i+1,-1,'+');
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
    			WriteNode(C, i + j, ReadeNode(A, j)*ReadeNode(B, i),'+');
    		}
    	}
    	Check(C);
    };
    void Divide(n* A, n* B, n* C) {//  C=A/B (C為int，所以得到的商不會有小數點，如3/2=1
    	int flag = 1;
    	n* D;
    	if (!(IfBBiggerA(A, B))) {
    		while (flag) {
    			D = MALLOC();
    			Multiply(B, C, D);
    			if (IfBBiggerA(A, D)) {
    				WriteNode(C, 0, -1,'+');
    				Check(C);
    				flag = 0;
    			}
    			else {
    				WriteNode(C, 0, 1,'+');
    				Check(C);
    			}
    			FREE(D);
    		}
    		Check0(C);
    	}
    };
    int IfBBiggerA(n* A, n* B) {//判斷B是否大於A
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
    void Check(n* input) {//檢查input裡所有的值，若有>=10的值，則進位，若<0，則借位
    	int length = FindLength(input);
    	int temp;
    	for (int i = 0; i <= length; i++) {
    		temp = ReadeNode(input, i);
    		if (temp >= 10) {
    			if (i == length) {
    				CreateNode(ReturnAddr(input, i), 1);
    			}
    			WriteNode(input, i, temp % 10);
    			WriteNode(input, i + 1, temp / 10,'+');
    		}
    	}
    };
    void Check0(n* input) {//檢查再一串數字裡前面是否有多餘的0，如果有，則刪除 (例如: 001234 -> 1234)
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
    };
    void FREE(n* input) {//釋放input裡所有節點的記憶體
    	for (int length = FindLength(input); length >= 0; length--) {
    		free(ReturnAddr(input, length));
    	}
    };
    void Scan(char input) {//輸入數字
        n* ptr;
        switch (input) {
            case 'A':
                ptr=A;
                break;
            case 'B':
                ptr=B;
                break;
            default:
                std::cout << "Error: Enter parameter NOT accept!";
        };
        n* ptr2 = ptr;
        int length = 0;
        char InputChar;
        std::cout << "Please enter number " << input << "> ";
        InputChar = std::cin.get();
        while (InputChar != '\n') {
            ptr->num = InputChar - '0';
            InputChar = std::cin.get();
            if (InputChar != '\n') {
                CreateNode(ptr, 1);
                ptr = ptr->ptr;
                length++;
            }
        }
        Reverse(ptr2, length);
    };
public:
    void Calc(){
        char input;
        std::cout << "Please enter operator (\"+\" or \"-\" or \"*\" or \"/\")> ";
        std::cin >> input;
        switch (input) {
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
            std::cout << "Error: Enter operator NOT accept!";
    		break;
    	};
    };
    void Print(char input){//列印數字
        n* ptr;
        switch (input) {
            case 'A':
                ptr=A;
                break;
            case 'B':
                ptr=B;
                break;
            case 'C':
                ptr=C;
                break;
            default:
                std::cout << "Error: Enter parameter NOT accept!";
        }
    	int length;
    	length = FindLength(ptr);
    	if (!(ptr->biggerthan0)) {
            std::cout << "-";
    	}
    	for (int i = length; i >= 0; i--) {
            std::cout << ReadeNode(ptr, i);
    	}
        std::cout << std::endl;
    };
    void Print(){
        Print('C');
    }
    void Scan(){
        Format();
        Scan('A');
        Scan('B');
    };
    void Free(){
        FREE(A);
        FREE(B);
        FREE(C);
    };
    void Format(){
        A=MALLOC();
        B=MALLOC();
        C=MALLOC();
    };
};
int main(){
    BigNumber ABC;
    ABC.Format();
    ABC.Scan();
    ABC.Calc();
    ABC.Print();
    ABC.Free();
    return 0;
}
