#include <iostream>
#include <vector>
#include <stdexcept>
#include <typeinfo>

// -*-*-*-*-*-*-* 定义测试类 -*-*-*-*-*-*-*-*-*
struct pubilc_animals {
    // pubilc_animals() = default;     // 析构函数（默认）
    std::string name = "sheeps";
    double weight(size_t idx, const float arr[]);
    std::string run(std::string sound);
};

class animals {
    public:
        std::string run(std::string sound);
        // friend pubilc_animals;

    private:
        std::string name = "";
        double weight(size_t idx, const float arr[]);
};


// -*-*-*- 定义函数重载 与 传引用和传值拷贝（传参） -*-*-*-
void print_size(size_t idx, std::vector<int> arr)
{
    std::vector<int> a (10);
    std::cout << idx << std::endl;
}

// decltype(arr) print_size()
// {

// }

// std::string::size_type print_size(const std::string &s)
// {

// }

inline const std::string &
find_short_string(const std::string &s1, const std::string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

int main(int argc, char const *argv[])
{
    // std::string
    std::string name = "yijiantao";
    for (auto &c: name){
        if (c == 'a') c = 'x';
    }
    std::cout << name << std::endl;

    // std::vector
    std::vector<int> num(10, 42);
    for (auto _v: num) std::cout << _v << std::endl;
    // auto mid = num.begin() + num.size() / 2;
    auto mid = num.size() / 2;
    std::cout << mid << std::endl;

    // 类型转换
    // std::string str_num (10, '1');   // string static_cast强转出错
    int str_num = 1;
    double double_name = static_cast<double> (str_num);
    std::cout << str_num << ' ' << typeid(str_num).name() << std::endl;
    std::cout << double_name << ' ' << typeid(double_name).name() << std::endl;

    // 异常捕获
    // try{
    //     double double_name = static_cast<double> name;
    //     if (name != double_name) 
    //         throw runtime_error("Data must refer to same!")

    // } catch (runtime_error err) {
    //     // 异常逻辑确保对象有效，资源无泄漏等
    //     std::cout << err.what()
    //               << "do something" << std::endl;
    // } catch(overflow_error err) {

    // } catch (logic_error err) {

    // }

    // -*-*-*-*-*-*-*- 函数调用 -*-*-*-*-*-*-*-*-*-*-
    std::cout << find_short_string(name, name+ " changed") << std::endl;

    // -*-*-*-*-*-*-*- 类定义 -*-*-*-*-*-*-*-*-*--*-
    pubilc_animals pa{};
    std::cout << pa.name << std::endl;
    return 0;
}
