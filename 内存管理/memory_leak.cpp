#include <iostream>
#include <memory>

class Simple {
public:
    Simple() { m_ptr = new int(); }
    ~Simple() { delete m_ptr; }
    void setValue(int value) { *m_ptr = value; }
private:
    int* m_ptr;
};

void doSomething(Simple*& outSimplePtr) {
    //没有释放原来的资源
    outSimplePtr = new Simple();
}

void doSomething1(std::unique_ptr<Simple>& outPtr) {
    outPtr.reset(new Simple());
}

int main() {
    // Simple* simplePtr = new Simple();
    // doSomething(simplePtr);
    // delete simplePtr;
    std::unique_ptr<Simple> up = std::make_unique<Simple>();
    doSomething1(up);
    return 0;
}