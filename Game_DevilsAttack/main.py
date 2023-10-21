import sys
import io
import os
import random
import pygame
import Images
import Sounds
import Buttons
import Show_HP

buffer = io.StringIO()
sys.stdout = sys.stderr = buffer


# Общие данные
WIDTH = 1400
HEIGHT = 700
FPS = 120
display = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("Devil's Attack")
pygame.display.set_icon(Images.icon)
pygame.init()
pygame.mixer.init()
clock = pygame.time.Clock()



class Meteors:
    def __init__(self, display, speed, image, Met_Width, Met_Height, mode):
        self.display = display
        self.speed = speed
        self.mode = mode
        self.image = image
        if self.mode == "PVE1":
            self.Met_X = random.randint(50, 600)

        if self.mode == "PVP":
            self.Met_X = random.randint(800, 1300)

        self.Met_Y = 0
        self.Met_Width = Met_Width
        self.Met_Height = Met_Height

    def Damage_Player(self):
        if Player1.Invulnerability_frames_count == 0:
            # правым нижним углом
            if (Player1.Pl_X + Player1.Pl_Width >= self.Met_X and Player1.Pl_X + Player1.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player1.Pl_Y + Player1.Pl_Height >= self.Met_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player1.HP = Player1.HP - 1
                    self.Met_X = self.Met_X + self.speed*9
                    self.Met_Y = self.Met_Y + self.speed*9
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)
            # правым верхним углом
            if (Player1.Pl_X + Player1.Pl_Width >= self.Met_X and Player1.Pl_X + Player1.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player1.Pl_Y  >= self.Met_Y and Player1.Pl_Y <= self.Met_Height + self.Met_Y):
                    Player1.HP = Player1.HP - 1
                    self.Met_X = self.Met_X + self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9 + 70 + self.Met_Height/2
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

            # нижний левый углом
            if (Player1.Pl_X  >= self.Met_X and Player1.Pl_X <= self.Met_Width + self.Met_X):
                if (Player1.Pl_Y + Player1.Pl_Height >= self.Met_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player1.HP = Player1.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

                # верхний левый углом
            if (Player1.Pl_X + Player1.Pl_Width >= self.Met_X and Player1.Pl_X + Player1.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player1.Pl_Y + Player1.Pl_Height >= self.Met_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player1.HP = Player1.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9 + 70 + self.Met_Height/2
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)
            # касание по центру
            if (Player1.Pl_X + Player1.Pl_Width/2 >= self.Met_X and Player1.Pl_X + Player1.Pl_Width/2 <= self.Met_Width + self.Met_X):
                if (Player1.Pl_Y + Player1.Pl_Height/2 >= self.Met_Y and Player1.Pl_Y + Player1.Pl_Height/2 <= self.Met_Height + self.Met_Y):
                    Player1.HP = Player1.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9 + 60 + self.Met_Width/2
                    self.Met_Y = self.Met_Y + self.speed * 9 + 35 + self.Met_Height/2
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)


        if Player2.Invulnerability_frames_count == 0:
            # правым нижним углом
            if (Player2.Pl_X + Player2.Pl_Width >= self.Met_X and Player2.Pl_X + Player2.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player2.Pl_Y + Player2.Pl_Height >= self.Met_Y and Player2.Pl_Y + Player2.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player2.HP = Player2.HP - 1
                    self.Met_X = self.Met_X + self.speed*9
                    self.Met_Y = self.Met_Y + self.speed*9
                    Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)
            # правым верхним углом
            if (Player2.Pl_X + Player2.Pl_Width >= self.Met_X and Player2.Pl_X + Player2.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player2.Pl_Y  >= self.Met_Y and Player2.Pl_Y <= self.Met_Height + self.Met_Y):
                    Player2.HP = Player2.HP - 1
                    self.Met_X = self.Met_X + self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9 + 70 + self.Met_Height/2
                    Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

            # нижний левый углом
            if (Player2.Pl_X  >= self.Met_X and Player2.Pl_X <= self.Met_Width + self.Met_X):
                if (Player2.Pl_Y + Player2.Pl_Height >= self.Met_Y and Player2.Pl_Y + Player2.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player2.HP = Player2.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9
                    Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

                # верхний левый углом
            if (Player2.Pl_X + Player2.Pl_Width >= self.Met_X and Player2.Pl_X + Player2.Pl_Width <= self.Met_Width + self.Met_X):
                if (Player2.Pl_Y + Player2.Pl_Height >= self.Met_Y and Player2.Pl_Y + Player2.Pl_Height <= self.Met_Height + self.Met_Y):
                    Player2.HP = Player2.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9
                    self.Met_Y = self.Met_Y + self.speed * 9 + 70 + self.Met_Height/2
                    Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)
            # касание по центру
            if (Player2.Pl_X + Player2.Pl_Width/2 >= self.Met_X and Player2.Pl_X + Player2.Pl_Width/2 <= self.Met_Width + self.Met_X):
                if (Player2.Pl_Y + Player2.Pl_Height/2 >= self.Met_Y and Player2.Pl_Y + Player2.Pl_Height/2 <= self.Met_Height + self.Met_Y):
                    Player2.HP = Player2.HP - 1
                    self.Met_X = self.Met_X - self.speed * 9 + 60 + self.Met_Width/2
                    self.Met_Y = self.Met_Y + self.speed * 9 + 35 + self.Met_Height/2
                    Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

    def Meteor_move(self):
        if self.mode == "PVE1":
            self.Met_Y = self.Met_Y + self.speed
            if (self.Met_Y >= 700):
                self.Met_X = random.randint(50, 600)
                self.Met_Y = 0

        if self.mode == "PVP":
            self.Met_Y = self.Met_Y + self.speed
            if (self.Met_Y >= 700):
                self.Met_X = random.randint(800, 1300)
                self.Met_Y = 0

    def create_Meteors(self):
        self.Damage_Player()
        self.Meteor_move()
        display.blit(self.image, (self.Met_X, self.Met_Y))

