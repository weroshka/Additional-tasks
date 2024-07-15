#include <iostream>

struct node
{
	//data field
	int field;

	//pointer on the next element
	struct node* next;

	// pointer on the previous element
	struct node* prev;
};

struct node* init(node* first_node, int a)  // a- is the value of the first node
{
	first_node->field = a;
	first_node->next = first_node; //pointer on the next node
	first_node->prev = first_node; //pointer on the previos node
	return(first_node);
}

struct node* Add_element(node* nd, int data)
{
	struct node* temp, * p;
	temp = (struct node*)malloc(sizeof(node));

	//create pointer on new node
	p = nd->next;

	//the previous node points to the new one
	nd->next = temp;

	//save data of new node
	temp->field = data;

	//new node points to next node
	temp->next = p;

	//new node points to previous node
	temp->prev = nd;

	p->prev = temp;

	return(temp);
}

struct node* Delete_element(node* nd)
{
	struct node* prev;
	struct node* next;

	//the node before nd
	prev = nd->prev;

	// the node after nd
	next = nd->next;


	prev->next = nd->next;
	next->prev = nd->prev;

	//free the memory of the object which we deleted
	free(nd);
	return(prev);
}

void Print_list_from_begin(node* nd)
{
	struct node* p;
	p = nd;
	do
	{
		//print the value of the element p 
		printf("%d ", p->field);

		p = p->next;
	}
	// condition of the ending operation
	while (p != nd);
}
void Print_list_from_ending(node* nd)
{
	struct node* p;
	p = nd;
	do
	{
		p = p->prev;
		printf("%d ", p->field);
	} while (p != nd);
}


int main()
{
	node* list = new node;
	init(list, 1999);

	
	Add_element(list->next, 2002);
	Add_element(list->next->next, 2022);

	Print_list_from_begin(list);
	std::cout << std::endl;

	Delete_element(list->prev);
	Print_list_from_ending(list);

	return 0;
}


