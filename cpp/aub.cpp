#include<bits/stdc++.h>

using namespace std;

typedef  vector<int> vi ;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll ;
typedef vector<double>vd  ;
#define M_PI 3.1416589
typedef  vector<ll>vll;

const int INF = numeric_limits<int>::max();

const double EPS = 1e-10;

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}

  double operator * (const point & fuck) {
    return x * fuck.x + y * fuck.y;
  }

  double operator ^ (const point & fuck) {
    return x * fuck.y - y * fuck.x;
  }

  point operator - (const point& fuck) {
    return point(x - fuck.x, y - fuck.y);
  }

  point operator + (const point& fuck) {
    return point(x + fuck.x, y + fuck.y);
  }


  double operator >> (const point& fuck) {
    point d = (*this - fuck);
    return sqrt(d * d);
  }

  const bool operator < (const point& fuck) const {
    if (fuck.x != x) return x < fuck.x;
    return y < fuck.y;
  }

};

ostream& operator << (ostream& s, const point& p) {
  s << "(" << p.x << ", " << p.y << ")";
  return s;
}

struct boat {
  point dick;
  point cock;
};


vd qn(double a, double b, double c) {
  vd _;
  double d = b * b - 4 * a * c;
  if (d < 0) return _;
  d = sqrt(d);
  double x1 = (-b - d) / 2 / a;
  double x2 = (-b + d) / 2 / a;
  _.emplace_back(x1);
  if (x2 != x1) _.emplace_back(x2);
  return _;
}

int main() {

  int tcc; cin >> tcc;
  for (int tc = 1; tc <= tcc; tc++) {
    double r;
    int n;
    cin >> n >> r;
    vector<boat> fleet(n);
    for (ll i = 0; i < n; i++) {
      double x, y, d, s;
      cin >> x >> y >> d >> s;
      d = d * M_PI / 180;
      fleet[i].dick.x = x;
      fleet[i].dick.y = y;
      fleet[i].cock.x = s * sin(d);
      fleet[i].cock.y = s * cos(d);
      cout << fleet[i].dick << " " << fleet[i].cock << endl;
    }
    double t = 1e10;
    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        point dc = fleet[i].dick - fleet[j].dick;
        point dv = fleet[i].cock - fleet[j].cock;
        if ((dc * dc) <= r * r) {
          t = 0;
          break;
        }
        auto roots = qn(dv * dv,2 * (dv * dc),(dc * dc) - r * r);
        for (auto q : roots) if (q >= 0) t = min(t, q);
      }
    }
    if (t == 1e10) {
      cout << "No collision." << endl;
    } else {
      cout << round(t) << endl;
    }
  }
}