class Player:
    def __init__(self, display, Pl_X, Pl_Y, Pl_Width, Pl_Height, Player_speed, image, Pl_Attack_Frequency, HP, name):
        self.display = display
        self.name = name
        self.Pl_X = Pl_X
        self.Pl_Y = Pl_Y
        self.Pl_Width = Pl_Width
        self.Pl_Height = Pl_Height
        self.Player_speed = Player_speed
        self.image = image
        self.makefly = False
        self.HP = HP
        self.Invulnerability_frames_count = 0
        self.Pl_timer_attack = 0
       # self.Pl_timer_attack2 = 0
        self.Pl_Attack_Frequency = Pl_Attack_Frequency
        self.Pl_Count_Prj = 0 # количество летящих снарядов игрока1 на экране
       # self.Pl_Count_Prj2 = 0  количество летящих снарядов игрока2 на экране
        self.Pl_MAX_Speed = self.Player_speed + 3
        self.Pl_Mode_speed = False
        self.Pl_Count_speed = 0

    def fly_up(self):
        self.Pl_Y = self.Pl_Y - self.Player_speed
        self.make_fly = False
    def fly_down(self):
        self.Pl_Y = self.Pl_Y + self.Player_speed
        self.make_fly = False

    def fly_left(self):
        self.Pl_X = self.Pl_X - self.Player_speed
        self.make_fly = False
    def fly_right(self):
        self.Pl_X = self.Pl_X + self.Player_speed
        self.make_fly = False

    def Attack(self):
        if self.name == "Player1":
            if self.Pl_timer_attack == 0 or Player1_Projectile1_1.Prj_X >= WIDTH:
                if (self.Pl_Count_Prj == 2):
                    self.Pl_Count_Prj = 0
                pygame.mixer.Sound.play(Sounds.Attack_Player)
                Player1_Projectile1_1.Prj_X = 0
                Player1_Projectile1_1.Prj_Y = 0
                Player1_Projectile1_1.Create(Player1.Pl_X + 90, Player1.Pl_Y)
                self.Pl_timer_attack= self.Pl_timer_attack + 1
                self.Pl_Count_Prj += 1

            if Player1_Projectile1_1.Prj_X > 2 * WIDTH/3 + 200 and self.Pl_Count_Prj == 1:
                pygame.mixer.Sound.play(Sounds.Attack_Player)
                Player1_Projectile1_2.Prj_X = 0
                Player1_Projectile1_2.Prj_Y = 0
                Player1_Projectile1_2.Create(Player1.Pl_X + 90, Player1.Pl_Y)
                self.Pl_Count_Prj += 1

        if self.name == "Player2":
            if self.Pl_timer_attack == 0 or Player2_Projectile1_1.Prj_X <= 0:
                if (self.Pl_Count_Prj == 2):
                    self.Pl_Count_Prj = 0
                pygame.mixer.Sound.play(Sounds.Attack_Player)
                Player2_Projectile1_1.Prj_X = 0
                Player2_Projectile1_1.Prj_Y = 0
                Player2_Projectile1_1.Create(Player2.Pl_X, Player2.Pl_Y)
                self.Pl_timer_attack = self.Pl_timer_attack + 1
                self.Pl_Count_Prj += 1

            if Player2_Projectile1_1.Prj_X < WIDTH / 3 - 200 and self.Pl_Count_Prj == 1:
                pygame.mixer.Sound.play(Sounds.Attack_Player)
                Player2_Projectile1_2.Prj_X = 0
                Player2_Projectile1_2.Prj_Y = 0
                Player2_Projectile1_2.Create(Player2.Pl_X, Player2.Pl_Y)
                self.Pl_Count_Prj += 1

    def Player_move(self):
        keys = pygame.key.get_pressed()
        if self.name == "Player1":
            if keys[pygame.K_w]:
                self.make_fly = True
                self.fly_up()
            if keys[pygame.K_s]:
                self.make_fly = True
                self.fly_down()
            if keys[pygame.K_a]:
                self.make_fly = True
                self.fly_left()
            if keys[pygame.K_d]:
                self.make_fly = True
                self.fly_right()
            if keys[pygame.K_SPACE]:
                self.Attack()

            if keys[pygame.K_LSHIFT]:
                if self.Pl_Count_speed >= 50:
                    self.Pl_Count_speed = 0
                if self.Pl_Mode_speed == True and self.Pl_Count_speed == 0:
                    self.Player_speed -= 3
                    self.Pl_Mode_speed = False
                    self.Pl_Count_speed += 1
                if self.Pl_Mode_speed == False and self.Pl_Count_speed == 0:
                    self.Player_speed = self.Pl_MAX_Speed
                    self.Pl_Mode_speed = True
                    self.Pl_Count_speed += 1

        if self.name == "Player2":
            if keys[pygame.K_UP]:
                self.make_fly = True
                self.fly_up()
            if keys[pygame.K_DOWN]:
                self.make_fly = True
                self.fly_down()
            if keys[pygame.K_LEFT]:
                self.make_fly = True
                self.fly_left()
            if keys[pygame.K_RIGHT]:
                self.make_fly = True
                self.fly_right()
            if keys[pygame.K_KP_PLUS]:
                self.Attack()
            if keys[pygame.K_KP_ENTER]:
                if self.Pl_Count_speed >= 50:
                    self.Pl_Count_speed = 0
                if self.Pl_Mode_speed == True and self.Pl_Count_speed == 0:
                    self.Player_speed -= 3
                    self.Pl_Mode_speed = False
                    self.Pl_Count_speed += 1
                if self.Pl_Mode_speed == False and self.Pl_Count_speed == 0:
                    self.Player_speed = self.Pl_MAX_Speed
                    self.Pl_Mode_speed = True
                    self.Pl_Count_speed += 1
    def Damage_Outline(self):
        if (self.name == "Player1"):
            if self.Pl_X+ self.Pl_Width <= -20:
                self.HP -= 1
                self.Pl_X = WIDTH/4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_X >= WIDTH + 20:
                self.HP -= 1
                self.Pl_X = WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_Y + self.Pl_Width <= -20:
                self.HP -= 1
                self.Pl_X = WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_Y >= HEIGHT + 20:
                self.HP -= 1
                self.Pl_X = WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

        if (self.name == "Player2"):
            if self.Pl_X + self.Pl_Width <= -20:
                self.HP -= 1
                self.Pl_X = 3 * WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_X >= WIDTH + 20:
                self.HP -= 1
                self.Pl_X = 3 * WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_Y + self.Pl_Width <= -20:
                self.HP -= 1
                self.Pl_X = 3 * WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

            if self.Pl_Y >= HEIGHT + 20:
                self.HP -= 1
                self.Pl_X = 3 * WIDTH / 4 - 60
                self.Pl_Y = HEIGHT / 2 - 70
                pygame.mixer.Sound.play(Sounds.Damage_Outline)

    def Player_create(self):
        if self.HP > 0:
            self.Player_move()
            self.Damage_Outline()
            ################################ тайм-аут удара игрока
            if Player1_Projectile1_1.Prj_X != 0 and Player1_Projectile1_1.Prj_X < WIDTH:
                Player1_Projectile1_1.Create(Player1_Projectile1_1.Prj_X, Player1_Projectile1_1.Prj_Y)
            if Player1_Projectile1_2.Prj_X != 0 and Player1_Projectile1_2.Prj_X < WIDTH:
                Player1_Projectile1_2.Create(Player1_Projectile1_2.Prj_X, Player1_Projectile1_2.Prj_Y)
            if Player2_Projectile1_1.Prj_X != 0 and Player2_Projectile1_1.Prj_X < WIDTH:
                Player2_Projectile1_1.Create(Player2_Projectile1_1.Prj_X, Player2_Projectile1_1.Prj_Y)
            if Player2_Projectile1_2.Prj_X != 0 and Player2_Projectile1_2.Prj_X < WIDTH:
                Player2_Projectile1_2.Create(Player2_Projectile1_2.Prj_X, Player2_Projectile1_2.Prj_Y)
    ######################################################################

            if self.Pl_Count_speed != 0:
                self.Pl_Count_speed += 1

            display.blit(self.image, (self.Pl_X, self.Pl_Y))
            if self.Invulnerability_frames_count != 0:
                self.Invulnerability_frames_count = self.Invulnerability_frames_count + 1
                if self.Invulnerability_frames_count == 30:
                    self.Invulnerability_frames_count = 0

        if (self .HP <= 0):
            if self.name == "Player1":
                pygame.mixer.Sound.play(Sounds.Die_Player1)
                display.blit(Images.Die_Player_Back, (Player1.Pl_X, Player1.Pl_Y))

            if self.name == "Player2":
                pygame.mixer.Sound.play(Sounds.Die_Player1)
                display.blit(Images.Die_Player_Back, (Player2.Pl_X, Player2.Pl_Y))

