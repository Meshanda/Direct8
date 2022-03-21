﻿#pragma once

enum class ComponentCategory
{
	single,
	multiple,
};

class Component
{
	friend class EngineComponent;
	friend class MonoBehaviour;

	Component() = default;

public:
	virtual ~Component() = default;
	virtual const char* GetType() = 0; // a pure function makes the class abstract
	virtual ComponentCategory GetCategory() = 0;

	bool TypeEquals(Component* other);
	bool TypeEquals(const char* other);
	bool CategoryEquals(Component* other);
	bool CategoryEquals(const ComponentCategory other);

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void FixedUpdate() = 0;

	virtual void EngineStart() = 0;
	virtual void EngineUpdate() = 0;

	virtual void OnCollide(GameObject* other){}
	
	GameObject* gameObject;
	Transform* transform;

};
