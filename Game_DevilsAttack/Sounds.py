import pygame

pygame.init()
pygame.mixer.init()

Sound_level1 = pygame.mixer.Sound("Sound_level1.mp3")
Sound_level1.set_volume(0.4)

Die_Player1 = pygame.mixer.Sound("Player1_die.mp3")
Damage_Player1 = pygame.mixer.Sound("Damage_player1.mp3")
Damage_Player1.set_volume(0.2)
Die_Player1.set_volume(0.8)
Attack_Player = pygame.mixer.Sound("Attack_Player.mp3")
Attack_Player.set_volume(0.1)

Damage_Enemy1 = pygame.mixer.Sound("Damage_Enemy1.mp3")
Die_Enemy1 = pygame.mixer.Sound("Die_Enemy1.mp3")
Damage_Enemy1.set_volume(0.4)
Die_Enemy1.set_volume(0.8)
Attack_Enemy = pygame.mixer.Sound("Enemy_Attack.mp3")
Attack_Enemy.set_volume(0.1)

Menu_Sound = pygame.mixer.Sound("Menu_Sound.mp3")
Menu_Sound.set_volume(0.1)

Sound_For_Buttons = pygame.mixer.Sound("Sound_For_Buttons.mp3")

Dying_Menu = pygame.mixer.Sound("Dying_Menu.mp3")
Dying_Menu.set_volume(0.1)

Win = pygame.mixer.Sound("Win.mp3")
Win.set_volume(0.4)


PVP_Sound = pygame.mixer.Sound("PVP_Sound.mp3")
PVP_Sound.set_volume(0.1)
PVP_Win_sound = pygame.mixer.Sound("PVP_WIN.mp3")
PVP_Win_sound.set_volume(0.1)

Damage_Outline = pygame.mixer.Sound("Damage_Outline.mp3")