class Enemy:
    def __init__(self, display, Enemy_X, Enemy_Y, Enemy_Width, Enemy_Height, Enemy_speed, Enemy_move_count, image, Enemy_HP, Attack_Frequency, name):
        # Враги на первом уровне
        self.display = display
        self.Invulnerability_frames_count = 0
        self.Enemy_speed = Enemy_speed
        self.Enemy_Width = Enemy_Width
        self.Enemy_Height = Enemy_Height
        self.Enemy_X = Enemy_X
        self.Enemy_Y = Enemy_Y
        self.name = name
        self.Enemy_move_count = Enemy_move_count
        self.count_returnX1 = 0
        self.count_returnX2 = 0
        self.count_returnY1 = 0
        self.count_returnY2 = 0
        self.count = 0  # Длительность движения по выбираемой оси
        self.A = 0 # Выбор оси Х или У
        self.countX = 0 # Длина траектории по оси Х
        self.countY = 0 # Длина траектории по оси У
        self.A_X = 0  # Направление движения по оси х
        self.A_Y = 0  # Направление движения по оси у
        self.image = image
        self.Enemy_HP = Enemy_HP
        self.Attack_Frequency = Attack_Frequency # частота атак
        self.timer_attack = 0 # отсчет для атаки


    def Attack_Projectaile (self):
        if self.name == "Enemy":
            if self.timer_attack == 0 or (Enemy_Projectile1.Prj_X + Enemy_Projectile1.Prj_Width) <= 0:
                pygame.mixer.Sound.play(Sounds.Attack_Enemy)
                Enemy_Projectile1.Prj_X = 0
                Enemy_Projectile1.Prj_Y = 0
                Enemy_Projectile1.Create(self.Enemy_X + 30, self.Enemy_Y + 30)
                self.timer_attack = self.timer_attack + 1

            if self.timer_attack >= self.Attack_Frequency:
                self.timer_attack = 0

            if self.timer_attack != 0:
                self.timer_attack = self.timer_attack + 1
                Enemy_Projectile1.Create(Enemy_Projectile1.Prj_X, Enemy_Projectile1.Prj_Y)
                Enemy_Projectile2.Create(Enemy_Projectile2.Prj_X, Enemy_Projectile2.Prj_Y)

            if Enemy_Projectile1.Prj_X + Enemy_Projectile1.Prj_Width <= Player1.Pl_X:
                Enemy_Projectile2.Prj_X = 0
                Enemy_Projectile2.Prj_Y = 0
                Enemy_Projectile2.Create(self.Enemy_X + 30, self.Enemy_Y + 30)

        if self.name == "Enemy2":
            if self.timer_attack == 0 or (Enemy2_Projectile1.Prj_X + Enemy2_Projectile1.Prj_Width) <= 0:
                pygame.mixer.Sound.play(Sounds.Attack_Enemy)
                Enemy2_Projectile1.Prj_X = 0
                Enemy2_Projectile1.Prj_Y = 0
                Enemy2_Projectile1.Create(self.Enemy_X + 30, self.Enemy_Y + 30)
                self.timer_attack = self.timer_attack + 1

            if self.timer_attack >= self.Attack_Frequency:
                self.timer_attack = 0

            if self.timer_attack != 0:
                self.timer_attack = self.timer_attack + 1
                Enemy2_Projectile1.Create(Enemy2_Projectile1.Prj_X, Enemy2_Projectile1.Prj_Y)
                Enemy2_Projectile2.Create(Enemy2_Projectile2.Prj_X, Enemy2_Projectile2.Prj_Y)

            if Enemy2_Projectile1.Prj_X + Enemy2_Projectile1.Prj_Width <= Player1.Pl_X:
                Enemy2_Projectile2.Prj_X = 0
                Enemy2_Projectile2.Prj_Y = 0
                Enemy2_Projectile2.Create(self.Enemy_X + 30, self.Enemy_Y + 30)

        if self.name == "Enemy3":
            if self.timer_attack == 0 or (Enemy3_Projectile1.Prj_X + Enemy3_Projectile1.Prj_Width) <= 0:
                pygame.mixer.Sound.play(Sounds.Attack_Enemy)
                Enemy3_Projectile1.Prj_X = 0
                Enemy3_Projectile1.Prj_Y = 0
                Enemy3_Projectile1.Create(self.Enemy_X + 30, self.Enemy_Y + 30)
                self.timer_attack = self.timer_attack + 1

            if self.timer_attack >= self.Attack_Frequency:
                self.timer_attack = 0

            if self.timer_attack != 0:
                self.timer_attack = self.timer_attack + 1
                Enemy3_Projectile1.Create(Enemy3_Projectile1.Prj_X, Enemy3_Projectile1.Prj_Y)
                Enemy3_Projectile2.Create(Enemy3_Projectile2.Prj_X, Enemy3_Projectile2.Prj_Y)

            if Enemy3_Projectile1.Prj_X + Enemy3_Projectile1.Prj_Width <= Player1.Pl_X:
                Enemy3_Projectile2.Prj_X = 0
                Enemy3_Projectile2.Prj_Y = 0
                Enemy3_Projectile2.Create(self.Enemy_X + 30, self.Enemy_Y + 30)

    def Damage_player(self):
        if Player1.Invulnerability_frames_count == 0:
            # правым нижним углом
            if (Player1.Pl_X + Player1.Pl_Width >= self.Enemy_X and Player1.Pl_X + Player1.Pl_Width <= self.Enemy_Width + self.Enemy_X):
                if (Player1.Pl_Y + Player1.Pl_Height >= self.Enemy_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Enemy_Height + self.Enemy_Y):
                    Player1.HP = Player1.HP - 1
                    Player1.Pl_X = WIDTH / 4 - 58
                    Player1.Pl_Y = HEIGHT / 2 - 70
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)
            # правым верхним углом
            if (Player1.Pl_X + Player1.Pl_Width >= self.Enemy_X and Player1.Pl_X + Player1.Pl_Width <= self.Enemy_Width + self.Enemy_X):
                if (Player1.Pl_Y  >= self.Enemy_Y and Player1.Pl_Y <= self.Enemy_Height + self.Enemy_Y):
                    Player1.HP = Player1.HP - 1
                    Player1.Pl_X = WIDTH / 4 - 58
                    Player1.Pl_Y = HEIGHT / 2 - 70
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

            # нижний левый углом
            if (Player1.Pl_X  >= self.Enemy_X and Player1.Pl_X  <= self.Enemy_Width + self.Enemy_X):
                if (Player1.Pl_Y + Player1.Pl_Height >= self.Enemy_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Enemy_Height + self.Enemy_Y):
                    Player1.HP = Player1.HP - 1
                    Player1.Pl_X = WIDTH / 4 - 58
                    Player1.Pl_Y = HEIGHT / 2 - 70
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

                # верхний левый углом
            if (Player1.Pl_X  >= self.Enemy_X and Player1.Pl_X  <= self.Enemy_Width + self.Enemy_X):
                if (Player1.Pl_Y  >= self.Enemy_Y and Player1.Pl_Y <= self.Enemy_Height + self.Enemy_Y):
                    Player1.HP = Player1.HP - 1
                    Player1.Pl_X = WIDTH / 4 - 58
                    Player1.Pl_Y = HEIGHT / 2 - 70
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

            if (Player1.Pl_X + Player1.Pl_Width/2 >= self.Enemy_X and Player1.Pl_X + Player1.Pl_Width/2 <= self.Enemy_Width + self.Enemy_X):
                if (Player1.Pl_Y + Player1.Pl_Height/2 >= self.Enemy_Y and Player1.Pl_Y + Player1.Pl_Height/2 <= self.Enemy_Height + self.Enemy_Y):
                    Player1.HP = Player1.HP - 1
                    Player1.Pl_X = WIDTH / 4 - 58
                    Player1.Pl_Y = HEIGHT / 2 - 70
                    Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                    pygame.mixer.Sound.play(Sounds.Damage_Player1)

    def Enemy_move_X(self,x):
        if self.count_returnX1 == 20:
            self.count_returnX1 = 0
        if self.count_returnX2 == 20:
            self.count_returnX2 = 0
        if x >= 1250 or self.count_returnX1 > 0:
            self.count_returnX1 = self.count_returnX1 + 1
            x = self.Enemy_X - self.Enemy_speed
            return x

        if x <= 750 or self.count_returnX2 > 0:
            self.count_returnX2 = self.count_returnX2 + 1
            x = self.Enemy_X + self.Enemy_speed
            return x

        if x > 750 and  x < 1250 and self.count_returnX1 == 0 and self.count_returnX2 ==0 :
            if (self.countX == 0):
                self.A_X = random.randint(1,2)
            if (self.countX == self.Enemy_move_count):
                self.countX = 0
                return x

            if self.A_X == 1:
                x = self.Enemy_X - self.Enemy_speed
                self.countX = self.countX + 1
                return x
            if self.A_X == 2:
                x = self.Enemy_X + self.Enemy_speed
                self.countX = self.countX + 1
                return x

    def Enemy_move_Y(self, y):
        if self.count_returnY1 == 20:
            self.count_returnY1 = 0
        if self.count_returnY2 == 20:
            self.count_returnY2 = 0
        if y <= 0 or self.count_returnY1 > 0:
            self.count_returnY1 = self.count_returnY1 + 1
            y = self.Enemy_Y + self.Enemy_speed
            return y
        if y >= 550 or self.count_returnY2 > 0:
            self.count_returnY2 = self.count_returnY2 + 1
            y = self.Enemy_Y - self.Enemy_speed
            return y
        if(y > 0 and y < 550 and self.count_returnY1==0 and self.count_returnY2==0 ):
            if (self.countY == 0):
                self.A_Y = random.randint(1, 2)
            if (self.countY == self.Enemy_move_count):
                self.countY = 0
                return y
            if self.A_Y == 1:
                y = self.Enemy_Y - self.Enemy_speed
                self.countY = self.countY + 1
                return y
            if self.A_Y == 2:
                y = self.Enemy_Y + self.Enemy_speed
                self.countY = self.countY + 1
                return y

    def Create_Enemy(self):
        if self.Enemy_HP > 0:
            display.blit(self.image,(self.Enemy_X, self.Enemy_Y))
            if (self.count == 0):
                self.A = random.randint(1, 3)
            if (self.count == 20):
                self.count = 0
                self.A = 0
            if self.A == 1:
                self.count = self.count + 1
                self.Enemy_X = self.Enemy_move_X(self.Enemy_X)

            if self.A == 2 or self.A == 3:
                self.count = self.count + 1
                self.Enemy_Y = self.Enemy_move_Y(self.Enemy_Y)
            self.Damage_player()
            self.Attack_Projectaile()
            if self.Invulnerability_frames_count != 0:
                self.Invulnerability_frames_count = self.Invulnerability_frames_count + 1
                if self.Invulnerability_frames_count == 40:
                    self.Invulnerability_frames_count = 0

        if self.Enemy_HP <= 0:
            pygame.mixer.Sound.play(Sounds.Die_Enemy1)
            display.blit(Images.Die_Enemy_Back, (self.Enemy_X, self.Enemy_Y))

