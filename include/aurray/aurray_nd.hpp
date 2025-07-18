#ifndef AURRAY_ND_HPP
#define AURRAY_ND_HPP

#define ALIGN 32

#include <vector>
#include <cstdlib>

class AurrayND
{
private:
    float* data;
    size_t size;
    std::vector<size_t> shape;
    std::vector<size_t> strides;

    void calculate_strides();

public:
    AurrayND(const std::vector<size_t>& shape);
    ~AurrayND();

    float at(const std::vector<size_t>& index) const;
    void set(const std::vector<size_t>& index, float val);
    const std::vector<size_t>& get_shape() const;
};

#endif