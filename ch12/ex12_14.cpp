#include <memory>
#include <iostream>
#include <string>

using std::string;
using std::shared_ptr;
using std::cout;
using std::endl;

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

void disconnect(connection *conn){
    cout << conn->ip_ << " " << conn->port_ << endl;
}

void endconnection(connection *conn){
    disconnect(conn);
}

connection connect(destination *dst){
    auto conn = new connection(dst->ip_,dst->port_);
    shared_ptr<connection> sp(conn);
    cout << __func__<< " use count:" << sp.use_count() << endl;
    //shared_ptr<connection> sp(conn,std::bind(endconnection,conn));
    return *sp;
}

void f(destination *dst){
    auto conn = connect(dst);
    shared_ptr<connection> spConn(&conn,endconnection);
    cout << __func__ << " use count:" << spConn.use_count() << endl;
}

int main(){
    destination dst("127.0.0.1",54321);
    f(&dst);

    return 0;
}
