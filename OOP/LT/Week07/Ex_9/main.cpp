#include "lib.h"

int main() {
    cout << "Khoi tao he thong FS..." << endl;
    FS* mySystem = new FS();

    cout << "Tao Disk C: dung luong 3000..." << endl;
    Disk* diskC = new Disk("C:", 3000);
    mySystem->addDisk(diskC);

    cout << "Tao File baocao.docx (size 500)..." << endl;
    File* fileBaoCao = new File("baocao.docx", "binary", 500);

    cout << "Tao File avengers.mp4 (size 1000)..." << endl;
    File* filePhim = new File("avengers.mp4", "binary", 1000);

    cout << "Tao Folder LamPhim, them baocao.docx va avengers.mp4 vao..." << endl;
    Folder* folderLamPhim = new Folder("LamPhim");
    folderLamPhim->add(fileBaoCao);
    folderLamPhim->add(filePhim);

    cout << "Tao Shortcut tro den avengers.mp4..." << endl;
    Shortcut* shortcutPhim = new Shortcut("Shortcut_Avengers", filePhim);

    cout << "Them Folder, File va Shortcut vao Disk C:..." << endl;
    diskC->add(folderLamPhim);
    diskC->add(filePhim);
    diskC->add(shortcutPhim);

    cout << "\n--- KET QUA KIEM TRA ---" << endl;
    cout << "Tong dung luong dia: 3000" << endl;
    
    int freeSpace = diskC->getFreeSpace();
    cout << "Tong dung luong da su dung: " << (3000 - freeSpace) << endl;
    cout << "Dung luong con trong (Free Space): " << freeSpace << endl;

    return 0;
}