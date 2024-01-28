#include <memory>
#include <iostream>
#include <fstream>

int* malloc_int(int value) {
    int* p = (int*)malloc(sizeof(int));
    *p = value;
    return p;
}

void CloseFile(FILE* filePtr) {
    if (filePtr == nullptr) 
        return;
    fclose(filePtr);
    std::cout << "File closed." << std::endl;
}

//错误的示范
void WrongDoubleDelete() {
    int* pti = new int(20);
    std::shared_ptr<int> sp1(pti);
    std::cout << sp1.use_count() << std::endl;
    std::shared_ptr<int> sp2(pti);
    std::cout << sp2.use_count() << std::endl;
}

//正确的示范
void RightDoubleDelete() {
    int* pti = new int(28);
    std::shared_ptr<int> sp1(pti);
    std::shared_ptr<int> sp2(sp1);
    std::cout << sp1.use_count() << std::endl;
}

int main() {
    
    //shared_ptr在指定类型的时候不需要带上删除器的类型
    std::shared_ptr<int> sp(malloc_int(42), free);

    FILE* f = fopen("data.txt", "r");
    std::shared_ptr<FILE> ptf(f, CloseFile);
    if (ptf == nullptr) 
        std::cerr << "Error opening file." << std::endl;
    else 
        std::cout << "File opened." << std::endl;

    // WrongDoubleDelete();
    RightDoubleDelete();
    return 0;
}