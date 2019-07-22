namespace Geometry {
  using ftype = int;

  struct Point {
    ftype x, y, z;
    Point() {}
    Point(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}

    Point& operator +=(const Point &t) {
      x += t.x;
      y += t.y;
      z += t.z;
      return *this;
    }
    Point& operator -=(const Point &t) {
      x -= t.x;
      y -= t.y;
      z -= t.z;
      return *this;
    }
    Point& operator *=(ftype t) {
      x *= t;
      y *= t;
      z *= t;
      return *this;
    }
    Point& operator /=(ftype t) {
      x /= t;
      y /= t;
      z /= t;
      return *this;
    }
    Point operator +(const Point &t) const {
      return Point(*this) += t;
    }
    Point operator -(const Point &t) const {
      return Point(*this) -= t;
    }
    Point operator *(ftype t) const {
      return Point(*this) *= t;
    }
    Point operator /(ftype t) const {
      return Point(*this) /= t;
    }
  };

  Point operator *(ftype a, Point b) {
    return b * a;
  }

  ftype dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  ftype norm(Point a) {
    return dot(a, a);
  }

  double abs(Point a) {
    return sqrt(norm(a));
  }

  double proj(Point a, Point b) { // returns a * cos(theta)
    return dot(a, b) / abs(b);
  }

  double angle(Point a, Point b) { // returns angle between a and b
    return acos(dot(a, b) / abs(a) / abs(b));
  }

  Point cross(Point a, Point b) { // returns (a X b)
    return Point(
      a.y * b.z - a.z * b.y,
      a.z * b.x - a.x * b.z,
      a.x * b.y - a.y * b.x
    );
  }

  ftype triple(Point a, Point b, Point c) { // returns a . (b X c)
    return dot(a, cross(b, c));
  }
};

using namespace Geometry;