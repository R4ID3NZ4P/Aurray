#include "aurray/aurray.hpp"
#include <immintrin.h>
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

Aurray Aurray::operator+(const Aurray& a) const {
    assert(this->size == a.size);
    
    Aurray res(this->size);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 y = _mm256_load_ps(a.data + i);
        __m256 z = _mm256_add_ps(x, y);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator-(const Aurray& a) const {
    assert(this->size == a.size);
    
    Aurray res(this->size);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 y = _mm256_load_ps(a.data + i);
        __m256 z = _mm256_sub_ps(x, y);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator*(const Aurray& a) const {
    assert(this->size == a.size);
    
    Aurray res(this->size);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 y = _mm256_load_ps(a.data + i);
        __m256 z = _mm256_mul_ps(x, y);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator/(const Aurray& a) const {
    assert(this->size == a.size);
    
    Aurray res(this->size);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 y = _mm256_load_ps(a.data + i);
        __m256 z = _mm256_div_ps(x, y);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator+(float scalar) const {
    Aurray res(this->size);
    __m256 scalar_vec = _mm256_set1_ps(scalar);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 z = _mm256_add_ps(x, scalar_vec);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator-(float scalar) const {
    Aurray res(this->size);
    __m256 scalar_vec = _mm256_set1_ps(scalar);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 z = _mm256_sub_ps(x, scalar_vec);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator*(float scalar) const {
    Aurray res(this->size);
    __m256 scalar_vec = _mm256_set1_ps(scalar);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 z = _mm256_mul_ps(x, scalar_vec);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

Aurray Aurray::operator/(float scalar) const {
    Aurray res(this->size);
    __m256 scalar_vec = _mm256_set1_ps(scalar);

    for (size_t i = 0; i < this->size; i += 8) {
        __m256 x = _mm256_load_ps(this->data + i);
        __m256 z = _mm256_div_ps(x, scalar_vec);
        _mm256_store_ps(res.data + i, z);
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, const Aurray& a) {
    os << "[";
    for (size_t i = 0; i < a.size; i++) {
        os << *(a.data + i);
        if (i < a.size - 1) os << " ";
    }
    os << "]";

    return os;
}