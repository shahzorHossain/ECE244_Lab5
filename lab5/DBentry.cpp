
#include "DBentry.h"


DBentry::DBentry(){
    
    name = "default";
    IPaddress = -1;
    active = true;
}
DBentry::DBentry(string _name, unsigned int _IPaddress, bool _active){
    name = _name;
    IPaddress = _IPaddress;
    active = _active;
}
void DBentry::setName(string _name){
    name = _name;
    
}
string DBentry::getName() const{
    return name;
}
void DBentry::setIPaddress(unsigned int _IPaddress){
    IPaddress = _IPaddress;
}
void DBentry::setActive(bool _active){
    active = _active;
}
unsigned int DBentry::getIPaddress() const{
    return IPaddress;
    
}
bool DBentry::getActive() const{
    return active;
}
DBentry::~DBentry(){
    
}
