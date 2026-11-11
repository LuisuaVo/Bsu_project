#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

struct TStack {
	int n;
	char* items;
	int top;
};

void createStack(TStack& stack, int count) {
	stack.items = new char[count];
	stack.top = 0;
	stack.n = count;
}

void deleteStack(TStack& stack) {
	delete[] stack.items;
	stack.items = nullptr;
}

void push(TStack& stack, char k) {
	if (stack.top >= stack.n) return;
	stack.items[stack.top++] = k;
}

char pop(TStack& stack) {
	if (stack.top == 0) return 0;
	return stack.items[--stack.top];
}

bool isEmpty(TStack stack) {
	return (stack.top == 0);
}

char peek(TStack stack) {
	if (stack.top == 0) return '\0';
	return stack.items[stack.top - 1];
}


struct DStack {
	int n;
	double* items;
	int top;
};

void createStack(DStack& stack, int count) {
	stack.items = new double[count];
	stack.top = 0;
	stack.n = count;
}

void deleteStack(DStack& stack) {
	delete[] stack.items;
	stack.items = nullptr;
}

void push(DStack& stack, double k) {
	if (stack.top >= stack.n) return;
	stack.items[stack.top++] = k;
}

double pop(DStack& stack) {
	if (stack.top == 0) return 0;
	return stack.items[--stack.top];
}



int prior(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}


double eval(string postfix) {
	DStack Stack1;
	createStack(Stack1, postfix.length());
	int i = 0;
	while (i < postfix.length()) {
		char c = postfix[i];
		if (c >= '0' && c <= '9') {
			push(Stack1, double(c-'0'));
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			double op2 = pop(Stack1);
			double op1 = pop(Stack1);
			double res = 0;
			switch (c) {
			case '+': res = op1 + op2; break;
			case '-': res = op1 - op2; break;
			case '*': res = op1 * op2; break;
			case '/':
				if (op2 == 0) {
					cout << "\nDelenie na nol" << endl;
					deleteStack(Stack1);
					return 0;
				}
				res = op1 / op2;
				break;
			}
			push(Stack1, res);
		}
		i++;
	}
	double result = pop(Stack1);
	deleteStack(Stack1);
	return result;
}

bool CheckSkob(string& str)
{
	TStack stack;
	createStack(stack, 100);
	try
	{
		for (int i = 0; i < str.length(); i++)
		{
			char el = str[i];
			if (el == '(' || el == '[' || el == '{')
			{
				push(stack, el);
			}
			else if (el == ')' || el == ']' || el == '}')
			{
				if (isEmpty(stack))
				{
					deleteStack(stack);
					return false;
				}
				char topEl = peek(stack);
				if ((el == ')' && topEl == '(') || (el == ']' && topEl == '[') || (el == '}' && topEl == '{')) pop(stack);
				else
				{
					deleteStack(stack);
					return false;
				}

			}
		}
	}
	catch (...)
	{
		cout << "Stack operation error\n";
		deleteStack(stack);
		return false;
	}
	bool result = isEmpty(stack);
	deleteStack(stack);
	return result;
}

int main()
{
	string skob, prav, signs, otcrSkob;
	string str, out = "";
	char c;
	int i = 0;
	cout << "Enter string " << endl;
	getline(cin, str);
	prav = "0123456789";
	skob = "{}[]()";
	otcrSkob = "([{";
	signs = "+-*/";
	size_t a;
	while (str.find_first_not_of(prav + otcrSkob) == 0)
	{
		cout << "Incorrect entering of equation. First element of the equation must be digit or a open bracket. .Enter equation one more time.\n";
		getline(cin, str);
	}
	while (str.find_first_not_of(prav + skob + signs) != string::npos)
	{
		cout << "Incorrect entering of equation.Equation must consists only of digits, brackets and signs. Enter equation one more time.\n";
		getline(cin, str);
		while (str.find_first_not_of(prav + otcrSkob) == 0)
		{
			cout << "Incorrect entering of equation. First element of the equation must be digit or a open bracket. .Enter equation one more time.\n";
			getline(cin, str);
		}
	}
	if (!CheckSkob(str))
	{
		cout << "Oshibka v skobkax\n";
		return 0;
	}

	TStack charStack;
	createStack(charStack, str.length());


	while (i < str.length()) {
		c = str[i];
		switch (c) {
		case '(':
		case '{':
		case '[':
			push(charStack, c);
			break;
		case ')':
		case '}':
		case ']':
			while (!isEmpty(charStack) && peek(charStack) != '(' && peek(charStack) != '[' && peek(charStack) != '{') {
				out += pop(charStack);
			}
			if (!isEmpty(charStack)) pop(charStack);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (!isEmpty(charStack)) {
				char t = peek(charStack);
				if (t == '(' || t == '[' || t == '{' || prior(c) > prior(t)) break;
				else out += pop(charStack);
			}
			push(charStack, c);
			break;
		default:
			if (c != ' ') out += c;
			break;
		}
		i++;
	}


	while (!isEmpty(charStack)) {
		char k = pop(charStack);
		if (k != '(' && k != '[' && k != '{') out += k;
	}
	deleteStack(charStack);

	cout << "Postfix notation: " << out << endl;


	double finalResult = eval(out);


	cout << "Result: " << fixed << setprecision(2) << finalResult << endl;

	return 0;
}