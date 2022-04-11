#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

bool read_file(std::string file_name, std::vector<std::string> &file_value)
{
    std::string data_buffer;
    std::ifstream infile_handler(file_name);
    if (!infile_handler.is_open())
    {
        std::cout << "Erro opening file!" << std::endl;
        return false;
    }

    while (!infile_handler.eof())
    {
        getline(infile_handler, data_buffer);
        file_value.push_back(data_buffer);
    }
    infile_handler.close();
    return true;
}

bool write_file(std::string file_name, std::vector<std::string> change_strings)
{
    std::ofstream outfile_handler(file_name);
    if (!outfile_handler.is_open()) {
        return false;
    }
    for (auto _s: change_strings) {
        outfile_handler << _s;
    }
    outfile_handler.close();
    return true;
}

std::map<std::string, std::string> get_rule(std::string file_name)
{
    std::string buff;
    std::map<std::string, std::string> rule;
    std::ifstream infile_handle(file_name);
    if (infile_handle.is_open())
    {
        while (!infile_handle.eof())
        {
            getline(infile_handle, buff);
            size_t pos = buff.find(' ');
            rule[buff.substr(0, pos)] = buff.substr(pos + 1, buff.length());
        }
    }
    return rule;
}

void change(std::map<std::string, std::string> rule, std::vector<std::string>& want_change_strings)
{
    for (auto &_s:want_change_strings) {
        // 将 string _s 读入到input中
        std::string _temp_s = "", _res = "";
        std::stringstream input(_s);
        while (input >> _res) {
            // try
            // {
            //     _res = rule.at(_res);
            // }
            // catch (out_of_range)
            // {
            //     ;
            // }
            auto _iter = rule.find(_res);
            if (_iter != rule.end()) {
                _res = _iter->second;
            }
            _temp_s += _res;
        }
        _s = _temp_s;
    }
}



int main()
{
    std::string rule_file_name = "./rule.txt";
    std::map<std::string, std::string> rule;
    rule = get_rule(rule_file_name);
    for (auto _iter = rule.begin(); _iter != rule.end(); ++_iter)
    {
        std::cout << _iter->first << ':' << _iter->second << std::endl;
    }

    std::string file_name = "./want_change_text.txt";
    std::vector<std::string> file_result;
    if (read_file(file_name, file_result))
    {
        for (auto _s : file_result)
        {
            std::cout << _s << std::endl;
        }
    }

    change(rule, file_result);

    const std::string out_file_name = "./changed_file.txt";
    if (!write_file(out_file_name, file_result)) {
        return -1;
    }

    return 0;
}