#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using  ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
    static ComponentID last_id = 0;
    return last_id++;
}

template <typename T> inline ComponentID GetComponentTypeID () noexcept
{
    static ComponentID typeID = GetComponentTypeID();
    return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*,maxComponents>;

class Component
{
public:
    Component() = default;

    virtual ~Component() = default;
    
    Entity* entity;
    
    virtual void init() {}

    virtual void Update() {}

    virtual void Draw() {}
    
};

class Entity
{

public:
    
    void Update()
    {
        for (std::unique_ptr<Component>& c : components)
        {
            if(c)
            {
                c->Update();
                c->Draw();
            }
        }
    }
    void Draw()
    {
        
    }
    
    bool is_active() const {return active;}

    void Destroy() { active = false;}

    template <typename T> bool has_component() const
    {
        return component_bit_set[GetComponentTypeID<T>];
    }

    template <typename T,typename... TArgs> T& add_component(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        components.emplace_back(std::move(uPtr));
        component_array[GetComponentTypeID<T>()] = c;
        component_bit_set[GetComponentTypeID<T>()] = true;

        c->init();

        return *c;
    }

    template <typename T> T& get_component() const
    {
        Component* ptr(component_array[GetComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    
private:
    bool active = true;

    std::vector<std::unique_ptr<Component>> components;

    ComponentArray component_array;

    ComponentBitSet component_bit_set;
    
};