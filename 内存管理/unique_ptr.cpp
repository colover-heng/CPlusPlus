#include <memory>
#include <iostream>

class Foo {
public:
    Foo(std::unique_ptr<int> data) : m_data(std::move(data)) {}
private:
    std::unique_ptr<int> m_data;
};

int main() {

    //可以使用两种方式来初始化一个unique_ptr智能指针对象
    //最好采用make_unique方式来创建智能指针对象

    //采用make_unique方法来进行创建
    std::unique_ptr<int> pti = std::make_unique<int>(20);
    std::unique_ptr<int[]> prarr = std::make_unique<int[]>(19);

    //采用new返回的指针来初始化
    std::unique_ptr<int> pti1(new int(20));

    //reset方法可以使智能指针
    pti1.reset(); //释放资源且将pti1设为nullptr
    pti.reset(new int(30)); //释放原有的资源，并管理新的资源

    int* res = pti.release(); //断开与底层资源的连接，并将底层资源的指针返回出来
    delete res; 

    auto smartPointer = std::make_unique<int>(42);
    Foo f(std::move(smartPointer));
    return 0;
}