import Images
import pygame




class Show_hp():
    def __init__(self, display, image1, image2, image3, image4, image5, X):
        self.display = display
        self.X = X
        self.Y = 10
        self.image1 = image1
        self.image2 = image2
        self.image3 = image3
        self.image4 = image4
        self.image5 = image5

    def Create_Hp(self, HP):
        if HP == 1:
            self.display.blit(self.image1, (self.X, self.Y))
        if HP == 2:
            self.display.blit(self.image2, (self.X, self.Y))
        if HP == 3:
            self.display.blit(self.image3, (self.X, self.Y))
        if HP == 4:
            self.display.blit(self.image4, (self.X, self.Y))
        if HP == 5:
            self.display.blit(self.image5, (self.X, self.Y))