class Projectiles:
    def __init__(self, display, Prj_Width, Prj_Height, Prj_speed, Prj_image, Prj_master):
        self.display = display
        self.Prj_Width = Prj_Width
        self.Prj_Height = Prj_Height
        self.Prj_speed = Prj_speed
        self.Prj_image = Prj_image
        self.Prj_Master = Prj_master
        self.Prj_X = 0
        self.Prj_Y = 0

    def Move(self):
        if self.Prj_Master == "Player1":
            self.Prj_X = self.Prj_X + self.Prj_speed
        else:
            self.Prj_X = self.Prj_X - self.Prj_speed

    def Giving_Damage(self):
        if self.Prj_Master == "Player1":
            if Enemy1.Invulnerability_frames_count == 0:
                # правым нижним углом
                if (Enemy1.Enemy_X + Enemy1.Enemy_Width >= self.Prj_X and Enemy1.Enemy_X + Enemy1.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy1.Enemy_Y + Enemy1.Enemy_Height >= self.Prj_Y and Enemy1.Enemy_Y + Enemy1.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy1.Enemy_HP = Enemy1.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy1.Invulnerability_frames_count = Enemy1.Invulnerability_frames_count + 1

                    # правым верхним углом
                if (Enemy1.Enemy_X + Enemy1.Enemy_Width >= self.Prj_X and Enemy1.Enemy_X + Enemy1.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy1.Enemy_Y  >= self.Prj_Y and Enemy1.Enemy_Y <= self.Prj_Height + self.Prj_Y):
                        Enemy1.Enemy_HP = Enemy1.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy1.Invulnerability_frames_count = Enemy1.Invulnerability_frames_count + 1
                    # нижний левый углом
                if (Enemy1.Enemy_X  >= self.Prj_X and Enemy1.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy1.Enemy_Y + Enemy1.Enemy_Height >= self.Prj_Y and Enemy1.Enemy_Y + Enemy1.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy1.Enemy_HP = Enemy1.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy1.Invulnerability_frames_count = Enemy1.Invulnerability_frames_count + 1
                    # верхний левый углом
                if (Enemy1.Enemy_X  >= self.Prj_X and Enemy1.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy1.Enemy_Y  >= self.Prj_Y and Enemy1.Enemy_Y  <= self.Prj_Height + self.Prj_Y):
                        Enemy1.Enemy_HP = Enemy1.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy1.Invulnerability_frames_count = Enemy1.Invulnerability_frames_count + 1
                    # центром
                if (Enemy1.Enemy_X + Enemy1.Enemy_Width/2 >= self.Prj_X and Enemy1.Enemy_X + Enemy1.Enemy_Width/2 <= self.Prj_Width + self.Prj_X):
                    if (Enemy1.Enemy_Y + Enemy1.Enemy_Height/2 >= self.Prj_Y and Enemy1.Enemy_Y + Enemy1.Enemy_Height/2 <= self.Prj_Height + self.Prj_Y):
                        Enemy1.Enemy_HP = Enemy1.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy1.Invulnerability_frames_count = Enemy1.Invulnerability_frames_count + 1

            if Enemy2.Invulnerability_frames_count == 0:
                # правым нижним углом
                if (Enemy2.Enemy_X + Enemy2.Enemy_Width >= self.Prj_X and Enemy2.Enemy_X + Enemy2.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy2.Enemy_Y + Enemy2.Enemy_Height >= self.Prj_Y and Enemy2.Enemy_Y + Enemy2.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy2.Enemy_HP = Enemy2.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy2.Invulnerability_frames_count = Enemy2.Invulnerability_frames_count + 1

                    # правым верхним углом
                if (Enemy2.Enemy_X + Enemy2.Enemy_Width >= self.Prj_X and Enemy2.Enemy_X + Enemy2.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy2.Enemy_Y  >= self.Prj_Y and Enemy2.Enemy_Y <= self.Prj_Height + self.Prj_Y):
                        Enemy2.Enemy_HP = Enemy2.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy2.Invulnerability_frames_count = Enemy2.Invulnerability_frames_count + 1
                    # нижний левый углом
                if (Enemy2.Enemy_X  >= self.Prj_X and Enemy2.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy2.Enemy_Y + Enemy2.Enemy_Height >= self.Prj_Y and Enemy2.Enemy_Y + Enemy2.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy2.Enemy_HP = Enemy2.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy2.Invulnerability_frames_count = Enemy2.Invulnerability_frames_count + 1
                    # верхний левый углом
                if (Enemy2.Enemy_X  >= self.Prj_X and Enemy2.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy2.Enemy_Y  >= self.Prj_Y and Enemy2.Enemy_Y  <= self.Prj_Height + self.Prj_Y):
                        Enemy2.Enemy_HP = Enemy2.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy2.Invulnerability_frames_count = Enemy2.Invulnerability_frames_count + 1
                    # центром
                if (Enemy2.Enemy_X + Enemy2.Enemy_Width/2 >= self.Prj_X and Enemy2.Enemy_X + Enemy2.Enemy_Width/2 <= self.Prj_Width + self.Prj_X):
                    if (Enemy2.Enemy_Y + Enemy2.Enemy_Height/2 >= self.Prj_Y and Enemy2.Enemy_Y + Enemy2.Enemy_Height/2 <= self.Prj_Height + self.Prj_Y):
                        Enemy2.Enemy_HP = Enemy2.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy2.Invulnerability_frames_count = Enemy2.Invulnerability_frames_count + 1

            if Enemy3.Invulnerability_frames_count == 0:
                # правым нижним углом
                if (Enemy3.Enemy_X + Enemy3.Enemy_Width >= self.Prj_X and Enemy3.Enemy_X + Enemy3.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy3.Enemy_Y + Enemy3.Enemy_Height >= self.Prj_Y and Enemy3.Enemy_Y + Enemy3.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy3.Enemy_HP = Enemy3.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy3.Invulnerability_frames_count = Enemy3.Invulnerability_frames_count + 1

                    # правым верхним углом
                if (Enemy3.Enemy_X + Enemy3.Enemy_Width >= self.Prj_X and Enemy3.Enemy_X + Enemy3.Enemy_Width <= self.Prj_Width + self.Prj_X):
                    if (Enemy3.Enemy_Y  >= self.Prj_Y and Enemy3.Enemy_Y <= self.Prj_Height + self.Prj_Y):
                        Enemy3.Enemy_HP = Enemy3.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy3.Invulnerability_frames_count = Enemy3.Invulnerability_frames_count + 1
                    # нижний левый углом
                if (Enemy3.Enemy_X  >= self.Prj_X and Enemy3.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy3.Enemy_Y + Enemy3.Enemy_Height >= self.Prj_Y and Enemy3.Enemy_Y + Enemy3.Enemy_Height <= self.Prj_Height + self.Prj_Y):
                        Enemy3.Enemy_HP = Enemy3.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy3.Invulnerability_frames_count = Enemy3.Invulnerability_frames_count + 1
                    # верхний левый углом
                if (Enemy3.Enemy_X  >= self.Prj_X and Enemy3.Enemy_X  <= self.Prj_Width + self.Prj_X):
                    if (Enemy3.Enemy_Y  >= self.Prj_Y and Enemy3.Enemy_Y  <= self.Prj_Height + self.Prj_Y):
                        Enemy3.Enemy_HP = Enemy3.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy3.Invulnerability_frames_count = Enemy3.Invulnerability_frames_count + 1
                    # центром
                if (Enemy3.Enemy_X + Enemy3.Enemy_Width/2 >= self.Prj_X and Enemy3.Enemy_X + Enemy3.Enemy_Width/2 <= self.Prj_Width + self.Prj_X):
                    if (Enemy3.Enemy_Y + Enemy3.Enemy_Height/2 >= self.Prj_Y and Enemy3.Enemy_Y + Enemy3.Enemy_Height/2 <= self.Prj_Height + self.Prj_Y):
                        Enemy3.Enemy_HP = Enemy3.Enemy_HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Enemy1)
                        Enemy3.Invulnerability_frames_count = Enemy3.Invulnerability_frames_count + 1

            if Player2.Invulnerability_frames_count == 0:
                # правым нижним углом
                if (Player2.Pl_X + Player2.Pl_Width >= self.Prj_X and Player2.Pl_X + Player2.Pl_Width <= self.Prj_Width + self.Prj_X):
                    if (Player2.Pl_Y + Player2.Pl_Height >= self.Prj_Y and Player2.Pl_Y + Player2.Pl_Height <= self.Prj_Height + self.Prj_Y):
                        Player2.HP = Player2.HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                        Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1

                    # правым верхним углом
                if (Player2.Pl_X + Player2.Pl_Width >= self.Prj_X and Player2.Pl_X + Player2.Pl_Width <= self.Prj_Width + self.Prj_X):
                    if (Player2.Pl_Y  >= self.Prj_Y and Player2.Pl_Y  <= self.Prj_Height + self.Prj_Y):
                        Player2.HP = Player2.HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                        Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1
                    # нижний левый углом
                if (Player2.Pl_X  >= self.Prj_X and Player2.Pl_X <= self.Prj_Width + self.Prj_X):
                    if (Player2.Pl_Y + Player2.Pl_Height >= self.Prj_Y and Player2.Pl_Y + Player2.Pl_Height <= self.Prj_Height + self.Prj_Y):
                        Player2.HP = Player2.HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                        Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1

                    # верхний левый углом
                if (Player2.Pl_X  >= self.Prj_X and Player2.Pl_X  <= self.Prj_Width + self.Prj_X):
                    if (Player2.Pl_Y  >= self.Prj_Y and Player2.Pl_Y  <= self.Prj_Height + self.Prj_Y):
                        Player2.HP = Player2.HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                        Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1

                    # центром
                if (Player2.Pl_X + Player2.Pl_Width/2 >= self.Prj_X and Player2.Pl_X + Player2.Pl_Width/2 <= self.Prj_Width + self.Prj_X):
                    if (Player2.Pl_Y + Player2.Pl_Height/2 >= self.Prj_Y and Player2.Pl_Y + Player2.Pl_Height/2 <= self.Prj_Height + self.Prj_Y):
                        Player2.HP = Player2.HP - 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                        Player2.Invulnerability_frames_count = Player2.Invulnerability_frames_count + 1




        else:
            if Player1.Invulnerability_frames_count == 0:
                # правым нижним углом
                if (Player1.Pl_X + Player1.Pl_Width >= self.Prj_X and Player1.Pl_X + Player1.Pl_Width <= self.Prj_Width + self.Prj_X):
                    if (Player1.Pl_Y + Player1.Pl_Height >= self.Prj_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Prj_Height + self.Prj_Y):
                        Player1.HP = Player1.HP - 1
                        Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                        Player1.Pl_X = Player1.Pl_X - 3 * Player1.Player_speed
                        Player1.Pl_Y = Player1.Pl_Y - 3 * Player1.Player_speed
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                # правым верхним углом
                if (Player1.Pl_X + Player1.Pl_Width >= self.Prj_X and Player1.Pl_X + Player1.Pl_Width <= self.Prj_Width + self.Prj_X):
                    if (Player1.Pl_Y  >= self.Prj_Y and Player1.Pl_Y  <= self.Prj_Height + self.Prj_Y):
                        Player1.HP = Player1.HP - 1
                        Player1.Pl_X = Player1.Pl_X - 3 * Player1.Player_speed
                        Player1.Pl_Y = Player1.Pl_Y + 3 * Player1.Player_speed
                        Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)

                # нижний левый углом
                if (Player1.Pl_X  >= self.Prj_X and Player1.Pl_X <= self.Prj_Width + self.Prj_X):
                    if (Player1.Pl_Y + Player1.Pl_Height >= self.Prj_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Prj_Height + self.Prj_Y):
                        Player1.HP = Player1.HP - 1
                        Player1.Pl_X = Player1.Pl_X - 3 * Player1.Player_speed
                        Player1.Pl_Y = Player1.Pl_Y - 3 * Player1.Player_speed
                        Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                # верхний левый углом
                if (Player1.Pl_X + Player1.Pl_Width >= self.Prj_X and Player1.Pl_X + Player1.Pl_Width <= self.Prj_Width + self.Prj_X):
                    if (Player1.Pl_Y + Player1.Pl_Height >= self.Prj_Y and Player1.Pl_Y + Player1.Pl_Height <= self.Prj_Height + self.Prj_Y):
                        Player1.HP = Player1.HP - 1
                        Player1.Pl_X = Player1.Pl_X - 3 * Player1.Player_speed
                        Player1.Pl_Y = Player1.Pl_Y + 3 * Player1.Player_speed
                        Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)
                    # центр
                if (Player1.Pl_X + Player1.Pl_Width/2 >= self.Prj_X and Player1.Pl_X + Player1.Pl_Width/2 <= self.Prj_Width + self.Prj_X):
                    if (Player1.Pl_Y + Player1.Pl_Height/2 >= self.Prj_Y and Player1.Pl_Y + Player1.Pl_Height/2 <= self.Prj_Height + self.Prj_Y):
                        Player1.HP = Player1.HP - 1
                        Player1.Pl_X = Player1.Pl_X + 3 * Player1.Player_speed
                        Player1.Invulnerability_frames_count = Player1.Invulnerability_frames_count + 1
                        pygame.mixer.Sound.play(Sounds.Damage_Player1)


    def Create(self, Prj_X, Prj_Y):
        self.Prj_X = Prj_X
        self.Prj_Y = Prj_Y
        self.Move()
        self.Giving_Damage()
        display.blit(self.Prj_image, (self.Prj_X, self.Prj_Y))


# Создание моделей
#               surface  X                         Y                 Width Height Speed  Длина_траектории
Enemy1 = Enemy(display, random.randint(750, 1320), random.randint(0,650), 90, 47, 3, 30, Images.Enemy1, 10, 300, "Enemy")
Enemy2 = Enemy(display, random.randint(750, 1320), random.randint(0,350), 90, 47, 3, 30, Images.Enemy1, 10, 300, "Enemy2")
Enemy3 = Enemy(display, random.randint(750, 1320), random.randint(400,650), 90, 47, 3, 30, Images.Enemy1, 10, 300, "Enemy3")

Player1 = Player(display, random.randint(50, 500), random.randint(200,500), 105, 55, 4, Images.Player1, 200, 3, "Player1")
Player2 = Player(display, random.randint(750, 1200), random.randint(200,500), 105, 55, 4, Images.Player2, 200, 3, "Player2")
Player3 = Player(display, random.randint(50, 500), random.randint(200,500), 105, 55, 4, Images.Player2, 200, 3, "Player1")

Meteor1_1 = Meteors(display, 2, Images.Meteor1, 50, 70, "PVE1")
Meteor1_2 = Meteors(display, 2, Images.Meteor1, 50, 70, "PVE1")
Meteor1_3 = Meteors(display, 3, Images.Meteor1, 50, 70, "PVE1")
Meteor1_4 = Meteors(display, 3, Images.Meteor1, 50, 70, "PVP")
Meteor1_5 = Meteors(display, 3, Images.Meteor1, 50, 70, "PVP")





Player1_Projectile1_1 = Projectiles(display, 70, 40, 7, Images.Player1_Projectile1, "Player1")
Player1_Projectile1_2 = Projectiles(display, 70, 40, 7, Images.Player1_Projectile1, "Player1")

Player2_Projectile1_1 = Projectiles(display, 70, 40, 7, Images.Player2_Projectile1, "Enemy")
Player2_Projectile1_2 = Projectiles(display, 70, 40, 7, Images.Player2_Projectile1, "Enemy")

Enemy_Projectile1 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy")
Enemy_Projectile2 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy")
Enemy2_Projectile1 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy2")
Enemy2_Projectile2 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy2")
Enemy3_Projectile1 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy3")
Enemy3_Projectile2 = Projectiles(display, 34, 34, 7, Images.Enemy1_Projectile, "Enemy3")

def Menu():
    Menu = True
    pygame.mixer.stop()
    Button_Play = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT/2 - 35, 300, 70, Images.Play_Button1, Images.Play_Button2, GameCycle1)
    Button_Guide = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT/2 + 70, 300,  70, Images.Guide_Button1, Images.Guide_Button2, Guide_menu)
    Button_Exit = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT/2 + 175, 300, 70, Images.Exit_Button1, Images.Exit_Button2, os.abort)
    Button_PVP = Buttons.Buttons(display, WIDTH/4 - 150, HEIGHT/2 + 70  , 300, 70, Images.PVP_Button1, Images.PVP_Button2, Game1by1)
    Sounds.Menu_Sound.play()
    while Menu:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                Menu = False
                os.abort()
        display.blit(Images.Background_Menu, (0, 0))
        Button_Play.Button_Create()
        Button_Guide.Button_Create()
        Button_Exit.Button_Create()
        Button_PVP.Button_Create()
        pygame.display.update()
    clock.tick(FPS)


