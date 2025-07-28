from PIL import Image, ImageFilter
# Need to install the library Image, thats why the venv directory

before = Image.open("yard.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("blur.bmp")
