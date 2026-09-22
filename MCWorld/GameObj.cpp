#include "GameObj.hpp"
#include "Transform.hpp"
GameObj::GameObj(unsigned __int64 id, std::string&& name) :_id(id), _name(name) {

    _transform=AddComponent<Transform>();
}
GameObj::GameObj(unsigned __int64 id, std::string& name) :GameObj(id, std::move(name)) {

}
GameObj::GameObj(unsigned __int64 id) :GameObj(id, "GameObj") {

}
GameObj::~GameObj() {
    delete _transform;
}

Transform* GameObj::GetTransform()
{
    return this->_transform;
}

std::string& GameObj::GetName()
{
    return this->_name;
}
