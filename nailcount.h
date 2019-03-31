#ifndef NAIL_COUNT
#define NAIL_COUNT
#include <map>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

map<string, vector<vector<int>>> setHSVDict();
map<string, Mat> cropBlock(Mat src_image);
void findBoxDetail(string boxName);
vector<Mat> cropLineByPercent(int line_num, Mat block_image, string name);
int temMatch(Mat& line_image, Mat& temp_image);
int temMatchForUCS(Mat& line_image, Mat& temp_image);
int boxPOLYX(Mat image, string color);
map<string,int> boxDVR(Mat image);
void findBoxType();

#endif // !NAIL_COUNT
