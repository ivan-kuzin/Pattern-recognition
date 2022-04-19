#include "median_plugin.h"

QString median_plugin::name()
{
    return "Median";
}

void median_plugin::edit(const cv::Mat &input, cv::Mat &output)
{
    input.copyTo(output);
    for(int row = 1; row < input.rows-1;row++)
    {
        cv::Vec3b* ptrdst = output.ptr<cv::Vec3b>(row);
        for(int col = 1; col <  input.cols-1; col++)
        {
            std::vector<int> R;
            std::vector<int> G;
            std::vector<int> B;
            for(int r = row-1;r <= row+1;r++)
            {
                cv::Vec3b* ptrsrc = output.ptr<cv::Vec3b>(r);
                for(int c = col-1;c <= col+1;c++)
                {
                    B.push_back(ptrsrc[c][0]);
                    G.push_back(ptrsrc[c][1]);
                    R.push_back(ptrsrc[c][2]);
                }
            }
            shellsort(&B.front(),&B.back());
            shellsort(&G.front(),&G.back());
            shellsort(&R.front(),&R.back());
            cv::Vec3b outPix(B[4],G[4],R[4]);
            ptrdst[col] = outPix;
        }
    }
}

void median_plugin::shellsort(int* l, int* r) {
    int sz = r - l;
    int step = sz / 2;
    while (step >= 1) {
        for (int *i = l + step; i < r; i++) {
            int *j = i;
            int *diff = j - step;
            while (diff >= l && *diff > *j) {
                std::swap(*diff, *j);
                j = diff;
                diff = j - step;
            }
        }
        step /= 2;
    }
}