def Guide_menu():
    Guide = True
    Button_Back = Buttons.Buttons(display, 20, 20, 200, 50, Images.Back_Button1, Images.Back_Button2, Menu)

    while Guide:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                Guide = False
                os.abort()
        display.blit(Images.Background_Guide_Menu,(0, 0))
        Button_Back.Button_Create()
        pygame.display.update()
    clock.tick(FPS)


def Pause_Menu():
    Pause = True
    while Pause:
        display.blit(Images.Pause_Menu, (WIDTH / 2 - 350, HEIGHT / 2 - 150))
        pygame.display.update()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                Pause = False
                os.abort()
        keys = pygame.key.get_pressed()
        if keys[pygame.K_ESCAPE]:
            Pause = False
        clock.tick(FPS)

def Dying_Menu():
    Dying_Menu = True
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.Dying_Menu)
    Button_Restart = Buttons.Buttons(display, 200, HEIGHT/2, 300, 50, Images.Restart_Button1, Images.Restart_Button2, Menu)
    Button_Quit = Buttons.Buttons(display, 200, HEIGHT/2 + 100, 300, 50, Images.Quit_Button1, Images.Quit_Button2, os.abort)
    while Dying_Menu:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                Dying_Menu = False
                os.abort()
        display.blit(Images.Dying_display, (0, 0))
        Button_Restart.Button_Create()
        Button_Quit.Button_Create()
        pygame.display.update()
    clock.tick(FPS)

