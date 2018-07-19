#include<bits/stdc++.h>

using namespace std ;

#define N 0x400
#define tol 1e-9
#define pi (2*acos(0.0))
#define SQ(x) ((x)*(x))
#define oo (1 << 29)
#define INF (DBL_MAX-1024)

typedef long long i64;

int n,ans;
long double r,x[N],y[N],s[N],d[N],a[N],b[N],A,B,C,D,w;

#define ABS(x) ((x)<0?(-(x)):((x)))

int Rnd( long double x ) {
	i64 ax = (i64)(x+tol),
		bx = ax+1;
	if ( ABS(ax-x) < ABS(bx-x) )
		return ax;
	return bx;
}

int main() {
	int i,j,k,ts;
	long double r1,r2;

	for ( scanf("%d",&ts); ts--; ) {
		scanf("%d %Lf",&n,&r);
		for ( i = 0; i < n; ++i ) {
			scanf("%Lf %Lf %Lf %Lf",x+i,y+i,d+i,s+i);
			d[i] = 90-d[i];
			d[i] = d[i]*pi/180;
			a[i] = s[i]*cos(d[i]);
			b[i] = s[i]*sin(d[i]);
		}
		for ( i = 0; i < n; ++i )
			for ( j = i+1; j < n; ++j )
				if ( SQ(x[i]-x[j])+SQ(y[i]-y[j]) <= SQ(r) ) {
					puts("0");
					goto nx;
				}
		w = INF, ans = +oo;
		for ( i = 0; i < n; ++i )
			for ( j = i+1; j < n; ++j ) {
				A = SQ(a[i]-a[j])+SQ(b[i]-b[j]);
				B = 2*(x[i]-x[j])*(a[i]-a[j])+2*(y[i]-y[j])*(b[i]-b[j]);
				C = SQ(x[i]-x[j])+SQ(y[i]-y[j])-SQ(r);
				if ( ABS(A) > tol ) {
					assert( A > 0 );
					D = SQ(B)-4*A*C;
					if ( D < 0 )
						continue ;
					r1 = (-B-sqrt(D))/(2*A);
					r2 = (-B+sqrt(D))/(2*A);
					if ( r1 > 0 && r1 < w )
						w = r1, ans = Rnd(w);
				}
			}
		if ( ans < +oo )
			printf("%d\n",ans);
		else puts("No collision.");
		nx: continue ;
	}
	return 0;
}
