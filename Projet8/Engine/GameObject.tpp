#pragma once

template <typename T>
T* GameObject::GetComponent()
{
	const string type = NAMEOF(T);

	for (Component* component : components)
	{
		if (component->TypeEquals(type))
			return static_cast<T*>(component);
	}

	return nullptr;
}

template <typename T, typename... A>
T* GameObject::AddComponent(const A&... args)
{
	// ERROR? two possibilities:
	//		=> The type you are trying to add as as component is not a component, ex: AddComponent<Move>() is good, but AddComponent<DefaultScene>() won't build.
	//		=> The arguments you sent to this function do not match any constructor available for the specified class.
	Component* component = new T(args...);

	if (AddComponent(component))
		return static_cast<T*>(component);

	return nullptr;
}

template <typename T>
bool GameObject::RemoveComponent()
{
	const string type = NAMEOF(T);

	if (Utils::Contains(&EngineComponent::unremovableEngineComponents, type)) // unremovable components
		return false;

	for (Component* component : components)
	{
		if (component->TypeEquals(type))
		{
			components.remove(component);
			delete(component);
			return true;
		}
	}
	return false;
}