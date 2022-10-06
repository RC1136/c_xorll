
typedef struct {
	int data;

	unsigned int ptr;
} XorLL;

XorLL* push(XorLL** _head, int _data);
int pop(XorLL** _head);
XorLL* getel(XorLL* _head, const int _pos);
void insert(XorLL** _head, const int _data, const int _pos);



