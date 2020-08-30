#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct cell
{
	int x;
	int y;
	int dist;

	cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isInside(int x, int y, int A, int B)
{
	if(x >= 0 && x < A && y >= 0 && y < B)
		return true;
	return false;
}


int knight(int boardx, int boardy, int startx, int starty, int endx, int endy)
{
	int dx[] = {2,1,-1,-2,2,1,-1,-2};
	int dy[] = {1,2,2,1,-1,-2,-2,-1};
	queue<cell> q;
	cell src(startx-1, starty-1, 0); //distance of source from source is 0.
	bool visited[boardx][boardy];
	memset(visited, 0, sizeof(visited));

	visited[startx-1][starty-1] = true;
	q.push(src);
	int x, y, dist;

	while(!q.empty())
	{
		cell c = q.front();
		q.pop();

		if(c.x == endx-1 && c.y == endy-1)
			return c.dist;

		for(int i = 0 ; i < 8 ; i++)
		{
			x = c.x + dx[i];
			y = c.y + dy[i];

			if(isInside(x, y, boardx, boardy) && !visited[x][y])
			{
				visited[x][y] = true;
				cell t(x, y, c.dist + 1);
				q.push(t);
			}
		}
	}
	return -1;
}


int main()
{
	int x = 8;
	int y = 8;
	int srcx = 1;
	int srcy = 1;
	int destx = 8;
	int desty = 8;

	int ans = knight(8,8,1,1,8,8);
	cout<<ans<<endl;
	return 0;
}