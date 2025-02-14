#include "9.hpp"

Material::Material(std::string _name, int _ammount)  {
    name = _name;  
    ammount = _ammount;
}

bool Material::CanProcess (Material material) {
    return name == material.name && ammount >= material.ammount;
}

bool Material::operator== (Material material) {
    return name == material.name;
}

void Material::operator+= (Material material) {
    if (*this == material) {
        ammount += material.ammount;
    }
}

void Material::operator-= (Material material) {
    if (*this == material) {
        ammount -= material.ammount;
    }

}

void Material::Print() {
    std::cout<<name<<": "<<ammount<<std::endl;
}

Recipe::Recipe() {
    Material in("Jajo", 2);
    Material out("Jajecznica", 1);

    input = in;
    output = out;
}

Recipe::Recipe(Material in, Material out) {
    input = in;
    output = out;
}

void Factory::AddMaterial(const Material& material) {
    if (storage.size() == 0) {
        storage.push_back(material);
        return;
    }

    for (int i = 0; i <= storage.size(); i++) {
        if (storage[i] == material) {
            storage[i] += material;
            return;
        }
    }
    storage.push_back(material);
}

void Factory::PrintStorage() {
    std::cout<<"Storage"<<std::endl;
    for (auto &i : storage) {
        i.Print();
    }
}

Material Factory::operator () (Recipe r) {
    for (int i = 0; i < storage.size(); i++) {
        if (storage[i].CanProcess(r.input)) {
            storage[i] -= r.input;

            std::cout<<"Fabryka przetwarza"<<std::endl;
            std::cout<<"Input - ";
            r.input.Print();
            std::cout<<"Oputput - ";
            r.output.Print();

            return r.output;
        }
    }

    std::cout<<"Nie da sie wyprodukowac"<<std::endl;

    Material Azbest;
    return Azbest;
}