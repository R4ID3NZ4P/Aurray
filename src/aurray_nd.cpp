#include "aurray/aurray_nd.hpp"
#include <iostream>
#include <immintrin.h>
#include <cassert>
#include <cstdlib>
#include <cstring>

AurrayND::AurrayND(const std::vector<size_t>& shape) {
    this->shape = shape;
    calculate_strides();
    this->data = static_cast<float*>(_aligned_malloc(sizeof(float) * this->size, ALIGN));
    assert(data && "Mem alloc failed");
}

AurrayND::~AurrayND() {
    _aligned_free(this->data);
}

void AurrayND::calculate_strides() {
    this->strides.resize(this->shape.size());
    this->size = 1;
    
    for(size_t i = this->shape.size() - 1; i >= 0; i--) {
        this->strides[i] = this->size;
        this->size *= this->shape[i];
    }
}

float AurrayND::at(const std::vector<size_t>& index) const {
    assert(index.size() == this->shape.size());

    size_t ind = 0;

    for (size_t i = 0; i < this->shape.size(); i++) {
        assert(index[i] < this->shape[i]);
        ind += index[i] * this->strides[i];
    }

    return this->data[ind];
}

void AurrayND::set(const std::vector<size_t>& index, float val) {
    assert(index.size() == this->shape.size());

    size_t ind = 0;

    for (size_t i = 0; i < this->shape.size(); i++) {
        assert(index[i] < this->shape[i]);
        ind += index[i] * this->strides[i];
    }

    this->data[ind] = val;
}