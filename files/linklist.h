#pragma once
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED


class linklist{

	private:
		struct Node
		{
			int value;
			Node* next;
		};

	private:
		Node* head;

	public:
		linklist();
		void insert(int value);
		//void display();
		int LengthIs();
};

#endif // LINKLIST_H_INCLUDED
