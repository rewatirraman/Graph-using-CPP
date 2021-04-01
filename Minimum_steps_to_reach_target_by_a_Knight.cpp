#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x;
    int y;
    int distance;
    cell(){}
    cell(int x, int y, int d) : x(x), y(y), distance(d){}
};

class KnightTarget
{
    int numVertex;
    bool **visited;

    // Total 8 movement of knight possible from a cell.
    int possible_x[8] = {-1, -1,  1, 1, -2, -2,  2, 2};
    int possible_y[8] = {-2,  2, -2, 2, -1,  1, -1, 1};

    public:
        KnightTarget(){}
        KnightTarget(int v)
        { 
            numVertex = v;
            visited = new bool*[numVertex];
            for (int i = 0; i < numVertex; i++)
            {
                visited[i] = new bool[numVertex];
                for (int j = 0; j < numVertex; j++)
                {
                    visited[i][j] = false;
                }
            }
        }

        bool validPos(int x, int y)
        {
            if (x<0 || x>=numVertex || y<0 || y>=numVertex) {return false;}
            else {return true;}
        }   

        int solution(cell knight, cell target)
        {
            queue<cell> Q;
            Q.push(knight);
            visited[knight.x][knight.y] = true;
            int result=INT_MAX;

            while (!Q.empty())
            {
                cell u = Q.front();
                Q.pop();

                if ((u.x == target.x-1) && (u.y == target.y-1))
                {
                    result = u.distance;
                    break;
                }

                for (int i = 0; i < 8; i++)
                {
                    int tempX = u.x + possible_x[i];
                    int tempY = u.y + possible_y[i];
                    if (validPos(tempX, tempY) && !visited[tempX][tempY])
                    {
                        visited[tempX][tempY] = true;
                        cell temp(tempX, tempY, u.distance+1);
                        Q.push(temp);
                    }
                }
            }
            return result;
        }
};


int main()
{
    int n = 30;   // board dimention : n*n
    KnightTarget kt(n);

    int kx, ky, tx, ty;
    // kx = Knight x position
    // ky = Knight y position
    // tx = Target x position
    // tx = Target y position
    kx = 1;
    ky = 1;
    tx = 30;
    ty = 30;
    cell knight(kx, ky, 0);
    cell target(tx, ty, INT_MAX);
    cout << "Minimum steps needed to reach the target = " << kt.solution(knight, target) << endl;

    return 0;
}