#ifndef STACKPAC
#define STACKPAC

template <class T, int N>
class Stack {
private:
	T element[N];
	int counter;

public:
	void clearStack()   { counter = 0; }
	bool emptyStack()   { return counter == 0; }
	bool fullStack()    { return counter == N; }
	void pushStack(T x) { element[counter++] = x; }
	T popStack()        { return element[--counter]; }
};

#endif
