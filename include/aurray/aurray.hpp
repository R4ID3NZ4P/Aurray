#ifndef AURRAY_HPP
#define AURRAY_HPP
#define ALIGN 32

#include <vector>
#include <cstddef>
#include <ostream>
class Aurray {
private:
    float* data;
    size_t size;

public:
    Aurray(size_t size);
    ~Aurray();

    void load_data(const std::vector<float>& v);
    void print() const;

    Aurray operator+(const Aurray& a) const;
    Aurray operator-(const Aurray& a) const;
    Aurray operator*(const Aurray& a) const;
    Aurray operator/(const Aurray& a) const;
    friend std::ostream& operator<<(std::ostream& os, const Aurray& a);
};

#endif