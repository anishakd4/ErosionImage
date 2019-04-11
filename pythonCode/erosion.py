import cv2
import sys

image = cv2.imread("../assets/erosion.png")

#check if the input image exits
if image is None:
    print("input image doesn't exits")
    sys.exit()

#Create structing element/kernel which will be used for dilation
erosionSize = 6
element = cv2.getStructuringElement(cv2.MORPH_CROSS, (2*erosionSize + 1, 2*erosionSize + 1), (erosionSize, erosionSize))

#apply erode function to the input image. Erosion will decrease brightness. First Parameter is the orignal image, 
# second is the eroded image.
erodedImage = cv2.erode(image, element)

#create windows to display eroded image
cv2.namedWindow("input image", cv2.WINDOW_NORMAL)
cv2.namedWindow("eroded image", cv2.WINDOW_NORMAL)

#display images
cv2.imshow("input image", image)
cv2.imshow("eroded image", erodedImage)

#press esc to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()
