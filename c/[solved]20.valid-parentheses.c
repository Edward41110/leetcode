#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<Windows.h>

typedef struct _mystack {
	char ch;
	struct _mystack *next;
}mystack;

void push(mystack* head, char ch)
{
	mystack *pNew = (mystack *)malloc(sizeof(mystack));
	pNew->ch = ch;
	pNew->next = head->next;
	head->next = pNew;
}

char pop(mystack* head)
{
	char ch = 0;
	if (head->next == NULL)
		return 0;
	else
	{
		mystack *pTop;
		pTop = head->next;
		ch = pTop->ch;
		head->next = pTop->next;
		free(pTop);
	}
	return ch;
}

bool isValid(char * s) {
	bool ret = true;
	char ch;
	int i;
	mystack* head = (mystack *)malloc(sizeof(mystack));
	head->next = NULL; 
	for (i = 0;s[i] != '\0';i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			push(head, s[i]);
		else
		{
			if (ch = pop(head))
			{
				if ((s[i] == ')' && ch != '(') || (s[i] == ']' && ch != '[') || (s[i] == '}' && ch != '{'))
				{
					ret = false;
					break;
				}
			}
			else
			{
				ret = false;
				break;
			}
		}
	}
	if (head->next != NULL) ret = false;
	return ret;
}

int main()
{
	char *s = "";
	bool result = isValid(s);
	printf("%d\n", result);
	return 0;
}

