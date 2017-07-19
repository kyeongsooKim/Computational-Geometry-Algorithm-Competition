#include <iostream>
#include <fstream>
#include <cstring> //c style char array string
#include <string> // c++ string object
#include <stack>

using namespace std;


class PostOrder
{
private:
	char * postExp = NULL;

public:
	bool isOperator(int op);
	int getPrecedence(int op);
	void convert2Pfix(char infix[]);
	char * getPostExp();
};

char * PostOrder::getPostExp() {
	return postExp;
}

bool PostOrder::isOperator(int op){ // to check if the expression is operation.
	return op == '+' || '-' || '*' || '/';
}

int PostOrder::getPrecedence(int op) {
	switch(op) {
	case'*':
	case'/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1; //unregistered operation
}

void PostOrder::convert2Pfix(char infix[]) {
	int expLen = strlen(infix);
	postExp = (char*) malloc(expLen + 1);
	char tok;
	
	memset(postExp, 0, sizeof(char)*expLen + 1); //initialize postExp by 0 ('\0')
	stack<int> stack;
	
	int i, idx = 0;
	for (i = 0; i < expLen; i++) {
		tok = infix[i];
		if (isdigit(tok)) {
			postExp[idx++] = tok;
		}
		else if ((tok == '(') || (tok == ')')) {
			switch (tok) {
			case '(':
				stack.push(tok);
				break;
			case ')':
				while (!stack.empty() && stack.top() != '(') {
					postExp[idx++] = stack.top();
					stack.pop();
				}
				stack.pop();
			}
		}
		else if (isOperator(tok)) {
			while ( !stack.empty() && getPrecedence(tok) <= getPrecedence(stack.top()) )
			{
				postExp[idx++] = stack.top();
				stack.pop();
			}
			stack.push(tok);
		}
	}

	while (!stack.empty()) {
		postExp[idx++] = stack.top();
		stack.pop();
	}

}


int main(void) {

	ofstream fout("output.txt");
	ifstream fin("input.txt");
	string inputStr; 
	char infix[256];
	int testNum;
	getline(fin, inputStr); //string object : both "getline()" and "fin >> " work
	testNum = atoi(inputStr.c_str());

	cout << "Post Order expression" << endl<< endl;
	for (int k = 0; k < testNum; k++) {

		cout << '#' << k + 1 << endl;
		fout << '#' << k + 1 <<' ';

		fin >> infix; //c style character array : using " fin >> "
		PostOrder postOrder;
		postOrder.convert2Pfix(infix);

		cout << "in order : " << infix << endl;
		cout << "post order : " << postOrder.getPostExp() << "\n\n";
		fout << postOrder.getPostExp() << endl;
	}


	fout.close();
	fin.close();
}