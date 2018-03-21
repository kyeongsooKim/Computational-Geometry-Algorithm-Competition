
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct point
{
	int x, y;
	int name;
};

// A globle point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
point p0;

// A utility function to find next to top in a stack
point nextToTop(stack<point> &S)
{
	point p = S.top();
	S.pop();
	point res = S.top();
	S.push(p);
	return res;
}

// A utility function to swap two points
void swap(point &p1, point &p2)
{
	point temp = p1;
	p1 = p2;
	p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(point p1, point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(point p, point q, point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
	point *p1 = (point *)vp1;
	point *p2 = (point *)vp2;

	// Find orientation
	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

	return (o == 2) ? -1 : 1;
}


int Area2(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool Left(point a, point b, point c)
{
	return Area2(a, b, c) > 0;
}

bool Collinear(point a, point b, point c)
{
	return Area2(a, b, c) == 0;
}

bool LeftOn(point a, point b, point c)
{
	return Area2(a, b, c) >= 0;
}


// Prints convex hull of a set of n points.
void convexHull(point points[], int n)
{
	// Find the bottommost point
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		// Pick the bottom-most or chose the right most point in case of tie
		if ((y < ymin) || (ymin == y &&
			points[i].x > points[min].x))
			ymin = points[i].y, min = i;
	}

	// Place the bottom-most point at first position
	swap(points[0], points[min]);

	// Sort n-1 points with respect to the first point.
	// A point p1 comes before p2 in sorted ouput if p2 has larger polar angle
	//(in counterclockwise direction) than p1
	p0 = points[0];
	qsort(&points[1], n - 1, sizeof(point), compare);

	

	// If two or more points make same angle with p0, Remove all but the one
	// that is farthest from p0.
	cout << "Points after sorting" << endl;
	cout << "(" << points[0].x << ", " << points[0].y << ")\n";
	int m = 1; // Initialize size of modified array
	for (int i = 1; i<n; i++)
	{
		cout << "(" << points[i].x << ", " << points[i].y << ") ";
		// Keep removing i while angle of i and i+1 is same with respect to p0
		while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
		{
			cout << "  <= deleted\n";
			i++;
			cout << "(" << points[i].x << ", " << points[i].y << ")";
		}
		cout << endl;
			
		points[m] = points[i];
		m++;  // Update size of modified array
	}
	cout << endl;

	// If modified array of points has less than 3 points, convex hull is not possible
	if (m < 3) return;

	// Create an empty stack and push first three points to it.
	stack<point> S;


	S.push(points[0]);
	S.push(points[1]);

	point p1, p2;
	int i = 2;
	printf("i = %d : ", i);
	stack<point> temp = S;
	while (!temp.empty())
	{
		cout << "(" << temp.top().x << ", " << temp.top().y << ") ";
		temp.pop();
	}
	cout << endl;
	while(i< m)
	{
		

		p1 = nextToTop(S);
		p2 = S.top();

		if (Left(p1, p2, points[i])) {
			S.push(points[i]);
			i++;
		}
		else
			S.pop();
		printf("i = %d : ", i);
		stack<point> temp = S;
		while (!temp.empty())
		{
			cout << "(" << temp.top().x << ", " << temp.top().y << ") ";
			temp.pop();
		}
		cout << endl;
	}

	/*
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);

	// Process remaining n-3 points
	for (int i = 3; i < m; i++)
	{
		// Keep removing top while the angle formed by
		// points next-to-top, top, and points[i] makes
		// a non-left turn
		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
	}
	*/

	// Now stack has the output points, print contents of stack
	cout << "\n\nConvex hull : " << endl;
	while (!S.empty())
	{
		point p = S.top();
		cout << "(" << p.x << ", " << p.y << ") ";;
		S.pop();
	}
	cout << endl;
}

// Driver program to test above functions
int main()
{
	/*
	point points[] = { { 3, 1 },{ 4, 4 },{ 5, -1 },{ 2, -1 },
	{ 2, 2 },{ 2, 1 },{ 4, -1 },{ 6, 1 },{ 8, 1 }, {8, 5}, {7, 4}, {3, 3 } };
	*/

	point points[] = { { 0, 0 ,6},{ 4,1, 4 },{ 2, 2,2 },
	{ 1,2, 1 },{ 0, 4,0 },{ -1, 1,5 }, {0, 1, 3}
	};

	/*
	point points[] = { { 3, -2 },{ 5, 1 },{ 7, 4 },{ 6, 5 },
	{ 4, 2 },{ 3, 3 },{ 3, 5 },{ 2, 5 },{ 0, 5 },{ 0, 1 },{ -3, 4 },{ -2, 2 },
	{0,0}, {-3, 2}, {-5, 2}, {-5 ,1 }, {-5, -1}, {1, -2}, {-3, -2}
	};
	*/
	
	int n = sizeof(points) / sizeof(points[0]);
	convexHull(points, n);
	return 0;
}