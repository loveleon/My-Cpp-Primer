#include <memory>
#include <iostream>
#include <string>

using std::string;
struct connection{
    string ip_;
    uint16_t port_;
    connection(string ip,uint16_t port):ip_(ip),port_(port){}
};

struct destination{
    string ip_;
    uint16_t port_;
    destination(string ip,uint16_t port):ip_(ip),port_(port){}
};


