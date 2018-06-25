#pragma once
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
class Folder;
class Message{
    friend void swap(Message &lf,Message &rt);
    friend class Folder;
    public:
    explicit Message(const std::string &str = ""):content(str){}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void print();
    private:
    std::string content;
    std::set<Folder*> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void swap(Message &lf, Message &rt);

class Folder{
    friend class Message;
    friend void swap(Folder &, Folder &);
    public:
        Folder() = default;
        Folder(const Folder &f);
        Folder &operator=(const Folder &f);
        ~Folder();
        void print();
    private:
        std::set<Message *> m_sMsg;
        void add_to_Message(const Folder &);
        void remove_from_Message();

        void addMsg(Message *m){m_sMsg.insert(m);}
        void removeMsg(Message *m){m_sMsg.erase(m);}
};

