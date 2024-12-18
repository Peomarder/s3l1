#include <chrono>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;



	struct Node {
		string value = "";
		Node* next = nullptr;
		//Node(const string& val) : value(val), next(nullptr) {}
	};

struct Darr {
	string* data = new string[capacity];
	size_t capacity = 10;
	size_t size = 0;
		

	void push(string value) {
		if (size == capacity) {
			capacity *= 2;
			string* newData = new string[capacity];
			for (size_t i = 0; i < size; ++i) {
				newData[i] = data[i];	
			}
			data = newData;
		}
		data[size++] = value;
	}
	
	void del(size_t index){
		if (index>=size){
				throw runtime_error("Index OOB!");
			}
		for(size_t i = index; i<size-1; i++){
			data[i] = data[i+1];
		}
		
		size--;
	}
	
	string get(int index) {
		if (index>=size){
				throw runtime_error("Index OOB!");
			}
		return data[index];
	}

	void set(size_t index, string value) {
		if (index>=size){
				throw runtime_error("Index OOB!");
			}
		data[index] = value;
	}
	void print(){
		cout<<"Printing array:\n";
		for (size_t i = 0; i < size; ++i) {
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	
	string save() {
		string a;
	a.clear(); // Clear the string, just for fun tbh
	for (size_t i = 0; i < size; ++i) {
		a += data[i] + ","; // Append each element to the string, followed by a comma
	}
	a.pop_back(); // Remove the trailing comma
	return a;
}

};


struct DoubleLinkedList {
struct DNode {
string value;
DNode* prev;
DNode* next;
DNode(const string& val) : value(val), prev(nullptr), next(nullptr) {}
};

DNode* head;
DNode* tail;

DoubleLinkedList() : head(nullptr), tail(nullptr) {}

void addToHead(const string& value) {
	DNode* newNode = new DNode(value);
	if (!head) {
	head = tail = newNode;
	} else {
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	}
}

void addToTail(const string& value) {
	DNode* newNode = new DNode(value);
	if (!tail) {
	head = tail = newNode;
	} else {
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	}
}

void removeFromHead() {
	if (!head) {
		throw runtime_error("No head!");
		return;
	}
	DNode* temp = head;
	head = head->next;
	if (head) {
		head->prev = nullptr;
	} else {
		tail = nullptr;
	}
}

void removeFromTail() {
	if (!tail) {
		throw runtime_error("No tail!");
		return;
	}
	DNode* temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	} else {
		head = nullptr;
	}
}

void removeByValue(const string& value) {
	DNode* current = head;
	while (current) {
		if (current->value == value) {
			if (current == head) {
				removeFromHead();
			} else if (current == tail) {
				removeFromTail();
			} else {
				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current; //idk icky
			}
			return;
			}
			current = current->next;
	}
	cout << "Value not found." << endl;
}

int findVal(const string& value) {
	DNode* current = head;
	int i = 0;
	while (current) {
	if (current->value == value) {
	return i;
	}
	current = current->next;
	i++;
	}
	return -1;
}

	void print() {
	if (head == nullptr || tail == nullptr) {
				//throw runtime_error("No DoubleLinkedList!");
				cout << "No Double linked list.";
				return;
			}
	DNode* current = head;
	cout << "Printing double-linked list:" << endl;
	while (current) {
		cout << current->value << " <-> ";
		current = current->next;
	}
	cout << "nullptr" << endl;
	}
	
	string save() {
		string d;
		d.clear();
		if (head == nullptr || tail == nullptr) {
			d = "";
			return d;
		}
		DNode* current = head;
		while (current) {
			d += current->value + ",";
			current = current->next;
		}
		d.pop_back(); // Remove the trailing comma
		return d;
	}

};
//////////

struct Queue {
	Node* front = nullptr;
	Node* back = nullptr;

	void push(const string& value) {
		Node* newNode = new Node;
		newNode->value = value;
		if (back == nullptr) {
			front = back = newNode;
		} else {
			back->next = newNode;
			back = newNode;
		}
	}

	string pop() { //dogshit
			if (front == nullptr) {
				throw runtime_error("No queue!");
				return "";
			}
			string value = front->value;
			Node* temp = front;
			front = front->next;
					
			if (front == nullptr) {
				back = nullptr;
			}
			//delete temp;
			return temp->value;
		}

	void print() {
			if (front == nullptr) {
				cout << "" << endl;
				return;
			}
			cout << "Printing queue:" << endl;
			Node* current = front;
			while (current != nullptr) {
			cout << current->value << " -> ";
			current = current->next;
			}
			cout << "nullptr" << endl;
		}
		
		string save() {
			string q;
	q.clear();
	if (front == nullptr) {
		q = "";
		return q;
	}
	Node* current = front;
	while (current!= nullptr) {
		q += current->value + ",";
		current = current->next;
	}
	q.pop_back(); // Remove the trailing comma
	return q;
	}

};

////


struct Stack {

