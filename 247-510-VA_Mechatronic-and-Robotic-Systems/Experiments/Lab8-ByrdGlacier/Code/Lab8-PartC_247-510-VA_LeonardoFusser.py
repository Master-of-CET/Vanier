from PIL import Image, ImageFilter
from tqdm import tqdm

# region Optional: A task bar to show progress.
pbar = tqdm(total=5)
pbar.set_description('Processing Pipeline')
# endregion
# region Open the file.
filename = r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier.jpg"
Img = Image.open(filename)
pbar.update()
# endregion
# region Apply the blur filters.
Blurred_1 = Img.filter(ImageFilter.BLUR)
Blurred_2 = Img.filter(ImageFilter.BoxBlur(20))
Blurred_3 = Img.filter(ImageFilter.GaussianBlur(10))
pbar.update()
#Blurred_1.show()
#Blurred_2.show()
#Blurred_3.show()
# endregion
# region Apply the median filter.
Median_1 = Img.filter(ImageFilter.MedianFilter(9))
pbar.update()
#Median_1.show()
# endregion
# region Apply the max filter.
Max = Img.filter(ImageFilter.MaxFilter(3))
pbar.update()
#Max.show()
# endregion
# region Apply sharpen filters.
Sharpen_1 = Img.filter(ImageFilter.SHARPEN)
Sharpen_2 = Img.filter(ImageFilter.UnsharpMask(30))
pbar.update()
#Sharpen_1.show()
# endregion
# region Save filtered images.
Blurred_1.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Blurred_1.jpg")
Blurred_2.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Blurred_2.jpg")
Blurred_3.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Blurred_3.jpg")
Median_1.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Median_1.jpg")
Max.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Max.jpg")
Sharpen_1.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Sharpen_1.jpg")
Sharpen_2.save(r"D:\PycharmProjects\Vanier\Mechatronics&Robotics\Week9\byrd_glacier-Sharpen_2.jpg")
# endregion
