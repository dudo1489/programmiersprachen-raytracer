// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Color
// -----------------------------------------------------------------------------

#ifndef BUW_COLOR_HPP
#define BUW_COLOR_HPP

#include <iostream>

struct Color
{

  Color():
  r(0),
  g(0),
  b(0)
  {}

  Color(float red, float green, float blue) : r(red), g(green), b(blue) {}
  float r;
  float g;
  float b;

  friend std::ostream& operator<<(std::ostream& os, Color const& c)
  {
    os << "(" << c.r << "," << c.g << "," << c.b << ")\n";
    return os;
  }

  Color& operator+=(Color const& other)
  {
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
  }

  Color& operator-=(Color const& other)
  {
    r -= other.r;
    g -= other.g;
    b -= other.b;
    return *this;
  }

  friend Color operator+(Color const& a, Color const& b)
  {
    auto tmp(a);
    tmp += b;
    return tmp;
  }

  friend Color operator-(Color const& a, Color const& b)
  {
    auto tmp(a);
    tmp -= b;
    return tmp;
  }


  Color& operator *=(Color other)
  {
    r *= other.r;
    g *= other.g;
    b *= other.b;
    return *this;
  }

  Color& operator *=(float other)
  {
    r *= other;
    g *= other;
    b *= other;
    return *this;
  }

  friend Color operator *(Color const& abc, Color const& cba)
  {
    return Color(abc) *= cba;
  }

  friend Color operator*(Color const& a, float b)  //Fürs Skalarprodukt in givacolor!
  {
    auto tmp(a);
    tmp *= b;
    return tmp;
}
};

#endif //#define BUW_COLOR_HPP
