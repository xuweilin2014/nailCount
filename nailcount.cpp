#include <vector>
#include <map>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "nailcount.h"

using namespace std;
using namespace cv;
using namespace rapidjson;

vector<string> COLORLIST;
vector<string> BOXTYPE;
map<string, int> HOLELIST;
map<string, int> LINELIST;
int counter = 0;
int index = 0;

bool PointSort(const Point p1, const Point p2) {
	return p1.x < p2.x;
}

map<string, vector<Scalar>> setHSVDict() {

	vector<Scalar> red, red2, blue, green, yellow, purple;

	//红色范围[156,43,46]至[180,255,255]
	Scalar lower_red(156, 43, 46);
	Scalar upper_red(180, 255, 255);
	red.push_back(lower_red);
	red.push_back(upper_red);

	//另一个红色范围[0,100,100]与[10,255,255]
	Scalar lower_red2(0, 100, 100);
	Scalar upper_red2(10, 255, 255);
	red2.push_back(lower_red2);
	red2.push_back(upper_red2);

	//蓝色范围[78,43,46]与[124,255,255]
	Scalar lower_blue(78, 43, 46);
	Scalar upper_blue(124, 255, 255);
	blue.push_back(lower_blue);
	blue.push_back(upper_blue);
	//绿色范围[35, 100, 60]至[77, 255, 255]
	Scalar lower_green(35, 100, 60);
	Scalar upper_green(77, 255, 255);
	green.push_back(lower_green);
	green.push_back(upper_green);

	//黄色空间[12, 180, 60]至[30, 255, 255]
	Scalar lower_yellow(12, 180, 60);
	Scalar upper_yellow(30, 255, 255);
	yellow.push_back(lower_yellow);
	yellow.push_back(upper_yellow);

	//紫色范围[125, 43, 46]至[180, 255, 255]
	Scalar lower_purple(125, 43, 46);
	Scalar upper_purple(180, 255, 255);
	purple.push_back(lower_purple);
	purple.push_back(upper_purple);

	map<string, vector<Scalar>> color_dict;
	color_dict["red"] = red;
	color_dict["red2"] = red2;
	color_dict["blue"] = blue;
	color_dict["green"] = green;
	color_dict["yellow"] = yellow;
	color_dict["purple"] = purple;

	return color_dict;
}

