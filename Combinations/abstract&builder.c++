#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Laptop {
protected:
    string CPU = "100";
    string GPU = "120";
    int RAM = 130;
    int storage = 140;

public:
    virtual void use() = 0;
    void specs() {
        cout << "CPU: " << CPU << endl;
        cout << "GPU: " << GPU << endl;
        cout << "RAM: " << RAM << endl;
        cout << "Storage: " << storage << endl;
    }

    friend class GamingLaptopBuilder;
    friend class UltraBookBuilder;
};

class GamingLaptop : public Laptop {
public:
    void use() override {
        cout << "You have Gaming Laptop" << endl;
    }
};

class UltraBook : public Laptop {
public:
    void use() override {
        cout << "You have UltraBook" << endl;
    }
};

class LaptopBuilder {
protected:
    Laptop* laptop;

public:
    virtual void reset() = 0;

    // <- changed return types to pointers for fluent -> chaining
    virtual LaptopBuilder* setCPU(const string& cpu) = 0;
    virtual LaptopBuilder* setGPU(const string& gpu) = 0;
    virtual LaptopBuilder* setRAM(int ram) = 0;
    virtual LaptopBuilder* setStorage(int storage) = 0;

    virtual Laptop* build() = 0;
};

class GamingLaptopBuilder : public LaptopBuilder {
public:
    GamingLaptopBuilder() { reset(); }

    void reset() override {
        laptop = new GamingLaptop();
    }

    LaptopBuilder* setCPU(const string& cpu) override {
        laptop->CPU = cpu;
        return this;
    }
    LaptopBuilder* setGPU(const string& gpu) override {
        laptop->GPU = gpu;
        return this;
    }
    LaptopBuilder* setRAM(int ram) override {
        laptop->RAM = ram;
        return this;
    }
    LaptopBuilder* setStorage(int storage) override {
        laptop->storage = storage;
        return this;
    }

    Laptop* build() override {
        Laptop* result = laptop;
        laptop = nullptr; // optional: avoid accidental reuse
        return result;
    }
};

class UltraBookBuilder : public LaptopBuilder {
public:
    UltraBookBuilder() { reset(); }

    void reset() override {
        laptop = new UltraBook();
    }

    LaptopBuilder* setCPU(const string& cpu) override {
        laptop->CPU = cpu;
        return this;
    }
    LaptopBuilder* setGPU(const string& gpu) override {
        laptop->GPU = gpu;
        return this;
    }
    LaptopBuilder* setRAM(int ram) override {
        laptop->RAM = ram;
        return this;
    }
    LaptopBuilder* setStorage(int storage) override {
        laptop->storage = storage;
        return this;
    }

    Laptop* build() override {
        Laptop* result = laptop;
        laptop = nullptr;
        return result;
    }
};

int main() {
    LaptopBuilder* gBuilder = new GamingLaptopBuilder();

    // Now fluent chaining with -> works
    Laptop* gamingLaptop = gBuilder
        ->setCPU("i9")
        ->setGPU("RTX 4080")
        ->setRAM(32)
        ->setStorage(2000)
        ->build();

    gamingLaptop->use();
    gamingLaptop->specs();

    // cleanup
    delete gamingLaptop;
    delete gBuilder; // note: gBuilder->build() nulled laptop; destructor not implemented here

    return 0;
}
