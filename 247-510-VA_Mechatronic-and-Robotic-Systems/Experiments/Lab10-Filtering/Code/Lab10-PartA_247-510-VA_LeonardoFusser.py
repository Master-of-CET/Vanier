import cv2
from matplotlib import pyplot as plt
from PIL import Image, ImageFilter, ImageOps

# region Read image from default webcam using OpenCV, convert to Pillow object.
video_capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)
return_code, frame = video_capture.read()
im = Image.fromarray(frame)
# endregion

# region Filter the image: convert it to grayscale, emboss it and then equalize the result.
# Invert it before displaying it.
im_gray = ImageOps.grayscale(im)
im_emboss = im_gray.filter(ImageFilter.EMBOSS)
im_equalize = ImageOps.equalize(im_emboss)
im_invert = ImageOps.invert(im_equalize)
plt.imshow(im_invert, cmap='gray')
plt.show()
# endregion