def Win_Menu():

    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.Win)
    Win_Menu = True
    Button_Restart = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2, 300, 50, Images.Restart_Button1, Images.Restart_Button2,Menu)
    Button_Quit = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2 + 100, 300, 50, Images.Quit_Button1, Images.Quit_Button2, os.abort)
    while Win_Menu:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                Win_Menu = False
                os.abort()
        display.blit(Images.Win_Background, (0, 0))
        Button_Restart.Button_Create()
        Button_Quit.Button_Create()
        pygame.display.update()
    clock.tick(FPS)

def PVP_END_Menu1():
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.PVP_Win_sound)
    PVP_MENU = True
    Button_Restart = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2, 300, 50, Images.Restart_Button1, Images.Restart_Button2,Menu)
    Button_Quit = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2 + 100, 300, 50, Images.Quit_Button1, Images.Quit_Button2, os.abort)
    while PVP_MENU:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                PVP_MENU = False
                os.abort()
        display.blit(Images.Pl1_Win_Background, (0, 0))
        Button_Restart.Button_Create()
        Button_Quit.Button_Create()
        pygame.display.update()
    clock.tick(FPS)

def PVP_END_Menu2():
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.PVP_Win_sound)
    PVP_Menu = True
    Button_Restart = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2, 300, 50, Images.Restart_Button1, Images.Restart_Button2,Menu)
    Button_Quit = Buttons.Buttons(display, WIDTH/2 - 150, HEIGHT / 2 + 100, 300, 50, Images.Quit_Button1, Images.Quit_Button2, os.abort)
    while PVP_Menu:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                PVP_Menu = False
                os.abort()
        display.blit(Images.Pl2_Win_Background, (0, 0))
        Button_Restart.Button_Create()
        Button_Quit.Button_Create()
        pygame.display.update()
    clock.tick(FPS)

