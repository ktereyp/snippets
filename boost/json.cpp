#include "json.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>

using namespace boost::property_tree;

std::string ptree_to_string(ptree &p) {
    std::stringstream ss;
    write_json(ss, p, false);
    return ss.str();
}

std::string vector_ptree_to_string(std::vector<ptree> &ptree_vec) {
    std::string str_ret = "[";
    int count = (int) ptree_vec.size();
    for (int i = 0; i < count; i++) {
        ptree item = ptree_vec[i];
        std::string s = ptree_to_string(item);
        str_ret += s;
        if (i != count - 1 && str_ret.length() > 1) {
            str_ret += ",";
        }
    }
    str_ret += "]";
    return str_ret;
}

void json() {
    std::cout << "Hello, World!" << std::endl;
    ptree array_elem0;
    array_elem0.put("name", "侧身Julius Zeleny");
    array_elem0.put("birthday", "1991-01-01");
    array_elem0.put("phone", "(111) 11111111");

    ptree array_elem1;
    array_elem1.put("name", "Owen Cohron");
    array_elem1.put("birthday", "1992-02-02");
    array_elem1.put("phone", "(222) 22222222");

    std::vector<ptree> list = {array_elem0, array_elem1};
    auto s = vector_ptree_to_string(list);
    std::cout << s << std::endl;

    std::stringstream ss(s);
    ptree out;
    read_json(ss, out);
    std::cout << out.size() << std::endl;
}
