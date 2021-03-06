#ifndef MINGL_RGBCOLOR_INCLUDED
#define MINGL_RGBCOLOR_INCLUDED

#include <cstdint>

#include "colors.hpp"

struct RGBColor {
    uint8_t red{0}, green{0}, blue{0};

    RGBColor(uint8_t red, uint8_t green, uint8_t blue);
    RGBColor(const RGBColor &);
    virtual ~RGBColor();

    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    void inverse();
    HSLColor toHSL();

    /* Assignment operators */
    RGBColor &operator=(const RGBColor &);
    RGBColor &operator+=(const RGBColor &);
    RGBColor &operator-=(const RGBColor &);
    RGBColor &operator*=(const RGBColor &);
    RGBColor &operator/=(const RGBColor &);
    RGBColor &operator+=(uint8_t);
    RGBColor &operator-=(uint8_t);
    RGBColor &operator*=(uint8_t);
    RGBColor &operator/=(uint8_t);

    /* Arithmetic operators */
    RGBColor operator+(const RGBColor &) const;
    RGBColor operator-(const RGBColor &) const;
    RGBColor operator*(const RGBColor &) const;
    RGBColor operator/(const RGBColor &) const;
    friend RGBColor operator+(RGBColor, uint8_t);
    friend RGBColor operator-(RGBColor, uint8_t);
    friend RGBColor operator*(RGBColor, uint8_t);
    friend RGBColor operator/(RGBColor, uint8_t);
    friend RGBColor operator+(uint8_t, RGBColor);
    friend RGBColor operator-(uint8_t, RGBColor);
    friend RGBColor operator*(uint8_t, RGBColor);
    friend RGBColor operator/(uint8_t, RGBColor);

    RGBColor operator-() const;

    /* In/decrement operators */
    RGBColor &operator++();
    RGBColor &operator--();
    const RGBColor &operator++(int);
    const RGBColor &operator--(int);

    /* Comparision operators */
    bool operator==(const RGBColor &);
    bool operator!=(const RGBColor &);
};

#endif