def Game1by1():
    Count_change_cycle = 0
    count = 0
    game = True
    Player1.HP = 5
    Player2.HP = 5
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.PVP_Sound)
    Pause_Button = Buttons.Buttons(display, 20, 20, 200, 50, Images.Pause_Button1, Images.Pause_Button2,Pause_Menu)
    Show_HP1 = Show_HP.Show_hp(display, Images.HP1, Images.HP2, Images.HP3, Images.HP4, Images.HP5, 250)
    Show_HP2 = Show_HP.Show_hp(display, Images.HP1, Images.HP2, Images.HP3, Images.HP4, Images.HP5, 950)

    while game:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                os.abort()

        if Player1.HP <= 0 or Player2.HP <= 0:
            Count_change_cycle += 1

        if Player1.HP <= 0 and Count_change_cycle >= 50:
            PVP_END_Menu2()

        if Player2.HP <= 0 and Count_change_cycle >= 50:
            PVP_END_Menu1()

        display.blit(Images.PVP_Background, (0, 0))
        Player1.Player_create()
        Player2.Player_create()
        Meteor1_1.create_Meteors()
        Meteor1_4.create_Meteors()
        Pause_Button.Button_Create()
        Show_HP1.Create_Hp(Player1.HP)
        Show_HP2.Create_Hp(Player2.HP)

        if (count >= 160):
            Meteor1_2.create_Meteors()
            Meteor1_5.create_Meteors()


        if count > 10000:
            count = 0
        count = count + 1
        pygame.display.update()
        clock.tick(90)

