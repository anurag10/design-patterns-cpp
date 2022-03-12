/**
Singleton with a Twist !!
Design a Singleton class which returns one of two instances alternatively

Learnings:
1. How to init private static members...otherwise you get "undefined reference to Singleton::x" error
2. Lazy init
**/

#include <iostream>
using namespace std;

class Singleton {
public:
	static Singleton* GetInstance() {
		flag = !flag;
		if (flag) {
			if (s1 == nullptr)
				s1 = new Singleton("Even");
			return s1;
		}
		else {
			if (s2 == nullptr)
				s2 = new Singleton("Odd");
			return s2;
		}
	}
	string GetName() {
		return name;
	}

private:
	Singleton() = delete;

	// Copy contructor
	Singleton(Singleton&) = delete;

	// Assignment operator
	void operator=(Singleton obj) = delete;

	Singleton(string n) {
		name = n;
	}

	static Singleton* s1;
	static Singleton* s2;
	static bool flag;
	string name;
};
Singleton* Singleton::s1 = nullptr;
Singleton* Singleton::s2 = nullptr;
bool Singleton::flag = false;

int main() {
	for(int i = 0; i < 10; i++)
	cout << Singleton::GetInstance()->GetName() << endl;
	return 0;
}