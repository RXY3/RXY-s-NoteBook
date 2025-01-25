import cv2
import numpy as np

def blur_image(image_path, output_path):
    # 读取图片
    img = cv2.imread(image_path)
    
    # 定义3x3的均值滤波器
    kernel = np.ones((10, 10), np.float32) / 100
    
    # 应用滤波器进行模糊处理
    blurred_img = cv2.filter2D(img, -1, kernel)
    # # 加强对比度
    # blurred_img = cv2.addWeighted(blurred_img, 1.5, np.zeros(blurred_img.shape, blurred_img.dtype), 0, 0)
    # # 锐化
    # kernel = np.array([[0, -1, 0], [-1, 5,-1], [0, -1, 0]])
    # sharpened_img = cv2.filter2D(blurred_img, -1, kernel)
    # 
    # 保存模糊后的图片
    cv2.imwrite(output_path, blurred_img)
    
    # # 显示原图和模糊后的图片
    # cv2.imshow('Original Image', img)
    # cv2.imshow('Blurred Image', blurred_img)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()

# 使用示例，这里可以处理的图片格式是jpg,png,bmp,jpeg
image_path = '/Users/apple/Desktop/RXY-s-NoteBook/截屏2024-11-11 16.19.58.png'  # 替换为你的图片路径
output_path = 'blurred_image.png'  # 输出图片的路径
blur_image(image_path, output_path)
