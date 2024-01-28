#include <iostream>
#include <memory>

class Simple {
public:
    Simple() { std::cout << "Constructor called!" << std::endl; }
    ~Simple() { std::cout << "Destructor called!" << std::endl; }
};

void useResource(std::weak_ptr<Simple>& weakPtr) {
    //使用weak_ptr调用lock函数可以返回一个该weak_ptr指向的资源的shared_ptr
    //如果该weak_ptr指向的资源已经被释放，则返回nullptr
    auto resource = weakPtr.lock();
    if (resource) 
        std::cout << "Resource still alive!" << std::endl;
    else 
        std::cout << "Resource has been freed!" << std::endl;
}

int main() {
    auto sps = std::make_shared<Simple>();
    std::weak_ptr<Simple> weakSimple(sps);
    useResource(weakSimple);
    std::cout << weakSimple.use_count() << std::endl;
    sps.reset();
    useResource(weakSimple);
    return 0;
}