#include <iostream>
#include <string>
#include <stdexcept>
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
};

class GamingLaptop : public Laptop {
public:
    void use() override {
        cout << "You have Gaming Laptop" << endl;
    }

    class Builder {
    private:
        string CPU;
        string GPU;
        int RAM = 0;
        int storage = 0;

        bool CPUset = false;
        bool RAMset = false;

    public:
        Builder& setCPU(const string& cpu) {
            CPU = cpu;
            CPUset = true;
            return *this;
        }

        Builder& setGPU(const string& gpu) {
            GPU = gpu;
            return *this;
        }

        Builder& setRAM(int ram) {
            RAM = ram;
            RAMset = true;
            return *this;
        }

        Builder& setStorage(int s) {
            storage = s;
            return *this;
        }

        GamingLaptop build() {
            if (!CPUset)
                throw runtime_error("CPU is required");

            if (!RAMset)
                throw runtime_error("RAM is required");

            GamingLaptop laptop;

            laptop.CPU = CPU;
            laptop.GPU = GPU;
            laptop.RAM = RAM;
        laptop.storage = storage;

            return laptop;
        }
    };
};

class UltraBook : public Laptop {
public:
    void use() override {
        cout << "You have UltraBook" << endl;
    }

    class Builder {
    private:
        string CPU;
        string GPU;
        int RAM = 0;
        int storage = 0;

        bool CPUset = false;
        bool RAMset = false;

    public:
        Builder& setCPU(const string& cpu) {
            CPU = cpu;
            CPUset = true;
            return *this;
        }

        Builder& setGPU(const string& gpu) {
            GPU = gpu;
            return *this;
        }

        Builder& setRAM(int ram) {
            RAM = ram;
            RAMset = true;
            return *this;
        }

        Builder& setStorage(int s) {
            storage = s;
            return *this;
        }

        UltraBook build() {
            if (!CPUset)
                throw runtime_error("CPU is required");

            if (!RAMset)
                throw runtime_error("RAM is required");

            UltraBook laptop;

            laptop.CPU = CPU;
            laptop.GPU = GPU;
            laptop.RAM = RAM;
            laptop.storage = storage;

            return laptop;
        }
    };
};

int main() {

    GamingLaptop gamingLaptop =
        GamingLaptop::Builder()
            .setCPU("Intel i9")
            .setGPU("RTX 4080")
            .setRAM(32)
            .setStorage(2000)
            .build();

    gamingLaptop.use();
    gamingLaptop.specs();

    cout << endl;

    UltraBook ultraBook =
        UltraBook::Builder()
            .setCPU("Intel Ultra 7")
            .setGPU("Integrated Iris Xe")
            .setRAM(16)
            .setStorage(1000)
            .build();

    ultraBook.use();
    ultraBook.specs();

    return 0;
}