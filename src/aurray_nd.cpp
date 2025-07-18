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
    strides.resize(shape.size());
    size = 1;
    
    for(size_t i = shape.size() - 1; i >= 0; i--) {
        strides[i] = size;
        size *= shape[i];
    }
}