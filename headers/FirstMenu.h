#ifndef FIRSTMENU_H_INCLUDED
#define FIRSTMENU_H_INCLUDED

#include "include.h"
#include "TexturesManager.h"

ManageTexture gPlayGame,gInstruction,gOptions,gQuit,gHighScores, gLogo,gCredits, gResume, gNewGame;

const string playgame = "textures/menu/StartGame/SG.png";
const string playgame_button = "textures/menu/StartGame/SG_Button.png";
const string instruc = "textures/menu/Instructions/Ins.png";
const string instruc_button = "textures/menu/Instructions/Ins_Button.png";
const string option = "textures/menu/Options_110x65/OPT.png";
const string option_button = "textures/menu/Options_110x65/OPT_Button.png";
const string quit = "textures/menu/Quit_110x65/QUIT.png";
const string quit_button = "textures/menu/Quit_110x65/QUIT_Button.png";
const string highsc = "textures/menu/HighScores/HS.png";
const string highsc_button = "textures/menu/HighScores/HS_Button.png";
const string logo = "textures/menu/Logo/LOGO.png";
const string cred = "textures/menu/Credits_142x70/Cre.png";
const string cred_button = "textures/menu/Credits_142x70/Cre_Button.png";
const string resume = "textures/menu/Resume/RS.png";
const string resume_button = "textures/menu/Resume/RS_Button.png";
const string newgame = "textures/menu/NewGame/NG.png";
const string newgame_button = "textures/menu/NewGame/NG_Button.png";

void loadSource();

void inputFirstMenu();

void firstmenu();

SDL_RendererFlip flip = SDL_FLIP_NONE;

#endif // FIRSTMENU_H_INCLUDED
