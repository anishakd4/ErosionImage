#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    //Read the image to be eroded
    Mat image = imread("../assets/erosion.png");

    //Create a structiong element/kernel
    int erosionSize = 6;
    Mat element = getStructuringElement(MORPH_CROSS, Size(2*erosionSize + 1, 2*erosionSize + 1), Point(erosionSize, erosionSize));

    Mat erodedImage;

    //Apply erode function to the input image. Erosion will decrease brightness. First Parameter is the orignal image, 
    //second is the eroded image.
    erode(image, erodedImage, element);

    //Create windows to display images
    namedWindow("input image", WINDOW_NORMAL);
    namedWindow("eroded image", WINDOW_NORMAL);

    //Display images
    imshow("input image", image);
    imshow("eroded image", erodedImage);

    //Press esc on keyboard to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();

    return 0;
}