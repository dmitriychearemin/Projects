import pygame

import Sounds


class Buttons:
    def __init__(self, display, Butt_X, Butt_Y, Butt_Width, Butt_Height, image1, image2, action):
        self.display = display
        self.Butt_X = Butt_X
        self.Butt_Y = Butt_Y
        self.Butt_Width = Butt_Width
        self.Butt_Height = Butt_Height
        self.image1 = image1
        self.image2 = image2
        self.action = action
    def pressed(self, mouse):
        click = pygame.mouse.get_pressed()
        if self.Butt_X < mouse[0] < self.Butt_X + self.Butt_Width:
            if self.Butt_Y < mouse[1] < self.Butt_Y + self.Butt_Height:
                if click[0] == 1:
                    pygame.time.delay(200)
                    pygame.mixer.Sound.play(Sounds.Sound_For_Buttons)
                    pygame.time.delay(400)
                    self.action()


    def Guidance_on_Button(self):
        mouse = pygame.mouse.get_pos()
        if self.Butt_X < mouse[0] < self.Butt_X + self.Butt_Width and self.Butt_Y < mouse[1] < self.Butt_Y + self.Butt_Height:
            self.display.blit(self.image2, (self.Butt_X, self.Butt_Y))
        else:
            self.display.blit(self.image1, (self.Butt_X, self.Butt_Y))


    def Button_Create (self):
        self.Guidance_on_Button()
        self.pressed(pygame.mouse.get_pos())
