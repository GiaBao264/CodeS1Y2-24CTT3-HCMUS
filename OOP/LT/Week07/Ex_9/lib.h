#include <iostream>
#include <vector>

using namespace std;

class Component {
protected:
	string name;

public:
	Component(string n) { name = n; }
	virtual int getSize() = 0;
};

class File : public Component {
private:
	string type;
	int size;

public:
	File(string n, string t, int s);
	int getSize();
};

class Shortcut : public Component {
private:
	Component* target;

public:
	Shortcut(string n, Component* s);
	int getSize();
};

class Folder : public Component {
private:
	vector<Component*> child;

public:
	Folder(string n);
	void add(Component* c);
	int getSize();
};

class Disk {
private:
	string name;
	int capacity;
	vector<Component*> contents;

public:
	Disk(string n, int c);
	void add(Component* item);
	int getFreeSpace();
};

class FS {
private:
	vector<Disk*> disks;

public:
	void addDisk(Disk* d);
};