def GameCycle1():
    Count_change_cycle = 0
    count = 0
    game = True
    Player1.HP = 3
    Enemy1.Enemy_HP = 0
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.Sound_level1)
    Pause_Button = Buttons.Buttons(display, 20, 20, 200, 50, Images.Pause_Button1, Images.Pause_Button2, Pause_Menu)
    Show_HP1 = Show_HP.Show_hp(display, Images.HP1, Images.HP2, Images.HP3, Images.HP4, Images.HP5, 250)

    while game:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                os.abort()

        if Player1.HP <= 0 or Enemy1.Enemy_HP <= 0:
            Count_change_cycle +=1

        if Player1.HP <= 0 and Count_change_cycle >= 50:
            Dying_Menu()

        if Enemy1.Enemy_HP <= 0 and Count_change_cycle >= 50:
            GameCycle2()

        display.blit(Images.Stage1, (0, 0))
        Player1.Player_create()
        Enemy1.Create_Enemy()
        Meteor1_1.create_Meteors()
        Pause_Button.Button_Create()
        Show_HP1.Create_Hp(Player1.HP)

        if (count >= 160):
            Meteor1_2.create_Meteors()

        if (count >= 320):
            Meteor1_3.create_Meteors()

        if count > 100000:
            count = 0

        count = count + 1
        pygame.display.update()
        clock.tick(FPS)

def GameCycle2():
    Count_change_cycle = 0
    count = 0
    game = True
    Player3.HP = Player1.HP + 1
    pygame.mixer.stop()
    pygame.mixer.Sound.play(Sounds.Sound_level1)
    Pause_Button = Buttons.Buttons(display, 20, 20, 200, 50, Images.Pause_Button1, Images.Pause_Button2, Pause_Menu)
    Show_HP1 = Show_HP.Show_hp(display, Images.HP1, Images.HP2, Images.HP3, Images.HP4, Images.HP5, 250)

    while game:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                os.abort()

        if Player3.HP <= 0 or (Enemy2.Enemy_HP <= 0 and Enemy3.Enemy_HP <=0):
            Count_change_cycle +=1

        if Player3.HP <= 0 and Count_change_cycle >= 50:
            Dying_Menu()

        if Enemy2.Enemy_HP <= 0 and Enemy3.Enemy_HP <= 0 and Count_change_cycle >= 50:
            Win_Menu()

        display.blit(Images.Stage1, (0, 0))
        Player3.Player_create()
        Enemy2.Create_Enemy()
        Enemy3.Create_Enemy()
        Meteor1_1.create_Meteors()
        Pause_Button.Button_Create()
        Show_HP1.Create_Hp(Player1.HP)

        if (count >= 160):
            Meteor1_2.create_Meteors()

        if count > 100000:
            count = 0

        count = count + 1
        pygame.display.update()
        clock.tick(FPS)

Menu()
