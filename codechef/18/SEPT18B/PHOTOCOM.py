class Pixel:
    def __init__(self,h,w,value):
        self.shape=[h,w]
        self.value=value

    def resize(self,a,b):
        self.shape=[a*(self.h),b*(self.w)]
        return self.shape

    def display_pixel(self):
        for i in range(h):
            print(value,end='')*w
