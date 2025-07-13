#include "aurray/aurray.hpp"
#include <immintrin.h>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>

Aurray::Aurray(size_t n): size(n) {
    assert(n % 8 == 0 && "----------Size must be multiple of 8----------");
    this->data = static_cast<float*>(_aligned_malloc(sizeof(float) * size, ALIGN));
    std::memset(data, 0, sizeof(float) * size);
}

Aurray::~Aurray() {
    _aligned_free(data);
}

void Aurray::load_data(const std::vector<float>& v) {
    assert(v.size() == size);
    std::memcpy(data, v.data(), sizeof(float) * size);
}