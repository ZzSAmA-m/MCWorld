#pragma once
#include <unordered_map>
#include <string>
#include <type_traits>
#include <stdexcept>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include "Component.hpp"
class Transform;
class MCBehavior;
/// <summary>
/// 游戏对象
/// </summary>
class GameObj final
{
	friend class World;
private:
	/// <summary>
	/// 唯一id
	/// </summary>
	unsigned __int64 _id;
	/// <summary>
	/// 名字
	/// </summary>
	std::string _name;

	Transform* _transform;
	std::unordered_map<std::type_index, Component*> _components;
	std::unordered_map<std::type_index, MCBehavior*> _behaviors;
public:
	GameObj(unsigned __int64 id, std::string&& name);
	GameObj(unsigned __int64 id, std::string& name);
	GameObj(unsigned __int64 id);
	~GameObj();
	Transform* GetTransform();
	std::string& GetName();

	template<class T>
	T* AddComponent() {
		static_assert(std::is_base_of_v<Component, T>, "无法添加这个组件,没继承自Component类");
		if (_components.count(std::type_index(typeid(T)))) {
			throw std::logic_error("已经有这个组件,无法再次添加");
			return nullptr;
		}
		T* cmp = new T(this);
		_components[std::type_index(typeid(T))] = static_cast<Component*>(cmp);
		if constexpr (std::is_base_of_v<MCBehavior, T>) {
			_behaviors[std::type_index(typeid(T))] = static_cast<MCBehavior*>(cmp);
		}
		return cmp;
	}

	template<class T>
	T* GetComponent() {
		if (_components.count(std::type_index(typeid(T)))) {
			return static_cast<T*>(_components[std::type_index(typeid(T))]);
		}
		return nullptr;
	}
	template<class T>
	void RemoveComponent() {
		auto it = _components.find(std::type_index(typeid(T)));
		if (it != _components.end()) {
			_components.erase(it);
		}
		else {
			throw std::runtime_error("移除组件失败,没有这个组件");
		}

		auto it2 = _behaviors.find(std::type_index(typeid(T)));
		if (it2 != _behaviors.end()) {
			_behaviors.erase(it2);
		}

	}
};