	Node* top = nullptr;

	void push(const string& value) {
		Node* newNode = new Node{value, top};
		top = newNode;
	}

	string pop() {
		if (top == nullptr) {
			throw runtime_error("No stack!");
			return "";
		}
		Node* temp = top;
		top = top->next;
		//delete temp;
		return temp->value;
	}


	void print() {
		if (top == nullptr) {
			cout << "No stack." << endl;
			return;
		}
			cout << "Printing stack:" << endl;
			Node* current = top;
			while (current != nullptr) {
			cout << current->value << endl;
			cout << " -> " ;
			current = current->next;
		}
		cout << "nullptr" << endl;	
	}
	
string save() {
string s;
s.clear();

if (top == nullptr) {
s = "";
return s;
}

Node* current = top;
while (current!= nullptr) {
s = current->value + "," + s;
current = current->next;
}

if (!s.empty()) {
s.pop_back(); // Remove the trailing comma
}

return s;
}

	
};

////////////////////


struct HashTable {
	const int HASHSIZE = 10;
	
	struct Bucket {
		string key;
		string value;
		Bucket* next;
		Bucket(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
	};

	Bucket** buckets;

	HashTable() {
		buckets = new Bucket*[HASHSIZE];
		for (int i = 0; i < HASHSIZE; ++i) {
			buckets[i] = nullptr;
		}
	}

	int hash(const string& key) {
		size_t sum = 0;
		for (char c : key) {
			sum += c;
		}
		return sum % HASHSIZE;
	}

	void insert(const string& key, const string& value) {
		int index = hash(key);
		Bucket* newBucket = new Bucket(key, value);

		if (!buckets[index]) {
			buckets[index] = newBucket;
		} else {
			Bucket* current = buckets[index];
			while (current->next) {
				if (current->key == key) {
					current->value = value;
					delete newBucket;
					cout << "Key already exists. Value updated!" << endl;
					return;
				}
				current = current->next;
			}
			if (current->key == key) {
				current->value = value;
				delete newBucket;
				cout << "Key already exists. Value updated!" << endl;
			} else {
				current->next = newBucket;
			}
		}
	}
	
	string get(const string& key) {
		int index = hash(key);
		Bucket* current = buckets[index];

		while (current) {
			if (current->key == key) {
				return current->value;
			}
			current = current->next;
		}

		throw runtime_error("Key not found in the hash table!");
		return "N/A";
	}

