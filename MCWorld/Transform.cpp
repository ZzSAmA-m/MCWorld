#include "Transform.hpp"

Vector3 Transform::GetPosition()
{
    return _position;
}

void Transform::SetPosition(Vector3 newPos)
{
    this->_position = newPos;
}


Transform::Transform(GameObj* owner)
{
    this->_position = Vector3();
    this->_gameobj = owner;
}