map<string, Mat> cropBlock(Mat src_image) {
	Mat hsv_image, gray_image;
	cvtColor(src_image, hsv_image, CV_BGR2HSV);
	cvtColor(src_image, gray_image, CV_BGR2GRAY);
	map<string, vector<Scalar>> color_dict = setHSVDict();
	Mat bimg, kernel, opening;
	inRange(hsv_image, color_dict["red2"][0], color_dict["red2"][1], bimg);
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(bimg, opening, MORPH_OPEN, kernel, Point(-1, -1), 3);
	vector<vector<Point>> contours;
	findContours(opening, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	vector<Point> points;
	vector<vector<Point>>::iterator begin_iter = contours.begin();
	vector<vector<Point>>::iterator end_iter = contours.end();

	for (int k = 0; begin_iter != end_iter; begin_iter++, k++) {
		if (k == 0) {
			points.push_back((*begin_iter)[2]);
		}
		else {
			points.push_back((*begin_iter)[0]);
		}

	}

	sort(points.begin(), points.end(), PointSort);
	vector<Mat> image_list;
	map<string, Mat> color_image_dict;
	for (int i = 0; i < points.size() - 1; i++) {
		Mat aimg;
		Point p1 = points[i];
		Point p2 = points[i + 1];
		if (p1.y < p2.y) {
			Rect rect(p1.x, p1.y + 10, p2.x - p1.x, p2.y - p1.y);
			aimg = gray_image(rect);
		}
		else {
			Rect rect(p1.x, p2.y + 10, p2.x - p1.x, p1.y - p2.y);
			aimg = gray_image(rect);
		}
		string title = "temp_image/croppedblock" + to_string(counter++) + ".jpg";
		imwrite(title, aimg);
		color_image_dict[COLORLIST[i]] = aimg;
		image_list.push_back(aimg);
	}

	return color_image_dict;
}

void findBoxType() {
	FILE* fp = fopen("boxType.json", "rb");
	char readBuffer[65535];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document d;
	d.ParseStream(is);

	Value typeArray = d["boxType"].GetArray();
	Value::ValueIterator typeIter = typeArray.Begin();
	for (; typeIter != typeArray.End(); typeIter++) {
		BOXTYPE.push_back(typeIter->GetString());
	}
	fclose(fp);
}

void findBoxDetail(string boxName) {
	FILE* fp = fopen("boxDetail.json", "rb");
	char readBuffer[65535];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document d;
	d.ParseStream(is);

	Value::MemberIterator iter = d.MemberBegin();
	for (; iter != d.MemberEnd(); iter++) {
		if (iter->name.GetString() == boxName) {
			Value colorArray = iter->value.GetArray();
			Value::ValueIterator valIter = colorArray.Begin();
			for (; valIter != colorArray.End(); valIter++) {
				Value::MemberIterator lineIter = valIter->MemberBegin();
				string key = lineIter->name.GetString();
				COLORLIST.push_back(key);
				Value num = lineIter->value.GetArray();
				for (SizeType i = 0; i < num.Size(); i++) {
					if (i == 0) {
						LINELIST[key] = num[i].GetInt();
					}
					else if (i == 1) {
						HOLELIST[key] = num[i].GetInt();
					}
				}
			}
		}
	}

	fclose(fp);
}

vector<Mat> cropLineByPercent(int line_num, Mat block_image, string color_name) {
	int line_height = (block_image.rows) / line_num;
	vector<Mat> line_list;
	int start = 0;
	for (int i = 0; i < line_num; i++) {
		Rect rect(0, start, block_image.cols, line_height);
		Mat aimg = block_image(rect);
		string title = "temp_image/block" + to_string(counter++) + ".jpg";
		line_list.push_back(aimg);
		imwrite(title, aimg);
		start += line_height;
	}
	return line_list;
}

int temMatch(Mat& line_image, Mat& temp_image) {

	// 将被显示的原图像
	Mat result;

	// 创建输出结果的矩阵
	int result_cols = line_image.cols - temp_image.cols + 1;
	int result_rows = line_image.rows - temp_image.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);

	int match_method = CV_TM_CCOEFF_NORMED;

	// 进行匹配和标准化
	matchTemplate(line_image, temp_image, result, match_method);
	//normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	// 通过函数 minMaxLoc 定位最匹配的位置
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	vector<int> x_loc;

	for (int x = 0; x < result.cols; x++) {
		for (int y = 0; y < result.rows; y++) {
			if ((result.at<float>(y, x)) > 0.73) {
				x_loc.push_back(x);
			}
		}
	}

	sort(x_loc.begin(), x_loc.end());
	vector<int>::iterator iter = x_loc.begin();
	int hole_counter = 0;
	int last_x = 0;
	for (; iter != x_loc.end(); iter++) {
		int x = (*iter);
		if (x - last_x > temp_image.cols) {
			hole_counter++;
			last_x = x;
		}
	}

	return hole_counter;
}

int temMatchForUCS(Mat& line_image, Mat& temp_image) {
	// 将被显示的原图像
	Mat result;

	// 创建输出结果的矩阵
	int result_cols = line_image.cols - temp_image.cols + 1;
	int result_rows = line_image.rows - temp_image.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);

	int match_method = CV_TM_CCOEFF_NORMED;

	// 进行匹配和标准化
	matchTemplate(line_image, temp_image, result, match_method);
	//normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	// 通过函数 minMaxLoc 定位最匹配的位置
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	vector<int> y_loc;

	for (int x = 0; x < result.cols; x++) {
		for (int y = 0; y < result.rows; y++) {
			if ((result.at<float>(y, x)) > 0.2) {
				y_loc.push_back(y);
			}
		}
	}

	sort(y_loc.begin(), y_loc.end());
	vector<int>::iterator iter = y_loc.begin();
	int hole_counter = 0;
	int last_y = 0;
	for (; iter != y_loc.end(); iter++) {
		int y = (*iter);
		if (y - last_y > temp_image.rows) {
			hole_counter++;
			last_y = y;
		}
	}

	return hole_counter;
}

map<string,int> boxDVR(Mat image) {
	findBoxDetail("DVR");
	map<string, Mat> colorImageDict = cropBlock(image);
	map<string,int> nailNums;
	map<string, Mat>::iterator iter = colorImageDict.begin();
	vector<Mat> lines;
	int* heightArray;
	for (int i = 0; iter != colorImageDict.end(); iter++, i++) {
		string path = "template_image\\" + iter->first + "_tem.jpg";
		Mat temp = imread(path, 0);
		Mat blockImg = iter->second;
		heightArray = horizontalProjection(blockImg, iter->first);
		lines = cropLineByProjection(heightArray, blockImg);
		int blockNum = 0;
		if (iter->first == "UCS") {
			blockNum += temMatchForUCS(blockImg, temp);
			nailNums[iter->first] = LINELIST[iter->first] * HOLELIST[iter->first] - blockNum;
		}
		else {
			vector<Mat>::iterator line_iter = lines.begin();
			for (; line_iter != lines.end(); line_iter++) {
				Mat src = *line_iter;
				blockNum += temMatch(src, temp);
			}
			nailNums[iter->first] = LINELIST[iter->first] * HOLELIST[iter->first] - blockNum;
		}
	}
	delete heightArray;
	return nailNums;
}