	void remove(const string& key) {
		int index = hash(key);
		Bucket* current = buckets[index];
		Bucket* prev = nullptr;

		while (current) {
			if (current->key == key) {
				if (prev) {
					prev->next = current->next;
				} else {
					buckets[index] = current->next;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}

		throw runtime_error("Key not found.");
	}

	void print() {
		cout << "Printing hash table:" << endl;
		for (size_t i = 0; i < HASHSIZE; ++i) {
			cout << "Bucket " << i << ": ";
			Bucket* current = buckets[i];
			while (current) {
				cout << "(" << current->key << ": " << current->value << ") -> ";
				current = current->next;
			}
			cout << "nullptr" << endl;
		}
	}
	
	string save() {
	string h;
	h.clear();
	for (size_t i = 0; i < HASHSIZE; ++i) {
		Bucket* current = buckets[i];
		while (current) {
			h +=  current->value + "," + current->key + "," ;
			current = current->next;
		}
	}
	h.pop_back(); // Remove the trailing comma
	return h;
}
	
};


struct CompleteBinaryTree {
		
	struct TreeNode {
	string data = "n/a";
	TreeNode* left;
	TreeNode* right;
	};
		
	TreeNode* root = nullptr;
	int nodeCount = 0;
	Queue data;

	void insert(string value) {
	nodeCount++;
	root = insertHelper(root, value, 1);
	data.push(value);
	}

	TreeNode* insertHelper(TreeNode* node, string value, int index) {
		if (node == nullptr) {
		return new TreeNode{value, nullptr, nullptr};
		}
		if (index * 2 <= nodeCount) {
		node->left = insertHelper(node->left, value, index * 2);
		} else {
		node->right = insertHelper(node->right, value, index * 2 + 1);
		}
		return node;
	}

	bool search(string value) {
	TreeNode* B = searchHelper(root, value); 
	return (B->data==value)?true:false;//retarded
	}

	TreeNode* searchHelper(TreeNode* node, string value) {
	if (node == nullptr || node->data == value) return node;
	TreeNode* left = searchHelper(node->left, value);
	return left ? left : searchHelper(node->right, value);
	}

	bool isComplete() {
	return isCompleteHelper(root, 0);
	}

	bool isCompleteHelper(TreeNode* node, int index) {
	if (node == nullptr) return true;
	if (index >= nodeCount) return false;
	return isCompleteHelper(node->left, 2 * index + 1) &&
	isCompleteHelper(node->right, 2 * index + 2);
	}

	
	string getEBI(int index) { //el by index
	if (index < 1 || index > nodeCount) {
		return "Invalid index";
	}
		return getEBIHelper(root, index, 1);
	}

	string getEBIHelper(TreeNode* node, int targetIndex, int currentIndex) {
		if (node == nullptr) {
			return "Node not found";
		}
		if (currentIndex == targetIndex) {
			return node->data;
		}
		if (targetIndex < currentIndex * 2) {
			return getEBIHelper(node->left, targetIndex, currentIndex * 2);
		} else {
			return getEBIHelper(node->right, targetIndex, currentIndex * 2 + 1);
		}
	}
	
	
	void print() {
		cout << "Complete Binary Tree:" << endl;
		printHelper(root, 0);
	}

	void printHelper(TreeNode* node, int space) {
		if (node == nullptr) return;
		space += 5;
		printHelper(node->right, space);
		cout << endl;
		for (int i = 5; i < space; i++) cout << " ";
		cout << node->data << endl;
		printHelper(node->left, space);
	}
	string save(){
		return data.save();
	}

};

void saveToFile(const string& filename, Darr& ar, DoubleLinkedList& dr, Queue& qr, Stack& sr, HashTable& hr, CompleteBinaryTree& tr) {
	remove(filename.c_str());
	ofstream file(filename, ios::binary);
	if (!file.is_open()) {
	cout << "No file." << endl;
	return;
	}

	// Darr
	file << ar.save()<< "\n" <<dr.save()<< "\n" <<qr.save()<< "\n" <<sr.save()<< "\n" <<hr.save()<< "\n" <<tr.save()<< "\n";

	file.close();
	cout << "\n\nData saved to " << "data.txt" << "." << endl;
}


void loadFromFile(const string& filename, Darr& a, DoubleLinkedList& d, Queue& q, Stack& s, HashTable& h, CompleteBinaryTree& t) {
	try{
	ifstream file(filename);
	string line;
	int structureIndex = 0;
	if (!file.is_open()) {
		cout << "no file..." << endl;
		return;
	}
	while (getline(file, line) && structureIndex < 6) {
		istringstream ss(line);
		string value;
		string valuekey;
		if (line.empty()) continue;
		while (getline(ss, value, ',')) { //idk breaks here
				
			value.erase(0, value.find_first_not_of("	 "));
			value.erase(value.find_last_not_of("	 ") + 1);
			if (value==""){break;};
			switch(structureIndex) {
					
				case 0: a.push(value); break;
				case 1: d.addToTail(value); break;
				case 2: q.push(value); break;
				case 3: s.push(value); break;
				case 4: getline(ss, valuekey, ','); h.insert(valuekey,value); break; //needs key
				case 5: t.insert(value); break;
			}
		}

		structureIndex++;
	}

	file.close();
	cout << "Data loaded from " << filename << "." << endl;
	}
	catch(exception& e){
		cout<<"ERROR: "<<e.what()<<endl;
	}

}

int main(int argc, char* argv[10]) {
try{
cout << "Welcome to the Data Structures!" << endl;
	/// ////////////////////////////////
				Darr arrr;
				DoubleLinkedList dll;
				Queue sq;
				Stack st;
				HashTable hsh ;
				CompleteBinaryTree cbt;
	/// ///////////////////////////////
	loadFromFile("data.txt",arrr,dll,sq,st,hsh,cbt);
	
cout<<"7";
int index;
string value,command, filename = "data_structures.txt";
cout << "Available commands: M* (Array), L* (List), Q* (Queue), S* (Stack), H* (Hash Table), T* (Tree), PRINT, EXIT" << endl;

string filePath = "";
string query = "";



  for (int i = 1; i < argc; i++)
	{
	string temp = argv[i];
	  if (temp == "--file"){
		filePath = argv[i + 1];
		//cout <<i<<" " << argv[i+1] <<" ";
	  
	  continue;
	}
	  else if (temp == "--query")
	{
	  for (int j = i + 1; j < argc; j++)
		{
			temp = argv[j];
	//cout <<j<<" " << argv[j] <<" ";
		  if (temp == "--file"){
		break;}
		  query += temp + ' ';
		}
		
	}
	}

	cout << "File path: " << filePath << endl;


	cout << "Query: " << query << endl;
if (!query.empty()) {
}


	try{
//cout << "Enter command: ";
//string input;
//getline(cin, input);
istringstream isstr(query);
isstr >> command;

if (command == "MPUSH") {
	if (isstr >> value) {
	arrr.push(value);
	cout << "Element " << value << " added to array." << endl;
	}
}

else if (command == "MSET") {

if (isstr >> index >> value) {
	arrr.set(index,value);
	cout << "Element " << value << " set to array at index " << index << "." << endl;
}
}

else if (command == "MDEL") {

if (isstr >> index) {
	arrr.del(index);
	cout << "Element at index " << index << " removed!" << endl;
}
}

else if (command == "MGET") {

if (isstr >> index) {
	cout << "Got: " << arrr.get(index)<<endl;
	cout << "Element at index " << index << " retrieved." << endl;
}
}

////
else if (command == "LPUSH") {
string position;

if (isstr >> position >> value) {
	if (position == "head" || position == "tail") {
			if(position == "head"){
			dll.addToHead(value);
			} else {
			dll.addToTail(value);
			}
			// listPush(position == "head", value);
		cout << "Element " << value << " added to the " << position << " of the list." << endl;
	} else {
		cout << "Invalid position for LPUSH." << endl;
	}
} else {
	cout << "Invalid input for LPUSH. " << endl;
}
}


else if (command == "LDEL") {
	string position;
	if (isstr >> position) {
		if (position == "head" || position == "tail" || position == "value") {

			if(position == "head"){
			dll.removeFromHead();
			} else if (position == "tail") {
			dll.removeFromTail();
			} else {
				isstr>>value;
				dll.removeByValue(value);
				cout << "Element removed from the list." << endl;
				return 0;
			}

		cout << "Element removed from the " << position << " of the list." << endl;
		} else {
		cout << "Invalid position for LDEL." << endl;
		}
	} else {
	cout << "Invalid input for LDEL." << endl;
	}
}


else if (command == "LGET") {
	if (isstr >> value) {
		int result = dll.findVal(value);
		if(result == -1){ cout<<"Couldn't find value"; return 1;} 
		else {
			cout<< "Found at "<< result;
		}
	} else {
		cout << "Invalid input for LGET." << endl;
	}
} 

else if (command ==  "SPUSH"){
	if (isstr >> value) {
		st.push(value);
		cout << "Element " << value << " added to the stack." << endl;
	} else {
		cout << "Invalid input for SPUSH." << endl;
	}
}

else if (command == "QPUSH") {

	if (isstr >> value) {
		sq.push(value);
		cout << "Element " << value << " added to the queue." << endl;
	} else {
		cout << "Invalid input for QPUSH." << endl;
	}
} 

else if (command == "QPOP") {
	cout << "Element "<< sq.pop() <<" popped from the queue." << endl;
} 

else if (command == "SPOP") {
	st.pop();
	cout << "Element"<< st.pop() <<" popped from the stack." << endl;
} 

else if (command == "HSET") {
	string key;
	if (isstr >> key >> value) {
		hsh.insert(key,value);
		cout << "Key-value pair (" << key << ", " << value << ") added to hash table." << endl;
	} else {
		cout << "Invalid input for HSET." << endl;
	}
} 

else if (command == "HDEL") {
	string key;
	if (isstr >> key) {
		hsh.remove(key);
		cout << "Key " << key << " removed from hash table." << endl;
	} else {
		cout << "Invalid input for HDEL." << endl;
	}
} 

else if (command == "HGET") {
	string key;
	if (isstr >> key) {
		hsh.get(key);
		cout << "Value for key " << key << " retrieved from hash table." << endl;
	} else {
		cout << "Invalid input for HGET." << endl;
	}
} 


else if (command == "TPUSH") {
if (isstr >> value) {
	cbt.insert(value);
// treeInsert(value);
cout << "Element " << value << " inserted into the tree." << endl;
} else {
cout << "Invalid input for TINSERT." << endl;
}
} 
else if (command == "TGET") {

if (isstr >> value) {
	
 bool found = cbt.search(value);// uh idk
 if(found){
 cout << "Element " << value << " found in the tree!" << endl;}
 else {cout<<"idk ";}
} else {
cout << "Invalid input for TGET." << endl;
}
} 
else if (command == "TCHECK") {
	if (cbt.isComplete()){ cout<<"tree is ok \n";} else {cout<<"tree is not ok \n";}
 

} 
else if (command == "PRINT") {
	arrr.print();
	dll.print();
	sq.print();
	st.print();
	hsh.print();
	cbt.print();
// Implement print logic for all structures
cout << "All data structures printed!" << endl;
} 
else if (command == "SAVE") {
//saveToFile(filename);
} 
else if (command == "LOAD") {
//loadFromFile(filename);
} 
else if (command == "EXIT"||command == "QUIT") {
cout << "Farewell!" << endl;
} else {
cout << "Unknown command!" << endl;
}
}
catch(exception& e){
	cout<<"ERROR: "<<e.what()<<endl;
}



saveToFile(filePath,arrr,dll,sq,st,hsh,cbt);
}
catch(exception& e){
	cout<<"ERROR: "<<e.what()<<endl;
}

return 0;
}

	
	



