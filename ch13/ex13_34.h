#pragma once
#include <string>
#include <set>
#include <algorithm>
class Folder;
class Message{
    friend class Folder;
    public:
    explicit Message(const std::string &str = ""):content(str){}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    private:
    std::string content;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};
