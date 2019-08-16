#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int n;

    // std::fstream in("data/hdu1231.txt");

    // while(in>>n&&n)
    while(std::cin>>n&&n)
    {
        int sum(0),left(0),right(0),tleft(0),elem(0),head(0),tail(0);
        int max(-0x3f3f3f3f);
        
        for(int i = 0;i<n;i++)
        {
            std::cin>>elem;
            // in>>elem;

            if(i==0)
            {
                left = elem;
                tleft = elem;
                head = elem;
            }

            if(i==n-1)
                tail = elem;

            if(sum + elem < elem)
            {
                tleft = elem;
                sum = elem;
            }
            else
            {
                sum += elem;
            }

            if(sum > max)
            {
                max = sum;
                left = tleft;
                right = elem;
            }
        }
        

        if(max<0)
        {
            left = head;
            right = tail;
            max = 0;
        }

        std::cout<<max<<" "<<left<<" "<<right<<std::endl;

    }
}