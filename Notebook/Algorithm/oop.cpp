#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Query_base {
    public:
        Query_base() = default;

    private:
        double book_no;

    protected:
        double price;
};

class bulk_query : public Query_base {

};


int main()
{
    std::string name = "test";
    std::shared_ptr<std::string> = std::make_shared(name);
    return 0;
}