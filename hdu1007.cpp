

//寻找最近的一对点



// 暴力 






// double forceFindMinPair(const std::vector<Pos>& pv)
// {
//     double minD = 200000;

//     for(int i = 0; i < pv.size();i++)
//     {
//         for(int j = i+1 ; j< pv.size(); j++)
//         {
//             double dis = getDis(pv.at(i), pv.at(j));
//             if(minD > dis)
//             {
//                 minD = dis;
               
//             }
//         }
//     }

//     return minD;
// } 


// std::vector<Pos> pos_generator(int size)
// {
//     std::vector<Pos> pv;
//     std::random_device rd;
//     std::default_random_engine e(rd());
//     std::uniform_real_distribution<> dist(0, 100);
//     auto generator = std::bind(dist,e);

//     for(int i = 0; i<size;i++)
//     {
//         double x = generator();
//         double y = generator();
//         pv.push_back(Pos(x,y));
//     }

//     return std::move(pv);
// }


//分治
// double findMinPair(const std::vector<Pos>& pv, int left, int right)
// {

//     int size = right - left + 1;
//     if(size<=1)
//     {
//         return 0;
//     }
//     else if(size==2) 
//     {
//         return getDis(pv.at(left), pv.at(left+1));
//     }
//     else if(size==3)
//     {
//         double dis1 = getDis(pv.at(left), pv.at(left+1));
//         double dis2 = getDis(pv.at(left), pv.at(left+2));
//         double dis3 = getDis(pv.at(left+1), pv.at(left+2));
//         return std::min(dis3,std::min(dis1,dis2));
//     }
//     else
//     {
//         int half = size / 2;
//         int middle = left + half - 1;
//         double dis1 = findMinPair(pv, left, middle);
//         double dis2 = findMinPair(pv, middle+1, right);

//         double minD = std::min(dis1, dis2);
//         double midLine = (pv.at(middle).x + pv.at(middle+1).x)/2;
        
//         std::vector<Pos> temp;

//         for(int i = left ; i<=right;i++)
//         {
//             if(std::fabs(pv.at(i).x - midLine) <= minD)
//                 temp.push_back(pv.at(i));

//         }

//         std::sort(temp.begin(), temp.end(), compy);

//         for(int i = 0; i < temp.size() ;i++)
//         {
//             for(int j = i+1; j < temp.size()  && (temp.at(j).y - temp.at(i).y) <= minD;j++)
//             {
//                 double dis = getDis(temp.at(i),temp.at(j));
//                 minD = std::min(dis, minD);
             
//             }
//         }

//         return minD;

//     }
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// #include <random>
// #include <functional>
// #include <chrono>
// #include <iomanip>
// #include <fstream>
#include <cstdio>

using namespace std;


struct Pos
{
    double x, y;
    Pos(double x = 0, double y = 0):x(x), y(x){};
};

bool compx(const Pos* point1, const Pos* point2)
{
    return point1->x <  point2->x;
}

// bool compy(const Pos& point1, const Pos& point2)
// {
//     return point1.y <  point2.y;
// }

bool compy(const Pos* point1, const Pos* point2)
{
    return point1->y < point2->y;
}



double getDis(const Pos* p1, const Pos* p2)
{
    return std::sqrt(std::pow(p1->x - p2->x,2)+std::pow(p1->y - p2->y , 2));
}

#define LEN 100005

Pos point[LEN], *px[LEN], *py[LEN];

double cFindMinPair(int s, int e)
{
    int size = e - s + 1;

    if(size == 2)
        return getDis(px[s], px[e]);

    if(size == 3)
    {
        double dis1 = getDis(px[s],px[s+1]);
        double dis2 = getDis(px[s],px[s+2]);
        double dis3 = getDis(px[s+1],px[s+2]);
        return std::min(dis1, std::min(dis2,dis3));
    }

    int middle = s + size/2 - 1;
    double dis1 = cFindMinPair(s, middle);
    double dis2 = cFindMinPair(middle+1, e);

    double minD = std::min(dis1,dis2);

    double midLine = (px[middle]->x + px[middle+1]->x)/2;

    int count(0);

    for(int i = s; i<=e;i++)
    {
        if(std::fabs(px[i]->x - midLine)<=minD)
            py[count++] = px[i];
    }

    std::sort(py, py+count, compy);

    for(int i = 0; i < count ;i++)
    {
        for(int j = i +1 ;j < count; j++)
        {
            if(py[j]->y - py[i]->y > minD)
                break;

            minD = std::min(minD, getDis(py[i],py[j]));
        }
    }

    return minD;

}




int main()
{
    // std::fstream in("data/hdu1007.txt");

    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i < n ;i++)
        {
            scanf("%lf %lf", &point[i].x , &point[i].y);
            px[i] = & point[i];
        }

        std::sort(px, px+n, compx);
        double r = cFindMinPair(0, n-1)/2;
        printf("%0.2lf\n", r);

    }
    return 0;
}

//教训 acm的题目 用c 少用 c++