void getColor(Mat frame, string color, Mat& bimg) {
	Mat hsv_frame;
	cvtColor(frame, hsv_frame, CV_BGR2HSV);
	map<string, vector<Scalar>> color_dict = setHSVDict();
	map<string, vector<Scalar>>::iterator color_dict_iter = color_dict.begin();
	for (; color_dict_iter != color_dict.end(); color_dict_iter++) {
		if (color_dict_iter->first == color) {
			inRange(hsv_frame, color_dict_iter->second[0], color_dict_iter->second[1], bimg);
		}
	}
}

int boxPOLYX(Mat image,string color) {
	Mat bimg;
	getColor(image, color, bimg);
	Mat kernel, opening, erosion;
	vector<vector<Point>> points;
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	morphologyEx(bimg, opening, MORPH_CLOSE, kernel, Point(-1, -1), 9);
	morphologyEx(opening, erosion, MORPH_OPEN, kernel, Point(-1, -1), 2);
	findContours(erosion, points, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(-1, -1));
	return points.size();
}

int* horizontalProjection(Mat& blockImg,string nailType) {

	int height = blockImg.rows;
	int width = blockImg.cols;
	int* heightArray = new int[height] {0};

	Mat dst;
	//二值化图像的保存路径
	string binaryImgPath = "binary_image/binary_image_" + nailType + ".jpg";
	//水平投影示意图的保存路径
	string projection_img = "projection_image/projection_" + nailType + ".jpg";
	threshold(blockImg, dst, 130, 255, THRESH_BINARY);
	//保存二值图像
	imwrite(binaryImgPath, dst);

	Mat pad(height, width, CV_8UC1);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pad.at<uchar>(i, j) = 255;
		}
	}

	for (int y = 0; y < height; y++) {
		int counter = 0;
		for (int x = 0; x < width; x++) {
			if (dst.at<uchar>(y, x) == 0) {
				if (counter > 92) {
					heightArray[y] += 1;
				}
				counter++;
			}
		}
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < heightArray[y]; x++) {
			pad.at<uchar>(y, x) = 0;
		}
	}
		//保存投影图像
	imwrite(projection_img, pad);
	return heightArray;
}

vector<Mat> cropLineByProjection(int* heightArray, Mat& img) {
	int firstY = 0, lastY = 0;
	int firstYBackUp = firstY, lastYBackUp = lastY;
	int rectStartY = (firstY + lastY) / 2;
	bool isFirst = true, isInNail = false, isOutNail = true;
	vector<Mat> lineList;

	for (int y = 0; y < img.rows; y++) {
		if (heightArray[y] > 0 && isFirst && isOutNail) {
			firstY = y;
			isFirst = false;
			isInNail = true;
			isOutNail = false;
		}
		else if (heightArray[y] == 0 && isInNail) {
			int lineHeight = y - firstY;
			if (lineHeight > 15) {
				lastYBackUp = lastY;
				lastY = y;
			}
			else {
				firstY = firstYBackUp;
				rectStartY = (firstY + lastYBackUp) / 2;
			}
			isInNail = false;
			isOutNail = true;
		}
		else if (heightArray[y] > 0 && isOutNail && !isFirst) {
			firstYBackUp = firstY;
			firstY = y;
			Rect rect(0, rectStartY, img.cols, (firstY + lastY) / 2 - rectStartY);
			Mat aLineImg = img(rect);
			string path = "temp_image/line" + to_string(index++) + ".jpg";
			lineList.push_back(aLineImg);
			imwrite(path, aLineImg);
			rectStartY = (firstY + lastY) / 2;
			isInNail = true;
			isOutNail = false;
		}
	}

	Rect rect(0, rectStartY, img.cols, img.rows - rectStartY);
	Mat aLineImg = img(rect);
	string path = "temp_image/line" + to_string(index++) + ".jpg";
	lineList.push_back(aLineImg);
	imwrite(path, aLineImg);

	return lineList;
}
