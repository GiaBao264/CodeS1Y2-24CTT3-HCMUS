#include "lib.h"

File::File(string n, string t, int s) : Component(n) {
	type = t;
	size = s;
}

int File::getSize() { return size; }

Shortcut::Shortcut(string n, Component* s) : Component(n) { target = s; }

int Shortcut::getSize() { return 1; }

Folder::Folder(string n) : Component(n) {}

void Folder::add(Component* c) { child.push_back(c); }

int Folder::getSize() {
	int totalSize = 0;
	for (Component* c : child) {
		totalSize += c->getSize();
	}
	return totalSize;
}

Disk::Disk(string n, int c) {
	name = n;
	capacity = c;
}

void Disk::add(Component* item) { contents.push_back(item); }

int Disk::getFreeSpace() {
	int usedSpace = 0;
	for (Component* item : contents) {
		usedSpace += item->getSize();
	}
	return capacity - usedSpace;
}

void FS::addDisk(Disk* d) { disks.push_back(d); }