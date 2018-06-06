#include <iostream>
#include <memory>
#include <string>

using std::shared_ptr;
using std::cout;
using std::endl;
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

connection connect(destination *dst){
    shared_ptr<connection> conn(new connection(dst->ip_,dst->port_));
    cout << __func__ << " use count :" << conn.use_count() << endl;
    return *conn;
}

void disconnect(const connection *conn){
    cout << "disconnect to " << conn->ip_ << ":" << conn->port_ << endl;
}

void endconnection(connection *conn){
    disconnect(conn);
}

void f(destination *dst){
    auto conn = connect(dst);
    //shared_ptr<connection> sp(&conn,[](const connection *conn){
    //        cout << "disconnect to " << conn->ip_ << ":" << conn->port_ << endl;
    //        });
    shared_ptr<connection> sp(&conn,[](const connection *conn){
            disconnect(conn);
            });
    cout << __func__ << " use count :" << sp.use_count() << endl;
}

int main(){
    destination dst("127.0.0.1",54321);
    f(&dst);

    return 0;
}


