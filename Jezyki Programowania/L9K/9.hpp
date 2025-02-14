#include <iostream>
#include <algorithm>
#include <vector>

class Material {
    std::string name; 
    int ammount;

    public:

    Material(std::string = "Azbest", int = 1);
    ~Material() {};

    void Print();

    bool CanProcess(Material); // ===

    void operator += (Material);
    void operator -= (Material);
    bool operator == (Material);
    

};

class Recipe {
    Material input;
    Material output;

    public:
    Recipe();
    Recipe(Material, Material);
    ~Recipe() {};

    friend class Factory; // Wydalo mi sie oczywiste, ze fabryka zna przepisy wedlug ktorych produkuje przedmioty
};

class Factory {
    std::vector<Material> storage;
    
    public:
    Factory() {};
    ~Factory() {};
    void AddMaterial(const Material&);
    void PrintStorage();
    Material operator () (Recipe);
};