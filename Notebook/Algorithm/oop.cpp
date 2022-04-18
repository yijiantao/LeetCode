#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Query_base {
    public:
        Query_base() = default;
        std::string find(Query_base& p) const {};
    private:
        double book_no;

    protected:
        double price;
};

class bulk_query : public Query_base {
    public:
        std::string find(bulk_query& p ) const {}; // 测试动态绑定（运行时绑定）
    private:
        double price_value;     // 折扣价格

    protected:
        double price;
};


int main()
{
    std::string name = "test";
    std::shared_ptr<std::string> = std::make_shared(name);
    return 0;
}