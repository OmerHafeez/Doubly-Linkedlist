#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int dat)
	{
		data = dat;
		left = nullptr;
		right = nullptr;
	}
};

class linkedlist {
public:
	Node* head;
	linkedlist()
	{
		head = nullptr;
	}

	Node* create_Node(int data)
	{
		Node* newNode = new Node(data);
		if (newNode == nullptr)
		{
			cout << "Space not allocated" << endl;
		}
		else
		{
			return newNode;
		}
	}

	int count_Nodes()
	{
		if (head == nullptr)
			return 0;
		else if (head->right == nullptr)
			return 1;
		else
		{
			int count = 0;

			Node* current = head;
			while (current->right != nullptr)
			{
				count++;
				current = current->right;
			}
			return count+1;
		}
	}

	void add_Node_start()
	{
		int dat;
		cout << "Enter the data for this node" << endl;
		cin >> dat;
		Node* newNode = create_Node(dat);
		if (head == nullptr)
		{
			head= newNode;
			newNode->right = nullptr;
		}
		else
		{
			newNode->right = head;
			head = newNode;
			newNode->right->left = newNode;
		}
	}

	void add_Node_end()
	{
		int dat;
		cout << "Enter the data for this node" << endl;
		cin >> dat;
		Node* newNode = create_Node(dat);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->right!=nullptr)
			{
				current = current->right;
			}
			current->right = newNode;
			newNode->left = current;
		}
	}

	void add_Node_Random()
	{
		
		int position;
		int dat;
		cout << "Enter the position of the new Node" << endl;
		cin >> position;
		cout << "Enter the data for the Node" << endl;
		cin >> dat;
		Node* newNode = create_Node(dat);
		if (position<0 || position>(count_Nodes() + 1))
			cout << "Entered position is invalid" << endl;
		else if (head == nullptr)
		{
			head = newNode;
			newNode->right = nullptr;
		}
		else if(position==(count_Nodes()+1))
		{
			Node *current = head;
			while (current->right != nullptr)
			{
				current = current->right;
			}
			current->right = newNode;
			newNode->left = current;
		}
		else
		{
			Node* current = head;
			int pos = 0;
			while (pos < position - 1)
			{
				current = current->right;
				pos++;
			}
			newNode->right = current->right;
			newNode->left = current;
			if (current->right != nullptr)
			{
				current->right->left = newNode;
			}
			current->right = newNode;
		}
	}

	void delete_Node_start()
	{
		if (head == nullptr)
			cout << "Linked List is already empty" << endl;
		else if (head->right == nullptr)
			delete head;
		else
		{
			Node* newNode = head;
			head = head->right;
			delete newNode;
		}
	}

	void delete_Node_end()
	{
		if (head == nullptr)
		{
			cout << "Linked List is already empty" << endl;
		}
		else if (head->right == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* last = head;
			while (last->right != nullptr) // Change to != for correct loop condition
			{
				last = last->right;
			}

			if (last->left != nullptr)
			{
				last->left->right = nullptr;
			}
			else
			{
				head = nullptr;
			}
			delete last;
		}
	}


	void displayList() 
	{
		Node* current = head;
		while (current != nullptr) 
		{
			cout << current->data << " -> ";
			current = current->right;
		}
		cout << "nullptr" << endl;
	}
	
	void displayList_reverse() 
	{
    // Find the last node by traversing from the head
    Node* current = head;
    while (current != nullptr && current->right != nullptr) 
    {
        current = current->right;
    }

    // Now, 'current' points to the last node
    // Traverse the list in reverse order from 'current' to the head
    while (current != nullptr) 
    {
        cout << current->data << " -> ";
        current = current->left;  // Move to the previous node
    }
    
    cout << "nullptr" << endl;
	}
};

int main()
{

	linkedlist myList;


	int choice = -1; // Initialize choice to a non-zero value

	while (choice != 0) 
	{
		cout << "Linked List Menu:" << endl;
		cout << "1. Count Nodes" << endl;
		cout << "2. Add Node at start" << endl;
		cout << "3. Add Node at End" << endl;
		cout << "4. Add Node at Random Position" << endl;
		cout << "5. Delete Node at start" << endl;
		cout << "6. Delete Node at End" << endl;
		cout << "7. Delete Node at Random Position" << endl;
		cout << "8. Display List" << endl;
		cout << "9. Display reversed List" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
			cout << "Total Nodes: " << myList.count_Nodes() << endl;
		 if (choice == 2)
			myList.add_Node_start();
		else if (choice == 3)
			myList.add_Node_end();
		else if (choice == 4)
			myList.add_Node_Random();
		else if (choice == 5)
			myList.delete_Node_start();
		else if (choice == 6)
			myList.delete_Node_end();
		//else if (choice == 7) 
		//  myList.delete_Node_Random();
		else if (choice == 8)
			myList.displayList();
		else if (choice == 9)
			myList.displayList_reverse();
		else if (choice == 0)
			cout << "Exiting..." << endl;
		else
			cout << "Invalid choice! Please try again." << endl;
			
	}

	// Free memory for all nodes before exiting
	//    while (start != nullptr) {
	//        Node* temp = start;
	//        start = start->next;
	//        delete temp;
	//    }
	cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "X The Code is Ended X" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
	return 0;
}