#include <iostream>
#include <string>

using namespace std;

class link_list
{
	public:
    struct node
	{
        string name;
        string prn;
        int roll;
        node *next;
    };

    node *head;
    int counter = 0;

    link_list() : head(nullptr) {}

    ~link_list()
	{
        while (head != nullptr)
		{
            node *temp = head;
            head = head -> next;
            
            delete temp;
        }
    }

    void insert(int roll, const string &name, const string &prn);
    
    void deletion(const string &prn);
    
	void display() const
	{
    	node *temp = head;
    	
	    if (counter == 0)
    	{
    	    cout << "No students present in database. " << endl;
    	    cout << "Please [Insert] entities first. " << endl << endl;
    	}
    	else
    	{
    	    cout << "Total Number of students = " << counter << endl << endl;
    	    cout << ">> Student List <<" << endl << endl;
    	    
    	    while (temp != nullptr)
    	    {
    	        if (temp -> roll == 0)
    	        {
    	            cout << "President: " << endl;
    	        }
    	        else if (temp -> roll == 1)
        	    {
            	    cout << "Member: " << endl;
            	}
            	else if (temp -> roll == 2)
            	{
            	    cout << "Secretary: " << endl;
            	}
            		    
            	cout << "\tName: " << temp -> name << endl;
            	cout << "\tRoll No: " << temp -> roll << endl;
           		cout << "\tPRN: " << temp -> prn << endl;
            	    
            	temp = temp -> next;
        		
            	cout << endl;
        	}
    	}
	}


    void concatenate(link_list &l1);
};

void link_list::insert(int roll, const string &name, const string &prn)
{
    node *new_node = new node;
    
    new_node -> roll = roll;
    new_node -> name = name;
    new_node -> prn = prn;
    
    new_node -> next = nullptr;
    
    counter++;

    if (head == nullptr)
	{
        head = new_node;
        return;
    }

    if (roll == 0)
	{
        new_node -> next = head;
        head = new_node;
    }
    
	else if (roll == 1)
	{
	    node *temp = head;
	    while (temp -> next != nullptr && temp -> next -> roll != 2)
		{
	        temp = temp -> next;
	    }
	    new_node -> next = temp -> next;
	    temp -> next = new_node;
	}
	
	else if (roll == 2)
	{
        node *temp = head;
        while (temp -> next != nullptr)
		{
            temp = temp -> next;
        }
        temp -> next = new_node;
    } 
}

void link_list::deletion(const string &prn)
{
    node *temp = head;
    node *prev = nullptr;

    while (temp != nullptr && temp -> prn != prn)
	{
        prev = temp;
        temp = temp -> next;
    }

    if (temp == nullptr)
	{
        cout << "PRN not found. " << endl;
        return;
    }

    if (temp == head)
	{
        head = head -> next;
    }
    else
	{
        prev -> next = temp -> next;
    }
    
    delete temp;
    counter--;
}

void link_list::concatenate(link_list &l1)
{		
    if (head == nullptr)
	{
        head = l1.head;
    }
    else
    {
        node *temp = head;
        while (temp -> next != nullptr)
		{
            temp = temp -> next;
        }
        temp -> next = l1.head;
    }

    node *temp = l1.head;
    while (temp != nullptr)
    {
        counter++;
        temp = temp -> next;
    }

    l1.head = nullptr;
}

int getChoiceNumber(const string &choice)
{
    if (choice == "1" || choice == "Insert") return 1;
    
    if (choice == "2" || choice == "Delete") return 2;
    
    if (choice == "3" || choice == "Concatenate") return 3;
    
    if (choice == "4" || choice == "Display") return 4;
    
    if (choice == "5" || choice == "Exit") return 5;
    
    else
    {
		return 0; 
	}
}

int main()
{
    link_list l1;
    string choice;
    int choice_num;

    do
	{
		cout << ">> Linked List <<" << endl << endl;

		cout << "[ 1 = Insert ]\n[ 2 = Delete ]\n[ 3 = Concatenate ]\n[ 4 = Display Student List ]\n[ 5 = Exit ]" << endl << endl;
		
        cout << "Action to be performed: ";
        cin >> choice;
        
        cout << "________________________________" << endl;
        
        choice_num = getChoiceNumber(choice);
        switch (choice_num)
		{
            case 1:
				{
	                string name, prn;
                	int roll;
                	
                	cout << endl;
                	cout << "Enter Student Name: ";
                	cin.ignore();
                	getline(cin, name);
                	
                	cout << "Enter PRN: ";
                	cin >> prn;
                	
                	cout << "For Roll Number of Student: " << endl << endl;
					cout << "[ 0 = President ]\n[ 1 = Member ]\n[ 2 = Secretary ]\n\n";
					cout << "Enter Roll No: ";
                	cin >> roll;
                	
                	if (roll < 0 || roll > 2)
					{
                    	cout << "Invalid input. " << endl;
                    	
                    	break;
                	}
                	
                	cout << endl;
                	cout << "________________________________" << endl;
                	
                	l1.insert(roll, name, prn);
                	//l1.display();
                	
                	break;
            }
            
            case 2:
				{
                	string prn;
                	cout << endl;
                	
                	cout << "Enter the PRN of student you want to delete: ";
                	cin >> prn;
                	
                	l1.deletion(prn);
                	//l1.display();
                	
                	cout << "________________________________" << endl;
                	
                	break;
            }
            
            case 3:
				{
                	link_list l2;
                	int n;
											
					cout << "Number of students in List 2: ";
					cin >> n;
                	
                	cout << endl;
                	
                	for (int i = 0; i < n; i++)
					{
                    	string name, prn;
                    	int roll;
                    	
                    	cout << endl;
                    	
                    	cout << "Enter student name: ";
                    	cin.ignore(); 
                    	getline(cin, name);
                    	
                    	cout << "Enter PRN: ";
                    	cin >> prn;
                    	
                    	cout << "For Roll Number of Student: " << endl << endl;
						cout << "[ 0 = President ]\n[ 1 = Member ]\n[ 2 = Secretary ]\n\n";
						cout << "Enter Roll No: ";
						cin >> roll;
                    	
                    	if (roll < 0 || roll > 2)
						{
                        	cout << "Invalid input." << endl;
                        	i--; 
                        	
                        	continue;
                    	}
                    	
                    	l2.insert(roll, name, prn);
                    	cout << "________________________________" << endl;
                	}
                	
                	l1.concatenate(l2);
                	//l1.display();
                	
                	break;
            }
            
            case 4:
            	cout << endl;
				
				l1.display();
				cout << "________________________________" << endl;
				
				break;
			
            case 5:
			    cout << endl;
			    
			    cout << "Exiting program..." << endl;
			    
			    break;
			
            default:
            	cout << endl;
            	
                cout << "Invalid input." << endl;
                cout << "________________________________" << endl;
                
                break;
        }
    }
    
	while (choice_num != 5);
    {
		return 0;
	}
}
