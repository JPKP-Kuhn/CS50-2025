import qrcode
import os

img = qrcode.make("https://jpkp-kuhn.github.io/Sobre-mim/")
img.save("qr.png", "PNG")

