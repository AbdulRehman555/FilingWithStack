#include<iostream>
#include<fstream>
using namespace std;

class MyStack{
	int data;
	MyStack *next;
	MyStack *top;
public:
	MyStack():data(0),next(NULL),top(NULL){}
	bool isempty();
	void push(int);
	void pop();
	void readFile();

};
void writeFile(int value) {
	fstream outfile;
	outfile.open("Stack.dat", ios::app | ios::binary);
	if (!outfile)
		cout << "File Not created.\n";
	outfile.write(reinterpret_cast<char*>(&value), sizeof(int));
	outfile.close();
	
}
void MyStack::push(int value){
	MyStack *ptr = new MyStack;
	ptr->data = value;
	ptr->next = top;
	top = ptr;
	writeFile(value);

}
void MyStack::readFile() {
	fstream infile;
	infile.open("Stack.dat",ios::in | ios::binary);
	if (!infile)
		cout << "ERROR\n";
	
	while (!infile.eof()) {
		MyStack *ptr = new MyStack;
		infile.read(reinterpret_cast<char*>(&ptr->data), sizeof(int));
		ptr->next = top;
		top=ptr;
	}
	infile.close();
}
void MyStack::pop(){
	
	if (isempty())
		cout << "Stack is Empty" << endl;
	else{
		cout << top->data << " ";
		MyStack *ptr = top;
		top = top->next;
		delete(ptr);
	}

}

bool MyStack::isempty(){
	if (top == NULL)
		return true;
	else
		return false;
}
int main(){

	MyStack stack;
	/*stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);*/
	stack.readFile();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	system("pause");
	return 0;
}
