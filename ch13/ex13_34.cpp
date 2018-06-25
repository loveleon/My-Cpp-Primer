#include "ex13_34_2.h"

void Message::save(Folder &f){
    folders.insert(&f);
   f.addMsg(this);
}

void Message::remove(Folder &f){
    folders.erase(&f);
    f.removeMsg(this);
}

Message::Message(const Message &m):content(m.content),folders(m.folders){
    add_to_Folders(m);
}

Message &Message::operator=(const Message &m){
    remove_from_Folders();
    content = m.content;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Message::~Message(){
    remove_from_Folders();
}

void Message::add_to_Folders(const Message &m){
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders(){
    for(auto f : folders)
        f->removeMsg(this);
}

void Message::print(){
        std::cout << content << std::endl;
}

void swap(Message &lf, Message &rt){
    lf.remove_from_Folders();
    rt.remove_from_Folders();
    using std::swap;
    swap(lf.content,rt.content);
    swap(lf.folders,rt.folders);
    lf.add_to_Folders(lf);
    rt.add_to_Folders(rt);
}

Folder::Folder(const Folder &f):m_sMsg(f.m_sMsg) {
    add_to_Message(f);
}

Folder &Folder::operator=(const Folder &f){
   remove_from_Message();
   m_sMsg = f.m_sMsg;
   add_to_Message(f);
   return *this;
}

Folder::~Folder(){
    remove_from_Message();
}

void Folder::remove_from_Message(){
    for(auto m : m_sMsg)
        m->folders.erase(this);
}

void Folder::add_to_Message(const Folder &f){
    for(auto m : f.m_sMsg)
        m->folders.insert(this);
}

void Folder::print(){
    for(auto m: m_sMsg)
        std::cout << m->content << std::endl;
    std::cout << std::endl;
}

void swap(Folder &lf,Folder &rt){
    using std::swap;
    lf.remove_from_Message();
    rt.remove_from_Message();
    swap(lf.m_sMsg,rt.m_sMsg);
    lf.add_to_Message(lf);
    rt.add_to_Message(rt);
}

